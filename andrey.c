#include "s21_smartcalc.h"

int main() {

  char str[200] = "12+10/5+cos(0)";
  double k =0.;
  smart_calc(str, &k);

  return 0;
}