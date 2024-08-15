#include "s21_all_tests.h"

/* memcmp TEST */  // memcmp – сравнение массивов.

START_TEST(s21_memcmp_1) {
  unsigned char s1[10] = "1234\0";
  unsigned char s2[10] = "1\0";
  ;
  ck_assert_int_eq(s21_memcmp(s1, s2, 5), memcmp(s1, s2, 5));
}
END_TEST

START_TEST(s21_memcmp_2) {
  unsigned char s1[10] = "1234\0";
  unsigned char s2[10] = "5678\0";
  ck_assert_int_eq(s21_memcmp(s1, s2, 5), memcmp(s1, s2, 5));
}
END_TEST

START_TEST(s21_memcmp_3) {
  unsigned char s1[20] = "Hello\0";
  unsigned char s2[20] = "Hello world\0";
  ck_assert_int_eq(s21_memcmp(s1, s2, 7), memcmp(s1, s2, 7));
}
END_TEST

START_TEST(s21_memcmp_4) {
  unsigned char s1[10] = "Hello\0";
  unsigned char s2[10] = "Bye\0";
  ck_assert_int_eq(s21_memcmp(s1, s2, 10), memcmp(s1, s2, 10));
}
END_TEST
START_TEST(s21_memcmp_5) {
  char s1[] = "1234";
  char s2[] = "1234";
  int n = 2;

  ck_assert_int_eq(s21_memcmp(s1, s2, n), memcmp(s1, s2, n));
}
END_TEST

START_TEST(s21_memcmp_6) {
  char s1[] = "13";
  char s2[] = "1234";
  int n = 2;

  ck_assert_int_eq(s21_memcmp(s1, s2, n), memcmp(s1, s2, n));
}
END_TEST

START_TEST(s21_memcmp_7) {
  char s1[] = "134567";
  char s2[] = "1234";
  int n = 2;

  ck_assert_int_eq(s21_memcmp(s1, s2, n), memcmp(s1, s2, n));
}
END_TEST

START_TEST(s21_memcmp_8) {
  char s1[] =
      "111111111111111111112312312312312312434524563567adsfe 4rafa ewfseASDASD";
  char s2[] =
      "111111111111111111112312312312312312434524563567adsfe 4rafa ewfseASDASD";
  int n = 71;

  ck_assert_int_eq(s21_memcmp(s1, s2, n), memcmp(s1, s2, n));
}
END_TEST

START_TEST(s21_memcmp_9) {
  char s1[] =
      "111111111111111111112312312312312312434524563567adsfe 4rafa ewfseASDASD";
  char s2[] =
      "111111111111111111112312312312312312434524563567adsfe 4rafa ewfseASDASd";
  int n = 71;

  ck_assert_int_eq(s21_memcmp(s1, s2, n), memcmp(s1, s2, n));
}
END_TEST

START_TEST(s21_memcmp_10) {
  char s1[] = "1";
  char s2[] = "1";
  int n = 0;

  ck_assert_int_eq(s21_memcmp(s1, s2, n), memcmp(s1, s2, n));
}
END_TEST

START_TEST(s21_memcmp_11) {
  char *test_str = "12345";
  char *test_substr = "12345";
  s21_size_t n = 5;

  int s21_result = s21_memcmp(test_str, test_substr, n);
  int lib_result = memcmp(test_str, test_substr, n);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_memcmp_12) {
  char *test_str = "02345";
  char *test_substr = "12345";
  s21_size_t n = 0;

  int s21_result = s21_memcmp(test_str, test_substr, n);
  int lib_result = memcmp(test_str, test_substr, n);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_memcmp_13) {
  char *test_str = "12346";
  char *test_substr = "12345";
  s21_size_t n = 2;

  int s21_result = s21_memcmp(test_str, test_substr, n);
  int lib_result = memcmp(test_str, test_substr, n);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_memcmp_14) {
  char *test_str = "02346";
  char *test_substr = "04345";
  s21_size_t n = 2;

  int s21_result = s21_memcmp(test_str, test_substr, n);
  int lib_result = memcmp(test_str, test_substr, n);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_memcmp_15) {
  char *test_str = "";
  char *test_substr = "";
  s21_size_t n = 0;

  int s21_result = s21_memcmp(test_str, test_substr, n);
  int lib_result = memcmp(test_str, test_substr, n);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_memcmp_16) {
  char *test_str = "0";
  char *test_substr = "46545";
  s21_size_t n = 2;

  int s21_result = s21_memcmp(test_str, test_substr, n);
  int lib_result = memcmp(test_str, test_substr, n);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_memcmp_17) {
  char *test_str = "46426";
  char *test_substr = "1";
  s21_size_t n = 2;

  int s21_result = s21_memcmp(test_str, test_substr, n);
  int lib_result = memcmp(test_str, test_substr, n);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

Suite *memcmp_suite(void) {
  Suite *s21_string = suite_create("s21_memcmp_test");
  TCase *tc_core = tcase_create("core");

  tcase_add_test(tc_core, s21_memcmp_1);
  tcase_add_test(tc_core, s21_memcmp_2);
  tcase_add_test(tc_core, s21_memcmp_3);
  tcase_add_test(tc_core, s21_memcmp_4);
  tcase_add_test(tc_core, s21_memcmp_5);
  tcase_add_test(tc_core, s21_memcmp_6);
  tcase_add_test(tc_core, s21_memcmp_7);
  tcase_add_test(tc_core, s21_memcmp_8);
  tcase_add_test(tc_core, s21_memcmp_9);
  tcase_add_test(tc_core, s21_memcmp_10);
  tcase_add_test(tc_core, s21_memcmp_11);
  tcase_add_test(tc_core, s21_memcmp_12);
  tcase_add_test(tc_core, s21_memcmp_13);
  tcase_add_test(tc_core, s21_memcmp_14);
  tcase_add_test(tc_core, s21_memcmp_15);
  tcase_add_test(tc_core, s21_memcmp_16);
  tcase_add_test(tc_core, s21_memcmp_17);
  suite_add_tcase(s21_string, tc_core);
  return s21_string;
}