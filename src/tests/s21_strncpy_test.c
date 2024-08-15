#include "s21_all_tests.h"

// /* strncpy TEST */ // strncpy – копирование строк c ограничением длины.

START_TEST(s21_strncpy_1) {
  char s1[] = "Hello world\0";
  char s2[] = "Hello \0";
  char s3[] = "Hello world\0";
  char s4[] = "Hello \0";
  s21_strncpy(s1, s2, 3);
  strncpy(s3, s4, 3);
  ck_assert_str_eq(s1, s3);
}
END_TEST

START_TEST(s21_strncpy_2) {
  char s1[] = "Hello\0";
  char s2[] = "123\0";
  char s3[] = "Hello\0";
  char s4[] = "123\0";
  s21_strncpy(s1, s2, 2);
  strncpy(s3, s4, 2);
  ck_assert_str_eq(s1, s3);
}
END_TEST

START_TEST(s21_strncpy_3) {
  char s1[] = " \n\0";
  char s2[] = " \0";
  char s3[] = " \n\0";
  char s4[] = " \0";
  s21_strncpy(s1, s2, 1);
  strncpy(s3, s4, 1);
  ck_assert_str_eq(s1, s3);
}
END_TEST

START_TEST(s21_strncpy_4) {
  char s1[] = "\0";
  char s2[] = "\0";
  char s3[] = "\0";
  char s4[] = "\0";
  s21_strncpy(s1, s2, 1);
  strncpy(s3, s4, 1);
  ck_assert_str_eq(s1, s3);
}
END_TEST

START_TEST(s21_strncpy_5) {
  char s1[] = "H e l l o\0";
  char s2[] = "H E L L O\0";
  char s3[] = "H e l l o\0";
  char s4[] = "H E L L O\0";
  s21_strncpy(s1, s2, 5);
  strncpy(s3, s4, 5);
  ck_assert_str_eq(s1, s3);
}
END_TEST

START_TEST(s21_strncpy_6) {
  char src[] = "123";
  char res[] = "123";
  char exp[] = "123";
  s21_size_t n_byte = 0;

  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);

  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(s21_strncpy_7) {
  char src[] = "";
  char res[] = "123";
  char exp[] = "123";
  s21_size_t n_byte = 0;

  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);

  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(s21_strncpy_8) {
  char src[] = "123";
  char res[5] = "123";
  char exp[5] = "123";
  s21_size_t n_byte = 1;

  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);

  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(s21_strncpy_9) {
  char src[] = "123";
  char res[7] = "123";
  char exp[7] = "123";
  s21_size_t n_byte = 2;

  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);

  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(s21_strncpy_10) {
  char src[] = "Str1ng";
  char res[7 + 7] = "Str1ng";
  char exp[7 + 7] = "Str1ng";
  s21_size_t n_byte = 7;

  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);

  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(s21_strncpy_11) {
  char test_dest[100] = "Hello world gello world gellortwls";
  char test_dest2[100] = "Hello world gello world gellortwls";
  const char test_src[100] = "taktaktak";
  s21_size_t n = 5;
  char *s21_res = s21_strncpy(test_dest, test_src, n);
  ck_assert_str_eq(s21_res, strncpy(test_dest2, test_src, n));
}
END_TEST

START_TEST(s21_strncpy_12) {
  char test_dest[50] = "hello world again! and again";
  char test_dest2[50] = "hello world again! and again";
  const char test_src[100] = "taktaktak";
  s21_size_t n = 10;
  char *s21_res = s21_strncpy(test_dest, test_src, n);
  ck_assert_str_eq(s21_res, strncpy(test_dest2, test_src, n));
}
END_TEST

Suite *strncpy_suite(void) {
  Suite *s21_string = suite_create("s21_strncpy_test");
  TCase *tc_core = tcase_create("core");

  tcase_add_test(tc_core, s21_strncpy_1);
  tcase_add_test(tc_core, s21_strncpy_2);
  tcase_add_test(tc_core, s21_strncpy_3);
  tcase_add_test(tc_core, s21_strncpy_4);
  tcase_add_test(tc_core, s21_strncpy_5);
  tcase_add_test(tc_core, s21_strncpy_6);
  tcase_add_test(tc_core, s21_strncpy_7);
  tcase_add_test(tc_core, s21_strncpy_8);
  tcase_add_test(tc_core, s21_strncpy_9);
  tcase_add_test(tc_core, s21_strncpy_10);
  tcase_add_test(tc_core, s21_strncpy_11);
  tcase_add_test(tc_core, s21_strncpy_12);
  suite_add_tcase(s21_string, tc_core);
  return s21_string;
}