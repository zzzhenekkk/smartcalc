#ifndef SRC_S21_TEST_H_
#define SRC_S21_TEST_H_

#include <check.h>


#include "s21_smartcalc.h"

#define SUITE_NAME "Unit"
#define TCASE_NAME "Tests"

TCase *tests_s21_main(void);
TCase *tests_s21_invalid_val_math(void);
TCase *tests_s21_credit_annuitet(void);
TCase *tests_s21_credit_diff(void);

#endif  // SRC_S21_TEST_H_
