#include "../s21_string.h"
/**
 * @brief Находит первое вхождение любого из символов второй строки в первой
 * строке
 * @param str1 Указатель на строку, в которой осуществляется поиск
 * @param str2 Указатель на строку, содержащую символы для поиска в 'str1'
 * @return Указатель на первое вхождение одного из символов 'str2' в 'str1', или
 * NULL, если ни один из символов не найден. В случае, если 'str1' или 'str2'
 * равны NULL, возвращается NULL
 */
char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = S21_NULL;

  if (str1 != S21_NULL && str2 != S21_NULL) {
    while (*str1 != '\0') {
      if (s21_strchr(str2, *str1) != S21_NULL) {
        result = (char *)str1;
        break;
      }
      str1++;
    }
  }
  return result;
}