#include "s21_all_tests.h"

// /* strtok TEST */ // strtok – разбиение строки на части по указанному
// разделителю.

START_TEST(s21_strtok_1) {
  char s1[] = "H e l l o\0";
  char s2[] = " ";
  char *r = s21_strtok(s1, s2);
  ck_assert_str_eq(r, strtok(s1, s2));
}
END_TEST

START_TEST(s21_strtok_2) {
  char s1[] = "Hello\0";
  char s2[] = "l";
  char *r = s21_strtok(s1, s2);
  ck_assert_str_eq(r, strtok(s1, s2));
}
END_TEST

START_TEST(s21_strtok_3) {
  char s1[] = "H.el.lo\0";
  char s2[] = ".\0";
  char *r = s21_strtok(s1, s2);
  ck_assert_str_eq(r, strtok(s1, s2));
}
END_TEST

START_TEST(s21_strtok_4) {
  char s1[] = "abbabba\0";
  char s2[] = "bb\0";
  char *r = s21_strtok(s1, s2);
  ck_assert_str_eq(r, strtok(s1, s2));
}
END_TEST

START_TEST(s21_strtok_5) {
  char s1[] = "Hello\0";
  char s2[] = "Hello\0";
  char *r = s21_strtok(s1, s2);
  ck_assert_ptr_null(r);
}
END_TEST

START_TEST(s21_strtok_6) {
  char s1[] = "++++++++";
  char s2[] = "++++++++";
  const char delims[] = "+_! =";

  char *got = s21_strtok(s1, delims);
  char *expected = strtok(s2, delims);

  ck_assert_ptr_null(got);
  ck_assert_ptr_null(expected);
}
END_TEST

START_TEST(s21_strtok_7) {
  char s1[] = "Aboba_Floppa_Roba";
  char s2[] = "Aboba_Floppa_Roba";
  const char delims[] = "+_! =";

  char *got = s21_strtok(s1, delims);
  char *expected = strtok(s2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  int i = 5;
  while (i) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);
    i--;

    ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(s21_strtok_8) {
  char s1[] = "Roba++++Kepa++A++++B__V";
  char s2[] = "Roba++++Kepa++A++++B__V";
  const char delims[] = "+_! =";

  char *got = s21_strtok(s1, delims);
  char *expected = strtok(s2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got && expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(s21_strtok_9) {
  char s1[] = "Aboba__+Floppa_  Roba";
  char s2[] = "Aboba__+Floppa_  Roba";
  const char delims[] = "+_! =";

  char *got = s21_strtok(s1, delims);
  char *expected = strtok(s2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got && expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(s21_strtok_10) {
  char s1[] = "Aboba__Floppa_+++Roba_Kepa";
  char s2[] = "Aboba__Floppa_+++Roba_Kepa";
  const char delims[] = "+_! =";

  char *got = s21_strtok(s1, delims);
  char *expected = strtok(s2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got && expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(s21_strtok_11) {
  char s1[] = "     Aboba__+ Flo!ppa_   Roba+";
  char s2[] = "     Aboba__+ Flo!ppa_   Roba+";
  const char delims[] = "+_! =";

  char *got = s21_strtok(s1, delims);
  char *expected = strtok(s2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got || expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(s21_strtok_12) {
  char s1[] = "!Stepa__ !M!ish a____Anton+An!!!drey";
  char s2[] = "!Stepa__ !M!ish a____Anton+An!!!drey";
  const char delims[] = "+_! =";

  char *got = s21_strtok(s1, delims);
  char *expected = strtok(s2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got || expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(s21_strtok_13) {
  char s1[] = "!       A!B!C!D!E!!F!!G";
  char s2[] = "!       A!B!C!D!E!!F!!G";
  const char delims[] = "+_! =";

  char *got = s21_strtok(s1, delims);
  char *expected = strtok(s2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got || expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    if (got || expected) {
      ck_assert_str_eq(got, expected);
      ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(s21_strtok_14) {
  char s1[] = "Aboba+Anuroba_Floppa!Kotya_Kekus";
  char s2[] = "Aboba+Anuroba_Floppa!Kotya_Kekus";
  const char delims[] = "+_! =";

  char *got = s21_strtok(s1, delims);
  char *expected = strtok(s2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got && expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(s21_strtok_15) {
  char s1[] = "++Aboba++Floppa_! Kotya===!Shleppa+++ A +";
  char s2[] = "++Aboba++Floppa_! Kotya===!Shleppa+++ A +";
  const char delims[] = "+_! =";

  char *got = s21_strtok(s1, delims);
  char *expected = strtok(s2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got && expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(s21_strtok_16) {
  char s21_test_str[30] = "one/two.three?four";
  char lib_test_str[30] = "one/two.three?four";
  char *step = "./?";
  char *s21_result = s21_strtok(s21_test_str, step);
  char *lib_result = strtok(lib_test_str, step);

  while (s21_result != S21_NULL && lib_result != S21_NULL) {
    ck_assert_str_eq(s21_result, lib_result);
    s21_result = s21_strtok(S21_NULL, step);
    lib_result = strtok(S21_NULL, step);
  }
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strtok_17) {
  char s21_test_str[30] = "one/two.three?four";
  char lib_test_str[30] = "one/two.three?four";
  char *step = "$()-";
  char *s21_result = s21_strtok(s21_test_str, step);
  char *lib_result = strtok(lib_test_str, step);

  while (s21_result != S21_NULL && lib_result != S21_NULL) {
    ck_assert_str_eq(s21_result, lib_result);
    s21_result = s21_strtok(S21_NULL, step);
    lib_result = strtok(S21_NULL, step);
  }
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strtok_18) {
  char s21_test_str[30] = "";
  char lib_test_str[30] = "";
  char *step = "$()-";
  char *s21_result = s21_strtok(s21_test_str, step);
  char *lib_result = strtok(lib_test_str, step);

  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

Suite *strtok_suite(void) {
  Suite *s21_string = suite_create("s21_strtok_test");
  TCase *tc_core = tcase_create("core");

  tcase_add_test(tc_core, s21_strtok_1);
  tcase_add_test(tc_core, s21_strtok_2);
  tcase_add_test(tc_core, s21_strtok_3);
  tcase_add_test(tc_core, s21_strtok_4);
  tcase_add_test(tc_core, s21_strtok_5);
  tcase_add_test(tc_core, s21_strtok_6);
  tcase_add_test(tc_core, s21_strtok_7);
  tcase_add_test(tc_core, s21_strtok_8);
  tcase_add_test(tc_core, s21_strtok_9);
  tcase_add_test(tc_core, s21_strtok_10);
  tcase_add_test(tc_core, s21_strtok_11);
  tcase_add_test(tc_core, s21_strtok_12);
  tcase_add_test(tc_core, s21_strtok_13);
  tcase_add_test(tc_core, s21_strtok_14);
  tcase_add_test(tc_core, s21_strtok_15);
  tcase_add_test(tc_core, s21_strtok_16);
  tcase_add_test(tc_core, s21_strtok_17);
  tcase_add_test(tc_core, s21_strtok_18);
  suite_add_tcase(s21_string, tc_core);
  return s21_string;
}