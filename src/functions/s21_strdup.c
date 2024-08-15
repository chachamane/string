#include "../s21_string.h"
/**
 * @brief Создает новую строку, являющуюся копией указанной строки
 * @param str Указатель на строку, которую необходимо скопировать
 * @return Указатель на новую строку, которая является копией str, или NULL,
 * если str равен NULL или произошла ошибка при выделении памяти
 */
char *s21_strdup(const char *str) {
  char *arr = S21_NULL;

  if (str) {
    s21_size_t len = s21_strlen(str);
    arr = (char *)malloc(len + 1);
    if (arr) {
      s21_strcpy(arr, str);
    }
  }
  return arr;
}
