#include "s21_all_tests.h"

// /* strstr TEST */ // strstr – поиск первого вхождения строки А в строку В.

START_TEST(s21_strstr_1) {
  char s1[] = "H e l l o\0";
  char s2[] = "H e l\0";
  ck_assert_str_eq(s21_strstr(s1, s2), strstr(s1, s2));
}
END_TEST

START_TEST(s21_strstr_2) {
  char s1[] = "Hello\0";
  char s2[] = "llo\0";
  ck_assert_str_eq(s21_strstr(s1, s2), strstr(s1, s2));
}
END_TEST

START_TEST(s21_strstr_3) {
  char s1[] = "Hello\0";
  char s2[] = "ll\0";
  ck_assert_str_eq(s21_strstr(s1, s2), strstr(s1, s2));
}
END_TEST

START_TEST(s21_strstr_4) {
  char s1[] = "H e l l o\0";
  char s2[] = "\0";
  ck_assert_str_eq(s21_strstr(s1, s2), strstr(s1, s2));
}
END_TEST

START_TEST(s21_strstr_5) {
  char s1[] = "Hello\0";
  char s2[] = "Hello\0";
  ck_assert_str_eq(s21_strstr(s1, s2), strstr(s1, s2));
}
END_TEST

START_TEST(s21_strstr_6) {
  char haystack[] = "AD AD AD";
  char needle[] = "AD";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(s21_strstr_7) {
  char haystack[] = "22 321 123";
  char needle[] = "123";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(s21_strstr_8) {
  char haystack[] = "1";
  char needle[] = "1";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(s21_strstr_9) {
  char haystack[] =
      "13625523478437263475984675342345sdghyftrg freshtsyASFWEt wEafe";
  char needle[] = " ";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(s21_strstr_10) {
  char haystack[] = "-";
  char needle[] = "1234567890qwertyuiopasdfghjk-";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(s21_strstr_11) {
  char *test_haystack = "12345678";
  char *test_needle = "3";

  char *s21_result = s21_strstr(test_haystack, test_needle);
  char *lib_result = strstr(test_haystack, test_needle);

  ck_assert_str_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strstr_12) {
  char *test_haystack = "67878";
  char *test_needle = "345";

  char *s21_result = s21_strstr(test_haystack, test_needle);
  char *lib_result = strstr(test_haystack, test_needle);

  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strstr_13) {
  char *test_haystack = "123456";
  char *test_needle = "";

  char *s21_result = s21_strstr(test_haystack, test_needle);
  char *lib_result = strstr(test_haystack, test_needle);

  ck_assert_str_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strstr_14) {
  char *test_haystack = "";
  char *test_needle = "";

  char *s21_result = s21_strstr(test_haystack, test_needle);
  char *lib_result = strstr(test_haystack, test_needle);

  ck_assert_str_eq(s21_result, lib_result);
}
END_TEST

Suite *strstr_suite(void) {
  Suite *s21_string = suite_create("s21_strstr_test");
  TCase *tc_core = tcase_create("core");

  tcase_add_test(tc_core, s21_strstr_1);
  tcase_add_test(tc_core, s21_strstr_2);
  tcase_add_test(tc_core, s21_strstr_3);
  tcase_add_test(tc_core, s21_strstr_4);
  tcase_add_test(tc_core, s21_strstr_5);
  tcase_add_test(tc_core, s21_strstr_6);
  tcase_add_test(tc_core, s21_strstr_7);
  tcase_add_test(tc_core, s21_strstr_8);
  tcase_add_test(tc_core, s21_strstr_9);
  tcase_add_test(tc_core, s21_strstr_10);
  tcase_add_test(tc_core, s21_strstr_11);
  tcase_add_test(tc_core, s21_strstr_12);
  tcase_add_test(tc_core, s21_strstr_13);
  tcase_add_test(tc_core, s21_strstr_14);
  suite_add_tcase(s21_string, tc_core);
  return s21_string;
}