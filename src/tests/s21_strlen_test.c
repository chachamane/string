#include "s21_all_tests.h"

/* strlen TEST */  // strlen – определение длины строки.

START_TEST(s21_strlen_1) {
  ck_assert_int_eq(s21_strlen("Hello world\0"), strlen("Hello world\0"));
}
END_TEST

START_TEST(s21_strlen_2) {
  ck_assert_int_eq(s21_strlen("Hello world\n\0"), strlen("Hello world\n\0"));
}
END_TEST

START_TEST(s21_strlen_3) {
  ck_assert_int_eq(s21_strlen("a\n\0"), strlen("a\n\0"));
}
END_TEST

START_TEST(s21_strlen_4) {
  ck_assert_int_eq(s21_strlen(" \n\0"), strlen(" \n\0"));
}
END_TEST

START_TEST(s21_strlen_5) { ck_assert_int_eq(s21_strlen(" \0"), strlen(" \0")); }
END_TEST

START_TEST(s21_strlen_6) {
  ck_assert_int_eq(s21_strlen("\n\0"), strlen("\n\0"));
}
END_TEST

START_TEST(s21_strlen_7) { ck_assert_int_eq(s21_strlen("\0"), strlen("\0")); }
END_TEST

START_TEST(s21_strlen_8) {
  char src[] = "987623456124678";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(s21_strlen_9) {
  char src[] =
      "987623456124678qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(s21_strlen_10) {
  char src[] = "dai_mne_pen(321321)...123...123";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(s21_strlen_11) {
  char *test_str = "12345678";
  int s21_result = s21_strlen(test_str);
  int lib_result = strlen(test_str);
  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strlen_12) {
  char *test_str = "";

  int s21_result = s21_strlen(test_str);
  int lib_result = strlen(test_str);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

Suite *strlen_suite(void) {
  Suite *s21_string = suite_create("s21_strlen_test");
  TCase *tc_core = tcase_create("core");

  tcase_add_test(tc_core, s21_strlen_1);
  tcase_add_test(tc_core, s21_strlen_2);
  tcase_add_test(tc_core, s21_strlen_3);
  tcase_add_test(tc_core, s21_strlen_4);
  tcase_add_test(tc_core, s21_strlen_5);
  tcase_add_test(tc_core, s21_strlen_6);
  tcase_add_test(tc_core, s21_strlen_7);
  tcase_add_test(tc_core, s21_strlen_8);
  tcase_add_test(tc_core, s21_strlen_9);
  tcase_add_test(tc_core, s21_strlen_10);
  tcase_add_test(tc_core, s21_strlen_11);
  tcase_add_test(tc_core, s21_strlen_12);
  suite_add_tcase(s21_string, tc_core);
  return s21_string;
}