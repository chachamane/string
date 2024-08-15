#include "s21_all_tests.h"

/* memcpy TEST */  // memcpy – копирование непересекающихся массивов.

START_TEST(s21_memcpy_1) {
  char str1[20] = "42\0";
  char str2[20] = "Hello\0";
  ck_assert_str_eq(s21_memcpy(str1, str2, 20), memcpy(str1, str2, 20));
}
END_TEST

START_TEST(s21_memcpy_2) {
  char str1[20] = "a\n\0";
  char str2[20] = " \n\0";
  ck_assert_str_eq(s21_memcpy(str1, str2, 1), memcpy(str1, str2, 1));
}
END_TEST

START_TEST(s21_memcpy_3) {
  char str1[20] = "\0";
  char str2[20] = "\n\0";
  ck_assert_str_eq(s21_memcpy(str1, str2, 1), memcpy(str1, str2, 1));
}
END_TEST

START_TEST(s21_memcpy_4) {
  char str2[20] = "42";
  char str1[20] = "Hello";
  ck_assert_str_eq(s21_memcpy(str1, str2, 20), memcpy(str1, str2, 20));
}
END_TEST

START_TEST(s21_memcpy_5) {
  char src[] = "Zboba";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];

  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(s21_memcpy_6) {
  char src[] = "09";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];

  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(s21_memcpy_7) {
  char src[] = "abobasdafoijasdofjas asdopij";
  s21_size_t kByte = 28;
  char res[kByte + 8];
  char expected[kByte + 8];

  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(s21_memcpy_8) {
  char src[] = "aposkd AOSIjFasodijpaoisdjf poisdjfg";
  s21_size_t kByte = 36;
  char res[kByte + 8];
  char expected[kByte + 8];

  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(s21_memcpy_9) {
  char src[] = "aodasf ieuwfh luhasdfLIAUSHD liuh 12li3uh 12i4ouhsdfh";
  s21_size_t kByte = 53;
  char res[kByte + 8];
  char expected[kByte + 8];

  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(s21_memcpy_10) {
  char src[] =
      "()()(((())):!,....aodasf ieuwfh luhasdfLIAUSHD liuh 12li3uh 12i4ouhsdfh";
  s21_size_t kByte = 71;
  char res[kByte + 8];
  char expected[kByte + 8];

  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(s21_memcpy_11) {
  char test_dest[100] = "hello world again!";
  char test_dest2[100] = "hello world again!";
  const char *test_src = "tak";
  s21_size_t test_count = 3;
  char *s21_res = s21_memcpy(test_dest, test_src, test_count);
  ck_assert_str_eq(s21_res, memcpy(test_dest2, test_src, test_count));
}
END_TEST

START_TEST(s21_memcpy_12) {
  char test_dest[100] = "hello world again!";
  char test_dest2[100] = "hello world again!";
  const char *test_src = "tak";
  s21_size_t test_count = 2;
  char *s21_res = s21_memcpy(test_dest, test_src, test_count);
  ck_assert_str_eq(s21_res, memcpy(test_dest2, test_src, test_count));
}
END_TEST

START_TEST(s21_memcpy_13) {
  char test_dest[100] = "";
  char test_dest2[100] = "";
  const char *test_src = "tak";
  s21_size_t test_count = 3;
  char *s21_res = s21_memcpy(test_dest, test_src, test_count);
  ck_assert_str_eq(s21_res, memcpy(test_dest2, test_src, test_count));
}
END_TEST

START_TEST(s21_memcpy_14) {
  char test_dest[100] = "hello world";
  char test_dest2[100] = "hello world";
  const char *test_src = "";
  s21_size_t test_count = 0;
  char *s21_res = s21_memcpy(test_dest, test_src, test_count);
  ck_assert_str_eq(s21_res, memcpy(test_dest2, test_src, test_count));
}
END_TEST

Suite *memcpy_suite(void) {
  Suite *s21_string = suite_create("s21_memcpy_test");
  TCase *tc_core = tcase_create("core");

  tcase_add_test(tc_core, s21_memcpy_1);
  tcase_add_test(tc_core, s21_memcpy_2);
  tcase_add_test(tc_core, s21_memcpy_3);
  tcase_add_test(tc_core, s21_memcpy_4);
  tcase_add_test(tc_core, s21_memcpy_5);
  tcase_add_test(tc_core, s21_memcpy_6);
  tcase_add_test(tc_core, s21_memcpy_7);
  tcase_add_test(tc_core, s21_memcpy_8);
  tcase_add_test(tc_core, s21_memcpy_9);
  tcase_add_test(tc_core, s21_memcpy_10);
  tcase_add_test(tc_core, s21_memcpy_11);
  tcase_add_test(tc_core, s21_memcpy_12);
  tcase_add_test(tc_core, s21_memcpy_13);
  tcase_add_test(tc_core, s21_memcpy_14);
  suite_add_tcase(s21_string, tc_core);
  return s21_string;
}