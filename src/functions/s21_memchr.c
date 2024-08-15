#include "../s21_string.h"
/**
 * @brief Поиск первого вхождения символа в блоке памяти
 * @param str Указатель на блок памяти, в котором производится поиск
 * @param c Символ, который ищется в блоке памяти. Приводится к типу unsigned
 * char
 * @param n Количество первых байтов в блоке памяти, в рамках которых
 * осуществляется поиск
 * @return Указатель на первое вхождение искомого символа в блоке памяти, или
 * NULL, если символ в заданном блоке не найден
 */
void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *result = S21_NULL;

  if (str != S21_NULL) {
    unsigned char *s = (unsigned char *)str;
    for (; n != 0; n--, s++) {
      if (*s == (unsigned char)c) {
        result = s;
        break;
      }
    }
  }
  return result;
}