#include "../tests.h"

START_TEST(test_s21_int_to_smartcalc_0) {
  char *src = "2458.324234*4.53345435-5^22.234324+123.4543/2.1212321";

  double expected = -3476366391885870.520000000000;

  double result = 0;
  smart_calc(src, &result);
  printf("\nFINAL RESULT: %lf\nEXPEC RESULT: %lf\n", result, expected);
  ck_assert_double_eq(result, expected);

  printf("\n");
}
END_TEST

// START_TEST(test_s21_int_to_smartcalc_1) {
//   int test = 1;
//   s21_smartcalc value = {{0, 0, 0, 0}};
//   s21_smartcalc result = {{test, 0, 0, 0}};

//   s21_from_int_to_smartcalc(test, &value);
//   ck_assert_int_eq(value.bits[0], result.bits[0]);
//   ck_assert_int_eq(value.bits[1], result.bits[1]);
//   ck_assert_int_eq(value.bits[2], result.bits[2]);
//   ck_assert_int_eq(value.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(test_s21_int_to_smartcalc_10) {
//   int test = 10;
//   s21_smartcalc value = {{0, 0, 0, 0}};
//   s21_smartcalc result = {{test, 0, 0, 0}};

//   s21_from_int_to_smartcalc(test, &value);
//   ck_assert_int_eq(value.bits[0], result.bits[0]);
//   ck_assert_int_eq(value.bits[1], result.bits[1]);
//   ck_assert_int_eq(value.bits[2], result.bits[2]);
//   ck_assert_int_eq(value.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(test_s21_int_to_smartcalc_1234567) {
//   int test = 1234567;
//   s21_smartcalc value = {{0, 0, 0, 0}};
//   s21_smartcalc result = {{test, 0, 0, 0}};

//   s21_from_int_to_smartcalc(test, &value);
//   ck_assert_int_eq(value.bits[0], result.bits[0]);
//   ck_assert_int_eq(value.bits[1], result.bits[1]);
//   ck_assert_int_eq(value.bits[2], result.bits[2]);
//   ck_assert_int_eq(value.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(test_s21_int_to_smartcalc_int_max) {
//   int test = INT_MAX;
//   s21_smartcalc value = {{0, 0, 0, 0}};
//   s21_smartcalc result = {{test, 0, 0, 0}};

//   s21_from_int_to_smartcalc(test, &value);
//   ck_assert_int_eq(value.bits[0], result.bits[0]);
//   ck_assert_int_eq(value.bits[1], result.bits[1]);
//   ck_assert_int_eq(value.bits[2], result.bits[2]);
//   ck_assert_int_eq(value.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(test_s21_int_to_smartcalc_minus_1) {
//   int test = -1;
//   s21_smartcalc value = {{0, 0, 0, 0}};
//   s21_smartcalc result = {
//       {-test, 0, 0, 0x80000000}};  // = 0x80000000 = -2147483648 = 2147483648

//   // s21_init_smartcalc(&value);
//   s21_from_int_to_smartcalc(test, &value);
//   // result.bits[0] = 0b00000000000000000000000000000001;
//   // result.bits[1] = 0b00000000000000000000000000000000;
//   // result.bits[2] = 0b00000000000000000000000000000000;
//   // result.bits[3] = 0b10000000000000000000000000000000;
//   ck_assert_int_eq(value.bits[0], result.bits[0]);
//   ck_assert_int_eq(value.bits[1], result.bits[1]);
//   ck_assert_int_eq(value.bits[2], result.bits[2]);
//   ck_assert_int_eq(value.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(test_s21_int_to_smartcalc_minus_10) {
//   int test = -10;
//   s21_smartcalc value = {{0, 0, 0, 0}};
//   s21_smartcalc result = {{-test, 0, 0, 0x80000000}};

//   // s21_init_smartcalc(&value);
//   s21_from_int_to_smartcalc(test, &value);
//   // result.bits[0] = 0b00000000000000000000000000001010;
//   // result.bits[1] = 0b00000000000000000000000000000000;
//   // result.bits[2] = 0b00000000000000000000000000000000;
//   // result.bits[3] = 0b10000000000000000000000000000000;
//   ck_assert_int_eq(value.bits[0], result.bits[0]);
//   ck_assert_int_eq(value.bits[1], result.bits[1]);
//   ck_assert_int_eq(value.bits[2], result.bits[2]);
//   ck_assert_int_eq(value.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(test_s21_int_to_smartcalc_minus_1234567) {
//   int test = -1234567;
//   s21_smartcalc value = {{0, 0, 0, 0}};
//   s21_smartcalc result = {{-test, 0, 0, 0x80000000}};

//   // s21_init_smartcalc(&value);
//   s21_from_int_to_smartcalc(test, &value);
//   // result.bits[0] = 0b00000000000100101101011010000111;
//   // result.bits[1] = 0b00000000000000000000000000000000;
//   // result.bits[2] = 0b00000000000000000000000000000000;
//   // result.bits[3] = 0b10000000000000000000000000000000;
//   ck_assert_int_eq(value.bits[0], result.bits[0]);
//   ck_assert_int_eq(value.bits[1], result.bits[1]);
//   ck_assert_int_eq(value.bits[2], result.bits[2]);
//   ck_assert_int_eq(value.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(test_s21_int_to_smartcalc_int_min) {
//   int test = INT_MIN;
//   s21_smartcalc value = {{0, 0, 0, 0}};
//   s21_smartcalc result = {{-test, 0, 0, 0x80000000}};

//   // s21_init_smartcalc(&value);
//   s21_from_int_to_smartcalc(test, &value);
//   // result.bits[0] = 0b10000000000000000000000000000000;
//   // result.bits[1] = 0b00000000000000000000000000000000;
//   // result.bits[2] = 0b00000000000000000000000000000000;
//   // result.bits[3] = 0b10000000000000000000000000000000;
//   ck_assert_int_eq(value.bits[0], result.bits[0]);
//   ck_assert_int_eq(value.bits[1], result.bits[1]);
//   ck_assert_int_eq(value.bits[2], result.bits[2]);
//   ck_assert_int_eq(value.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(test_s21_int_max_to_smartcalc_to_int) {
//   int test = INT_MAX;
//   int summary = 0;
//   s21_smartcalc value = {{0, 0, 0, 0}};

//   s21_from_int_to_smartcalc(test, &value);
//   s21_from_smartcalc_to_int(value, &summary);
//   s21_from_int_to_smartcalc(summary, &value);
//   s21_from_smartcalc_to_int(value, &summary);
//   s21_from_int_to_smartcalc(summary, &value);
//   s21_from_smartcalc_to_int(value, &summary);
//   s21_from_int_to_smartcalc(summary, &value);
//   s21_from_smartcalc_to_int(value, &summary);
//   s21_from_int_to_smartcalc(summary, &value);
//   s21_from_smartcalc_to_int(value, &summary);
//   s21_from_int_to_smartcalc(summary, &value);
//   s21_from_smartcalc_to_int(value, &summary);
//   ck_assert_int_eq(test, summary);
// }
// END_TEST

// START_TEST(test_s21_int_to_smartcalc_null_error) {
//   int check = 0;
//   s21_smartcalc *test = NULL;
//   int val = s21_from_int_to_smartcalc(check, test);
//   ck_assert_int_eq(val, S21_ERROR);
// }
// END_TEST

TCase *tests_s21_int_to_smartcalc(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, test_s21_int_to_smartcalc_0);
  // tcase_add_test(tcase, test_s21_int_to_smartcalc_1);
  // tcase_add_test(tcase, test_s21_int_to_smartcalc_10);
  // tcase_add_test(tcase, test_s21_int_to_smartcalc_1234567);
  // tcase_add_test(tcase, test_s21_int_to_smartcalc_int_max);
  // tcase_add_test(tcase, test_s21_int_to_smartcalc_minus_1);
  // tcase_add_test(tcase, test_s21_int_to_smartcalc_minus_10);
  // tcase_add_test(tcase, test_s21_int_to_smartcalc_minus_1234567);
  // tcase_add_test(tcase, test_s21_int_to_smartcalc_int_min);
  // tcase_add_test(tcase, test_s21_int_max_to_smartcalc_to_int);
  // tcase_add_test(tcase, test_s21_int_to_smartcalc_null_error);

  return tcase;
}
