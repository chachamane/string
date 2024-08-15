#include "../s21_string.h"
/**
 * @brief Вычисляет длину начального сегмента строки str1, состоящего только из
 * символов, содержащихся в строке str2
 * @param str1 Указатель на строку, в которой осуществляется поиск
 * @param str2 Указатель на строку, содержащую набор символов, которые
 * используются для сравнения
 * @return s21_size_t - количество символов начального сегмента строки str1,
 * состоящего только из символов, встречающихся в str2
 */
s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t result = 0;

  for (const char *s = str1; *s != '\0'; s++) {
    if (s21_strchr(str2, *s) == S21_NULL) {
      break;
    }
    result++;
  }
  return result;
}