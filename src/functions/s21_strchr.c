#include "../s21_string.h"
/**
 * @brief Поиск первого вхождения символа в строке
 * @param str Указатель на строку, в которой осуществляется поиск
 * @param c Искомый символ, поиск которого осуществляется в строке	'str'
 * @return Указатель на первое вхождение символа 'c' в строке 'str'. В случае,
 * если символ 'c' не найден в строке, возвращается NULL
 */
char *s21_strchr(const char *str, int c) {
  char *result = S21_NULL;

  if (str != S21_NULL) {
    while (*str != '\0') {
      if (*str == c) {
        result = (char *)str;
        break;
      }
      str++;
    }
    if (c == '\0') {
      result = (char *)str;
    }
  }
  return result;
}