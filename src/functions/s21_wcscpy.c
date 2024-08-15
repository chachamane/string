#include "../s21_string.h"
/**
 * @brief Копирует строку wchar_t, на которую указывает src (включая нулевой
 * символ), в массив, на который указывает dest
 * @param dest Указатель на массив wchar_t, в который будет скопирована строка
 * @param src Указатель на строку wchar_t, которая будет скопирована
 * @return Возвращает указатель на массив dest, в который скопирована строка
 */
wchar_t* s21_wcscpy(wchar_t* dest, const wchar_t* src) {
  wchar_t* ptr = dest;
  while (*src != L'\0') {
    *dest = *src;
    dest++;
    src++;
  }
  *dest = L'\0';
  return ptr;
}