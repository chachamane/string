#include "s21_all_tests.h"

// /* trim TEST */ // trim - возвращает новую строку, в которой удаляются все
// начальные и конечные вхождения набора заданных символов (trim_chars) из
// данной строки (src).

START_TEST(s21_trim_1) {
  const char *s1 = "88Hello my world888\0";
  const char *s2 = "8";
  char *a = s21_trim(s1, s2);
  ck_assert_str_eq(a, "Hello my world");
  free(a);
}
END_TEST

START_TEST(s21_trim_2) {
  const char *s1 = "11Hello world321";
  const char *s2 = "321";
  char *a = s21_trim(s1, s2);
  ck_assert_str_eq(a, "Hello world");
  free(a);
}
END_TEST

START_TEST(s21_trim_3) {
  const char *s1 = "00g0000";
  const char *s2 = "0";
  char *a = s21_trim(s1, s2);
  ck_assert_str_eq(a, "g");
  free(a);
}
END_TEST

START_TEST(s21_trim_4) {
  char str[] = "";
  char trim_ch[] = "";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_trim_5) {
  char str[] = "";
  char trim_ch[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_trim_6) {
  char str[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char trim_ch[] = "";
  char expected[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_trim_7) {
  char str[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char trim_ch[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_trim_8) {
  char str[] = "+!!++Abo+ba++00";
  char trim_ch[] = "+!0-";
  char expected[] = "Abo+ba";
  char *got = (char *)s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_trim_9) {
  char str[] = "Ab000cd0";
  char trim_ch[] = "003";
  char expected[] = "Ab000cd";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_trim_10) {
  char str[] = "&* !!sc21 * **";
  char trim_ch[] = "&!* ";
  char expected[] = "sc21";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_trim_11) {
  char str[] = " Good morning!    ";
  char trim_ch[] = " ";
  char expected[] = "Good morning!";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_trim_12) {
  char str[] = "        abc         ";
  char trim_ch[] = "";
  char expected[] = "abc";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_trim_13) {
  char str[] = "        abc         ";
  char *trim_ch = NULL;
  char expected[] = "abc";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_trim_14) {
  char str[] = "abc--def--ghi";
  char trim_ch[] = "--";
  char expected[] = "abc--def--ghi";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_trim_15) {
  char str[] = "\t\n  Hello World  \n\t";
  char trim_ch[] = "\t\n ";
  char expected[] = "Hello World";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_trim_16) {
  char str[] = "\x01\x02test string\x03\x04";
  char trim_ch[] = "\x01\x02\x03\x04";
  char expected[] = "test string";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_trim_17) {
  char str[] = "1234567Hello1234567";
  char trim_ch[] = "1234567";
  char expected[] = "Hello";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_trim_18) {
  char str[] = "aaaaa";
  char trim_ch[] = "a";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_trim_19) {
  char str[] = "zyxwHelloxyzw";
  char trim_ch[] = "wxyz";
  char expected[] = "Hello";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_trim_20) {
  char str[] = "*&^%$Hello$%^&*";
  char trim_ch[] = "*&^%$";
  char expected[] = "Hello";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_trim_21) {
  char str[] = "\r\n\t Hello World \t\n\r";
  char trim_ch[] = "\r\n\t ";
  char expected[] = "Hello World";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_trim_22) {
  char str[] = "";
  char trim_ch[] = "abc";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_trim_23) {
  char str[] = "AAAAaaBBBbbb";
  char trim_ch[] = "AB";
  char expected[] = "aaBBBbbb";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_trim_24) {
  char str[] = "¡Hola, mundo!¿";
  char trim_ch[] = "¡¿";
  char expected[] = "Hola, mundo!";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_trim_25) {
  char *test_str = "my name is";
  char *trim_chars = "my";

  char *func_res = s21_trim(test_str, trim_chars);
  ck_assert_str_eq(func_res, " name is");
  free(func_res);
}
END_TEST

START_TEST(s21_trim_26) {
  char *test_str = "my name is rey";
  char *trim_chars = "my";

  char *func_res = s21_trim(test_str, trim_chars);
  ck_assert_str_eq(func_res, " name is re");
  free(func_res);
}
END_TEST

START_TEST(s21_trim_27) {
  char *test_str = " my name is rey ";
  char *trim_chars = " ";

  char *func_res = s21_trim(test_str, trim_chars);
  ck_assert_str_eq(func_res, "my name is rey");
  free(func_res);
}
END_TEST

START_TEST(s21_trim_28) {
  char *result;
  char *banner = " \n   !* * *'\' Much Ado About Nothing * * '\'*  !\n";
  result = s21_trim(banner, " *!\n '\'");
  if (result) {
    ck_assert_str_eq(result, "Much Ado About Nothing");
    free(result);
  }

  char *banner2 = "xxx Hello, world! xxx ---";
  char *format_str = "x -";
  result = s21_trim(banner2, format_str);
  if (result) {
    ck_assert_str_eq(result, "Hello, world!");
    free(result);
  }

  char *empty_str = "";
  result = s21_trim(empty_str, S21_NULL);
  if (result) {
    ck_assert_str_eq(result, "");
    free(result);
  }

  char *empty_format = "";
  result = s21_trim(S21_NULL, empty_format);
  ck_assert(result == S21_NULL);

  result = s21_trim(banner, empty_format);
  if (result) {
    ck_assert_str_eq(result, "!* * *'' Much Ado About Nothing * * ''*  !");
    free(result);
  }

  result = s21_trim("banner \n", "\n");
  if (result) {
    ck_assert_str_eq(result, "banner ");
    free(result);
  }

  result = s21_trim(empty_str, " \n\0");
  if (result) {
    ck_assert_str_eq(result, "");
    free(result);
  }
}
END_TEST

Suite *trim_suite(void) {
  Suite *s21_string = suite_create("s21_trim_test");
  TCase *tc_core = tcase_create("core");

  tcase_add_test(tc_core, s21_trim_1);
  tcase_add_test(tc_core, s21_trim_2);
  tcase_add_test(tc_core, s21_trim_3);
  tcase_add_test(tc_core, s21_trim_4);
  tcase_add_test(tc_core, s21_trim_5);
  tcase_add_test(tc_core, s21_trim_6);
  tcase_add_test(tc_core, s21_trim_7);
  tcase_add_test(tc_core, s21_trim_8);
  tcase_add_test(tc_core, s21_trim_9);
  tcase_add_test(tc_core, s21_trim_10);
  tcase_add_test(tc_core, s21_trim_11);
  tcase_add_test(tc_core, s21_trim_12);
  tcase_add_test(tc_core, s21_trim_13);
  tcase_add_test(tc_core, s21_trim_14);
  tcase_add_test(tc_core, s21_trim_15);
  tcase_add_test(tc_core, s21_trim_16);
  tcase_add_test(tc_core, s21_trim_17);
  tcase_add_test(tc_core, s21_trim_18);
  tcase_add_test(tc_core, s21_trim_19);
  tcase_add_test(tc_core, s21_trim_20);
  tcase_add_test(tc_core, s21_trim_21);
  tcase_add_test(tc_core, s21_trim_22);
  tcase_add_test(tc_core, s21_trim_23);
  tcase_add_test(tc_core, s21_trim_24);
  tcase_add_test(tc_core, s21_trim_25);
  tcase_add_test(tc_core, s21_trim_26);
  tcase_add_test(tc_core, s21_trim_27);
  tcase_add_test(tc_core, s21_trim_28);
  suite_add_tcase(s21_string, tc_core);
  return s21_string;
}