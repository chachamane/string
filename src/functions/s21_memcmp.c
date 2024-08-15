#include "../s21_string.h"
/**
 * @brief Сравнение двух блоков памяти
 * @param str1 Указатель на первый блок памяти для сравнения
 * @param str2 Указатель на второй блок памяти для сравнения
 * @param n Количество байтов для сравнения
 * @return Результат сравнения в виде целого числа:
        0, если блоки памяти идентичны;
        положительное число, если первый несовпадающий байт в 'str1' больше
соответствующего байта в 'str2';
        отрицательное число, если первый несовпадающий
байт в 'str1' меньше соответствующего байта в 'str2'
 */
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;

  if (str1 != S21_NULL && str2 != S21_NULL) {
    unsigned char *s1 = (unsigned char *)str1;
    unsigned char *s2 = (unsigned char *)str2;
    for (; n != 0; n--, s1++, s2++) {
      if (*s1 != *s2) {
        result = *s1 - *s2;
        break;
      }
    }
  }
  return result;
}