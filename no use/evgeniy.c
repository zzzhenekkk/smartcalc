#include "s21_smartcalc.h"

int main() {

  char str[200] = "123.4+sin(+2*x)";
  double k =0.;
  smart_calc(str, &k);

  return 0;
}