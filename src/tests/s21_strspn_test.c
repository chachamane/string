#include "s21_all_tests.h"

// /* strspn TEST */ // strspn – ищет начало строки (первый аргумент) и
// вычисляет количество последовательных символов, которые входят в набор
// символов, указанный вторым аргументом

START_TEST(s21_strspn_1) {
  char src[] = "";
  char res[] = "";

  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(s21_strspn_2) {
  char src[] = "gora";
  char res[] = "";

  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(s21_strspn_3) {
  char src[] = "";
  char res[] = "gora";

  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(s21_strspn_4) {
  char src[] = "gora";
  char res[] = "gOra";

  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(s21_strspn_5) {
  char src[] = "123";
  char res[] = "123";

  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(s21_strspn_6) {
  char src[] = "12345";
  char res[] = "123";

  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(s21_strspn_7) {
  char src[] = "123";
  char res[] = "12345";

  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(s21_strspn_8) {
  char src[] = "1234567890";
  char res[] = "0987654321";

  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(s21_strspn_9) {
  char src[] = "1A2A3A4A5A";
  char res[] = "123";

  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(s21_strspn_10) {
  char src[] = "a1aaa23aaa41235";
  char res[] = "123";

  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(s21_strspn_11) {
  char src[] = "absD";
  char res[] = "aD";

  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(s21_strspn_12) {
  char src[] = "32ASDASDPare[0g9jf m07y271234567890";
  char res[] = "0987654321";

  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(s21_strspn_13) {
  char src[] = "32jersASDASDPare[0g9jf m07y271234567890";
  char res[] = "1234567890qwertyuiopasdfghjklczxcvbnm";

  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(s21_strspn_14) {
  char src[] =
      "333333333333333333333333333333333333333333333333333333333333333333333333"
      "33333333333333";
  char res[] =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "11111111111113";

  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(s21_strspn_15) {
  char str_1[12] = "hello world";
  char *str_2 = "world";
  int s21_result = s21_strspn(str_1, str_2);
  int lib_result = strspn(str_1, str_2);
  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strspn_16) {
  char str_1[12] = "hello";
  char *str_2 = "hello";
  int s21_result = s21_strspn(str_1, str_2);
  int lib_result = strspn(str_1, str_2);
  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strspn_17) {
  char *str_1 = "";
  char *str_2 = "world";
  int s21_result = s21_strspn(str_1, str_2);
  int lib_result = strspn(str_1, str_2);
  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strspn_18) {
  char str_1[12] = "hello world";
  char *str_2 = "";
  int s21_result = s21_strspn(str_1, str_2);
  int lib_result = strspn(str_1, str_2);
  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strspn_19) {
  char str_1[12] = "hello world";
  char *str_2 = "mac";
  int s21_result = s21_strspn(str_1, str_2);
  int lib_result = strspn(str_1, str_2);
  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strspn_20) {
  char *str_1 = "";
  char *str_2 = "";
  int s21_result = s21_strspn(str_1, str_2);
  int lib_result = strspn(str_1, str_2);
  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strspn_21) {
  char src[] = "32ASDASDPare[0g9jf m07y271234567890";
  char res[] = "1234567890QWERTYUIOPASDFGHJKLZXCVBNM";

  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

Suite *strspn_suite(void) {
  Suite *s21_string = suite_create("s21_strspn_test");
  TCase *tc_core = tcase_create("core");

  tcase_add_test(tc_core, s21_strspn_1);
  tcase_add_test(tc_core, s21_strspn_2);
  tcase_add_test(tc_core, s21_strspn_3);
  tcase_add_test(tc_core, s21_strspn_4);
  tcase_add_test(tc_core, s21_strspn_5);
  tcase_add_test(tc_core, s21_strspn_6);
  tcase_add_test(tc_core, s21_strspn_7);
  tcase_add_test(tc_core, s21_strspn_8);
  tcase_add_test(tc_core, s21_strspn_9);
  tcase_add_test(tc_core, s21_strspn_10);
  tcase_add_test(tc_core, s21_strspn_11);
  tcase_add_test(tc_core, s21_strspn_12);
  tcase_add_test(tc_core, s21_strspn_13);
  tcase_add_test(tc_core, s21_strspn_14);
  tcase_add_test(tc_core, s21_strspn_15);
  tcase_add_test(tc_core, s21_strspn_16);
  tcase_add_test(tc_core, s21_strspn_17);
  tcase_add_test(tc_core, s21_strspn_18);
  tcase_add_test(tc_core, s21_strspn_19);
  tcase_add_test(tc_core, s21_strspn_20);
  tcase_add_test(tc_core, s21_strspn_21);
  suite_add_tcase(s21_string, tc_core);
  return s21_string;
}