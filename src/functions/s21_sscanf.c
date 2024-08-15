#include "../s21_string.h"

int checkEnd(char c) {
  int res = 0;
  if (c == ' ' || c == '\n' || c == '\t') res = 1;
  return res;
}
void skipSpace(char **src) {
  while (**src && checkEnd(**src) != 0) {
    (*src)++;
  }
}
int isNum(char c) {
  int res = 0;
  if (c >= '0' && c <= '9') res = 1;
  return res;
}
int getChar(char *str) {
  int res = 0;
  while (str[res] != '\0' && checkEnd(str[res]) == 0) res++;
  return res;
}
void getWidth(char **src, char **buf, char **temp, int *len,
              currentFlagParameters *flag) {
  if (flag->width == -1 || *len <= flag->width) {
    s21_strncpy(*temp, *buf, *len);
    (*src) += *len;
  } else if (*len >= flag->width) {
    s21_strncpy(*temp, *buf, flag->width);
    (*src) += flag->width;
  }
}
void writeFlag(specifiers *spec, char ch) {
  switch (ch) {
    case 'c':
      spec->c = 1;
      break;
    case 'd':
      spec->d = 1;
      break;
    case 'i':
      spec->i = 1;
      break;
    case 'e':
      spec->e = 1;
      break;
    case 'E':
      spec->E = 1;
      break;
    case 'f':
      spec->f = 1;
      break;
    case 'g':
      spec->g = 1;
      break;
    case 'G':
      spec->G = 1;
      break;
    case 'o':
      spec->o = 1;
      break;
    case 's':
      spec->s = 1;
      break;
    case 'x':
      spec->x = 1;
      break;
    case 'X':
      spec->X = 1;
      break;
    case 'p':
      spec->p = 1;
      break;
    case 'n':
      spec->n = 1;
      break;
    case 'u':
      spec->u = 1;
      break;
    default:
      break;
  }
}
int parser(const char *format, int *index, specifiers *spec,
           currentFlagParameters *fl, int *stop) {
  int end = *index + 1;
  if (format[*index] == '%' && format[*index + 1] == '%')
    *stop = -1;
  else {
    searchWidth(&end, format, fl);
    searchTypeSpecificators(&end, format, fl);
    searchSpecificators(&end, format, spec);
    *index = end;
  }
  return 0;
}
int getFloatLength(char *str) {
  int res = 0;
  if (str[0] == '-' || str[0] == '+') res++;
  while (str[res] != '\0' && isNum(str[res]) == 1) res++;
  if (str[res] == '.') {
    res++;
    while (str[res] != '\0' && isNum(str[res]) == 1) res++;
  }
  if (str[res] == 'e' || str[res] == 'E') {
    res++;
    if (str[res] == '+' || str[res] == '-') res++;
    while (str[res] != '\0' && isNum(str[res]) == 1) res++;
  }
  if (checkNAN(str) != 0 || checkINF(str) != 0) res = 3;
  return res;
}

int searchSpecificators(int *index, const char *format, specifiers *specifier) {
  int res = 1;
  char *s = S21_NULL;
  s = s21_strchr("cdieEfgGosuxXpn", format[*index]);
  if (s != S21_NULL) {
    writeFlag(specifier, s[0]);
  } else
    res = 0;
  return res;
}
void searchLengthFlags(currentFlagParameters *fl, const char *ch, int i) {
  switch (ch[i]) {
    case 'h':
      fl->len_h = 1;
      break;
    case 'l':
      fl->len_l = 1;
      if (ch[i + 1] == 'l') fl->len_l++;
      break;
    case 'L':
      fl->len_L = 1;
      break;
    case '*':
      fl->star = 1;
      break;
    default:
      break;
  }
}
int searchTypeSpecificators(int *begin, const char *format,
                            currentFlagParameters *flags) {
  int ret = 1;
  char *s = S21_NULL;
  s = s21_strchr("lLh*", format[*begin]);
  if (s != S21_NULL) {
    searchLengthFlags(flags, format, *begin);
    if (flags->len_l == 1 || flags->len_h == 1 || flags->len_L == 1 ||
        flags->star == 1)
      *begin += 1;
    else if (flags->len_l == 2)
      *begin += 2;
  } else
    ret = 0;
  return ret;
}
int searchWidth(int *start, const char *format, currentFlagParameters *flags) {
  int res = 1;
  char buf[32] = {'\0'};
  int i = 0;
  while (format[*start] >= '0' && format[*start] <= '9') {
    buf[i] = format[*start];
    i++;
    (*start)++;
  }
  if (i > 0) {
    flags->width = convertToInt(buf);
  }
  if (i == 0) {
    res = 0;
  }
  return res;
}
void convertSizeDouble(long double num, void *ptr, currentFlagParameters *f) {
  if (f->len_l == 1) {
    *(double *)ptr = (double)num;
  } else if (f->len_l == 2 || f->len_L == 1) {
    *(long double *)ptr = num;
  } else {
    *(float *)ptr = (float)num;
  }
}
void convertSizeInt(long long int num, void *ptr, currentFlagParameters *f) {
  if (f->len_l == 1)
    *(long *)ptr = (long int)num;
  else if (f->len_l == 2)
    *(long long *)ptr = num;
  else if (f->len_h == 1)
    *(short *)ptr = (short int)num;
  else
    *(int *)ptr = (int)num;
}
void convertSizeUnsigned(va_list args, char *temp,
                         currentFlagParameters *flag) {
  void *ptr = va_arg(args, void *);
  long long unsigned int num = 0;
  if (convertToInt(temp) < 0)
    num = ULONG_MAX + convertToInt(temp) + 1;
  else
    num = convertToInt(temp);
  if (flag->len_l == 1)
    *(unsigned long *)ptr = (long int)num;
  else if (flag->len_l == 2)
    *(unsigned long long *)ptr = num;
  else if (flag->len_h == 1)
    *(unsigned short *)ptr = (short int)num;
  else
    *(unsigned int *)ptr = (int)num;
}
int searchHexadecimalValue(const char *str, specifiers *spec) {
  char match[32] = {'\0'};
  if (spec->o == 1)
    s21_strcpy(match, "01234567");
  else if (spec->X == 1 || spec->x == 1)
    s21_strcpy(match, "ABCDEFabcdef0123456789");
  int i = 0;
  while (str[i] != '\0' && s21_strchr(match, str[i]) != S21_NULL) {
    i++;
  }
  return i;
}
void getHexadecimal(char **src, char *buf, specifiers *spec, int *len,
                    int *shift) {
  if ((spec->x == 1 || spec->X == 1)) {
    if ((buf[*shift] == '0' &&
         (buf[*shift + 1] == 'x' || buf[*shift + 1] == 'X')))
      *shift += 2;
    s21_strcpy(buf, *src);
    *len += *shift;
    while (buf[*len] != '\0' &&
           s21_strchr("0123456789abcdefABCDEF", buf[*len]) != S21_NULL)
      *len += 1;
  } else if (spec->o == 1) {
    if (buf[*shift] == '0') *shift += 1;
    s21_strcpy(buf, *src);
    *len += *shift;
    while (buf[*len] != '\0' && s21_strchr("01234567", buf[*len]) != S21_NULL)
      *len += 1;
  }
}
void convertSizeHexadecimal(currentFlagParameters *f, va_list args,
                            long long unsigned int *num, specifiers *spec) {
  void *ptr = va_arg(args, void *);
  if (f->len_l == 1 || spec->p == 1)
    *(unsigned long int *)ptr = (long int)*num;
  else if (f->len_l == 2)
    *(unsigned long long int *)ptr = *num;
  else if (f->len_h == 1)
    *(unsigned short int *)ptr = (short int)*num;
  else
    *(unsigned int *)ptr = (int)*num;
}

void getString(va_list args, currentFlagParameters *flag, char *t1,
               specifiers *spec) {
  void *res = va_arg(args, void *);
  wchar_t temp[1024] = {'\0'};
  if (flag->len_l == 1) {
    mbstowcs(temp, t1, s21_strlen(t1));
    if (spec->c == 1) {
      *(wchar_t *)res = *(char *)t1;
    } else {
      s21_wcscpy((wchar_t *)res, temp);
    }
  } else if (flag->len_l == 0) {
    if (spec->c == 1) {
      *(char *)res = *(char *)t1;
    } else {
      s21_strcpy((char *)res, t1);
    }
  }
}
void scan_n(va_list args, currentFlagParameters *flag, int *stop_scan,
            int *for_n) {
  int *ptr = S21_NULL;
  if (*stop_scan != -1) {
    if (flag->star != 1) {
      ptr = va_arg(args, int *);
      *ptr = *for_n;
    }
  }
}
void scan_i(char **src, specifiers *spec) {
  int shift = 0;
  char buf[512] = {'\0'};
  skipSpace(src);
  s21_strcpy(buf, *src);
  if (buf[shift] == '-') shift++;
  if (buf[shift] == '0' && (buf[shift + 1] == 'X' || buf[shift + 1] == 'x'))
    spec->x = 1;
  else if (buf[shift] == '0')
    spec->o = 1;
  else
    spec->d = 1;
}
void scan_u(char **src, currentFlagParameters *flag, va_list args, int *count,
            int *stop_scan, int *for_n) {
  char t[512] = {'\0'};
  char b[512] = {'\0'};
  char *temp = t;
  char *buf = b;
  int len = 0;
  if (*stop_scan != -1) {
    skipSpace(src);
    s21_strcpy(buf, *src);
    if (buf[0] == '-' || buf[0] == '+') len++;
    while (buf[len] != '\0' && isNum(buf[len]) == 1) len++;
    if (len != 0 &&
        (!((len == 1 && buf[0] == '-') || (len == 1 && buf[0] == '+')))) {
      if (flag->star == 1)
        *src += len;
      else {
        getWidth(src, &buf, &temp, &len, flag);
        *for_n = (int)s21_strlen(temp);
        if (flag->star != 1) {
          convertSizeUnsigned(args, temp, flag);
          *count += 1;
        }
      }
    } else {
      *stop_scan = -1;
      if (s21_strlen(*src) == 0) *count = -1;
    }
  }
}
void scan_x(char **src, currentFlagParameters *f, va_list args,
            specifiers *spec, int *result, int *stop_scan, int *for_n) {
  char t[512] = {'\0'};
  char b[512] = {'\0'};
  char *temp = t;
  char *buf = b;
  int len = 0;
  int shift = 0;
  int sign = 1;
  long long unsigned int num = 0;
  if (*stop_scan != -1) {
    skipSpace(src);
    s21_strcpy(buf, *src);
    if (buf[0] == '-' || buf[0] == '+') {
      sign = -1;
      shift++;
    }
    getHexadecimal(src, buf, spec, &len, &shift);
    if (len != 0) {
      getWidth(src, &buf, &temp, &len, f);
      *for_n = (int)s21_strlen(temp);
      num = convertToHexadecimal(temp + shift, spec, &sign);
      if (f->star != 1) {
        convertSizeHexadecimal(f, args, &num, spec);
        *result += 1;
      }
    } else {
      *stop_scan = -1;
      if (s21_strlen(*src) == 0) *result = -1;
    }
  }
}
void scan_f(char **src, va_list args, currentFlagParameters *flag, int *count,
            int *stop_scan, int *for_n) {
  char t[512] = {'\0'};
  char b[512] = {'\0'};
  char *temp = t;
  char *buf = b;
  int len = 0;
  long double num = 0;
  void *res = S21_NULL;
  if (*stop_scan != -1) {
    skipSpace(src);
    s21_strcpy(buf, *src);
    len = getFloatLength(buf);
    if (!(len == 0 || (len == 1 && (buf[0] == '-' || buf[0] == '+')))) {
      getWidth(src, &buf, &temp, &len, flag);
      *for_n = (int)s21_strlen(temp);
      num = convertToDouble(temp);
      if (flag->star != 1) {
        res = va_arg(args, void *);
        convertSizeDouble(num, res, flag);
        *count += 1;
      }
    } else {
      *stop_scan = -1;
      if (s21_strlen(*src) == 0) *count = -1;
    }
  }
}
void scan_s(char **str, va_list args, currentFlagParameters *flag, int *count,
            specifiers *s, int *stop_scan, int *skip, int *for_n) {
  char t1[512] = {'\0'};
  int len = 0;
  if (*stop_scan != -1) {
    len = 0;
    if (s->c != 1 || (s->c == 1 && *skip == 1)) skipSpace(str);
    if (s->c == 1) {
      if (*str[0] != '\0') len = 1;
    } else if (s->s == 1)
      len = getChar(*str);
    if (len != 0) {
      if (flag->width <= len && flag->width != -1) {
        s21_strncpy(t1, *str, flag->width);
        *str += flag->width;
      } else if (flag->width == -1 || flag->width > len) {
        s21_strncpy(t1, *str, len);
        *str += len;
      }
      *for_n = (int)s21_strlen(t1);
      if (flag->star != 1) {
        getString(args, flag, t1, s);
        *count += 1;
      }
    } else {
      *stop_scan = -1;
      *count = -1;
    }
  }
}
void scan_d(char **src, currentFlagParameters *flag, va_list args, int *count,
            int *stop_scan, int *for_n) {
  char t[512] = {'\0'};
  char b[512] = {'\0'};
  char *temp = t;
  char *buf = b;
  int length = 0;
  long long int d;
  void *res = S21_NULL;
  if (*stop_scan != -1) {
    skipSpace(src);
    if (*src[0] == '+') (*src)++;
    s21_strcpy(buf, *src);
    if (buf[0] == '-') length++;
    while (buf[length] != '\0' && isNum(buf[length]) == 1) {
      length++;
    }
    if (length != 0 && (!(length == 1 && buf[0] == '-'))) {
      if (flag->star == 1)
        *src += length;
      else {
        getWidth(src, &buf, &temp, &length, flag);
        *for_n = (int)s21_strlen(temp);
        d = convertToInt(temp);
        if (flag->star != 1) {
          res = va_arg(args, void *);
          convertSizeInt(d, res, flag);
          *count += 1;
        }
      }
    } else {
      *stop_scan = -1;
      if (s21_strlen(*src) == 0) *count = -1;
    }
  }
}

long long int convertToInt(const char *str) {
  long long int res = 0;
  int sign = 1;
  unsigned int i = 0;
  while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r' ||
         str[i] == '\v' || str[i] == '\f') {
    i++;
  }
  if (str[i] == '-') {
    sign = -1;
    i++;
  } else if (str[i] == '+') {
    i++;
  }
  while (str[i] >= '0' && str[i] <= '9') {
    res = res * 10 + str[i] - '0';
    i++;
  }
  res = res * sign;
  return res;
}
double checkINF(char *str) {
  double res = 0;
  if ((str[0] == 'i' || str[0] == 'I') && (str[1] == 'n' || str[1] == 'N') &&
      (str[2] == 'f' || str[2] == 'F'))
    res = INFINITY;
  return res;
}
double checkNAN(char *str) {
  double res = 0;
  if ((str[0] == 'n' || str[0] == 'N') && (str[1] == 'a' || str[1] == 'A') &&
      (str[2] == 'n' || str[2] == 'N'))
    res = NAN;
  return res;
}
long double convertToDouble(char *str) {
  long double number = 0, res = 0;
  int eps = 0, i = 0, power = 0;
  int sign = 1, epsSign;
  if (str[0] == '-') {
    sign = -1;
    i = 1;
  } else if (str[0] == '+')
    i++;
  while (str[i] != '\0' && isNum(str[i]) == 1) {
    number = number * 10.0 + (str[i] - 48);
    i++;
  }
  if (str[i] == '.') {
    if (isNum(str[i + 1]) || isNum(str[i - 1])) i++;
    while (str[i] != '\0' && isNum(str[i]) == 1) {
      number = number * 10.0 + (str[i] - 48);
      eps--;
      i++;
    }
  }
  if (str[i] == 'E' || str[i] == 'e') {
    i++;
    (str[i] == '+') ? (epsSign = 1) : (epsSign = -1);
    i++;

    while (str[i] != '\0' && isNum(str[i]) == 1) {
      power = power * 10 + (str[i] - 48);
      i++;
    }
    eps = eps + epsSign * power;
  }
  while (eps > 0) {
    number = number * 10.0;
    eps--;
  }
  while (eps < 0) {
    number = number * 0.1;
    eps++;
  }
  res = sign * number;
  if (checkINF(str) != 0) res = INFINITY;
  if (checkNAN(str) != 0) res = NAN;
  return res;
}

void checkPowerHexadecimal(char *str, long long unsigned int *num, int *i,
                           int *powd, specifiers *spec) {
  int divide = 0;
  if (spec->o == 1)
    divide = 8;
  else if (spec->X == 1 || spec->x == 1)
    divide = 16;
  *num = *num + ((str[*i] - 48) * pow(divide, *powd));
  *powd -= 1;
}

void convertTo16(char *str, long long unsigned int *num, int *i, int *power) {
  if (str[*i] >= 'a' && str[*i] <= 'f') {
    *num = *num + ((str[*i] - 'a' + 10) * pow(16, *power));
    *power -= 1;
  } else if (str[*i] >= 'A' && str[*i] <= 'F') {
    *num = *num + ((str[*i] - 'A' + 10) * pow(16, *power));
    *power -= 1;
  }
}
long long unsigned int convertToHexadecimal(char *str, specifiers *spec,
                                            int *sign) {
  long long unsigned int num = 0;
  int i = 0, power = searchHexadecimalValue(str, spec) - 1;
  if (s21_strlen(str) > 8 && (spec->x == 1 || spec->X == 1))
    num = ULLONG_MAX;
  else {
    while (i <= searchHexadecimalValue(str, spec) && power != -1) {
      if (spec->x == 1 || spec->X == 1 || spec->p == 1) {
        if (s21_strchr("ABCDEFabcdef", str[i]) != S21_NULL)
          convertTo16(str, &num, &i, &power);
        else
          checkPowerHexadecimal(str, &num, &i, &power, spec);
      } else if (spec->o == 1)
        checkPowerHexadecimal(str, &num, &i, &power, spec);
      i++;
    }
  }
  if (*sign == -1) num = ULLONG_MAX - num + 1;
  return num;
}

int s21_sscanf(const char *src, const char *format, ...) {
  va_list args;
  va_start(args, format);
  char temp[1024] = {'\0'};
  s21_strcpy(temp, src);
  char *str = S21_NULL;
  str = temp;
  int count_item = 0, stop_scan = 0, for_n = 0, skip = 0, i = 0, result = 0;
  currentFlagParameters flag = {0};
  specifiers currentSpecifier = {0};
  while (format[i] != '\0' && stop_scan != -1) {
    skip = 0;
    if (format[i] == '%') {
      if (i - 1 > -1 && checkEnd(format[i - 1]) == 1) skip = 1;
      s21_memset(&flag, 0, sizeof(flag));
      flag.width = -1;
      s21_memset(&currentSpecifier, 0, sizeof(currentSpecifier));
      parser(format, &i, &currentSpecifier, &flag, &stop_scan);
      if (currentSpecifier.i == 1) scan_i(&str, &currentSpecifier);
      if (currentSpecifier.p == 1) currentSpecifier.x = 1;
      if (currentSpecifier.d == 1)
        scan_d(&str, &flag, args, &count_item, &stop_scan, &for_n);
      if (currentSpecifier.c == 1 || currentSpecifier.s == 1)
        scan_s(&str, args, &flag, &count_item, &currentSpecifier, &stop_scan,
               &skip, &for_n);
      if (currentSpecifier.f == 1 || currentSpecifier.G == 1 ||
          currentSpecifier.g == 1 || currentSpecifier.E == 1 ||
          currentSpecifier.e == 1)
        scan_f(&str, args, &flag, &count_item, &stop_scan, &for_n);
      if (currentSpecifier.X == 1 || currentSpecifier.x == 1 ||
          currentSpecifier.o == 1 || currentSpecifier.p == 1)
        scan_x(&str, &flag, args, &currentSpecifier, &count_item, &stop_scan,
               &for_n);
      if (currentSpecifier.u == 1)
        scan_u(&str, &flag, args, &count_item, &stop_scan, &for_n);
      if (currentSpecifier.n == 1) {
        scan_n(args, &flag, &stop_scan, &for_n);
      }
      result = count_item;
    }
    i++;
  }
  va_end(args);
  return result;
}