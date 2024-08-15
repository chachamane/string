#include "s21_all_tests.h"

// /* strpbrk TEST */ // strpbrk – поиск первого вхождения в строку символа из
// указанного множества.

START_TEST(s21_strpbrk_1) {
  char s1[] = "H e l l o\0";
  char s2[] = "lo\0";
  ck_assert_str_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(s21_strpbrk_2) {
  char s1[] = "Hello\0";
  char s2[] = "HE\0";
  ck_assert_str_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(s21_strpbrk_3) {
  char s1[] = "Hello\0";
  char s2[] = "\0";
  ck_assert_ptr_null(s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(s21_strpbrk_4) {
  char s1[] = "Hello\0";
  char s2[] = "Hello\0";
  ck_assert_str_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(s21_strpbrk_5) {
  char s1[] = "Hello\0";
  char s2[] = "hELLO\0";
  ck_assert_ptr_null(s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(s21_strpbrk_6) {
  char str1[] = "ppppppppppppP";
  char str2[] = "\0";

  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_7) {
  char test_str[11] = "0123456789";
  char symb[4] = "345";

  char *s21_result = s21_strpbrk(test_str, symb);
  char *lib_result = strpbrk(test_str, symb);

  ck_assert_str_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strpbrk_8) {
  char test_str[11] = "0123456789";
  char symb[2] = "a";

  char *s21_result = s21_strpbrk(test_str, symb);
  char *lib_result = strpbrk(test_str, symb);

  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strpbrk_9) {
  char test_str[11] = "0123456789";
  char *symb = "";

  char *s21_result = s21_strpbrk(test_str, symb);
  char *lib_result = strpbrk(test_str, symb);

  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strpbrk_10) {
  char *test_str = "";
  char symb[4] = "123";

  char *s21_result = s21_strpbrk(test_str, symb);
  char *lib_result = strpbrk(test_str, symb);

  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

Suite *strpbrk_suite(void) {
  Suite *s21_string = suite_create("s21_strpbrk_test");
  TCase *tc_core = tcase_create("core");

  tcase_add_test(tc_core, s21_strpbrk_1);
  tcase_add_test(tc_core, s21_strpbrk_2);
  tcase_add_test(tc_core, s21_strpbrk_3);
  tcase_add_test(tc_core, s21_strpbrk_4);
  tcase_add_test(tc_core, s21_strpbrk_5);
  tcase_add_test(tc_core, s21_strpbrk_6);
  tcase_add_test(tc_core, s21_strpbrk_7);
  tcase_add_test(tc_core, s21_strpbrk_8);
  tcase_add_test(tc_core, s21_strpbrk_9);
  tcase_add_test(tc_core, s21_strpbrk_10);
  suite_add_tcase(s21_string, tc_core);
  return s21_string;
}