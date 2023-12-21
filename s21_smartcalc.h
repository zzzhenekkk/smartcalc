#ifndef S21_SMARTCALC
#define S21_SMARTCALC


#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SUCCESS 1
#define FAILURE 0



// typedef struct {
//     union {
//         double value; // значение
//     }
//     int type; // какой тип

//     // ссылка на след элемент
    
//     // ссылка на предыдущий элемент

    
// } Node;


typedef enum { EMPTY = -1,
               NUMBER,
               X_NUMBER,
// 0 плюсы минусы
               BINARY_PLUS,
               BINARY_MINUS,
               UNARY_MINUS,
               UNARY_PLUS,
// 1 умножение деление остаток
               MULT,
               DIV,
               MOD,
// 2 функции
               COS,
               SIN,
               TAN,
               ACOS,
               ASIN,
               ATAN,
               SQRT,
               LN,
               LOG, 
// 3 степень
               POW,
// 4 скобки
               OPEN_BRACKET,
               CLOSE_BRACKET,
} token_type;


typedef struct token {
    token_type type;
    long double num;
} token_t;

typedef struct node {
  struct node *prev;
  struct node *next;
  token_t token;
} node_t;

int smart_calc(char * src, long double * result);

// задаем новый список
node_t * init_node ();

// добавить элемент в конец списка, с указателем на предыдущий токен, значением и типом, отдает указатель на текущий
node_t * add_elem (node_t * prev, long double num, token_type type);

// удалить элемент с конца списка, отдает ссылку на предыдущий элемент или null
node_t * del_elem (node_t * cur);

// полностью очистить список с текущего элемента
void remove_node(node_t *cur);

// вывод всего листа
void printNode(node_t *head);

// проверка на корректность введенных скобок
int checkBrackets(node_t *input_head);

void skip_space(char **src);

// определение функции из 1 символа
int find_one_char (node_t ** input_list, char ** src);

// определение функции из 2-4 символов
int find_func (node_t ** input_list, char ** src);

// определение числа
int find_number (node_t ** input_list, char ** src);

#endif  // S21_SMARTCALC
