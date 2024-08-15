#include "s21_all_tests.h"

// /* strcpy TEST */

START_TEST(s21_strcpy_1) {
  char test_dest[100] = "hello world again! and again";
  char test_dest2[100] = "hello world again! and again";
  const char test_src[100] = "taktaktak";
  char *s21_res = s21_strcpy(test_dest, test_src);
  ck_assert_str_eq(s21_res, strcpy(test_dest2, test_src));
}
END_TEST

START_TEST(s21_strcpy_2) {
  char test_dest[50] = "hello world again! and again";
  char test_dest2[50] = "hello world again! and again";
  const char test_src[100] = "taktaktak";
  char *s21_res = s21_strcpy(test_dest, test_src);
  ck_assert_str_eq(s21_res, strcpy(test_dest2, test_src));
}
END_TEST

START_TEST(s21_strcpy_3) {
  char test_1[] = "Axe and Primal Beast";
  char test_2[] = "     ";
  char test_3[] = "Axe\0";
  char test_4[] = "Dire\0Radiant";
  char test_5[128] = "";
  char test_6[] = "School 21 and School 42";
  char test_7[] = "";
  char test_8[] = "1";
  ck_assert_str_eq(s21_strcpy(test_1, test_2), strcpy(test_1, test_2));
  ck_assert_str_eq(s21_strcpy(test_2, test_3), strcpy(test_2, test_3));
  ck_assert_str_eq(s21_strcpy(test_4, test_5), strcpy(test_4, test_5));
  ck_assert_str_eq(s21_strcpy(test_5, test_4), strcpy(test_5, test_4));
  ck_assert_str_eq(s21_strcpy(test_6, test_5), strcpy(test_6, test_5));
  ck_assert_str_eq(s21_strcpy(test_7, test_5), strcpy(test_7, test_5));
  ck_assert_str_eq(s21_strcpy(test_8, test_5), strcpy(test_8, test_5));
}
END_TEST

Suite *strcpy_suite(void) {
  Suite *s21_string = suite_create("s21_strcpy_test");
  TCase *tc_core = tcase_create("core");

  tcase_add_test(tc_core, s21_strcpy_1);
  tcase_add_test(tc_core, s21_strcpy_2);
  tcase_add_test(tc_core, s21_strcpy_3);
  suite_add_tcase(s21_string, tc_core);
  return s21_string;
}