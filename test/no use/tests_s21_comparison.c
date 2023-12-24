#include "../tests.h"

// ----------------is not equal----------------- //
START_TEST(not_equal_zero) {
  s21_smartcalc val1 = {{0, 0, 0, 0}};
  s21_smartcalc val2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_not_equal(val1, val2), 0);
}
END_TEST

START_TEST(not_equal_dif_exp) {
  s21_smartcalc val1 = {{0, 0, 1, 393216}};
  s21_smartcalc val2 = {{0, 0, 1, 196608}};

  ck_assert_int_eq(s21_is_not_equal(val1, val2), 1);
}
END_TEST

START_TEST(not_equal_dif_sign) {
  s21_smartcalc val1 = {{0, 0, 1, (unsigned int)-65536}};
  s21_smartcalc val2 = {{0, 0, 1, 65536}};

  ck_assert_int_eq(s21_is_not_equal(val1, val2), 1);
}
END_TEST

START_TEST(not_equal_dif_mantissa) {
  s21_smartcalc val1 = {{4, 3, 2, 0}};  // 3.6893488160304E+19
  s21_smartcalc val2 = {{1, 3, 4, 0}};  // 7.3786976307723E+19

  ck_assert_int_eq(s21_is_not_equal(val1, val2), 1);
}
END_TEST

START_TEST(not_equal_neg_zero) {
  s21_smartcalc val1 = {{0, 0, 0, (unsigned int)-2147483648}};
  s21_smartcalc val2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_not_equal(val1, val2), 0);
}
END_TEST

// ----------------is equal----------------- //

START_TEST(equal_zero) {
  s21_smartcalc val1 = {{0, 0, 0, 0}};
  s21_smartcalc val2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_equal(val1, val2), 1);
}
END_TEST

START_TEST(equal_dif_exp) {
  s21_smartcalc val1 = {{1, 0, 0, 393216}};  // 0.000001
  s21_smartcalc val2 = {{1, 0, 0, 196608}};  // 0.001

  ck_assert_int_eq(s21_is_equal(val1, val2), 0);
}
END_TEST

START_TEST(equal_dif_sign) {
  s21_smartcalc val1 = {{0, 0, 1, (unsigned int)-65536}};
  s21_smartcalc val2 = {{0, 0, 1, 65536}};

  ck_assert_int_eq(s21_is_equal(val1, val2), 0);
}
END_TEST

START_TEST(equal_dif_mantissa) {
  s21_smartcalc val1 = {{4, 3, 2, 0}};  // 3.6893488160304E+19
  s21_smartcalc val2 = {{1, 3, 4, 0}};  // 7.3786976307723E+19

  ck_assert_int_eq(s21_is_equal(val1, val2), 0);
}
END_TEST

START_TEST(equal_neg_zero) {
  s21_smartcalc val1 = {{0, 0, 0, (unsigned int)-2147483648}};  // -0
  s21_smartcalc val2 = {{0, 0, 0, 0}};                          // 0

  ck_assert_int_eq(s21_is_equal(val1, val2), 1);
}
END_TEST

START_TEST(equal_neg_zero_2) {
  s21_smartcalc val1 = {{0, 0, 0, (unsigned int)-2147483648}};
  s21_smartcalc val2 = {{0, 0, 0, (unsigned int)-2147483648}};

  ck_assert_int_eq(s21_is_equal(val1, val2), 1);
}
END_TEST

// ----------------is less----------------- //

START_TEST(less_zero) {
  s21_smartcalc val1 = {{0, 0, 0, 0}};
  s21_smartcalc val2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_less(val1, val2), 0);
}
END_TEST

START_TEST(less_dif_exp) {
  s21_smartcalc val1 = {{1, 0, 0, 393216}};  // 0.000001
  s21_smartcalc val2 = {{1, 0, 0, 196608}};  // 0.001

  ck_assert_int_eq(s21_is_less(val1, val2), 1);
}
END_TEST

START_TEST(less_dif_sign) {
  s21_smartcalc val1 = {{0, 0, 1, (unsigned int)-65536}};
  s21_smartcalc val2 = {{0, 0, 1, 65536}};

  ck_assert_int_eq(s21_is_less(val1, val2), 1);
}
END_TEST

START_TEST(less_dif_mantissa) {
  s21_smartcalc val1 = {{4, 3, 2, 0}};  // 3.6893488160304E+19
  s21_smartcalc val2 = {{1, 3, 4, 0}};  // 7.3786976307723E+19

  ck_assert_int_eq(s21_is_less(val1, val2), 1);
}
END_TEST

START_TEST(less_dif_sign_float) {
  s21_smartcalc val1 = {
      {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
  s21_smartcalc val2 = {
      {12, 0, 0, 0b10000000000000010000000000000000}};  //  -1.2;

  ck_assert_int_eq(s21_is_less(val1, val2), 0);
}
END_TEST

START_TEST(less_dif_float) {
  s21_smartcalc val1 = {
      {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
  s21_smartcalc val2 = {{12, 0, 0, 0b00000000000000010000000000000000}};  //  1.2;

  ck_assert_int_eq(s21_is_less(val1, val2), 0);
}
END_TEST

START_TEST(less_dif_float_2) {
  s21_smartcalc val1 = {
      {12345, 0, 0, 0b00000000000000110000000000000000}};  //  12.345
  s21_smartcalc val2 = {
      {1122345, 0, 0, 0b00000000000001010000000000000000}};  //  11.22345

  ck_assert_int_eq(s21_is_less(val1, val2), 0);
}
END_TEST

START_TEST(less_dif_neg_float) {
  s21_smartcalc val1 = {
      {55555, 0, 0, 0b10000000000001000000000000000000}};  //  -5.5555
  s21_smartcalc val2 = {{65, 0, 0, 0b10000000000000010000000000000000}};  //  -6.5

  ck_assert_int_eq(s21_is_less(val1, val2), 0);
}
END_TEST

START_TEST(less_eq_neg_num) {
  s21_smartcalc val1 = {{123, 0, 0, (unsigned int)-2147483648}};
  s21_smartcalc val2 = {{123, 0, 0, (unsigned int)-2147483648}};

  ck_assert_int_eq(s21_is_less(val1, val2), 0);
}
END_TEST

START_TEST(less_eq_num) {
  s21_smartcalc val1 = {{123, 0, 0, 0}};
  s21_smartcalc val2 = {{123, 0, 0, 0}};

  ck_assert_int_eq(s21_is_less(val1, val2), 0);
}
END_TEST

START_TEST(less_neg_zero) {
  s21_smartcalc val1 = {{0, 0, 0, (unsigned int)-2147483648}};
  s21_smartcalc val2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_less(val1, val2), 0);
}
END_TEST

START_TEST(less_neg_zero_2) {
  s21_smartcalc val1 = {{0, 0, 0, (unsigned int)-2147483648}};
  s21_smartcalc val2 = {{0, 0, 0, (unsigned int)-2147483648}};

  ck_assert_int_eq(s21_is_less(val1, val2), 0);
}
END_TEST

// ----------------is less or eqeal----------------- //

START_TEST(less_or_eq_zero) {
  s21_smartcalc val1 = {{0, 0, 0, 0}};
  s21_smartcalc val2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_less_or_equal(val1, val2), 1);
}
END_TEST

START_TEST(less_or_eq_dif_exp) {
  s21_smartcalc val1 = {{1, 0, 0, 393216}};  // 0.000001
  s21_smartcalc val2 = {{1, 0, 0, 196608}};  // 0.001

  ck_assert_int_eq(s21_is_less_or_equal(val1, val2), 1);
}
END_TEST

START_TEST(less_or_eq_dif_sign) {
  s21_smartcalc val1 = {{0, 0, 1, (unsigned int)-65536}};
  s21_smartcalc val2 = {{0, 0, 1, 65536}};

  ck_assert_int_eq(s21_is_less_or_equal(val1, val2), 1);
}
END_TEST

START_TEST(less_or_eq_dif_mantissa) {
  s21_smartcalc val1 = {{4, 3, 2, 0}};  // 3.6893488160304E+19
  s21_smartcalc val2 = {{1, 3, 4, 0}};  // 7.3786976307723E+19

  ck_assert_int_eq(s21_is_less_or_equal(val1, val2), 1);
}
END_TEST

// ----------------is greater or eqeal----------------- //

START_TEST(greater_or_eq_zero) {
  s21_smartcalc val1 = {{0, 0, 0, 0}};
  s21_smartcalc val2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_greater_or_equal(val1, val2), 1);
}
END_TEST

START_TEST(greater_or_eq_dif_exp) {
  s21_smartcalc val1 = {{1, 0, 0, 393216}};  // 0.000001
  s21_smartcalc val2 = {{1, 0, 0, 196608}};  // 0.001

  ck_assert_int_eq(s21_is_greater_or_equal(val1, val2), 0);
}
END_TEST

START_TEST(greater_or_eq_dif_sign) {
  s21_smartcalc val1 = {{0, 0, 1, (unsigned int)-65536}};
  s21_smartcalc val2 = {{0, 0, 1, 65536}};

  ck_assert_int_eq(s21_is_greater_or_equal(val1, val2), 0);
}
END_TEST

START_TEST(greater_or_eq_dif_mantissa) {
  s21_smartcalc val1 = {{4, 3, 2, 0}};  // 3.6893488160304E+19
  s21_smartcalc val2 = {{1, 3, 4, 0}};  // 7.3786976307723E+19

  ck_assert_int_eq(s21_is_greater_or_equal(val1, val2), 0);
}
END_TEST

// ----------------is greater----------------- //

START_TEST(greater_zero) {
  s21_smartcalc val1 = {{0, 0, 0, 0}};
  s21_smartcalc val2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_greater(val1, val2), 0);
}
END_TEST

START_TEST(greater_dif_exp) {
  s21_smartcalc val1 = {{1, 0, 0, 393216}};  // 0.000001
  s21_smartcalc val2 = {{1, 0, 0, 196608}};  // 0.001

  ck_assert_int_eq(s21_is_greater(val1, val2), 0);
}
END_TEST

START_TEST(greater_dif_sign) {
  s21_smartcalc val1 = {{0, 0, 1, (unsigned int)-65536}};
  s21_smartcalc val2 = {{0, 0, 1, 65536}};

  ck_assert_int_eq(s21_is_greater(val1, val2), 0);
}
END_TEST

START_TEST(greater_dif_mantissa) {
  s21_smartcalc val1 = {{4, 3, 2, 0}};  // 3.6893488160304E+19
  s21_smartcalc val2 = {{1, 3, 4, 0}};  // 7.3786976307723E+19

  ck_assert_int_eq(s21_is_greater(val1, val2), 0);
}
END_TEST

START_TEST(greater_dif_sign_float) {
  s21_smartcalc val1 = {
      {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
  s21_smartcalc val2 = {
      {12, 0, 0, 0b10000000000000010000000000000000}};  //  -1.2;

  ck_assert_int_eq(s21_is_greater(val1, val2), 1);
}
END_TEST

START_TEST(greater_dif_float) {
  s21_smartcalc val1 = {
      {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
  s21_smartcalc val2 = {{12, 0, 0, 0b00000000000000010000000000000000}};  //  1.2;

  ck_assert_int_eq(s21_is_greater(val1, val2), 1);
}
END_TEST

START_TEST(greater_dif_float_2) {
  s21_smartcalc val1 = {
      {12345, 0, 0, 0b00000000000000110000000000000000}};  //  12.345
  s21_smartcalc val2 = {
      {1122345, 0, 0, 0b00000000000001010000000000000000}};  //  11.22345

  ck_assert_int_eq(s21_is_greater(val1, val2), 1);
}
END_TEST

START_TEST(greater_dif_neg_float) {
  s21_smartcalc val1 = {
      {55555, 0, 0, 0b10000000000001000000000000000000}};  //  -5.5555
  s21_smartcalc val2 = {{65, 0, 0, 0b10000000000000010000000000000000}};  //  -6.5

  ck_assert_int_eq(s21_is_greater(val1, val2), 1);
}
END_TEST

START_TEST(greater_eq_neg_num) {
  s21_smartcalc val1 = {{123, 0, 0, (unsigned int)-2147483648}};
  s21_smartcalc val2 = {{123, 0, 0, (unsigned int)-2147483648}};

  ck_assert_int_eq(s21_is_greater(val1, val2), 0);
}
END_TEST

START_TEST(greater_eq_num) {
  s21_smartcalc val1 = {{123, 0, 0, 0}};
  s21_smartcalc val2 = {{123, 0, 0, 0}};

  ck_assert_int_eq(s21_is_greater(val1, val2), 0);
}
END_TEST

START_TEST(greater_neg_zero) {
  s21_smartcalc val1 = {{0, 0, 0, (unsigned int)-2147483648}};
  s21_smartcalc val2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_greater(val1, val2), 0);
}
END_TEST

START_TEST(greater_neg_zero_2) {
  s21_smartcalc val1 = {{0, 0, 0, (unsigned int)-2147483648}};
  s21_smartcalc val2 = {{0, 0, 0, (unsigned int)-2147483648}};

  ck_assert_int_eq(s21_is_greater(val1, val2), 0);
}
END_TEST

TCase *tests_s21_comparison(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, not_equal_zero);
  tcase_add_test(tcase, not_equal_dif_exp);
  tcase_add_test(tcase, not_equal_dif_sign);
  tcase_add_test(tcase, not_equal_dif_mantissa);
  tcase_add_test(tcase, not_equal_neg_zero);
  tcase_add_test(tcase, equal_zero);
  tcase_add_test(tcase, equal_dif_exp);
  tcase_add_test(tcase, equal_dif_sign);
  tcase_add_test(tcase, equal_dif_mantissa);
  tcase_add_test(tcase, equal_neg_zero);
  tcase_add_test(tcase, equal_neg_zero_2);
  tcase_add_test(tcase, less_zero);
  tcase_add_test(tcase, less_dif_exp);
  tcase_add_test(tcase, less_dif_sign);
  tcase_add_test(tcase, less_dif_mantissa);
  tcase_add_test(tcase, less_dif_sign_float);
  tcase_add_test(tcase, less_dif_float);
  tcase_add_test(tcase, less_dif_float_2);
  tcase_add_test(tcase, less_dif_neg_float);
  tcase_add_test(tcase, less_eq_neg_num);
  tcase_add_test(tcase, less_eq_num);
  tcase_add_test(tcase, less_neg_zero);
  tcase_add_test(tcase, less_neg_zero_2);
  tcase_add_test(tcase, less_or_eq_zero);
  tcase_add_test(tcase, less_or_eq_dif_exp);
  tcase_add_test(tcase, less_or_eq_dif_sign);
  tcase_add_test(tcase, less_or_eq_dif_mantissa);
  tcase_add_test(tcase, greater_or_eq_zero);
  tcase_add_test(tcase, greater_or_eq_dif_exp);
  tcase_add_test(tcase, greater_or_eq_dif_sign);
  tcase_add_test(tcase, greater_or_eq_dif_mantissa);
  tcase_add_test(tcase, greater_zero);
  tcase_add_test(tcase, greater_dif_exp);
  tcase_add_test(tcase, greater_dif_sign);
  tcase_add_test(tcase, greater_dif_mantissa);
  tcase_add_test(tcase, greater_dif_sign_float);
  tcase_add_test(tcase, greater_dif_float);
  tcase_add_test(tcase, greater_dif_float_2);
  tcase_add_test(tcase, greater_dif_neg_float);
  tcase_add_test(tcase, greater_eq_neg_num);
  tcase_add_test(tcase, greater_eq_num);
  tcase_add_test(tcase, greater_neg_zero);
  tcase_add_test(tcase, greater_neg_zero_2);

  return tcase;
}
