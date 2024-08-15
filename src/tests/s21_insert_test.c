#include "s21_all_tests.h"

/* insert TEST */  // insert - возвращает новую строку, в которой указанная
                   // строка (str) вставлена в указанную позицию (start_index) в
                   // данной строке (src).

// Тест 1: Вставляем строку в конец.
START_TEST(s21_insert_1) {
  char s1[] = "Hello !";
  char s2[] = "world";
  char *a = s21_insert(s1, s2, 6);
  ck_assert_str_eq(a, "Hello world!");
  free(a);
}
END_TEST

// Тест 2: Вставляем строку в середину.
START_TEST(s21_insert_2) {
  char *str = "Tupity Unity";
  char *res = s21_insert(str, " -===3.50===-", 6);
  ck_assert_str_eq(res, "Tupity -===3.50===- Unity");
  free(res);
}
END_TEST

// Тест 3: Пробуем вставить что-либо в строку, равную NULL.
START_TEST(s21_insert_3) {
  char *null = S21_NULL;
  char *res = s21_insert(null, "???", 48);
  ck_assert_pstr_eq(res, S21_NULL);
}
END_TEST

// Тест 4: Пробуем вставить NULL в строку.
START_TEST(s21_insert_4) {
  char *str = "Tupity Unity";
  char *res = s21_insert(str, NULL, 48);
  ck_assert_pstr_eq(res, S21_NULL);
}
END_TEST

// Тест 5: Пробуем вставить что-то в место, выходящее за рамки заданной строки.
START_TEST(s21_insert_5) {
  char *str = "Tupity Unity";
  char *res = s21_insert(str, "3.50", 777);
  ck_assert_pstr_eq(res, S21_NULL);
}
END_TEST

// Тест 6: Пробуем вызвать функцию с отрицательным параметром start_index.
START_TEST(s21_insert_6) {
  char *str = "Tupity Unity";
  char *res = s21_insert(str, "3.50", -777);
  ck_assert_pstr_eq(res, S21_NULL);
}
END_TEST

// Тест 7: Вставляем строку в конец другой строки.
START_TEST(s21_insert_7) {
  char *str = "Tupity Unity";
  char *res = s21_insert(str, " Forever", s21_strlen(str));
  ck_assert_str_eq(res, "Tupity Unity Forever");
  free(res);
}
END_TEST

// Тест 8: Вставляем строку в начало другой строки.
START_TEST(s21_insert_8) {
  char *str = "Tupity Unity";
  char *res = s21_insert(str, "Forever ", 0);
  ck_assert_str_eq(res, "Forever Tupity Unity");
  free(res);
}
END_TEST

START_TEST(s21_insert_9) {
  char str[] = "";
  char src[] = "";
  s21_size_t index = 100;
  char *expected = "";
  char *got = (char *)s21_insert(src, str, index);
  if (got) {
    ck_assert_str_eq(got, expected);
    free(got);
  }
}
END_TEST

START_TEST(s21_insert_10) {
  char *src = NULL;
  char *str = NULL;
  s21_size_t index = 100;
  char *expected = NULL;
  char *got = (char *)s21_insert(src, str, index);
  if (got) {
    ck_assert_str_eq(got, expected);
    free(got);
  }
}
END_TEST

START_TEST(s21_insert_11) {
  char str[] = "";
  char src[] = "Hello";
  s21_size_t index = 0;
  char *expected = "Hello";
  char *got = (char *)s21_insert(str, src, index);
  if (got) {
    ck_assert_str_eq(got, expected);
    free(got);
  }
}
END_TEST

START_TEST(s21_insert_12) {
  char str[] = "Hello";
  char src[] = "World";
  s21_size_t index = 5;
  char *expected = "HelloWorld";
  char *got = (char *)s21_insert(str, src, index);
  if (got) {
    ck_assert_str_eq(got, expected);
    free(got);
  }
}
END_TEST

START_TEST(s21_insert_13) {
  char *str = NULL;
  char src[] = "Hello";
  s21_size_t index = 2;
  char *expected = NULL;
  char *got = (char *)s21_insert(str, src, index);
  if (got) {
    ck_assert_str_eq(got, expected);
    free(got);
  }
}
END_TEST

START_TEST(s21_insert_14) {
  char str[] = "";
  char src[] = "";
  s21_size_t index = 0;
  char *expected = "";
  char *got = (char *)s21_insert(str, src, index);
  if (got) {
    ck_assert_str_eq(got, expected);
    free(got);
  }
}
END_TEST

START_TEST(s21_insert_15) {
  char str[] = "Hello";
  char src[] = "!";
  s21_size_t index = 5;
  char *expected = "Hello!";
  char *got = (char *)s21_insert(str, src, index);
  if (got) {
    ck_assert_str_eq(got, expected);
    free(got);
  }
}
END_TEST

START_TEST(s21_insert_16) {
  char *src = "Regular!";
  char *str = ", brainfucker";
  char *new_str = {0};
  new_str = s21_insert(src, str, 7);
  if (new_str) {
    ck_assert_str_eq(new_str, "Regular, brainfucker!");
    free(new_str);
  }

  new_str = s21_insert(src, "", 9);
  ck_assert(new_str == S21_NULL);
  free(new_str);

  new_str = s21_insert("Regular!", ", brainfucker!!", 7);
  if (new_str) {
    ck_assert_str_eq(new_str, "Regular, brainfucker!!!");
    free(new_str);
  }

  new_str = s21_insert("Regular!", ", brainfucker!!", 35);
  ck_assert(new_str == S21_NULL);
  free(new_str);

  new_str = s21_insert("", "", 0);
  if (new_str) {
    ck_assert_str_eq(new_str, "");
    free(new_str);
  }

  char *src1 = "1";
  char *str1 = "1";
  char *new_str2 = s21_insert(src1, str1, 1);
  if (new_str2) {
    ck_assert_str_eq(new_str2, "11");
    free(new_str2);
  }
}
END_TEST

START_TEST(s21_insert_17) {
  char *src = "lol cho";
  char *str = "nie rozumiem";
  s21_size_t start_index1 = 1000;
  s21_size_t start_index2 = -2;

  char *func_result1 = s21_insert(src, str, start_index1);
  char *func_result2 = s21_insert(src, str, start_index2);

  ck_assert_ptr_eq(func_result1, S21_NULL);
  ck_assert_ptr_eq(func_result2, S21_NULL);
  free(func_result1);
  free(func_result2);
}
END_TEST

START_TEST(s21_insert_18) {
  char *src = "Regular!";
  char *str = ", brainfucker";
  char *new_str = {0};
  new_str = s21_insert(src, str, 7);
  if (new_str) {
    ck_assert_str_eq(new_str, "Regular, brainfucker!");
    free(new_str);
  }

  new_str = s21_insert(src, "", 9);
  ck_assert(new_str == S21_NULL);
  free(new_str);

  new_str = s21_insert("Regular!", ", brainfucker!!", 7);
  if (new_str) {
    ck_assert_str_eq(new_str, "Regular, brainfucker!!!");
    free(new_str);
  }

  new_str = s21_insert("Regular!", ", brainfucker!!", 35);
  ck_assert(new_str == S21_NULL);
  free(new_str);

  new_str = s21_insert("", "", 0);
  if (new_str) {
    ck_assert_str_eq(new_str, "");
    free(new_str);
  }

  char *src1 = "1";
  char *str1 = "1";
  char *new_str2 = s21_insert(src1, str1, 1);
  if (new_str2) {
    ck_assert_str_eq(new_str2, "11");
    free(new_str2);
  }
}

END_TEST

Suite *insert_suite(void) {
  Suite *s21_string = suite_create("s21_insert_test");
  TCase *tc_core = tcase_create("core");

  tcase_add_test(tc_core, s21_insert_1);
  tcase_add_test(tc_core, s21_insert_2);
  tcase_add_test(tc_core, s21_insert_3);
  tcase_add_test(tc_core, s21_insert_4);
  tcase_add_test(tc_core, s21_insert_5);
  tcase_add_test(tc_core, s21_insert_6);
  tcase_add_test(tc_core, s21_insert_7);
  tcase_add_test(tc_core, s21_insert_8);
  tcase_add_test(tc_core, s21_insert_9);
  tcase_add_test(tc_core, s21_insert_10);
  tcase_add_test(tc_core, s21_insert_11);
  tcase_add_test(tc_core, s21_insert_12);
  tcase_add_test(tc_core, s21_insert_13);
  tcase_add_test(tc_core, s21_insert_14);
  tcase_add_test(tc_core, s21_insert_15);
  tcase_add_test(tc_core, s21_insert_16);
  tcase_add_test(tc_core, s21_insert_17);
  tcase_add_test(tc_core, s21_insert_18);
  suite_add_tcase(s21_string, tc_core);
  return s21_string;
}