#include "../s21_string.h"
/**
 * @brief Заполнение блока памяти постоянным байтом
 * @param str Указатель на блок памяти, который нужно заполнить
 * @param c Значение для заполнения, преобразованное в 'unsigned char'
 * @param n Количество байтов для заполнения
 * @return Указатель на заполненный блок памяти 'str'. Если 'str' равен NULL,
 * возвращается NULL без изменения памяти
 */
void *s21_memset(void *str, int c, s21_size_t n) {
  if (str != S21_NULL) {
    unsigned char *s = (unsigned char *)str;
    for (; n != 0; n--, s++) {
      *s = (unsigned char)c;
    }
  }
  return str;
}