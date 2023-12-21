#include "s21_smartcalc.h"

int smart_calc (char * src, long double * result) {
  int status = SUCCESS;
  node_t * input_list = init_node();
  node_t * head = input_list;
  if (src) {
    status = SUCCESS;
    while (*src) {
      find_number(&input_list, &src); // если точек > 1 : выдать ошбку
      find_one_char(&input_list, &src); // если подряд знаки - тоже ошибка
      find_func(&input_list, &src); //
      skip_space(&src);
    }
    printNode(head);


  } else 
    status = FAILURE;


  return status;
}

// определение числа
int find_number (node_t ** input_list, char ** src) {
      int status = FAILURE;
      int length_number = 0;
      length_number = strspn(*src, "1234567890.");
      long double var = 0;

      if (length_number) {
        sscanf(*src, "%Lf", &var);
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
node_t * add_elem (node_t * prev, long double num, token_type type) {
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
        node_t *next = current->next;
        if (current->token.type == NUMBER)
            printf(" %Lf ", current->token.num);
        else
            printf(" %s ", type[current->token.type+1]);
        current = next;
    }
}

