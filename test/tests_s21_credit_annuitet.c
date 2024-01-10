#include "../tests.h"

START_TEST(test_1) {
    double sum_credit = 300000, percent = 15;
    int period = 18;
    double payment = 0., extra = 0., total = 0.;
    calulate_credit(ANNUITET, sum_credit, percent, period, 1, &payment, &extra, &total);
    // printf("pay: %lf, extra: %lf, total: %lf\n", payment, extra, total);
    ck_assert_double_eq_tol(payment, 18715.44, 1e-2);
    ck_assert_double_eq_tol(extra, 36877.92, 1e-2);
    ck_assert_double_eq_tol(total, 336877.92, 1e-2);
}
END_TEST

START_TEST(test_2) {
    double sum_credit = 1000000, percent = 5;
    int period = 1;
    double payment = 0., extra = 0., total = 0.;
    calulate_credit(ANNUITET, sum_credit, percent, period, 1, &payment, &extra, &total);
    ck_assert_double_eq_tol(payment, 1004166.67, 1e-2);
    ck_assert_double_eq_tol(extra, 4166.67, 1e-2);
    ck_assert_double_eq_tol(total, 1004166.67, 1e-2);
}
END_TEST

START_TEST(test_3) {
    double sum_credit = 1000000, percent = 0;
    int period = 10;
    double payment = 0., extra = 0., total = 0.;
    calulate_credit(ANNUITET, sum_credit, percent, period, 1, &payment, &extra, &total);
    ck_assert_double_eq_tol(payment, 100000, 1e-2);
    ck_assert_double_eq_tol(extra, 0, 1e-2);
    ck_assert_double_eq_tol(total, 1000000, 1e-2);
}
END_TEST

START_TEST(test_4) {
    double sum_credit = 10, percent = 10;
    int period = 10;
    double payment = 0., extra = 0., total = 0.;
    calulate_credit(ANNUITET, sum_credit, percent, period, 1, &payment, &extra, &total);
    ck_assert_double_eq_tol(payment, 1.05, 1e-2);
    ck_assert_double_eq_tol(extra, 0.5, 1e-2);
    ck_assert_double_eq_tol(total, 10.5, 1e-2);
}
END_TEST

START_TEST(test_5) {
    double sum_credit = 0, percent = 10;
    int period = 6;
    double payment = 0., extra = 0., total = 0.;
    calulate_credit(ANNUITET, sum_credit, percent, period, 1, &payment, &extra, &total);
    ck_assert_double_eq_tol(payment, 0, 1e-2);
    ck_assert_double_eq_tol(extra, 0, 1e-2);
    ck_assert_double_eq_tol(total, 0, 1e-2);
}
END_TEST

START_TEST(test_6) {
    double sum_credit = 12345, percent = 12.5;
    int period = 15;
    double payment = 0., extra = 0., total = 0.;
    calulate_credit(ANNUITET, sum_credit, percent, period, 1, &payment, &extra, &total);
    ck_assert_double_eq_tol(payment, 893.24, 1e-2);
    ck_assert_double_eq_tol(extra, 1053.6, 1e-2);
    ck_assert_double_eq_tol(total, 13398.60, 1e-2);
}
END_TEST

TCase *tests_s21_credit_annuitet(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, test_1);
  tcase_add_test(tcase, test_2);
  tcase_add_test(tcase, test_3);
  tcase_add_test(tcase, test_4);
  tcase_add_test(tcase, test_5);
  tcase_add_test(tcase, test_6);

  return tcase;
}