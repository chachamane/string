#include "s21_all_tests.h"

// /* to_upper TEST */ // to_upper - возвращает копию строки, преобразованной в
// верхний регистр.

START_TEST(s21_to_upper_1) {
  char *str = "HELLO world";
  char *a = s21_to_upper(str);
  ck_assert_str_eq(a, "HELLO WORLD");
  free(a);
}
END_TEST

START_TEST(s21_to_upper_2) {
  char *str = "12345";
  char *a = s21_to_upper(str);
  ck_assert_str_eq(a, "12345");
  free(a);
}
END_TEST

START_TEST(s21_to_upper_3) {
  char *str = "\n\0";
  char *a = s21_to_upper(str);
  ck_assert_str_eq(a, "\n\0");
  free(a);
}
END_TEST

START_TEST(s21_to_upper_4) {
  char *str = "AaAa";
  char *a = s21_to_upper(str);
  ck_assert_str_eq(a, "AAAA");
  free(a);
}
END_TEST

START_TEST(s21_to_upper_5) {
  char str[] = "1+1*1";
  char expected[] = "1+1*1";
  char *got = s21_to_upper(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_to_upper_6) {
  char str[] = " ";
  char expected[] = " ";
  char *got = s21_to_upper(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_to_upper_7) {
  char str[] = "";
  char expected[] = "";
  char *got = s21_to_upper(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

Suite *toupper_suite(void) {
  Suite *s21_string = suite_create("s21_to_upper_test");
  TCase *tc_core = tcase_create("core");

  tcase_add_test(tc_core, s21_to_upper_1);
  tcase_add_test(tc_core, s21_to_upper_2);
  tcase_add_test(tc_core, s21_to_upper_3);
  tcase_add_test(tc_core, s21_to_upper_4);
  tcase_add_test(tc_core, s21_to_upper_5);
  tcase_add_test(tc_core, s21_to_upper_6);
  tcase_add_test(tc_core, s21_to_upper_7);
  suite_add_tcase(s21_string, tc_core);
  return s21_string;
}