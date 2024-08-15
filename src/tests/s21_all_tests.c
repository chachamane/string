#include "s21_all_tests.h"

void run_tests(void) {
  Suite *list_cases[] = {memchr_suite(),  memcmp_suite(),
                         memcpy_suite(),  memset_suite(),
                         memmove_suite(), strncmp_suite(),
                         strncpy_suite(), strcpy_suite(),
                         strcspn_suite(), strncat_suite(),
                         strcat_suite(),  strerror_suite(),
                         strlen_suite(),  strpbrk_suite(),
                         strchr_suite(),  strrchr_suite(),
                         strstr_suite(),  strtok_suite(),
                         strspn_suite(),  tolower_suite(),
                         toupper_suite(), insert_suite(),
                         trim_suite(),    sprintf_suite(),
                         sscanf_suite(),  NULL};
  for (Suite **current_testcase = list_cases; *current_testcase != NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
}

void run_testcase(Suite *testcase) {
  static int counter_testcase = 1;

  if (counter_testcase > 0) putchar('\n');
  printf("%s%d%s", "CURRENT TEST: ", counter_testcase, "\n");
  counter_testcase++;
  SRunner *sr = srunner_create(testcase);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  srunner_free(sr);
}

int main(void) {
  run_tests();
  return 0;
}