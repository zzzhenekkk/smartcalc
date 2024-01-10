#include "../tests.h"

START_TEST(test_1) {
    double sum_credit = 300000, percent = 15;
    int period = 18;
    double payment = 0., extra = 0., total = 0.;
    calulate_credit(DIFF, sum_credit, percent, period, 1, &payment, &extra, &total);
    // printf("pay: %lf, extra: %lf, total: %lf\n", payment, extra, total);
    ck_assert_double_eq_tol(payment, 20416.67, 1e-2);
    ck_assert_double_eq_tol(extra, 35625, 1e-2);
    ck_assert_double_eq_tol(total, 335625, 1e-2);
}
END_TEST

START_TEST(test_1_different_monthes) {
    double sum_credit = 300000, percent = 15;
    int period = 18;
    double payment = diff_payment(sum_credit, percent, period, 2);
    // printf("pay: %lf\n", payment);
    ck_assert_double_eq_tol(payment, 20208.33, 1e-2);
    payment = diff_payment(sum_credit, percent, period, 5);
    ck_assert_double_eq_tol(payment, 19583.33, 1e-2);
    payment = diff_payment(sum_credit, percent, period, 11);
    ck_assert_double_eq_tol(payment, 18333.33, 1e-2);
    payment = diff_payment(sum_credit, percent, period, 18);
    ck_assert_double_eq_tol(payment, 16875, 1e-2);
}
END_TEST

START_TEST(test_3) {
    double sum_credit = 1000000, percent = 10;
    int period = 1;
    double payment = 0., extra = 0., total = 0.;
    calulate_credit(DIFF, sum_credit, percent, period, 1, &payment, &extra, &total);
    ck_assert_double_eq_tol(payment, 1008333.33, 1e-2);
    ck_assert_double_eq_tol(extra, 8333.33, 1e-2);
    ck_assert_double_eq_tol(total, 1008333.33, 1e-2);
}
END_TEST

START_TEST(test_4) {
    double sum_credit = 100000, percent = 0;
    int period = 5;
    double payment = 0., extra = 0., total = 0.;
    calulate_credit(DIFF, sum_credit, percent, period, 1, &payment, &extra, &total);
    ck_assert_double_eq_tol(payment, 20000, 1e-2);
    ck_assert_double_eq_tol(extra, 0, 1e-2);
    ck_assert_double_eq_tol(total, 100000, 1e-2);
}
END_TEST

START_TEST(test_5) {
    double sum_credit = 0, percent = 6.7;
    int period = 5;
    double payment = 0., extra = 0., total = 0.;
    calulate_credit(DIFF, sum_credit, percent, period, 1, &payment, &extra, &total);
    ck_assert_double_eq_tol(payment, 0, 1e-2);
    ck_assert_double_eq_tol(extra, 0, 1e-2);
    ck_assert_double_eq_tol(total, 0, 1e-2);
}
END_TEST

TCase *tests_s21_credit_diff(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, test_1);
  tcase_add_test(tcase, test_1_different_monthes);
  tcase_add_test(tcase, test_3);
  tcase_add_test(tcase, test_4);
  tcase_add_test(tcase, test_5);

  return tcase;
}