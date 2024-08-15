#include "../s21_string.h"

char *s21_strcat(char *dest, const char *src) {
  char *result = S21_NULL;

  if (dest != S21_NULL && src != S21_NULL) {
    char *d = dest;
    const char *s = src;
    while (*d != '\0') {
      d++;
    }
    while (*s != '\0') {
      *d++ = *s++;
    }
    *d = '\0';
    result = dest;
  }
  return result;
}