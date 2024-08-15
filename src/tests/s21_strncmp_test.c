#include "s21_all_tests.h"

// /* strncmp TEST */ // strncmp – сравнение строк с ограничением количества
// сравниваемых символов.

START_TEST(s21_strncmp_1) {
  char s1[50] = "Hello world\0";
  char s3[50] = "Hello worl\0";
  ck_assert_int_eq(s21_strncmp(s1, s3, 3), strncmp(s1, s3, 3));
}
END_TEST

START_TEST(s21_strncmp_2) {
  char s1[50] = "Hello world\0";
  char s3[50] = "Hello\0";
  ck_assert_int_eq(s21_strncmp(s1, s3, 4), strncmp(s1, s3, 4));
}
END_TEST

START_TEST(s21_strncmp_3) {
  char s1[50] = "\n\0";
  char s3[50] = "\n\0";
  ck_assert_int_eq(s21_strncmp(s1, s3, 1), strncmp(s1, s3, 1));
}
END_TEST

START_TEST(s21_strncmp_4) {
  char s1[50] = "privet\0";
  char s3[50] = "privet medved\0";
  ck_assert_int_eq(s21_strncmp(s1, s3, 2), strncmp(s1, s3, 2));
}
END_TEST

START_TEST(s21_strncmp_5) {
  char s1[] = "";
  char s2[] = "";
  s21_size_t n_byte = 0;

  int got = s21_strncmp(s1, s2, n_byte);
  int expected = strncmp(s1, s2, n_byte);

  if (got > 1) got = 1;
  if (expected > 1) expected = 1;

  if (got < -1) got = -1;
  if (expected < -1) expected = -1;

  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_strncmp_6) {
  char s1[] = "floppa";
  char s2[] = "";
  s21_size_t n_byte = 0;

  int got = s21_strncmp(s1, s2, n_byte);
  int expected = strncmp(s1, s2, n_byte);

  if (got > 1) got = 1;
  if (expected > 1) expected = 1;

  if (got < -1) got = -1;
  if (expected < -1) expected = -1;

  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_strncmp_7) {
  char s1[] = "";
  char s2[] = "floppa";
  s21_size_t n_byte = 0;

  int got = s21_strncmp(s1, s2, n_byte);
  int expected = strncmp(s1, s2, n_byte);

  if (got > 1) got = 1;
  if (expected > 1) expected = 1;

  if (got < -1) got = -1;
  if (expected < -1) expected = -1;

  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_strncmp_8) {
  char s1[] = "floppa";
  char s2[] = "floppa";
  s21_size_t n_byte = 6;

  int got = s21_strncmp(s1, s2, n_byte);
  int expected = strncmp(s1, s2, n_byte);

  if (got > 1) got = 1;
  if (expected > 1) expected = 1;

  if (got < -1) got = -1;
  if (expected < -1) expected = -1;

  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_strncmp_9) {
  char s1[] = "floppabazbazkotya";
  char s2[] = "floppabaz";
  s21_size_t n_byte = 10;

  int got = s21_strncmp(s1, s2, n_byte);
  int expected = strncmp(s1, s2, n_byte);

  if (got > 1) got = 1;
  if (expected > 1) expected = 1;

  if (got < -1) got = -1;
  if (expected < -1) expected = -1;

  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_strncmp_10) {
  char s1[] = "floppa";
  char s2[] = "floppa";
  s21_size_t n_byte = 1;

  int got = s21_strncmp(s1, s2, n_byte);
  int expected = strncmp(s1, s2, n_byte);

  if (got > 1) got = 1;
  if (expected > 1) expected = 1;

  if (got < -1) got = -1;
  if (expected < -1) expected = -1;

  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_strncmp_11) {
  char *test_str = "12345";
  char *test_substr = "12345";
  s21_size_t n = 3;

  int s21_result = s21_strncmp(test_str, test_substr, n);
  int lib_result = strncmp(test_str, test_substr, n);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strncmp_12) {
  char *test_str = "12345";
  char *test_substr = "12345";
  s21_size_t n = 5;

  int s21_result = s21_strncmp(test_str, test_substr, n);
  int lib_result = strncmp(test_str, test_substr, n);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strncmp_13) {
  char *test_str = "12345";
  char *test_substr = "22345";
  s21_size_t n = 4;

  int s21_result = s21_strncmp(test_str, test_substr, n);
  int lib_result = strncmp(test_str, test_substr, n);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strncmp_14) {
  char *test_str = "22345";
  char *test_substr = "";
  s21_size_t n = 3;

  int s21_result = s21_strncmp(test_str, test_substr, n);
  int lib_result = strncmp(test_str, test_substr, n);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strncmp_15) {
  char *test_str = "22345";
  char *test_substr = "12345";
  s21_size_t n = 0;

  int s21_result = s21_strncmp(test_str, test_substr, n);
  int lib_result = strncmp(test_str, test_substr, n);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strncmp_16) {
  char *test_str = "12345";
  char *test_substr = "13545";
  s21_size_t n = 4;

  int s21_result = s21_strncmp(test_str, test_substr, n);
  int lib_result = strncmp(test_str, test_substr, n);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strncmp_17) {
  char *test_str = "";
  char *test_substr = "";
  s21_size_t n = 4;

  int s21_result = s21_strncmp(test_str, test_substr, n);
  int lib_result = strncmp(test_str, test_substr, n);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strncmp_18) {
  char *test_str = "22345";
  char *test_substr = "12345";
  s21_size_t n = 7;

  int s21_result = s21_strncmp(test_str, test_substr, n);
  int lib_result = strncmp(test_str, test_substr, n);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

Suite *strncmp_suite(void) {
  Suite *s21_string = suite_create("s21_strncmp_test");
  TCase *tc_core = tcase_create("core");

  tcase_add_test(tc_core, s21_strncmp_1);
  tcase_add_test(tc_core, s21_strncmp_2);
  tcase_add_test(tc_core, s21_strncmp_3);
  tcase_add_test(tc_core, s21_strncmp_4);
  tcase_add_test(tc_core, s21_strncmp_5);
  tcase_add_test(tc_core, s21_strncmp_6);
  tcase_add_test(tc_core, s21_strncmp_7);
  tcase_add_test(tc_core, s21_strncmp_8);
  tcase_add_test(tc_core, s21_strncmp_9);
  tcase_add_test(tc_core, s21_strncmp_10);
  tcase_add_test(tc_core, s21_strncmp_11);
  tcase_add_test(tc_core, s21_strncmp_12);
  tcase_add_test(tc_core, s21_strncmp_13);
  tcase_add_test(tc_core, s21_strncmp_14);
  tcase_add_test(tc_core, s21_strncmp_15);
  tcase_add_test(tc_core, s21_strncmp_16);
  tcase_add_test(tc_core, s21_strncmp_17);
  tcase_add_test(tc_core, s21_strncmp_18);
  suite_add_tcase(s21_string, tc_core);
  return s21_string;
}