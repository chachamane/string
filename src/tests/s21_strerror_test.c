#include "s21_all_tests.h"

/* strerror TEST */

START_TEST(s21_strerror_1) {
  char *s21_test_str = s21_strerror(1);
  char *lib_test_str = strerror(1);

  ck_assert_str_eq(s21_test_str, lib_test_str);
}
END_TEST

START_TEST(s21_strerror_2) {
  char *s21_test_str = s21_strerror(109);
  char *lib_test_str = strerror(109);

  ck_assert_str_eq(s21_test_str, lib_test_str);
}
END_TEST

START_TEST(s21_strerror_3) {
  char *case1 = s21_strerror(0);
  char *case2 = strerror(0);
  ck_assert_uint_eq((unsigned long)*case1, (unsigned long)*case2);

  char *case9 = s21_strerror(1);
  char *case10 = strerror(1);
  ck_assert_uint_eq((unsigned long)*case9, (unsigned long)*case10);

  char *case0 = s21_strerror(106);
  char *case3 = strerror(106);
  ck_assert_uint_eq((unsigned long)*case0, (unsigned long)*case3);

  char *case7 = s21_strerror(200);
  char *case8 = strerror(200);
  ck_assert_uint_eq((unsigned long)*case7, (unsigned long)*case8);

  char *case5 = s21_strerror(INT_MAX);
  char *case6 = strerror(INT_MAX);
  ck_assert_uint_eq((unsigned long)*case5, (unsigned long)*case6);

  char *case11 = s21_strerror(-1);
  char *case12 = strerror(-1);
  ck_assert_uint_eq((unsigned long)*case11, (unsigned long)*case12);
}
END_TEST

START_TEST(s21_strerror_4) {
  for (int i = -1000; i < 150; i++) {
    char *got = s21_strerror(i);
    char *expected = strerror(i);
    ck_assert_str_eq(got, expected);
  }
}
END_TEST

START_TEST(s21_strerror_5) {
  const char *got = s21_strerror(-1);
  char *expected = strerror(-1);
  ck_assert_str_eq(got, expected);
}
END_TEST

Suite *strerror_suite(void) {
  Suite *s21_string = suite_create("s21_strerror_test");
  TCase *tc_core = tcase_create("core");

  tcase_add_test(tc_core, s21_strerror_1);
  tcase_add_test(tc_core, s21_strerror_2);
  tcase_add_test(tc_core, s21_strerror_3);
  tcase_add_test(tc_core, s21_strerror_4);
  tcase_add_test(tc_core, s21_strerror_5);
  suite_add_tcase(s21_string, tc_core);
  return s21_string;
}