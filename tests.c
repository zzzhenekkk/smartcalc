#include "tests.h"

int main() {
  Suite *suite = suite_create(SUITE_NAME);
  TCase *tcase = tcase_create(TCASE_NAME);
  SRunner *srunner = srunner_create(suite);
  int counted_errors = 0;

  suite_add_tcase(suite, tcase);
  suite_add_tcase(suite, tests_s21_main());
  suite_add_tcase(suite, tests_s21_invalid_val_math());
  suite_add_tcase(suite, tests_s21_credit_annuitet());
  suite_add_tcase(suite, tests_s21_credit_diff());

  srunner_set_fork_status(srunner, CK_NOFORK);
  srunner_run_all(srunner, CK_VERBOSE);
  counted_errors = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return counted_errors == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
