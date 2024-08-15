#include "../s21_string.h"
/**
 * @brief Копирует строку, указанную src, в массив, указанный dest
 * @param dest Указатель на массив, куда будет скопирована строка
 * @param src Указатель на строку, которая будет скопирована
 * @param n Максимальное количество символов для копирования
 * @return Указатель на массив 'dest'
 */
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *start = dest;

  if (dest != S21_NULL && src != S21_NULL) {
    s21_size_t i = 0;
    for (; i < n && *src != '\0'; i++, src++, dest++) {
      *dest = *src;
    }
    for (; i < n; i++, dest++) {
      *dest = '\0';
    }
  }
  return start;
}
