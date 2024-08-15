#include "s21_all_tests.h"

// /* to_lower TEST */ // to_lower - возвращает копию строки, преобразованной в
// нижний регистр.

START_TEST(s21_to_lower_1) {
  char *str = "HELLO world";
  char *a = s21_to_lower(str);
  ck_assert_str_eq(a, "hello world");
  free(a);
}
END_TEST

START_TEST(s21_to_lower_2) {
  char *str = "12345";
  char *a = s21_to_lower(str);
  ck_assert_str_eq(a, "12345");
  free(a);
}
END_TEST

START_TEST(s21_to_lower_3) {
  char *str = "\n\0";
  char *a = s21_to_lower(str);
  ck_assert_str_eq(a, "\n\0");
  free(a);
}
END_TEST

START_TEST(s21_to_lower_4) {
  char *str = "aAaAaA";
  char *a = s21_to_lower(str);
  ck_assert_str_eq(a, "aaaaaa");
  free(a);
}
END_TEST

START_TEST(s21_to_lower_5) {
  char str[] = "123456789Q";
  char expected[] = "123456789q";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

Suite *tolower_suite(void) {
  Suite *s21_string = suite_create("s21_to_lower_test");
  TCase *tc_core = tcase_create("core");

  tcase_add_test(tc_core, s21_to_lower_1);
  tcase_add_test(tc_core, s21_to_lower_2);
  tcase_add_test(tc_core, s21_to_lower_3);
  tcase_add_test(tc_core, s21_to_lower_4);
  tcase_add_test(tc_core, s21_to_lower_5);
  suite_add_tcase(s21_string, tc_core);
  return s21_string;
}