#ifndef SRC_S21_STRING_TEST_H
#define SRC_S21_STRING_TEST_H

#include <check.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../s21_string.h"

Suite *memchr_suite(void);
Suite *memcmp_suite(void);
Suite *memcpy_suite(void);
Suite *memmove_suite(void);
Suite *memset_suite(void);
Suite *strncat_suite(void);
Suite *strcat_suite(void);
Suite *strchr_suite(void);
Suite *strncmp_suite(void);
Suite *strncpy_suite(void);
Suite *strcpy_suite(void);
Suite *strcspn_suite(void);
Suite *strerror_suite(void);
Suite *strlen_suite(void);
Suite *strpbrk_suite(void);
Suite *strrchr_suite(void);
Suite *strchr_suite(void);
Suite *strstr_suite(void);
Suite *strtok_suite(void);
Suite *strspn_suite(void);
Suite *tolower_suite(void);
Suite *toupper_suite(void);
Suite *insert_suite(void);
Suite *trim_suite(void);
Suite *sprintf_suite(void);
Suite *sscanf_suite(void);

void run_tests(void);
void run_testcase(Suite *testcase);

#endif  // SRC_S21_STRING_TEST_H