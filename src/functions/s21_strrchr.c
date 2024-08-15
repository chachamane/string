#include "../s21_string.h"
/**
 * @brief Находит последнее вхождение символа в строке
 * @param str Указатель на строку, в которой осуществляется поиск
 * @param c Искомый символ. Может быть представлен как char, но передается как
 * int
 * @return Указатель на последнее вхождение символа 'c' в строке 'str' или NULL,
 * если символ не найден. В случае, если 'str' равен NULL, возвращается NULL
 */
char *s21_strrchr(const char *str, int c) {
  char *result = S21_NULL;

  if (str != S21_NULL) {
    do {
      if (*str == c) {
        result = (char *)str;
      }
    } while (*str++);
  }
  return result;
}