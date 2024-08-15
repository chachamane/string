#include "../s21_string.h"
/**
 * @brief Копирование блока памяти
 * @param dest Указатель на область памяти, куда будут скопированы данные
 * @param src Указатель на область памяти, откуда копируются данные
 * @param n Количество байтов для копирования
 * @return Указатель на область памяти 'dest'. В случае, если 'dest' или 'src'
 * равны NULL, возвращается NULL
 */
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  void *result = S21_NULL;

  if (dest != S21_NULL && src != S21_NULL) {
    unsigned char *d = (unsigned char *)dest;
    unsigned char *s = (unsigned char *)src;
    for (; n != 0; n--, d++, s++) {
      *d = *s;
    }
    result = dest;
  }
  return result;
}