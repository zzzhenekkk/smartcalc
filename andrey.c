#include "s21_smartcalc.h"

int main() {
  int status = SUCCESS;
  double result = 0.;
  node_t * output_list = NULL;
  status = convert_polish_notation (&output_list, "3");
  printNode(output_list);
double x = -1.0;
 for (int i = 0; i < 3; i++) {
      if (status == SUCCESS)
    status = calculate (output_list, &result, x, GRAPH_ON);
  x += 1.0;
    printf("\n%d %g", status, result);
 }

  // printf("\n%d %lf", status, result);
  remove_node(output_list);


  return 0;
}