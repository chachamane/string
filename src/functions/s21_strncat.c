#include "../s21_string.h"
/**
 * @brief Конкатенирует строки с ограничением по длине
 * @param dest Указатель на строку назначения, к которой добавляется 'src'
 * @param src Указатель на строку источника, из которой копируются символы
 * @param n Максимальное количество символов для добавления из 'src'
 * @return Указатель на результирующую строку 'dest'. Если 'dest' или 'src'
 * равны NULL, возвращается NULL
 */
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *result = dest;

  if (dest != S21_NULL && src != S21_NULL) {
    while (*dest != '\0') {
      dest++;
    }
    while (n != 0 && *src != '\0') {
      *dest++ = *src++;
      n--;
    }
    *dest = '\0';
  }
  return result;
}