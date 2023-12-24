#include "../tests.h"

START_TEST(test_s21_from_float_to_smartcalc_003f) {
  s21_smartcalc value;
  s21_from_float_to_smartcalc(0.03F, &value);
  ck_assert_int_eq(value.bits[0], 3);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0b00000000000000100000000000000000);
}
END_TEST

START_TEST(test_s21_from_float_to_smartcalc_m003f) {
  s21_smartcalc value;
  s21_from_float_to_smartcalc(-0.03F, &value);
  ck_assert_int_eq(value.bits[0], 3);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq((unsigned)value.bits[3], 0b10000000000000100000000000000000);
}
END_TEST

START_TEST(test_s21_from_float_to_smartcalc_30f) {
  s21_smartcalc value;
  s21_from_float_to_smartcalc(3.0F, &value);
  ck_assert_int_eq(value.bits[0], 3);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0);
}
END_TEST

START_TEST(test_s21_from_float_to_smartcalc_m30f) {
  s21_smartcalc value;
  s21_from_float_to_smartcalc(-3.0F, &value);
  ck_assert_int_eq(value.bits[0], 3);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq((unsigned)value.bits[3], S21_MINUS);
}
END_TEST

START_TEST(test_s21_from_float_to_smartcalc_0f) {
  s21_smartcalc value;
  s21_from_float_to_smartcalc(0.0F, &value);
  ck_assert_int_eq(value.bits[0], 0);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0);
}
END_TEST

START_TEST(test_s21_from_float_to_smartcalc_105f) {
  s21_smartcalc value;
  s21_from_float_to_smartcalc(10.5F, &value);
  ck_assert_int_eq(value.bits[0], 105);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 65536);
}
END_TEST

START_TEST(test_s21_from_float_to_smartcalc_too_small) {
  s21_smartcalc value;
  int err = s21_from_float_to_smartcalc(1e-29F, &value);
  ck_assert_int_eq(value.bits[0], 0);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0);
  ck_assert_int_eq(err, S21_ERROR);
}
END_TEST

START_TEST(test_s21_from_float_to_smartcalc_div_mzero) {
  s21_smartcalc value;
  int err = s21_from_float_to_smartcalc(-1.0F / 0.0F, &value);
  ck_assert_int_eq(err, S21_ERROR);
}
END_TEST

START_TEST(test_s21_from_float_to_smartcalc_div_zero) {
  s21_smartcalc value;
  int err = s21_from_float_to_smartcalc(1.0F / 0.0F, &value);
  ck_assert_int_eq(err, S21_ERROR);
}
END_TEST

START_TEST(test_s21_from_float_to_smartcalc_small_num) {
  s21_smartcalc value;
  int err = s21_from_float_to_smartcalc(1.234567e-28F, &value);
  ck_assert_int_eq(value.bits[0], 1);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 1835008U);
  ck_assert_int_eq(err, S21_OK);
}
END_TEST

START_TEST(test_s21_from_float_to_smartcalc_10209f) {
  s21_smartcalc value;
  s21_from_float_to_smartcalc(1.02E+09F, &value);
  ck_assert_int_eq(value.bits[0], 1020000000);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0);
}
END_TEST

START_TEST(test_s21_from_float_to_smartcalc_NAN) {
  s21_smartcalc value;
  float nan_value = NAN;
  int err = s21_from_float_to_smartcalc(nan_value, &value);
  ck_assert_int_eq(err, S21_ERROR);
  ck_assert_int_eq(value.bits[0], 0);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0);
}
END_TEST

START_TEST(test_s21_from_float_to_smartcalc_12345678) {
  s21_smartcalc value;
  int err = s21_from_float_to_smartcalc(123456789.123456789F, &value);
  ck_assert_int_eq(value.bits[0], 123456800);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0);
  ck_assert_int_eq(err, S21_OK);
}
END_TEST

START_TEST(test_s21_from_float_to_smartcalc_00002f) {
  s21_smartcalc value;
  s21_from_float_to_smartcalc(0.000000002F, &value);
  ck_assert_int_eq(value.bits[0], 2);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0b00000000000010010000000000000000);
}
END_TEST

START_TEST(test_s21_from_float_to_smartcalc_001f) {
  s21_smartcalc value;
  int err = s21_from_float_to_smartcalc(10000000000.000000001F, &value);
  ck_assert_int_eq(value.bits[0], 0b01010100000010111110010000000000);
  ck_assert_int_eq(value.bits[1], 0b00000000000000000000000000000010);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0);
  ck_assert_int_eq(err, S21_OK);
}
END_TEST

START_TEST(test_s21_from_float_to_smartcalc_5454) {
  s21_smartcalc value;
  s21_from_float_to_smartcalc(-5454.353F, &value);
  ck_assert_int_eq(value.bits[0], 5454353);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq((unsigned)value.bits[3], 0b10000000000000110000000000000000);
}
END_TEST

START_TEST(test_s21_from_float_to_smartcalc_m5492) {
  s21_smartcalc value;
  s21_from_float_to_smartcalc(-5.492654F, &value);
  ck_assert_int_eq(value.bits[0], 5492654);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq((unsigned)value.bits[3], 0b10000000000001100000000000000000);
}
END_TEST

START_TEST(test_s21_from_float_to_smartcalc_7961) {
  s21_smartcalc value;
  s21_from_float_to_smartcalc(7.961328E+08F, &value);
  ck_assert_int_eq(value.bits[0], 796132800);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0);
}
END_TEST

START_TEST(test_s21_from_float_to_smartcalc_m1234) {
  s21_smartcalc value;
  s21_from_float_to_smartcalc(-1.234568E+07F, &value);
  ck_assert_int_eq(value.bits[0], 12345680);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq((unsigned)value.bits[3], S21_MINUS);
}
END_TEST

START_TEST(test_s21_from_float_to_smartcalc_null_error) {
  float check = 0.f;
  s21_smartcalc *test = NULL;
  int val = s21_from_float_to_smartcalc(check, test);
  ck_assert_int_eq(val, S21_ERROR);
}
END_TEST

TCase *tests_s21_float_to_smartcalc(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, test_s21_from_float_to_smartcalc_003f);
  tcase_add_test(tcase, test_s21_from_float_to_smartcalc_m003f);
  tcase_add_test(tcase, test_s21_from_float_to_smartcalc_30f);
  tcase_add_test(tcase, test_s21_from_float_to_smartcalc_m30f);
  tcase_add_test(tcase, test_s21_from_float_to_smartcalc_0f);
  tcase_add_test(tcase, test_s21_from_float_to_smartcalc_105f);
  tcase_add_test(tcase, test_s21_from_float_to_smartcalc_too_small);
  tcase_add_test(tcase, test_s21_from_float_to_smartcalc_div_mzero);
  tcase_add_test(tcase, test_s21_from_float_to_smartcalc_div_zero);
  tcase_add_test(tcase, test_s21_from_float_to_smartcalc_small_num);
  tcase_add_test(tcase, test_s21_from_float_to_smartcalc_10209f);
  tcase_add_test(tcase, test_s21_from_float_to_smartcalc_NAN);
  tcase_add_test(tcase, test_s21_from_float_to_smartcalc_12345678);
  tcase_add_test(tcase, test_s21_from_float_to_smartcalc_00002f);
  tcase_add_test(tcase, test_s21_from_float_to_smartcalc_001f);
  tcase_add_test(tcase, test_s21_from_float_to_smartcalc_5454);
  tcase_add_test(tcase, test_s21_from_float_to_smartcalc_m5492);
  tcase_add_test(tcase, test_s21_from_float_to_smartcalc_7961);
  tcase_add_test(tcase, test_s21_from_float_to_smartcalc_m1234);
  tcase_add_test(tcase, test_s21_from_float_to_smartcalc_null_error);

  return tcase;
}
