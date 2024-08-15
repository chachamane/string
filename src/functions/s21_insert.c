#include "../s21_string.h"
/**
 * @brief Вставляет строку str в другую строку src на указанной позиции
 * start_index
 * @param src Указатель на исходную строку, в которую будет вставлена строка
 * str
 * @param str Указатель на строку для вставки
 * @param start_index Индекс в строке src, начиная с которого будет произведена
 * вставка строки str
 * @return Указатель на новую строку с результатом вставки или NULL в случае
 * ошибки. Память для новой строки выделена динамически и должна быть
 * освобождена с помощью free()
 */
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *arr = S21_NULL;

  if (src != S21_NULL && str != S21_NULL) {
    s21_size_t src_len = s21_strlen(src);
    s21_size_t str_len = s21_strlen(str);

    if (src_len == 0 && start_index > 0) {
      return S21_NULL;
    }

    if (start_index <= src_len) {
      arr = (char *)malloc(sizeof(char) * (src_len + str_len + 1));
      if (arr) {
        // Копируем начальную часть src в arr
        s21_strncpy(arr, src, start_index);
        // Копируем str в arr, начиная с позиции start_index
        s21_strcpy(arr + start_index, str);
        // Копируем оставшуюся часть src после str в arr
        s21_strcpy(arr + start_index + str_len, src + start_index);
      }
    } else if (src_len == 0 && str_len == 0) {
      // Если обе строки пустые, делаем копию пустой строки
      arr = s21_strdup(src);
    }
  }
  return arr;
}