#include "../s21_string.h"
/**
 * @brief Копирует строку, на которую указывает src, в буфер, на который
 * указывает dest
 * @param dest Указатель на буфер, в который будет скопирована строка
 * @param src Указатель на строку для копирования
 * @return Возвращает указатель на начало строки dest. Если один из указателей
 * равен NULL, копирование не производится, и функция возвращает исходное
 * значение указателя dest
 */
char *s21_strcpy(char *dest, const char *src) {
  char *dest_start = dest;

  if (dest != S21_NULL || src != S21_NULL) {
    while (*src) {
      *dest++ = *src++;
    }
    *dest = '\0';
  }
  return dest_start;
}