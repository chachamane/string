#include "../s21_string.h"
/**
 * @brief Возвращает строку, описывающую ошибку, соответствующую номеру ошибки
 * @param errnum Числовой код ошибки, для которой требуется получить описание
 * @return Указатель на строку, описывающую ошибку. В случае, если 'errnum'
 * находится вне допустимого диапазона, возвращается NULL
 */

char *s21_strerror(int errnum) {
  static char result[BUFF_SIZE] = {'\0'};

  if (errnum < 0 || errnum >= S21_ERRSIZE)
    s21_sprintf(result, "Unknown error: %d", errnum);
  else
    s21_strcpy(result, s21_errlist[errnum]);

  return result;
}