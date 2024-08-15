#include "s21_all_tests.h"

/* memset TEST */  // memset – заполнения массива указанными символами.

START_TEST(s21_memset_1) {
  char str[20] = "1234567890";
  ck_assert_str_eq(s21_memset(str, '1', 5), memset(str, '1', 5));
}
END_TEST

START_TEST(s21_memset_2) {
  char str[20] = "Hello world\0";
  ck_assert_str_eq(s21_memset(str, 'H', 12), memset(str, 'H', 12));
}
END_TEST

START_TEST(s21_memset_3) {
  char str[20] = "Hello world\n\0";
  ck_assert_str_eq(s21_memset(str, 'H', 12), memset(str, 'H', 12));
}
END_TEST

START_TEST(s21_memset_4) {
  char str[20] = "a\n\0";
  ck_assert_str_eq(s21_memset(str, 'm', 3), memset(str, 'H', 3));
}
END_TEST

START_TEST(s21_memset_5) {
  char str[20] = " \n\0";
  ck_assert_str_eq(s21_memset(str, 'm', 3), memset(str, 'H', 3));
}
END_TEST

START_TEST(s21_memset_6) {
  char str[20] = " \0";
  ck_assert_str_eq(s21_memset(str, 'm', 3), memset(str, 'H', 3));
}
END_TEST

START_TEST(s21_memset_7) {
  char str[20] = "\n\0";
  ck_assert_str_eq(s21_memset(str, 'm', 3), memset(str, 'H', 3));
}
END_TEST

START_TEST(s21_memset_8) {
  char str[3] = "\0";
  ck_assert_str_eq(s21_memset(str, 'm', 1), memset(str, 'H', 1));
}
END_TEST

START_TEST(s21_memset_9) {
  char res[] = "a1obA";
  char expected[] = "a1obA";
  char replace = '1';
  s21_size_t n_byte = 5;

  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(s21_memset_10) {
  char res[] =
      "a1oas[pifjaosidfj oapisjdfpoi asjdfoij ouh12oi3 uh12i3 "
      "hiajhIOUAHSDiouAHSdu1).bA";
  char expected[] =
      "a1oas[pifjaosidfj oapisjdfpoi asjdfoij ouh12oi3 uh12i3 "
      "hiajhIOUAHSDiouAHSdu1).bA";
  char replace = '1';
  s21_size_t n_byte = 5;

  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(s21_memset_11) {
  char s21_test_str[10] = "Hello";
  s21_memset(s21_test_str, 'c', 3);
  char lib_test_str[10] = "Hello";
  memset(lib_test_str, 'c', 3);

  ck_assert_str_eq(s21_test_str, lib_test_str);
}
END_TEST

START_TEST(s21_memset_12) {
  char *s21_test_str = (char *)calloc(12, sizeof(char));
  char *lib_test_str = (char *)calloc(12, sizeof(char));

  s21_memset(s21_test_str, '\0', 11);
  memset(lib_test_str, '\0', 11);

  ck_assert_str_eq(s21_test_str, lib_test_str);
  free(s21_test_str);
  free(lib_test_str);
}
END_TEST

START_TEST(s21_memset_13) {
  char s21_test_str[10] = "Hello";
  char lib_test_str[10] = "Hello";
  s21_memset(s21_test_str, 0, 5);
  memset(lib_test_str, 0, 5);
  ck_assert_str_eq(s21_test_str, lib_test_str);
}
END_TEST

Suite *memset_suite(void) {
  Suite *s21_string = suite_create("s21_memset_test");
  TCase *tc_core = tcase_create("core");

  tcase_add_test(tc_core, s21_memset_1);
  tcase_add_test(tc_core, s21_memset_2);
  tcase_add_test(tc_core, s21_memset_3);
  tcase_add_test(tc_core, s21_memset_4);
  tcase_add_test(tc_core, s21_memset_5);
  tcase_add_test(tc_core, s21_memset_6);
  tcase_add_test(tc_core, s21_memset_7);
  tcase_add_test(tc_core, s21_memset_8);
  tcase_add_test(tc_core, s21_memset_9);
  tcase_add_test(tc_core, s21_memset_10);
  tcase_add_test(tc_core, s21_memset_11);
  tcase_add_test(tc_core, s21_memset_12);
  tcase_add_test(tc_core, s21_memset_13);
  suite_add_tcase(s21_string, tc_core);
  return s21_string;
}