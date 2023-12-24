#include "s21_smartcalc.h"

int main() {
  int status = SUCCESS;
  double result = 0.;
  char str[200] = "12+10/5+cos(0)";
  node_t * output_list = NULL;
  status = convert_polish_notation (&output_list, str);
  if (status == SUCCESS)
    status = calculate (output_list, &result, 0., GRAPH_OFF);

  printf("%d %lf", status, result);
  remove_node(output_list);
  
  return 0;
}