#include "s21_smartcalc.h"

int main() {
  int status = SUCCESS;
  double result = 0.;
  char str[200] = "2*x";
  // status = smart_calc(str, &result);
  node_t *input = init_node();
  status = convert_polish_notation(&input, str);
  if (status == SUCCESS){
    status = calculate(input, &result, 0.6, GRAPH_ON);
  }
  printf("\n%d %lf", status, result);
  remove_node(input);

  // printf("\n");
  return 0;
}