#include "s21_all_tests.h"

// /* strrchr TEST */ // strrchr – поиск последнего вхождения символа в строку.

START_TEST(s21_strrchr_1) {
  char s[] = "H e l l o\0";
  int c = ' ';
  ck_assert_str_eq(s21_strrchr(s, c), strrchr(s, c));
}
END_TEST

START_TEST(s21_strrchr_2) {
  char s[] = "Hello\0";
  int c = 'l';
  ck_assert_str_eq(s21_strrchr(s, c), strrchr(s, c));
}
END_TEST

START_TEST(s21_strrchr_3) {
  char s[] = "Hello\0";
  int c = ' ';
  ck_assert_ptr_null(s21_strrchr(s, c));
}
END_TEST

START_TEST(s21_strrchr_4) {
  char s[] = "Hello\n\0";
  int c = '\n';
  ck_assert_str_eq(s21_strrchr(s, c), strrchr(s, c));
}
END_TEST

START_TEST(s21_strrchr_5) {
  char s[] = "Hello\0";
  int c = 'p';
  ck_assert_ptr_null(s21_strrchr(s, c));
}
END_TEST

START_TEST(s21_strrchr_6) {
  char str1[] = "ppPpppppppppP";
  char str2 = 'P';

  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(s21_strrchr_7) {
  char str1[] = "123456789";
  char str2 = '0';

  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(s21_strrchr_8) {
  // Arrange
  char *str_1 = "hehllo";
  char n = 'h';
  // Act
  char *s21_result = s21_strrchr(str_1, n);
  char *lib_result = strrchr(str_1, n);
  // Assert
  ck_assert_str_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strrchr_9) {
  // Arrange
  char *str_1 = "";
  char n = 'h';
  // Act
  char *s21_result = s21_strrchr(str_1, n);
  char *lib_result = strrchr(str_1, n);
  // Assert
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strrchr_10) {
  // Arrange
  char *str_1 = "hello";
  char n = '\0';
  // Act
  char *s21_result = s21_strrchr(str_1, n);
  char *lib_result = strrchr(str_1, n);
  // Assert
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strrchr_11) {
  // Arrange
  char *str_1 = "";
  char n = '\0';
  // Act
  char *s21_result = s21_strrchr(str_1, n);
  char *lib_result = strrchr(str_1, n);
  // Assert
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

Suite *strrchr_suite(void) {
  Suite *s21_string = suite_create("s21_strrchr_test");
  TCase *tc_core = tcase_create("core");

  tcase_add_test(tc_core, s21_strrchr_1);
  tcase_add_test(tc_core, s21_strrchr_2);
  tcase_add_test(tc_core, s21_strrchr_3);
  tcase_add_test(tc_core, s21_strrchr_4);
  tcase_add_test(tc_core, s21_strrchr_5);
  tcase_add_test(tc_core, s21_strrchr_6);
  tcase_add_test(tc_core, s21_strrchr_7);
  tcase_add_test(tc_core, s21_strrchr_8);
  tcase_add_test(tc_core, s21_strrchr_9);
  tcase_add_test(tc_core, s21_strrchr_10);
  tcase_add_test(tc_core, s21_strrchr_11);
  suite_add_tcase(s21_string, tc_core);
  return s21_string;
}