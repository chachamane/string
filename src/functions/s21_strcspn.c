#include "../s21_string.h"
/**
 * @brief Определяет длину начального сегмента строки 'str1', который не
 * содержит символов из строки 'str2'
 * @param str1 Указатель на строку, в которой осуществляется поиск начального
 * сегмента
 * @param str2 Указатель на строку, символы которой используются для сравнения
 * @return Количество символов начального сегмента строки 'str1', не содержащего
 * символы из 'str2'. В случае, если 'str1' или 'str2' равны NULL, возвращается
 * 0
 */
s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t result = 0;

  if (str1 != S21_NULL && str2 != S21_NULL) {
    for (; *str1 != '\0'; str1++) {
      if (s21_strchr(str2, *str1) != S21_NULL) {
        break;
      }
      result++;
    }
  }
  return result;
}