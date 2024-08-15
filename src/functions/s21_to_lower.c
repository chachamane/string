#include "../s21_string.h"
/**
 * @brief Преобразует строку в нижний регистр
 * @param str Исходная строка для преобразования
 * @return Указатель на новую строку в нижнем регистре. Память для новой строки
 * выделена динамически и должна быть освобождена с помощью free()
 */
void *s21_to_lower(const char *str) {
  char *arr = S21_NULL;

  if (str != S21_NULL) {
    s21_size_t len = s21_strlen(str);
    arr = (char *)malloc(sizeof(char) * (len + 1));
    if (arr) {
      for (s21_size_t i = 0; i <= len; i++) {
        arr[i] =
            (str[i] >= 'A' && str[i] <= 'Z') ? str[i] + ('a' - 'A') : str[i];
      }
      arr[len] = '\0';
    }
  }
  return arr;
}