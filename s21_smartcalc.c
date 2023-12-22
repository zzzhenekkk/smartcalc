#include "s21_smartcalc.h"

int smart_calc(char * src, double * result) {
  int status = SUCCESS;
  node_t * input_list = init_node();

  node_t * head_input = input_list;

  if (src) {
    status = SUCCESS;
    // заполнение input_list лексемами из строки
    input_input_list (&input_list, &src);
    // печатаем все лексемы
    printNode(head_input);
    printf("\n");

    // выходной список, вначале для оп,ерандов а потом для операция
    node_t * output_list = init_node();
    // стек для операций, и их череда
    node_t * stack_list = init_node();

    node_t * head_output = output_list;
    // собираем обратную польскую нотацию по алгоритму декстеры
    
    polish_notattion (head_input, &src, &output_list, &stack_list);

    printNode(head_output);
    printf("%lf", calculate(head_output, 0.));
    // считаем обратную польскую нотацию 
    // double calculate_polish_not () {}
  } else 
    status = FAILURE;


  return status;
}

// собираем обратную польскую нотацию по алгоритму декстеры
int polish_notattion(node_t * input_list, char ** src, node_t ** output_list, node_t ** stack_list) {
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
double calculate(node_t * output_list, double x) {
  node_t *stack = init_node();
  double buf = 0.;
  double buf2 = 0.;
  while (output_list != NULL) {
    // есл число - кладем в стек
    if (output_list->token.type == NUMBER || output_list->token.type == X_NUMBER) {
      stack = add_elem (stack, output_list->token.num, output_list->token.type);
    }
    else if (output_list->token.type != EMPTY && priority(output_list) != 5){
      if (!is_binary(output_list)) {
        buf = stack->token.num;
        stack->token.num = for_unary(output_list, buf);
      }
      else {
        buf = stack->token.num;
        buf2 = stack->prev->token.num;
        stack = del_elem(stack);
        stack->token.num = for_binary(output_list, buf, buf2);
      }
    }
    else {
      printf("error\n");
    }
  output_list = output_list->next;
  }
  
  buf = stack->token.num;
  remove_node(stack);
  return buf;
}

// проверяет бинарный ли перед нами оператор, 1 - да
int is_binary(node_t * cur) {
  int answer = 1;
  if (priority(cur) == 3) 
    answer = 0;
  return answer;
}

double for_binary(node_t *stack, double num_1, double num_2) {
    token_type oper = stack->token.type;
    double res = 0.;
    if (oper == BINARY_PLUS)
        res = num_1 + num_2;
    else if (oper == BINARY_MINUS)
        res = num_1 - num_2;
    else if (oper == DIV)
        res = num_1 / num_2;
    else if (oper == MULT)
        res = num_1 * num_2;
    else if (oper == MOD)
        res = fmod(num_1, num_2);
    else if (oper == POW) {
        res = pow(num_1, num_2);
    }
    return res;
}

double for_unary(node_t *stack, double num_1) {
    token_type oper = stack->token.type;
    double res = 0.;
    if (oper == SQRT) 
        res = sqrt(num_1);
    else if (oper == SIN) 
        res = sin(num_1);
    else if (oper == COS) 
        res = cos(num_1);
    else if (oper == TAN) 
        res = tan(num_1);
    else if (oper == ASIN) 
      res = asin(num_1);
    else if (oper == ACOS) 
      res = acos(num_1);
    else if (oper == ATAN) 
      res = atan(num_1);
    else if (oper == LN)  // natural logarithm
        res = log(num_1);
    else if (oper == LOG)  // natural logarithm
      res = log10(num_1);

    return res;
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
      int func_found = 0;


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
      int length_number = 0;
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
int checkBrackets(node_t *input_head) {
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

// полностью очистить список с текущего элемента
void remove_node(node_t *cur) {
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