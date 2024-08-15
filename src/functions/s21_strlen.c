#include "../s21_string.h"
/**
 * @brief Вычисляет длину строки
 * @param str Указатель на строку, длину которой требуется вычислить
 * @return Количество символов в строке до первого нуль-терминатора. В случае,
 * если 'str' равен NULL, возвращается 0
 */
s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;

  if (str != S21_NULL) {
    while (str[len]) len++;
  }
  return len;
}