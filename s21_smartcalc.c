#include "s21_smartcalc.h"

int smart_calc(char * src, double * result) {
  int status = SUCCESS;
  *result = 0.;
  node_t * output_list = NULL;
  status = convert_polish_notation (&output_list, src);
  printNode(output_list);

  if (status == SUCCESS)
    status = calculate (output_list, result, 0., GRAPH_OFF);

  // printf("\n%d %lf", status, result);
  remove_node(output_list);
  
  return status;
}


// отдельно считаем польскую нотацию из строки, и отдаем список 
int convert_polish_notation (node_t ** output_list, char * src) {
  int status = SUCCESS;
  if (src && *src != '\0') {
    node_t * input_list = init_node();
    node_t * head_input = input_list;
    status = SUCCESS;

    // заполнение input_list лексемами из строки
    status = input_input_list (&input_list, &src);
    // печатаем все лексемы
    // printNode(head_input);
    // printf("\n");;

    if (status > 0) {
      // выходной список, вначале для оп,ерандов а потом для операция
      *output_list = init_node();

  

      node_t * head_output = *output_list;
      // собираем обратную польскую нотацию по алгоритму декстеры
      

      status = polish_notattion (head_input, output_list);

      *output_list = head_output;

      // зачищаем стек
      remove_node(input_list);


    }
  } else status = NOT_SRC;
    return status;
}



// собираем обратную польскую нотацию по алгоритму декстеры
int polish_notattion(node_t * input_list, node_t ** output_list) {
  int status = SUCCESS;

  node_t * stack_list = init_node();

  while (input_list != NULL && status > 0) {
    
    // printNode(input_list);
    // printNode(*output_list);
    // printNode(stack_list);

    // ситуация если закрывающая скобка
    if (input_list->token.type == CLOSE_BRACKET) {
      // проходимся в цикле, и выплевывем все из стека в output_list
      while (status > 0 && (stack_list)->token.type != OPEN_BRACKET) {
        if ((stack_list)->token.type == EMPTY) {status = FAILURE;}
        else {*output_list = add_elem (*output_list, (stack_list)->token.num, (stack_list)->token.type);
        stack_list = del_elem (stack_list);
        }
      }
      if (status > 0) stack_list = del_elem (stack_list); // удаляем открывающуюся скобку
    }

    // если приоретет <= то выплевываем до открывающейся скобки, либо до начала
    if (status > 0 && (priority(input_list) <= priority(stack_list)) && (priority(input_list) != 0) && (priority(input_list) != 5) && (input_list->token.type != UNARY_PLUS)) {
      // проходимся в цикле, и выплевывем все из стека в output_list
      while (status > 0 && (stack_list)->token.type != OPEN_BRACKET && (stack_list)->token.type != EMPTY && priority(input_list)<=priority(stack_list)) {
        *output_list = add_elem (*output_list, (stack_list)->token.num, (stack_list)->token.type);
        stack_list = del_elem (stack_list);
      }
    }

    if (status > 0) {

    
    // распределяем из input в output или стек
    // если числа, то распределяем в output_list
    if (input_list->token.type == NUMBER || input_list->token.type == X_NUMBER) {
      *output_list = add_elem (*output_list, input_list->token.num, input_list->token.type);
      // если с приоритетом != 0, чтобы исключить ситуации с числом, пустотой и закрывающей скобкой
    } else if ( priority(input_list) != 0 && input_list->token.type != CLOSE_BRACKET) {
        // для унарного минуса добавляем 0 в output_list
        if (input_list->token.type == UNARY_MINUS) {
          *output_list = add_elem (*output_list, 0., NUMBER);
          input_list->token.type = BINARY_MINUS;
        } 
        if (input_list->token.type != UNARY_PLUS)
          stack_list = add_elem (stack_list, input_list->token.num, input_list->token.type);
    }
    input_list = input_list->next;
    }
  }

  // input_list закончился, нужно выплюнуть из стека все, что там есть
  while (status > 0 && (stack_list)->token.type != EMPTY) {
    *output_list = add_elem (*output_list, (stack_list)->token.num, (stack_list)->token.type);
    stack_list = del_elem (stack_list);
  }

  // зачищаем стек
  remove_node(stack_list);

  return status;
}

// подсчет выражения по полученной польской нотации
int calculate(node_t * output_list, double * result, double x, int graph) {
  int status = SUCCESS;

  node_t *stack = init_node();
  double buf = 0.;
  double buf2 = 0.;


  while (output_list != NULL && status > 0) {
    if (output_list->token.type == EMPTY) output_list = output_list->next;
    // если число - кладем в стек
    if (output_list->token.type == NUMBER || output_list->token.type == X_NUMBER) {
      if (graph) {
        stack = add_elem (stack, x, output_list->token.type);
      } else {
        if (output_list->token.type == X_NUMBER) {
          status = GRAPH_X;
          break;
        }
        stack = add_elem (stack, output_list->token.num, output_list->token.type);
      }

    }
    else if (output_list->token.type != EMPTY && priority(output_list) != 5){
      if (!is_binary(output_list) && stack && stack->token.type == NUMBER) {
        buf = stack->token.num;
        status = for_unary(&stack->token.num, output_list, buf);
      }
      else {
        if (stack && stack->prev && stack->prev->token.type == NUMBER && stack->token.type == NUMBER) {
                  buf = stack->token.num;
        buf2 = stack->prev->token.num;
        stack = del_elem(stack);
        // if (buf2 == 0.) status = 
        status = for_binary(&stack->token.num, output_list, buf2, buf);
        } 
        else status = FAILURE;

      }
    }
    else {
      status = FAILURE;
    }
    output_list = output_list->next;
  }
  
  *result = stack->token.num;
  remove_node(stack);
  return status;
}

// проверяет бинарный ли перед нами оператор, 1 - да
int is_binary(node_t * cur) {
  int answer = 1;
  if (priority(cur) == 3) 
    answer = 0;
  return answer;
}

int for_binary(double * res, node_t *stack, double num_1, double num_2) {
    int status = SUCCESS;
    token_type oper = stack->token.type;
    *res = 0.;

    if (oper == BINARY_PLUS)
        *res = num_1 + num_2;
    else if (oper == BINARY_MINUS)
        *res = num_1 - num_2;
    else if (oper == DIV) {
        if (num_2) {
          *res = num_1 / num_2;
        } else {
          status = INCORRECT_VAL;
          if (num_1) *res = INFINITY;
          else *res = NAN;
        }
    }
    else if (oper == MULT)
        *res = num_1 * num_2;
    else if (oper == MOD) {
      if (num_2) {
        *res = fmod(num_1, num_2);
      } else {
        status = INCORRECT_VAL;
      }
    } else if (oper == POW) {
        if (num_2 >= 0. && num_1 != 0) {
          *res = pow(num_1, num_2);
        } else {
          status = INCORRECT_VAL;
        }
    }

    return status;
}

int for_unary(double * res, node_t *stack, double num_1) {
    int status = SUCCESS;
    token_type oper = stack->token.type;

    *res = 0.;
    if (oper == SQRT) {
      if (num_1 >= 0) {
        *res = sqrt(num_1);
      } else {
        status = INCORRECT_VAL;
      }
    }
    else if (oper == SIN) 
        *res = sin(num_1);
    else if (oper == COS) 
        *res = cos(num_1);
    else if (oper == TAN) 
        *res = tan(num_1);
    else if (oper == ASIN) {
      if (fabs(num_1) <= 1) {
        *res = asin(num_1);
      } else {
        status = INCORRECT_VAL;
      }
    }
    else if (oper == ACOS) {
      if (fabs(num_1) <= 1) {
        *res = acos(num_1);
      } else {
        status = INCORRECT_VAL;
      }
    }
    else if (oper == ATAN) 
      *res = atan(num_1);
    else if (oper == LN) { // natural logarithm
      if (num_1 > 0) {
        *res = log(num_1);
      } else {
        status = INCORRECT_VAL;
      }
    } 
    else if (oper == LOG)  { // natural logarithm
      if (num_1 > 0) {
        *res = log10(num_1);
      } else {
        status = INCORRECT_VAL;
      }
    } 

    return status;
}

// заполнение input_list лексемами из строки
int input_input_list (node_t ** input_list, char ** src) {
  int status = SUCCESS;
  while (**src != '\0' && status > 0) {
        status = find_number(input_list, src); // если точек > 1 : выдать ошбку
        if (status == SUCCESS) find_one_char(input_list, src); // если подряд знаки - тоже ошибка
        
        if (status == SUCCESS) find_func(input_list, src); //
        if (status == SUCCESS) skip_space(src);
        // printf("%s\n", *src);
        // sleep(1);
  }
  return status;
}

// определение числа
int find_number (node_t ** input_list, char ** src) {
      int status = SUCCESS;
      int length_number = 0;
      length_number = strspn(*src, "1234567890.");
      double var = 0;


      if (length_number) { 
        // если две точки в числе то ошибка
        if (two_doubles(*src, length_number)) status = FAILURE;
        else {
          sscanf(*src, "%lf", &var);
          *input_list = add_elem(*input_list, var, NUMBER);
          status = SUCCESS;
        }
      }

      *src += length_number;
      return status;
}

// ищет две точки в числе по длине len
int two_doubles(char * str, int len) {
  int result = 0;
  for (int i = 0; len > 0; len--, i++) {
    if (str[i] == '.') result++;
  }
  return result >= 2 ? 1 : 0;
}

// определение функции из 2-4 символов
int find_func (node_t ** input_list, char ** src) {
      int status = FAILURE;
      int length_number = 0;



      length_number = strspn(*src, "mod");
      if (length_number) {
        *input_list = add_elem(*input_list, 0., MOD);
        *src += length_number;
        length_number = 0;
        status = SUCCESS;
      }
      
      // подправить
      length_number = strspn(*src, "asin");
      if (length_number == 4) {
        *input_list = add_elem(*input_list, 0., ASIN);
        *src += length_number;
        length_number = 0;
        status = SUCCESS;
      }

      length_number = strspn(*src, "sin");
      if (length_number == 3) {
        *input_list = add_elem(*input_list, 0., SIN);
        *src += length_number;
        length_number = 0;
        status = SUCCESS;
      }

      length_number = strspn(*src, "acos");
      if (length_number == 4) {
        *input_list = add_elem(*input_list, 0., ACOS);
        *src += length_number;
        length_number = 0;
        status = SUCCESS;
      }

      length_number = strspn(*src, "cos");
      if (length_number == 3) {
        *input_list = add_elem(*input_list, 0., COS);
        *src += length_number;
        length_number = 0;
        status = SUCCESS;
      }

      length_number = strspn(*src, "atan");
      if (length_number == 4) {
        *input_list = add_elem(*input_list, 0., ATAN);
        *src += length_number;
        length_number = 0;
        status = SUCCESS;
      }

      length_number = strspn(*src, "tan");
      if (length_number == 3) {
        *input_list = add_elem(*input_list, 0., TAN);
        *src += length_number;
        length_number = 0;
        status = SUCCESS;
      }

      length_number = strspn(*src, "ln");
      if (length_number == 2) {
        *input_list = add_elem(*input_list, 0., LN);
        *src += length_number;
        length_number = 0;
        status = SUCCESS;
      }

      length_number = strspn(*src, "log");
      if (length_number == 3) {
        *input_list = add_elem(*input_list, 0., LOG);
        *src += length_number;
        length_number = 0;
        status = SUCCESS;
      }

      length_number = strspn(*src, "^");
      if (length_number == 1) {
        *input_list = add_elem(*input_list, 0., POW);
        *src += length_number;
        length_number = 0;
        status = SUCCESS;
      }


      length_number = strspn(*src, "sqrt");
      if (length_number == 4) {
        *input_list = add_elem(*input_list, 0., SQRT);
        *src += length_number;
        length_number = 0;
        status = SUCCESS;
      }

    
      return status;
}

// определение функции из 1 символа
void find_one_char (node_t ** input_list, char ** src) {
      if (**src == '+') {
        if (((*input_list)->prev == NULL) || ((*input_list)->token.type == OPEN_BRACKET)) {
          *input_list = add_elem(*input_list, 0., UNARY_PLUS);
          (*src)++;
        } else {
          *input_list = add_elem(*input_list, 0., BINARY_PLUS);
          (*src)++;
        }
      }
      if (**src == '-') {
        if (((*input_list)->prev == NULL) || ((*input_list)->token.type == OPEN_BRACKET)) {
          *input_list = add_elem(*input_list, 0., UNARY_MINUS);
          (*src)++;
        } else {
          *input_list = add_elem(*input_list, 0., BINARY_MINUS);
          (*src)++;
        }   
      }
      if (**src == '/') {
          *input_list = add_elem(*input_list, 0., DIV);
          (*src)++;
      }      
      if (**src == '*') {
          *input_list = add_elem(*input_list, 0., MULT);
          (*src)++;
      }
      if (**src == '(') {
          *input_list = add_elem(*input_list, 0., OPEN_BRACKET);
          (*src)++;
      }
      if (**src == ')') {
          *input_list = add_elem(*input_list, 0., CLOSE_BRACKET);
          (*src)++;
      }
      if (**src == 'x') {
          *input_list = add_elem(*input_list, 0., X_NUMBER);
          (*src)++;
      }
  
}

// задаем новый список
node_t * init_node () {
        node_t * head = (node_t *)calloc(1, sizeof(node_t));
    if (head != NULL) {
        head->token.type = EMPTY;
    }
    return head;
}

// добавить элемент в конец списка, с указателем на предыдущий токен, значением и типом
node_t * add_elem (node_t * prev, double num, token_type type) {
        node_t * cur = (node_t *)calloc(1, sizeof(node_t));
    if (cur != NULL) {
        prev->next = cur;
        cur->prev = prev;
        cur->token.num = num;
        cur->token.type = type;
    }
    return cur;
}




// удалить элемент с конца списка, отдает ссылку на предыдущий элемент или null
node_t * del_elem (node_t * cur) {
  node_t * prev = NULL;
  if (cur) {
    prev = cur->prev;
    prev->next = NULL;
    free(cur);
  }
  return prev;
}

// полностью очистить список с любого элемента
void remove_node(node_t *cur) {
  // переходим в самый конец для очистки
  while (cur && cur->next) 
    cur = cur->next;
  while (cur != NULL) {
    struct node *prev = cur->prev;
    free(cur);
    cur = prev;
  }
}

void skip_space(char **src) {
  while (**src == ' ') (*src)++;
}

void printNode(node_t *head) {
    node_t *current = head;
    char type [25][25] = {"EMPTY", "NUMBER", "X", "+", "-", "U-", "U+", "*", "/", "mod", "cos", "sin", "tan", "acos", "asin", "atan", "sqrt", "ln", "log", "^", "(", ")"};
    while (current != NULL) {
        if (current->token.type == NUMBER)
            printf(" %lg ", current->token.num);
        else
            printf(" %s ", type[current->token.type+1]);
        current = current->next;
    }
}

int priority(node_t * cur) {
  int prior = 0;
  if (cur->token.type <= 5 && cur->token.type >= 2) {
    prior = 1;
  } else if (cur->token.type >= 6 && cur->token.type <= 8) {
    prior = 2;
  } else if (cur->token.type >= 9 && cur->token.type <= 17) {
    prior = 3;
  } else if (cur->token.type == 18) {
    prior = 4;
  } else if (cur->token.type > 18) {
    prior = 5;
  }
  return prior;
}