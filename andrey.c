#include "s21_smartcalc.h"

int main() {
  int status = SUCCESS;
  double result = 0.;
  node_t * output_list = NULL;
  status = convert_polish_notation (&output_list, "2*x");
  printNode(output_list);

  if (status == SUCCESS)
    status = calculate (output_list, &result, 55., GRAPH_ON);

  // printf("\n%d %lf", status, result);
  remove_node(output_list);

  printf("\n%d %g", status, result);
  return 0;
}