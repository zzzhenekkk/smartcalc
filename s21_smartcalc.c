#include "s21_smartcalc.h"

// int smart_calc(char * src, double * result) {
//   int status = SUCCESS;
//   if (src) {
//     node_t * input_list = init_node();
//     node_t * head_input = input_list;
//     status = SUCCESS;
//     // заполнение input_list лексемами из строки
//     input_input_list (&input_list, &src);
//     // печатаем все лексемы
//     // printNode(head_input);
//     // printf("\n");

//     // выходной список, вначале для оп,ерандов а потом для операция
//     node_t * output_list = init_node();
//     // стек для операций, и их череда
//     node_t * stack_list = init_node();

//     node_t * head_output = output_list;
//     // собираем обратную польскую нотацию по алгоритму декстеры
    
//     polish_notattion (head_input, &output_list, &stack_list);

//     printNode(head_output);
//     *result = calculate(head_output, &status);
//     printf("%lf", *result);
  
//   // зачищаем все списки
//     remove_node(stack_list);
//     remove_node(output_list);
//     remove_node(input_list);
//   } else 
//     status = FAILURE;
//   return status;
// }


// отдельно считаем польскую нотацию из строки, и отдаем список 
int convert_polish_notation (node_t ** output_list, char * src) {
  int status = SUCCESS;
  if (src) {
    node_t * input_list = init_node();
    node_t * head_input = input_list;
    status = SUCCESS;

    // заполнение input_list лексемами из строки
    input_input_list (&input_list, &src);
    // печатаем все лексемы
    // printNode(head_input);
    // printf("\n");

    //  проверяем на корректные скобки
    status = check_brackets(input_list);

    if (status == SUCCESS) {
      // выходной список, вначале для оп,ерандов а потом для операция
      *output_list = init_node();

      // стек для операций, и их череда
      node_t * stack_list = init_node();

      node_t * head_output = output_list;
      // собираем обратную польскую нотацию по алгоритму декстеры
      

      status = polish_notattion (head_input, &output_list, &stack_list);

      *output_list = head_output;

      // зачищаем стек
      remove_node(stack_list);
    }


    

    // зачищаем список
    remove_node(input_list);
  }
    return status;
}

  // int calc (node_t * head_output, double * result, double x) {
  //   int status = SUCCESS;
  //   result = calculate(head_output, &status);
  //   return status;
  // }



// собираем обратную польскую нотацию по алгоритму декстеры
int polish_notattion(node_t * input_list, node_t ** output_list, node_t ** stack_list) {
  int status = SUCCESS;
  while (input_list != NULL) {
    
    // printNode(input_list);
    // printNode(*output_list);
    // printNode(*stack_list);

    // ситуация если закрывающая скобка
    if (input_list->token.type == CLOSE_BRACKET) {
      // проходимся в цикле, и выплевывем все из стека в output_list
      while ((*stack_list)->token.type != OPEN_BRACKET) {
        *output_list = add_elem (*output_list, (*stack_list)->token.num, (*stack_list)->token.type);
        *stack_list = del_elem (*stack_list);
      }
      *stack_list = del_elem (*stack_list); // удаляем открывающуюся скобку
    }

    // если приоретет <= то выплевываем до открывающейся скобки, либо до начала
    if ((priority(input_list) <= priority(*stack_list)) && (priority(input_list) != 0) && (priority(input_list) != 5) && (input_list->token.type != UNARY_PLUS)) {
      // проходимся в цикле, и выплевывем все из стека в output_list
      while ((*stack_list)->token.type != OPEN_BRACKET && (*stack_list)->token.type != EMPTY ) {
        *output_list = add_elem (*output_list, (*stack_list)->token.num, (*stack_list)->token.type);
        *stack_list = del_elem (*stack_list);
      }
    }


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
          *stack_list = add_elem (*stack_list, input_list->token.num, input_list->token.type);
    }
    input_list = input_list->next;
  }

  // input_list закончился, нужно выплюнуть из стека все, что там есть
  while ((*stack_list)->token.type != EMPTY) {
    *output_list = add_elem (*output_list, (*stack_list)->token.num, (*stack_list)->token.type);
    *stack_list = del_elem (*stack_list);
  }

  // зачищаем стек
  remove_node(*stack_list);

  return status;
}

// подсчет выражения по полученной польской нотации
int calculate(node_t * output_list, double * result, double x, int graph) {
  int status = SUCCESS;

  node_t *stack = init_node();
  double buf = 0.;
  double buf2 = 0.;


  while (output_list != NULL && status == SUCCESS) {

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
      if (!is_binary(output_list)) {
        buf = stack->token.num;
        status = for_unary(&stack->token.num, output_list, buf);
      }
      else {
        buf = stack->token.num;
        buf2 = stack->prev->token.num;
        stack = del_elem(stack);
        // if (buf2 == 0.) status = 
        status = for_binary(&stack->token.num, output_list, buf, buf2);
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
      if (fabs(num_1) > 1) {
        *res = asin(num_1);
      } else {
        status = INCORRECT_VAL;
      }
    }
    else if (oper == ACOS) {
      if (fabs(num_1) > 1) {
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
void input_input_list (node_t ** input_list, char ** src) {
  while (**src != '\0') {
        find_number(input_list, src); // если точек > 1 : выдать ошбку
        find_one_char(input_list, src); // если подряд знаки - тоже ошибка
        find_func(input_list, src); //
        skip_space(src);
        // printf("%s\n", *src);
        // sleep(1);
  }
}

// определение числа
int find_number (node_t ** input_list, char ** src) {
      int status = FAILURE;
      int length_number = 0;
      length_number = strspn(*src, "1234567890.");
      double var = 0;

      if (length_number) {
        sscanf(*src, "%lf", &var);
        *input_list = add_elem(*input_list, var, NUMBER);
        status = SUCCESS;
      }
      *src += length_number;
      return status;
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

      length_number = strspn(*src, "pow");
      if (length_number == 3) {
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


// проверка на корректность введенных скобок
int check_brackets(node_t *input_head) {
    int status = SUCCESS;
    node_t * buf = init_node();
    node_t * head = input_head;

    while (head != NULL && status) {

        if (head->token.type == OPEN_BRACKET)
            buf = add_elem(buf, 0., OPEN_BRACKET);
        else if (head->token.type == CLOSE_BRACKET) {
            if (buf != NULL)
                buf = del_elem(buf);
            else {
                status = FAILURE;
            }
        }
        head = head->next;
    }

    // if (input_head == NULL) {
    //     status = FAILURE;
    // }

    if (buf->token.type != EMPTY) status = FAILURE;

    // очистка buf
    remove_node(buf);

    return status;
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
  while (cur->next) 
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
    char type [25][25] = {"EMPTY", "NUMBER", "X", "B+", "B-", "U-", "U+", "*", "/", "mod", "cos", "sin", "tan", "acos", "asin", "atan", "sqrt", "ln", "log", "pow", "(", ")"};
    while (current != NULL) {
        if (current->token.type == NUMBER)
            printf(" %lf ", current->token.num);
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