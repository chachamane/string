#include "../s21_string.h"
/**
 * @brief Разделяет строку на токены на основе заданных разделителей
 * @param str Указатель на строку для разделения на первом вызове или NULL для
 * последующих вызовов
 * @param delim Указатель на строку, содержащую разделители
 * @return Указатель на следующий токен или NULL, если токенов больше нет
 */
char *s21_strtok(char *str, const char *delim) {
  static char *last = S21_NULL;
  char *result = S21_NULL;

  if (str != S21_NULL) {
    last = str;
  }

  if (last != S21_NULL) {
    last += s21_strspn(last, delim);

    if (*last != '\0') {
      result = last;

      char *end = last + s21_strcspn(last, delim);
      if (*end != '\0') {
        *end = '\0';
        last = end + 1;
      } else {
        last = S21_NULL;
      }
    }
  }

  return result;
}