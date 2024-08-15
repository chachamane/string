#include "s21_all_tests.h"

/* memmove TEST */

START_TEST(s21_memmove_1) {
  char test_dest[100] = "hello world again! and again";
  char test_dest2[100] = "hello world again! and again";
  const char test_src[100] = "taktaktak";
  s21_size_t test_count = 3;
  char *s21_res = s21_memmove(test_dest, test_src, test_count);
  ck_assert_str_eq(s21_res, memcpy(test_dest2, test_src, test_count));
}
END_TEST

START_TEST(s21_memmove_2) {
  char sc1[50] = "School21ForEveryBodyHere";
  s21_memmove(sc1, sc1 + 8, 8);

  char sc2[50] = "School21ForEveryBodyHere";
  s21_memmove(sc2 + 8, sc2, 16);

  char sc3[50] = "School21ForEveryBodyHere";
  memmove(sc3, sc3 + 8, 8);

  char sc4[50] = "School21ForEveryBodyHere";
  memmove(sc4 + 8, sc4, 16);

  ck_assert_str_eq(sc1, sc3);
  ck_assert_str_eq(sc2, sc4);
}
END_TEST

START_TEST(s21_memmove_3) {
  char test_dest[100] = "hello world again! and again";
  char test_dest2[100] = "hello world again! and again";
  const char test_src[100] = "taktaktak";
  s21_size_t test_count = 3;
  char *s21_res = s21_memmove(test_dest, &test_src[3], test_count);
  ck_assert_str_eq(s21_res, memcpy(test_dest2, &test_src[3], test_count));
}
END_TEST

START_TEST(s21_memmove_4) {
  char test_dest[100] = "hello world again! and again";
  char test_dest2[100] = "hello world again! and again";
  const char test_src[100] = "taktaktak";
  s21_size_t test_count = 3;
  char *s21_res = s21_memmove(&test_dest[1], &test_src[3], test_count);
  ck_assert_str_eq(s21_res, memcpy(&test_dest2[1], &test_src[3], test_count));
}
END_TEST

START_TEST(s21_memmove_5) {
  char test_dest[100] = "hello world again! and again";
  char test_dest2[100] = "hello world again! and again";
  const char test_src[100] = "taktaktak";
  s21_size_t test_count = 4;
  char *s21_res = s21_memmove(test_dest, test_src, test_count);
  ck_assert_str_eq(s21_res, memcpy(test_dest2, test_src, test_count));
}
END_TEST

START_TEST(s21_memmove_6) {
  char test_dest[50] = "hello world again! and again";
  char test_dest2[50] = "hello world again! and again";
  s21_size_t test_count = 3;
  char *s21_res = s21_memmove(&test_dest[5], &test_dest[2], test_count);
  ck_assert_str_eq(s21_res, memcpy(&test_dest2[5], &test_dest2[2], test_count));
}
END_TEST

Suite *memmove_suite(void) {
  Suite *s21_string = suite_create("s21_memmove_test");
  TCase *tc_core = tcase_create("core");

  tcase_add_test(tc_core, s21_memmove_1);
  tcase_add_test(tc_core, s21_memmove_2);
  tcase_add_test(tc_core, s21_memmove_3);
  tcase_add_test(tc_core, s21_memmove_4);
  tcase_add_test(tc_core, s21_memmove_5);
  tcase_add_test(tc_core, s21_memmove_6);
  suite_add_tcase(s21_string, tc_core);
  return s21_string;
}