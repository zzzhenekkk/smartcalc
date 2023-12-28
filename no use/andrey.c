#include "s21_smartcalc.h"

int main() {
  int status = SUCCESS;
  double result = 0.;
  char str[200] = "(.)(.+34)";
  status = smart_calc(str, &result);
  printf("\n%d %lf", status, result);
  
  // if (status == SUCCESS)
  //   status = calculate (output_list, &result, 0., GRAPH_OFF);

  // printf("\n%d %lf", status, result);
  // remove_node(output_list);
  

  // char src[200]= "log(45.236582*55522.85-583)";

  // double expected = 6.39986071453;

  // double result = 0.;
  // smart_calc(src, &result);
  // printf("\nFINAL RESULT: %lf\nEXPEC RESULT: %lf\n", result, expected);
  // ck_assert_double_eq(result, expected);

  // printf("\n");
  return 0;
}