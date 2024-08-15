#include "s21_all_tests.h"

/* memchr TEST */  // memchr – поиск первого вхождения указанного символа в
                   // массиве.

START_TEST(s21_memchr_1) {
  unsigned char src[15] = "1234567890";
  ck_assert_str_eq(s21_memchr(src, '3', 3), memchr(src, '3', 3));
}
END_TEST

START_TEST(s21_memchr_2) {
  unsigned char src[15] = "Hello world\0";
  ck_assert_str_eq(s21_memchr(src, ' ', 7), memchr(src, ' ', 7));
}
END_TEST

START_TEST(s21_memchr_3) {
  unsigned char src[15] = "Hello world\0";
  ck_assert_pstr_eq(s21_memchr(src, 'o', 1), memchr(src, 'o', 1));
}
END_TEST

START_TEST(s21_memchr_4) {
  unsigned char src[15] = "Hello world\n\0";
  ck_assert_str_eq(s21_memchr(src, ' ', 7), memchr(src, ' ', 7));
}
END_TEST

START_TEST(s21_memchr_5) {
  unsigned char src[15] = "a\n\0";
  ck_assert_str_eq(s21_memchr(src, 'a', 1), memchr(src, 'a', 1));
}
END_TEST

START_TEST(s21_memchr_6) {
  unsigned char src[15] = " \n\0";
  ck_assert_str_eq(s21_memchr(src, ' ', 7), memchr(src, ' ', 7));
}
END_TEST

START_TEST(s21_memchr_7) {
  unsigned char src[15] = " \0";
  ck_assert_str_eq(s21_memchr(src, ' ', 1), memchr(src, ' ', 1));
}
END_TEST

START_TEST(s21_memchr_8) {
  ck_assert_pstr_eq(s21_memchr("\n\0", '0', 1), memchr("\n\0", '0', 1));
}
END_TEST

START_TEST(s21_memchr_10) {
  unsigned char src[15] = "1234567890";
  ck_assert_str_eq(s21_memchr(src, '1', 6), memchr(src, '1', 6));
}
END_TEST

START_TEST(s21_memchr_11) {
  int array[] = {1, 2, 3, 666, 5, 99, 100};
  s21_size_t n_byte = sizeof(int) * 7;
  int find_byte = 666;

  ck_assert_ptr_eq(s21_memchr(array, find_byte, n_byte),
                   memchr(array, find_byte, n_byte));
}
END_TEST

START_TEST(s21_memchr_12) {
  float array[] = {1, 2, 3, 666, 5, 99, 100};
  s21_size_t n_byte = sizeof(float) * 7;
  int find_byte = 666;

  ck_assert_ptr_eq(s21_memchr(array, find_byte, n_byte),
                   memchr(array, find_byte, n_byte));
}
END_TEST

START_TEST(s21_memchr_13) {
  s21_size_t n_byte = 5;
  char str[10] = "aboba";
  int find_byte = 'c';

  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(s21_memchr_14) {
  // Arrange
  char *str = "ABCDEFG";
  char sym = 'D';
  s21_size_t n = strlen(str);
  // Act
  char *s21_result = s21_memchr(str, sym, n);
  char *lib_result = memchr(str, sym, n);
  // Assert
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_memchr_15) {
  // Arrange
  char *str = "";
  char sym = 'D';
  s21_size_t n = strlen(str);
  // Act
  char *s21_result = s21_memchr(str, sym, n);
  char *lib_result = memchr(str, sym, n);
  // Assert
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_memchr_16) {
  // Arrange
  char *str = "ABCDEFG";
  char sym = 'D';
  s21_size_t n = 0;
  // Act
  char *s21_result = s21_memchr(str, sym, n);
  char *lib_result = memchr(str, sym, n);
  // Assert
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_memchr_17) {
  char *str = "";
  char sym = '\0';
  s21_size_t n = strlen(str);
  char *s21_result = s21_memchr(str, sym, n);
  char *lib_result = memchr(str, sym, n);
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_memchr_18) {
  // Arrange
  char *str = "ABCDEFG";
  char sym = '\0';
  s21_size_t n = strlen(str);
  // Act
  char *s21_result = s21_memchr(str, sym, n);
  char *lib_result = memchr(str, sym, n);
  // Assert
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

Suite *memchr_suite(void) {
  Suite *s21_string = suite_create("s21_memchr_test");
  TCase *tc_core = tcase_create("core");

  tcase_add_test(tc_core, s21_memchr_1);
  tcase_add_test(tc_core, s21_memchr_2);
  tcase_add_test(tc_core, s21_memchr_3);
  tcase_add_test(tc_core, s21_memchr_4);
  tcase_add_test(tc_core, s21_memchr_5);
  tcase_add_test(tc_core, s21_memchr_6);
  tcase_add_test(tc_core, s21_memchr_7);
  tcase_add_test(tc_core, s21_memchr_8);
  tcase_add_test(tc_core, s21_memchr_10);
  tcase_add_test(tc_core, s21_memchr_11);
  tcase_add_test(tc_core, s21_memchr_12);
  tcase_add_test(tc_core, s21_memchr_13);
  tcase_add_test(tc_core, s21_memchr_14);
  tcase_add_test(tc_core, s21_memchr_15);
  tcase_add_test(tc_core, s21_memchr_16);
  tcase_add_test(tc_core, s21_memchr_17);
  tcase_add_test(tc_core, s21_memchr_18);
  suite_add_tcase(s21_string, tc_core);
  return s21_string;
}