#include "s21_all_tests.h"

// /* strchr TEST */ // strchr – поиск первого вхождения символа в строку.

START_TEST(s21_strchr_1) {
  char s1[50] = "asdf\0";
  char s3[50] = "asdf\0";
  ck_assert_str_eq(s21_strchr(s1, 'a'), strchr(s3, 'a'));
}
END_TEST

START_TEST(s21_strchr_2) {
  char s1[50] = "Hello world\0";
  char s3[50] = "Hello world\0";
  ck_assert_str_eq(s21_strchr(s1, 'o'), strchr(s3, 'o'));
}
END_TEST

START_TEST(s21_strchr_3) {
  char s1[50] = "Hello world\n\0";
  char s3[50] = "Hello world\n\0";
  ck_assert_str_eq(s21_strchr(s1, '\n'), strchr(s3, '\n'));
}
END_TEST

START_TEST(s21_strchr_4) {
  char s1[50] = "Hello world\0";
  char s3[50] = "Hello world\0";
  ck_assert_str_eq(s21_strchr(s1, '\0'), strchr(s3, '\0'));
}
END_TEST

START_TEST(s21_strchr_5) {
  char s1[50] = "Hello.world\0";
  char s3[50] = "Hello.world\0";
  ck_assert_str_eq(s21_strchr(s1, '.'), strchr(s3, '.'));
}
END_TEST

START_TEST(s21_strchr_6) {
  char s1[50] = "Hello world\0";
  char s3[50] = "Hello world\0";
  ck_assert_str_eq(s21_strchr(s1, ' '), strchr(s3, ' '));
}
END_TEST

START_TEST(s21_strchr_7) {
  char src[] = "abobasnutA1sa";
  char find = '1';

  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(s21_strchr_8) {
  char src[] = "abobasnutAsa";
  char find = 'Z';

  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(s21_strchr_9) {
  char src[] = "abobasnutAsa";
  char find = '3';

  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(s21_strchr_10) {
  char src[] = "";
  char find = '3';

  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(s21_strchr_11) {
  // Arrange
  char *str_1 = "hello";
  char n = 'h';
  // Act
  char *s21_result = s21_strchr(str_1, n);
  char *lib_result = strchr(str_1, n);
  // Assert
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strchr_12) {
  // Arrange
  char *str_1 = "";
  char n = 'h';
  // Act
  char *s21_result = s21_strchr(str_1, n);
  char *lib_result = strchr(str_1, n);
  // Assert
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strchr_13) {
  // Arrange
  char *str_1 = "hello";
  char n = '\0';
  // Act
  char *s21_result = s21_strchr(str_1, n);
  char *lib_result = strchr(str_1, n);
  // Assert
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strchr_14) {
  // Arrange
  char *str_1 = "";
  char n = '\0';
  // Act
  char *s21_result = s21_strchr(str_1, n);
  char *lib_result = strchr(str_1, n);
  // Assert
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

Suite *strchr_suite(void) {
  Suite *s21_string = suite_create("s21_strchr_test");
  TCase *tc_core = tcase_create("core");

  tcase_add_test(tc_core, s21_strchr_1);
  tcase_add_test(tc_core, s21_strchr_2);
  tcase_add_test(tc_core, s21_strchr_3);
  tcase_add_test(tc_core, s21_strchr_4);
  tcase_add_test(tc_core, s21_strchr_5);
  tcase_add_test(tc_core, s21_strchr_6);
  tcase_add_test(tc_core, s21_strchr_7);
  tcase_add_test(tc_core, s21_strchr_8);
  tcase_add_test(tc_core, s21_strchr_9);
  tcase_add_test(tc_core, s21_strchr_10);
  tcase_add_test(tc_core, s21_strchr_11);
  tcase_add_test(tc_core, s21_strchr_12);
  tcase_add_test(tc_core, s21_strchr_13);
  tcase_add_test(tc_core, s21_strchr_14);
  suite_add_tcase(s21_string, tc_core);
  return s21_string;
}