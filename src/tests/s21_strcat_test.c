#include "s21_all_tests.h"

START_TEST(s21_strcat_1) {
  // Arrange
  char str_1[20] = "hello";
  char *str_2 = "world";
  // Act
  char *s21_result = s21_strcat(str_1, str_2);
  char *lib_result = strcat(str_1, str_2);
  // Assert
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strcat_2) {
  // Arrange
  char str_1[20];
  str_1[0] = '\0';
  char str_2[20];
  str_2[0] = '\0';
  char *str_3 = "world";
  // Act
  char *s21_result = s21_strcat(str_1, str_3);
  char *lib_result = strcat(str_2, str_3);
  // Assert
  ck_assert_str_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strcat_3) {
  // Arrange
  char str_1[20] = "hello";
  char *str_2 = "";
  // Act
  char *s21_result = s21_strcat(str_1, str_2);
  char *lib_result = strcat(str_1, str_2);
  // Assert
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strcat_4) {
  // Arrange
  char str_1[20] = "";
  char *str_2 = "";
  // Act
  char *s21_result = s21_strcat(str_1, str_2);
  char *lib_result = strcat(str_1, str_2);
  // Assert
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

Suite *strcat_suite(void) {
  Suite *s21_string = suite_create("s21_strcat_test");
  TCase *tc_core = tcase_create("core");

  tcase_add_test(tc_core, s21_strcat_1);
  tcase_add_test(tc_core, s21_strcat_2);
  tcase_add_test(tc_core, s21_strcat_3);
  tcase_add_test(tc_core, s21_strcat_4);
  suite_add_tcase(s21_string, tc_core);
  return s21_string;
}