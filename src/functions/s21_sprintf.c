#include "../s21_string.h"
/**
 * @brief Функция s21_sprintf форматирует данные и записывает их в строку
 * @param str Указатель на строку, в которую будут записаны отформатированные
 * данные
 * @param format Строка формата, которая определяет необходимый способ
 * форматирования данных
 * @param ... Переменное количество аргументов, представляющих данные для
 * форматирования
 * @return Возвращает количество символов, записанных в строку, за
 исключением
 * завершающего нулевого символа
 */
int s21_sprintf(char *str, const char *format, ...) {
  va_list arg_ptr = {0};
  va_start(arg_ptr, format);
  SP_FLAGS params = {0};
  s21_size_t i = 0;
  str = s21_strcpy(str, "");

  while (*format) {
    params.precision = -1;
    params.plus_flag = params.minus_flag = params.space_flag =
        params.zero_flag = params.sharp_flag = params.width = params.dot =
            params.spec = params.length = 0;
    switch (*format) {
      case '%':
        format++;
        if (is_flag(*format)) {
          while (is_flag(*format)) {
            check_flags(&params, format++);
          }
        }
        if (is_dec(*format) || *format == '*') {
          format = char_to_int(&params.width, format++, &arg_ptr);
          if (params.width < 0) {
            params.minus_flag = 1;
            params.width *= -1;
          }
        }
        if (*format == '.') {
          params.dot = 1;
          params.precision = 0;
          format++;
          if (is_dec(*format) || *format == '*') {
            format = char_to_int(&params.precision, format++, &arg_ptr);
          } else {
            params.precision = -1;
          }
        }
        if (is_len(*format)) {
          while (is_len(*format)) {
            params.length = *(format++);
          }
        }
        if (is_spec(*format)) {
          params.spec = *(format++);
        }
        init_default_precision(&params);
        str = check_specs(str, &i, &arg_ptr, &params);
        break;
      default:
        str[i++] = *(format++);
        str[i] = '\0';
        break;
    }
  }
  va_end(arg_ptr);
  return (int)s21_strlen(str);
}

/**
 * @brief Инициализирует значение по умолчанию для точности (precision) в
 * структуре SP_FLAGS
 * @param params Указатель на структуру SP_FLAGS, содержащую параметры
 * форматирования.
 */
void init_default_precision(SP_FLAGS *params) {
  if (params->dot && params->precision <= 0) {
    params->precision = 0;
  }
  if (!params->dot && s21_strchr("eEfgG", params->spec)) {
    params->precision = 6;
  }
}

/**
 * @brief Проверяет и устанавливает флаги форматирования в структуре SP_FLAGS
 * @param params Указатель на структуру SP_FLAGS, в которой будут установлены
 флаги
 * @param format Строка формата, содержащая символы для анализа и установки
 * флагов
 */
void check_flags(SP_FLAGS *params, const char *format) {
  switch (*format) {
    case '-':
      params->minus_flag = 1;
      break;
    case '+':
      params->plus_flag = 1;
      break;
    case ' ':
      params->space_flag = 1;
      break;
    case '#':
      params->sharp_flag = 1;
      break;
    case '0':
      params->zero_flag = 1;
      break;
  }
}

/**
 * @brief Проверяет спецификаторы формата и вызывает соответствующие
 * обработчики. Результат обработки записывается во временную строку tmp,
 * которая затем добавляется к исходной строке str. После выполнения всех
 * обработок, функция освобождает память, выделенную для tmp, и обновляет
 длину
 * исходной строки str
 * @param str Указатель на исходную строку, к которой будут добавлены
 * результаты
 * @param str_len Указатель на переменную для хранения длины исходной строки
 * str
 * @param arg_ptr Указатель на список аргументов функции
 * @param params Указатель на структуру SP_FLAGS с параметрами форматирования
 * @return Указатель на исходную строку str с добавленными результатами
 */
char *check_specs(char *str, s21_size_t *str_len, va_list *arg_ptr,
                  SP_FLAGS *params) {
  char *tmp = S21_NULL;
  tmp = calloc(BUFF_SIZE, sizeof(char));
  if (tmp != S21_NULL) {
    switch (params->spec) {
      case 'c':
        c_handler(tmp, arg_ptr, params);
        break;
      case 'd':
      case 'i':
        di_handler(tmp, arg_ptr, params);
        break;
      case 'e':
      case 'E':
        eE_handler(tmp, arg_ptr, params);
        break;
      case 'f':
        f_handler(tmp, arg_ptr, params);
        break;
      case 'g':
      case 'G':
        gG_handler(tmp, arg_ptr, params);
        break;
      case 'n':
        n_handler(str_len, arg_ptr);
        break;
      case 'o':
        o_handler(tmp, arg_ptr, params);
        break;
      case 'p':
        p_handler(tmp, arg_ptr, params);
        break;
      case 's':
        s_handler(tmp, arg_ptr, params);
        break;
      case 'u':
        u_handler(tmp, arg_ptr, params);
        break;
      case 'x':
      case 'X':
        xX_handler(tmp, arg_ptr, params);
        break;
      case '%':
        percentage_handler(tmp, params);
        break;
    }
    s21_strcat(str, tmp);
    free(tmp);
    *str_len = s21_strlen(str);
  }
  return str;
}

/**
 * @brief Сдвигает все символы в строке str на одну позицию вправо.
 * Функция перемещает все символы в строке str на одну позицию вправо,
 * включая завершающий нулевой символ '\0'
 * @param str Указатель на строку, которую необходимо сдвинуть вправо
 */
void move_right_str(char *str) {
  int len = (int)s21_strlen(str);

  str[len + 1] = '\0';
  while (len > 0) {
    str[len] = str[len - 1];
    len--;
  }
}

/**
 * @brief Обрабатывает флаги форматирования в строке
 * @param params Указатель на структуру SP_FLAGS, содержащую параметры
 * форматирования
 * @param str Указатель на строку, в которой будут обрабатываться флаги
 * форматирования
 */
void input_str_flags_handler(SP_FLAGS *params, char *str) {
  int position = 0;

  if (!s21_strchr("cuo\%", params->spec)) {
    if (params->spec != 'x' && params->spec != 'X') {
      if (params->sign < 0) {
        move_right_str(str);
        str[position++] = '-';
        params->sign = 0;
      }
      if (params->plus_flag && params->sign != 0) {
        move_right_str(str);
        str[position] = (params->sign > 0) ? '+' : '-';
        params->sign = 0;
      }
      if (params->space_flag && params->sign != 0) {
        move_right_str(str);
        str[position] = (params->sign > 0) ? ' ' : '-';
        params->sign = 0;
      }
    }
    if (params->sharp_flag) {
      sharp_flag_handler(params, str);
    }
  }
  if (params->minus_flag) {
    position = (int)s21_strlen(str);
    while (position < params->width) {
      str[position++] = ' ';
    }
  }
}

/**
 * @brief Обрабатывает флаг '#' форматирования в строке
 * @param params Указатель на структуру SP_FLAGS, содержащую параметры
 * форматирования
 * @param str Указатель на строку, в которой будет обрабатываться флаг '#'
 */
void sharp_flag_handler(SP_FLAGS *params, char *str) {
  int position = 0;

  if (s21_strchr("oxX", params->spec)) {
    if (params->spec == 'x' || params->spec == 'X') {
      move_right_str(str);
    }
    params->spec == 'o' ? 1 : move_right_str(str);
    str[position++] = '0';
    if (params->spec != 'o') str[position] = params->spec == 'x' ? 'x' : 'X';
  }
  if (s21_strchr("eEf", params->spec)) {
    if (!s21_strchr(str, '.')) {
      str[s21_strlen(str)] = '.';
    }
  }
}

/**
 * @brief Обрабатывает ширину поля форматирования в строке
 * @param params Указатель на структуру SP_FLAGS, содержащую параметры
 * форматирования
 * @param str Указатель на строку, в которой будет обрабатываться ширина поля
 */
void input_str_width_handler(SP_FLAGS *params, char *str) {
  int str_len = (int)s21_strlen(str);

  if (params->width > str_len) {
    str[params->width + 1] = '\0';
    while (str_len >= 0) {
      str[params->width--] = str[str_len--];
    }
    for (str_len = 0; str_len <= params->width; str_len++) {
      if (s21_strchr("diopuxX", params->spec)) {
        str[str_len] = (params->zero_flag && !params->dot) ? '0' : ' ';
      }
      if (s21_strchr("feEgGcs", params->spec)) {
        str[str_len] = (params->zero_flag) ? '0' : ' ';
      }
    }
  }
}

/**
 * @brief Обрабатывает точность (precision) форматирования в строке
 * @param params Указатель на структуру SP_FLAGS, содержащую параметры
 * форматирования
 * @param str Указатель на строку, в которой будет обрабатываться точность
 */
void input_str_precision_handler(SP_FLAGS *params, char *str) {
  char *precision_str = S21_NULL;
  precision_str = calloc(BUFF_SIZE, sizeof(char));
  int position = 0;

  if (precision_str != S21_NULL) {
    if (s21_strchr("diouxX", params->spec)) {
      while (position < params->precision - (int)s21_strlen(str)) {
        precision_str[position++] = '0';
      }
      for (int i = 0; str[i] != '\0'; i++) {
        precision_str[position++] = str[i];
      }
      s21_strcpy(str, precision_str);
    }
    free(precision_str);
  }
}

/**
 * @brief Округляет число с заданной точностью и проверяет, изменилась ли
 * длина строки
 * @param params Указатель на структуру SP_FLAGS с параметрами форматирования
 * @param number Число типа long double, которое нужно округлить и проверить
 * @return 1, если длина строки изменилась после округления, и 0 в противном
 * случае
 */
int round_handler(SP_FLAGS *params, long double number) {
  char str[128] = {'\0'};
  int len = 0, result = 0;

  number *= pow(10, params->precision);
  int_to_char(params, str, number);
  len = s21_strlen(str);
  number = roundl(number);
  int_to_char(params, str, number);
  if (len < (int)s21_strlen(str)) {
    result = 1;
  }
  return result;
}

/**
 * @brief Удаляет незначащие нули из строки числа с плавающей точкой. Если
 * параметры форматирования задают флаг sharp_flag и точность больше 0, то
 * нули оставляются после точки до указанной точности. Если sharp_flag не
 * установлен, и последний символ строки - точка, она также удаляется
 * @param params Указатель на структуру SP_FLAGS с параметрами форматирования
 * @param str Указатель на строку, из которой нужно удалить незначащие нули
 */
void del_insignificant_zeros(SP_FLAGS *params, char *str) {
  int len = (int)s21_strlen(str) - 1;

  if (len > 0) {
    while (str[len] == '0') {
      if (!params->sharp_flag ||
          (params->sharp_flag && len > params->precision)) {
        str[len] = '\0';
        len -= 1;
      }
    }
    if (!params->sharp_flag && str[len] == '.') {
      str[len] = '\0';
    }
  }
}

/**
 * @brief Обрабатывает добавление мантиссы в строку форматирования числа в
 * научной нотации. В зависимости от параметров форматирования, она
 * также может добавить десятичную точку и знак экспоненты (+ или -) в начало
 * мантиссы
 * @param params Указатель на структуру SP_FLAGS с параметрами форматирования
 * @param mantissa Указатель на строку, в которую будет добавлена мантисса
 * @param order Экспонента (порядок) числа в научной нотации
 */
void add_mantissa(SP_FLAGS *params, char *mantissa, int order) {
  int str_start = 0;

  if (params->sharp_flag && params->precision <= 0) {
    mantissa[str_start++] = '.';
  }
  mantissa[str_start++] = s21_strchr("eg", params->spec) ? 'e' : 'E';
  mantissa[str_start++] = (order >= 0) ? '+' : '-';
  if (abs(order) < 10) {
    mantissa[str_start++] = '0';
    int_to_char(params, &mantissa[str_start], abs(order));
  } else {
    int_to_char(params, &mantissa[str_start], abs(order));
  }
}

/**
 * @brief Преобразует wchar_t строку (широкие символы) в обычную строку char
 * @param buf Указатель на буфер, в который будет сохранен результат
 * @param tmp Указатель на исходную wchar_t строку для преобразования
 * @param buf_len Максимальное количество символов для преобразования
 */
void wchart_to_string(char *buf, wchar_t *tmp, s21_size_t buf_len) {
  s21_size_t str_len = s21_strlen(buf);
  char *ptr = buf + str_len;
  int sym_count = buf_len;

  while (*tmp != '\0' && (buf_len == 0 || sym_count-- > 0)) {
    *(ptr++) = (char)*(tmp++);
  }
  *ptr = '\0';
}

/**
 * @brief Разворачивает строку задом наперед, для обработки числовых
 значений,
 * преобразованных в строки, так как числа обычно формируются с конца
 (начиная
 * с младших разрядов) и потом требуется их перевернуть для корректного
 * отображения
 * @param str Указатель на строку, которую нужно развернуть
 */
void reverse_str(char *str) {
  s21_size_t len = s21_strlen(str);
  char ch = 0;

  for (s21_size_t i = 0; i < len / 2; i++) {
    ch = str[i];
    str[i] = str[len - 1 - i];
    str[len - 1 - i] = ch;
  }
}

/**
 * @brief Обрабатывает спецификатор формата 'c'
 * @param str Указатель на строку, в которую будет вставлен результат
 * обработки
 * @param arg_ptr Указатель на список аргументов переменной длины
 * @param params Указатель на структуру flags, содержащую параметры
 * форматирования
 */
void c_handler(char *str, va_list *arg_ptr, SP_FLAGS *params) {
  wchar_t wch = 0;
  wchar_t wch_arr[10] = {0};

  switch (params->length) {
    case 'l':
      wch = va_arg(*arg_ptr, wchar_t);
      wch_arr[0] = wch;
      wchart_to_string(str, wch_arr, 0);
      break;
    default:
      str[0] = va_arg(*arg_ptr, int);
      str[1] = '\0';
      break;
  }
  input_str_flags_handler(params, str);
  input_str_width_handler(params, str);
}

/**
 * @brief Обрабатывает спецификаторы формата 'd' и 'i'
 * @param str Указатель на строку, в которую будет вставлен результат
 * обработки
 * @param arg_ptr Указатель на список аргументов переменной длины
 * @param params Указатель на структуру flags, содержащую параметры
 * форматирования
 */
void di_handler(char *str, va_list *arg_ptr, SP_FLAGS *params) {
  short int sh_int = 0;
  long int l_int = 0;
  int int_num = 0;

  switch (params->length) {
    case 'h':
      sh_int = (short int)va_arg(*arg_ptr, int);
      int_to_char(params, str, sh_int);
      break;
    case 'l':
      l_int = (long int)va_arg(*arg_ptr, long int);
      int_to_char(params, str, l_int);
      break;
    default:
      int_num = va_arg(*arg_ptr, int);
      int_to_char(params, str, int_num);
      break;
  }
  input_str_precision_handler(params, str);
  input_str_flags_handler(params, str);
  input_str_width_handler(params, str);
}

/**
 * @brief Обрабатывает аргументы для форматирования чисел с плавающей точкой
 и
 * записывает результат в строку
 * @param str Указатель на строку, в которую будет записан результат
 * форматирования
 * @param arg_ptr Указатель на список аргументов, содержащий значение для
 * форматирования
 * @param params Указатель на структуру flags, содержащую параметры
 * форматирования
 */
void f_handler(char *str, va_list *arg_ptr, SP_FLAGS *params) {
  long double ld_num = 0;
  double d_num = 0;

  switch (params->length) {
    case 'L':
      ld_num = va_arg(*arg_ptr, long double);
      float_to_char(str, ld_num, params);
      break;
    case 'l':
    default:
      d_num = va_arg(*arg_ptr, double);
      float_to_char(str, d_num, params);
      break;
  }
  input_str_flags_handler(params, str);
  input_str_width_handler(params, str);
}

/**
 * @brief Обработка аргумента типа строка 's' для форматированного вывода
 * @param str Указатель на выходную строку, в которую будет добавлен
 результат
 * @param arg_ptr Указатель на список аргументов функции, содержащий аргумент
 * типа строка
 * @param params Указатель на структуру SP_FLAGS, содержащую параметры
 * форматирования
 */
void s_handler(char *str, va_list *arg_ptr, SP_FLAGS *params) {
  char *arg_str = S21_NULL;
  arg_str = va_arg(*arg_ptr, char *);

  if (params->precision > -1) {
    s21_strncat(str, arg_str, params->precision);
  } else {
    s21_strcat(str, arg_str);
  }
  input_str_precision_handler(params, str);
  input_str_flags_handler(params, str);
  input_str_width_handler(params, str);
}

/**
 * @brief Преобразование беззнакового целого числа в строку
 * @param params Указатель на структуру SP_FLAGS, содержащую параметры
 * форматирования
 * @param str Указатель на выходную строку, в которую будет записан результат
 * @param arg_ptr Указатель на список аргументов функции
 */
void u_handler(char *str, va_list *arg_ptr, SP_FLAGS *params) {
  unsigned short us_num = 0;
  unsigned long ul_num = 0;
  unsigned int ui_num = 0;

  switch (params->length) {
    case 'h':
      us_num = (unsigned short)va_arg(*arg_ptr, unsigned int);
      unslong_to_char(params, str, us_num);
      break;
    case 'l':
      ul_num = (unsigned long)va_arg(*arg_ptr, unsigned long);
      unslong_to_char(params, str, ul_num);
      break;
    default:
      ui_num = (unsigned int)va_arg(*arg_ptr, unsigned int);
      unslong_to_char(params, str, ui_num);
      break;
  }
  input_str_precision_handler(params, str);
  input_str_flags_handler(params, str);
  input_str_width_handler(params, str);
}

/**
 * @brief Обработчик символа процента '%' для форматирования
 * @param str Указатель на выходную строку, в которую будет добавлен символ
 * процента
 * @param params Указатель на структуру SP_FLAGS, содержащую параметры
 * форматирования
 */
void percentage_handler(char *str, SP_FLAGS *params) {
  s21_strcat(str, "%");
  input_str_precision_handler(params, str);
  input_str_flags_handler(params, str);
  input_str_width_handler(params, str);
}

void n_handler(s21_size_t const *str_len, va_list *arg_ptr) {
  int *ptr = va_arg(*arg_ptr, int *);
  *ptr = (int)*str_len;
}
/**
 * @brief Обработчик указателя для форматирования
 * @param str Указатель на выходную строку, в которую будет записан результат
 * форматирования
 * @param arg_ptr Указатель на список аргументов, содержащий указатель для
 * форматирования
 * @param params Указатель на структуру SP_FLAGS, содержащую параметры
 * форматирования
 */
void p_handler(char *str, va_list *arg_ptr, SP_FLAGS *params) {
  int width = params->width < 15 ? 15 : params->width;
  char *str_start = S21_NULL;
  str_start = str;
  int *ptr = va_arg(*arg_ptr, int *);
  char buf[4] = "x0";

  if (ptr == S21_NULL) {
    s21_strcpy(buf, "0x0");
  }
  for (int *i = ptr, j = 0; i && j < width;
       i = (void *)(((s21_size_t)i) >> 4), j++) {
    unsigned int digit = ((s21_size_t)i) % 0x10;
    if (digit < 10)
      *(str_start++) = (char)('0' + digit);
    else
      *(str_start++) = (char)('a' + (digit - 10));
  }
  *str_start = '\0';
  s21_strcat(str, buf);
  reverse_str(str);
  input_str_precision_handler(params, str);
  input_str_flags_handler(params, str);
  input_str_width_handler(params, str);
}

/**
 * @brief Обрабатывает форматирование для целых чисел в восьмеричной системе
 * счисления. Функция обрабатывает форматирование для целых чисел, которые
 * должны быть выведены в восьмеричной системе счисления. В зависимости от
 * параметров форматирования, функция выбирает правильный размер целого числа
 * (short, long или int) и обрабатывает его в восьмеричное представление.
 Если
 * задан флаг sharp_flag, то также добавляет префикс "0" к результату
 *
 * @param str Указатель на строку, в которую будет записан результат
 * @param arg_ptr Указатель на список аргументов функции
 * @param params Указатель на структуру SP_FLAGS с параметрами форматирования
 */
void o_handler(char *str, va_list *arg_ptr, SP_FLAGS *params) {
  unsigned short int us_num = 0;
  unsigned long int ul_num = 0;
  unsigned int ui_num = 0;

  switch (params->length) {
    case 'h':
      us_num = (unsigned short int)va_arg(*arg_ptr, unsigned int);
      unslong_to_char_x8(str, us_num, params->sharp_flag);
      break;
    case 'l':
      ul_num = (unsigned long int)va_arg(*arg_ptr, unsigned long int);
      unslong_to_char_x8(str, ul_num, params->sharp_flag);
      break;
    default:
      ui_num = va_arg(*arg_ptr, unsigned int);
      unslong_to_char_x8(str, ui_num, params->sharp_flag);
      break;
  }
  input_str_precision_handler(params, str);
  input_str_flags_handler(params, str);
  input_str_width_handler(params, str);
}

/**
 * @brief Обрабатывает форматирование для целых чисел в шестнадцатеричной
 * системе счисления (x и X). В зависимости от параметров форматирования,
 * функция выбирает правильный размер целого числа (short, long или int) и
 * обрабатывает его в шестнадцатеричное представление. Если задан флаг
 * sharp_flag, то также добавляет префикс "0x" или "0X" к результату
 *
 * @param str Указатель на строку, в которую будет записан результат
 * @param arg_ptr Указатель на список аргументов функции
 * @param params Указатель на структуру SP_FLAGS с параметрами форматирования
 */
void xX_handler(char *str, va_list *arg_ptr, SP_FLAGS *params) {
  unsigned short int us_num = 0;
  unsigned long int ul_num = 0;
  unsigned int ui_num = 0;

  switch (params->length) {
    case 'h':
      us_num = (unsigned short int)va_arg(*arg_ptr, unsigned int);
      unslong_to_char_x16(params, str, us_num);
      break;
    case 'l':
      ul_num = (unsigned long int)va_arg(*arg_ptr, unsigned long int);
      unslong_to_char_x16(params, str, ul_num);
      break;
    default:
      ui_num = (unsigned int)va_arg(*arg_ptr, unsigned int);
      unslong_to_char_x16(params, str, ui_num);
      break;
  }
  input_str_precision_handler(params, str);
  input_str_flags_handler(params, str);
  input_str_width_handler(params, str);
}

/**
 * @brief Обрабатывает форматирование для чисел в научной нотации
 * (экспоненциальная запись). В зависимости от
 * параметров форматирования, функция выбирает правильный размер числа (long
 * double или double) и обрабатывает его в экспоненциальной записи. При
 * необходимости добавляет знак экспоненты, десятичную точку и нули к
 мантиссе
 * числа
 * @param str Указатель на строку, в которую будет записан результат
 * @param arg_ptr Указатель на список аргументов функции
 * @param params Указатель на структуру SP_FLAGS с параметрами форматирования
 */
void eE_handler(char *str, va_list *arg_ptr, SP_FLAGS *params) {
  long double ld_num = 0;
  double d_num = 0;

  switch (params->length) {
    case 'L':
      ld_num = va_arg(*arg_ptr, long double);
      convert_scientific_notation(params, str, ld_num);
      break;
    case 'l':
    default:
      d_num = va_arg(*arg_ptr, double);
      convert_scientific_notation(params, str, d_num);
      break;
  }
  input_str_precision_handler(params, str);
  input_str_flags_handler(params, str);
  input_str_width_handler(params, str);
}

/**
 * @brief Обрабатывает форматирование числа в экспоненциальной нотации 'gG'
 * @param str Указатель на строку, в которую будет записан результат
 * @param arg_ptr Указатель на список аргументов функции
 * @param params Указатель на структуру SP_FLAGS с параметрами форматирования
 */
void gG_handler(char *str, va_list *arg_ptr, SP_FLAGS *params) {
  long double ld_num = 0;
  double d_num = 0;

  switch (params->length) {
    case 'L':
      ld_num = va_arg(*arg_ptr, long double);
      convert_general_notation(params, str, ld_num);
      break;
    case 'l':
    default:
      d_num = va_arg(*arg_ptr, double);
      convert_general_notation(params, str, d_num);
      break;
  }
  input_str_precision_handler(params, str);
  input_str_flags_handler(params, str);
  input_str_width_handler(params, str);
}

/**
 * @brief Преобразует целое число в строку с учетом заданных флагов и
 * спецификаторов
 * @param params Указатель на структуру SP_FLAGS, содержащую флаги и
 * спецификаторы формата
 * @param copy Указатель на строку, куда будет записано преобразованное число
 * @param number Целое число для преобразования в строку
 */
void int_to_char(SP_FLAGS *params, char *copy, long double number) {
  int flag = 1;
  char *ptr = S21_NULL;

  params->sign = number < 0 ? -1 : 1;
  number *= params->sign;
  ptr = copy;
  if (params->spec != 'n') {
    while (flag) {
      int digit = 0;
      if (number >= 10) {
        digit = (int)fmod(number, 10);
        number = (number - digit) / 10;
      } else {
        digit = (int)number;
        flag = 0;
      }
      *(ptr++) = (char)(digit + '0');
    }
    if (s21_strchr("dioxX", params->spec) && params->precision == 0 &&
        number == 0 && params->dot)
      copy[0] = '\0';
    *ptr = '\0';
    reverse_str(copy);
  }
}

/**
 * @brief Преобразует числовое значение с плавающей точкой в строку
 * @param params Указатель на структуру flags, содержащую параметры
 * форматирования
 * @param copy Указатель на строку, в которую будет сохранен результат
 * @param number Числовое значение с плавающей точкой, которое нужно
 * преобразовать
 */
void float_to_char(char *copy, long double number, SP_FLAGS *params) {
  params->sign = number < 0 ? -1 : 1;
  number *= params->sign;
  int sign_fn = params->sign;
  if (params->precision <= 0) {
    int_to_char(params, copy, roundl(number));
  } else {
    long double int_part = 0, frac_part = 0;
    int position = 0;
    char result[256] = {0};
    frac_part = modfl(number, &int_part);
    if (s21_strchr("gG", params->spec) && params->precision == 1 &&
        frac_part >= 0.5) {
      int_part++;
    }
    int_to_char(params, copy, roundl(int_part));
    s21_strcat(copy, ".");
    int local_precision = params->precision;
    if (s21_strchr("gG", params->spec)) {
      if (int_part >= 1) {
        local_precision = params->precision - (int)s21_strlen(copy) + 1 +
                          ((int)roundl(number) == 0);
      } else if (frac_part * pow(10, local_precision) < 1) {
        local_precision = 4;
      }
    }
    for (int i = 0; i < local_precision; i++) frac_part *= 10;
    int_to_char(params, result, roundl(frac_part));
    position = (int)s21_strlen(result);
    for (int i = 0; position < local_precision; i++, position++) {
      move_right_str(result);
      result[i] = '0';
    }
    if (s21_strchr("gG", params->spec) && (int)roundl(number) != 0) {
      result[params->precision - (int)s21_strlen(copy) + 1] = '\0';
    }
    s21_strcat(copy, result);
  }
  params->sign = sign_fn;
}

/**
 * @brief Преобразует символы в целое число и обрабатывает форматирование,
 * функция проверяет, если следующий символ в format - '*', то извлекает
 * следующий аргумент из va_list и присваивает его переменной number
 * @param number Указатель на переменную, в которую будет сохранено целое
 число
 * @param format Указатель на строку с символами, которые нужно преобразовать
 * @param arg_ptr Указатель на список аргументов функции
 * @return Указатель на следующий символ в строке format
 */
char *char_to_int(int *number, const char *format, va_list *arg_ptr) {
  char wth[128] = {0};
  char *num = NULL;
  int count = 0;

  while (is_dec(*format)) {
    wth[count++] = *(format)++;
  }
  num = wth;
  while (count > 0) {
    *number += ((*(num)++) - '0') * pow(10, --count);
  }
  if (*format == '*') {
    *number = va_arg(*arg_ptr, int);
    format++;
  }
  return (char *)format;
}

/**
 * @brief Преобразование беззнакового длинного целого числа в строку
 * @param params Указатель на структуру SP_FLAGS, содержащую параметры
 * форматирования
 * @param copy Указатель на выходную строку, в которую будет записан
 результат
 * @param number Беззнаковое длинное целое число, которое нужно преобразовать
 * в строку
 */
void unslong_to_char(SP_FLAGS *params, char *copy, unsigned long long number) {
  int flag = 1;
  char *ptr = S21_NULL;
  ptr = copy;

  while (flag) {
    int digit = 0;
    if (number >= 10) {
      digit = (int)(number % 10);
      number = (number - digit) / 10;
    } else {
      digit = (int)number;
      flag = 0;
    }
    *(ptr++) = (char)(digit + '0');
  }
  if (params->precision == 0 && number == 0 && params->dot) copy[0] = '\0';
  *ptr = '\0';
  reverse_str(copy);
}

/**
 * @brief Преобразование беззнакового длинного целого числа в восьмеричную
 * строку
 * @param params Указатель на структуру SP_FLAGS, содержащую параметры
 * форматирования
 * @param copy Указатель на выходную строку, в которую будет записан
 результат
 * @param number Беззнаковое длинное целое число, которое нужно преобразовать
 * в восьмеричную строку
 * @param x8_sign Флаг, указывающий, нужно ли добавить символ '0' перед
 * строкой
 */
void unslong_to_char_x8(char *copy, unsigned long long number, int x8_sign) {
  char *ptr = S21_NULL;
  int flag = 1;
  ptr = copy;

  while (flag) {
    unsigned int digit;
    if (number > 7) {
      digit = number % 8;
      number = (number - digit) / 8;
    } else {
      digit = number;
      flag = 0;
    }
    *(ptr++) = (char)(digit + '0');
  }

  if (x8_sign == 1) *(ptr++) = '0';
  *ptr = '\0';
  reverse_str(copy);
}

/**
 * @brief Преобразование беззнакового длинного целого числа в
 * шестнадцатеричную строку
 * @param params Указатель на структуру SP_FLAGS, содержащую параметры
 * форматирования
 * @param copy Указатель на выходную строку, в которую будет записан
 результат
 * @param number Беззнаковое длинное целое число, которое нужно преобразовать
 * в шестнадцатеричную строку
 */
void unslong_to_char_x16(SP_FLAGS *params, char *copy,
                         unsigned long long number) {
  char *ptr = S21_NULL;
  int flag = 1, shift = 0;
  ptr = copy;
  shift = params->spec == 'x' ? 32 : 0;

  while (flag) {
    unsigned int digit;
    if (number > 15) {
      digit = number % 16;
      number = (number - digit) / 16;
    } else {
      digit = number;
      flag = 0;
    }
    if (digit < 10)
      *(ptr++) = (char)(digit + '0');
    else
      *(ptr++) = (char)(digit + 'A' + shift - 10);
  }
  *ptr = '\0';
  if (number == 0) {
    params->sharp_flag = 0;
  }
  reverse_str(copy);
}

/**
 * @brief Преобразует число в научную нотацию (экспоненциальную запись) и
 * форматирует его, применяет точность, обрабатывает флаги форматирования и
 * применяет ширину поля для полученного значения. Функция также учитывает
 * знак числа и добавляет мантиссу с экспонентой, если это необходимо
 * @param params Указатель на структуру SP_FLAGS с параметрами форматирования
 * @param copy Указатель на строку, в которую будет записан результат
 * @param number Число, которое нужно преобразовать и отформатировать
 */
void convert_scientific_notation(SP_FLAGS *params, char *copy,
                                 long double number) {
  params->sign = number < 0 ? -1 : 1;
  int order = 0, sing_fn = params->sign;
  number *= params->sign;

  if (number < 1) {
    while (number < 1 && order-- > -42) {
      number *= 10;
    }
    number < 1 ? (order = number = 0) : 1;
    if (round_handler(params, number)) {
      if (params->precision >= 0) {
        --params->precision;
      }
      order++;
    }
    if (s21_strchr("gG", params->spec)) del_insignificant_zeros(params, copy);
    add_mantissa(params, &copy[s21_strlen(copy)], order);
  } else {
    while (number >= 10) {
      order++;
      number /= 10;
    }
    if (round_handler(params, number)) {
      if (params->precision >= 0) {
        --params->precision;
      }
      order++;
    }
  }
  number = roundl(number * pow(10, params->precision));
  int_to_char(params, copy, number);
  if (params->precision > 0) {
    move_right_str(&copy[1]);
    copy[1] = '.';
    for (int i = (int)s21_strlen(copy); i < 2 + params->precision; i++) {
      copy[i] = '0';
    }
  }
  if (s21_strchr("gG", params->spec)) del_insignificant_zeros(params, copy);
  add_mantissa(params, &copy[s21_strlen(copy)], order);
  params->sign = sing_fn;
}

/**
 * @brief Обрабатывает форматирование числа в общей нотации
 * @param params Указатель на структуру SP_FLAGS с параметрами форматирования
 * @param copy Указатель на строку, в которую будет записан результат
 * @param number Число, которое нужно отформатировать
 */
void convert_general_notation(SP_FLAGS *params, char *copy,
                              long double number) {
  params->sign = number < 0 ? -1 : 1;
  int sing_fn = params->sign;
  number *= params->sign;

  if ((number / pow(10, params->precision)) > 1 ||
      ((number * (pow(10, 4))) < 1 && (number * (pow(10, 21))) >= 1)) {
    if (number < 1 && params->precision <= 0) {
      params->precision = 4;
    } else {
      --params->precision;
    }
    convert_scientific_notation(params, copy, number);
  } else {
    params->precision > 0 ? 1 : ++params->precision;
    float_to_char(copy, number, params);
    del_insignificant_zeros(params, copy);
  }
  params->sign = sing_fn;
}
