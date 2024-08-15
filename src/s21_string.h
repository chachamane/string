#ifndef SRC_S21_STRING_H
#define SRC_S21_STRING_H

#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#define BUFF_SIZE 1024
#define S21_NULL \
  ((void *)0)  // Макрос, являющийся значением константы нулевого указателя

typedef long unsigned s21_size_t;  // Целочисленный тип без знака, являющийся
                                   // результатом ключевого слова sizeof

#define UNKNOWN "Unknown error: "

/*--Sprintf defines--*/
#define is_flag(ch)                                                   \
  ((ch) == '-') || ((ch) == '+') || ((ch) == ' ') || ((ch) == '#') || \
      ((ch) == '0')

#define is_dec(ch) ((ch) >= '0' && (ch) <= '9')

#define is_len(ch) ((ch) == 'h' || (ch) == 'l' || (ch) == 'L')

#define is_spec(ch)                                                           \
  ((ch) == 'c' || (ch) == 'd' || (ch) == 'i' || (ch) == 'e' || (ch) == 'E' || \
   (ch) == 'f' || (ch) == 'g' || (ch) == 'G' || (ch) == 'o' || (ch) == 's' || \
   (ch) == 'u' || (ch) == 'x' || (ch) == 'X' || (ch) == 'p' || (ch) == 'n' || \
   (ch) == '%')
/*----*/

/*--Sprintf struct--*/
typedef struct SP_FLAGS {
  int plus_flag;
  int minus_flag;
  int space_flag;
  int zero_flag;
  int sharp_flag;
  int dot;
  int precision;
  int width;
  int sign;

  char length;
  char spec;
} SP_FLAGS;
/*----*/

/*--Sscanf struct--*/
typedef struct {
  int c;
  int d;
  int i;
  int e;
  int E;
  int f;
  int g;
  int G;
  int o;
  int s;
  int u;
  int x;
  int X;
  int p;
  int n;
} specifiers;

typedef struct {
  int star;
  int width;
  int len_h;
  int len_l;
  int len_L;
} currentFlagParameters;
/*----*/

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
s21_size_t s21_strspn(const char *str1, const char *str2);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
char *s21_strcpy(char *dest, const char *src);
char *s21_strdup(const char *str);
/*--Trim--*/
void *s21_trim(const char *src, const char *trim_chars);
void s21_trim_left(const char **src, const char *trim_chars,
                   s21_size_t *src_len, const s21_size_t trim_chars_len);
void s21_trim_right(const char **src, const char *trim_chars,
                    s21_size_t *src_len, const s21_size_t trim_chars_len);
/*----*/

/*--Strerror--*/
#if defined(__APPLE__)
#define S21_ERRSIZE 107
#elif defined(__linux__)
#define S21_ERRSIZE 134
#endif
#if defined(__APPLE__) || defined(__MACH__)
static const char *const s21_errlist[S21_ERRSIZE] = {
    [0] = "Undefined error: 0",
    [1] = "Operation not permitted",
    [2] = "No such file or directory",
    [3] = "No such process",
    [4] = "Interrupted system call",
    [5] = "Input/output error",
    [6] = "Device not configured",
    [7] = "Argument list too long",
    [8] = "Exec format error",
    [9] = "Bad file descriptor",
    [10] = "No child processes",
    [11] = "Resource deadlock avoided",
    [12] = "Cannot allocate memory",
    [13] = "Permission denied",
    [14] = "Bad address",
    [15] = "Block device required",
    [16] = "Resource busy",
    [17] = "File exists",
    [18] = "Cross-device link",
    [19] = "Operation not supported by device",
    [20] = "Not a directory",
    [21] = "Is a directory",
    [22] = "Invalid argument",
    [23] = "Too many open files in system",
    [24] = "Too many open files",
    [25] = "Inappropriate ioctl for device",
    [26] = "Text file busy",
    [27] = "File too large",
    [28] = "No space left on device",
    [29] = "Illegal seek",
    [30] = "Read-only file system",
    [31] = "Too many links",
    [32] = "Broken pipe",
    [33] = "Numerical argument out of domain",
    [34] = "Result too large",
    [35] = "Resource temporarily unavailable",
    [36] = "Operation now in progress",
    [37] = "Operation already in progress",
    [38] = "Socket operation on non-socket",
    [39] = "Destination address required",
    [40] = "Message too long",
    [41] = "Protocol wrong type for socket",
    [42] = "Protocol not available",
    [43] = "Protocol not supported",
    [44] = "Socket type not supported",
    [45] = "Operation not supported",
    [46] = "Protocol family not supported",
    [47] = "Address family not supported by protocol family",
    [48] = "Address already in use",
    [49] = "Can't assign requested address",
    [50] = "Network is down",
    [51] = "Network is unreachable",
    [52] = "Network dropped connection on reset",
    [53] = "Software caused connection abort",
    [54] = "Connection reset by peer",
    [55] = "No buffer space available",
    [56] = "Socket is already connected",
    [57] = "Socket is not connected",
    [58] = "Can't send after socket shutdown",
    [59] = "Too many references: can't splice",
    [60] = "Operation timed out",
    [61] = "Connection refused",
    [62] = "Too many levels of symbolic links",
    [63] = "File name too long",
    [64] = "Host is down",
    [65] = "No route to host",
    [66] = "Directory not empty",
    [67] = "Too many processes",
    [68] = "Too many users",
    [69] = "Disc quota exceeded",
    [70] = "Stale NFS file handle",
    [71] = "Too many levels of remote in path",
    [72] = "RPC struct is bad",
    [73] = "RPC version wrong",
    [74] = "RPC prog. not avail",
    [75] = "Program version wrong",
    [76] = "Bad procedure for program",
    [77] = "No locks available",
    [78] = "Function not implemented",
    [79] = "Inappropriate file type or format",
    [80] = "Authentication error",
    [81] = "Need authenticator",
    [82] = "Device power is off",
    [83] = "Device error",
    [84] = "Value too large to be stored in data type",
    [85] = "Bad executable (or shared library)",
    [86] = "Bad CPU type in executable",
    [87] = "Shared library version mismatch",
    [88] = "Malformed Mach-o file",
    [89] = "Operation canceled",
    [90] = "Identifier removed",
    [91] = "No message of desired type",
    [92] = "Illegal byte sequence",
    [93] = "Attribute not found",
    [94] = "Bad message",
    [95] = "EMULTIHOP (Reserved)",
    [96] = "No message available on STREAM",
    [97] = "ENOLINK (Reserved)",
    [98] = "No STREAM resources",
    [99] = "Not a STREAM",
    [100] = "Protocol error",
    [101] = "STREAM ioctl timeout",
    [102] = "Operation not supported on socket",
    [103] = "Policy not found",
    [104] = "State not recoverable",
    [105] = "Previous owner died",
    [106] = "Interface output queue is full"};
#elif defined(__linux__)
static const char *const s21_errlist[S21_ERRSIZE] = {
    [0] = "Success",
    [1] = "Operation not permitted",
    [2] = "No such file or directory",
    [3] = "No such process",
    [4] = "Interrupted system call",
    [5] = "Input/output error",
    [6] = "No such device or address",
    [7] = "Argument list too long",
    [8] = "Exec format error",
    [9] = "Bad file descriptor",
    [10] = "No child processes",
    [11] = "Resource temporarily unavailable",
    [12] = "Cannot allocate memory",
    [13] = "Permission denied",
    [14] = "Bad address",
    [15] = "Block device required",
    [16] = "Device or resource busy",
    [17] = "File exists",
    [18] = "Invalid cross-device link",
    [19] = "No such device",
    [20] = "Not a directory",
    [21] = "Is a directory",
    [22] = "Invalid argument",
    [23] = "Too many open files in system",
    [24] = "Too many open files",
    [25] = "Inappropriate ioctl for device",
    [26] = "Text file busy",
    [27] = "File too large",
    [29] = "No space left on device",
    [30] = "Illegal seek",
    [31] = "Read-only file system",
    [32] = "Too many links",
    [33] = "Broken pipe",
    [34] = "Numerical argument out of domain",
    [35] = "Numerical result out of range",
    [36] = "Resource deadlock avoided",
    [37] = "File name too long",
    [38] = "No locks available",
    [39] = "Function not implemented",
    [40] = "Directory not empty",
    [41] = "Too many levels of symbolic links",
    [42] = "Unknown error 41",
    [43] = "No message of desired type",
    [44] = "Identifier removed",
    [45] = "Channel number out of range",
    [46] = "Level 2 not synchronized",
    [47] = "Level 3 halted",
    [48] = "Level 3 reset",
    [49] = "Link number out of range",
    [50] = "Protocol driver not attached",
    [51] = "No CSI structure available",
    [52] = "Level 2 halted",
    [53] = "Invalid exchange",
    [54] = "Invalid request descriptor",
    [55] = "Exchange full",
    [56] = "No anode",
    [57] = "Invalid request code",
    [58] = "Invalid slot",
    [59] = "Unknown error 58",
    [60] = "Bad font file format",
    [61] = "Device not a stream",
    [62] = "No data available",
    [63] = "Timer expired",
    [64] = "Out of streams resources",
    [65] = "Machine is not on the network",
    [66] = "Package not installed",
    [67] = "Object is remote",
    [68] = "Link has been severed",
    [69] = "Advertise error",
    [70] = "Srmount error",
    [71] = "Communication error on send",
    [72] = "Protocol error",
    [73] = "Multihop attempted",
    [74] = "RFS specific error",
    [75] = "Bad message",
    [76] = "Value too large for defined data type",
    [77] = "Name not unique on network",
    [78] = "File descriptor in bad state",
    [79] = "Remote address changed",
    [80] = "Can not access a needed shared library",
    [81] = "Accessing a corrupted shared library",
    [82] = ".lib section in exrcutable file is corrupted",
    [83] = "Attempting to link in too many shared libraries",
    [84] = "Invalid or incomplete multibyte or wide character",
    [85] = "Interrupted system call should be restarted",
    [86] = "Streams pipe error",
    [87] = "Too many users",
    [88] = "Socket operation on non-socket",
    [89] = "Destination address required",
    [90] = "Message too long",
    [91] = "Protocol wrong type for socket",
    [92] = "Protocol not available",
    [93] = "Protocol not supported",
    [94] = "Socket type not supported",
    [95] = "Operation not supported",
    [96] = "Protocol family not supported",
    [97] = "Address family not supported by protocol",
    [98] = "Address already in use",
    [99] = "Cannot assign requested address",
    [100] = "Network is down",
    [101] = "Network is unreachable",
    [102] = "Network dropped connection on reset",
    [103] = "Software caused connection abort",
    [104] = "Connection reset by peer",
    [105] = "No buffer space available",
    [106] = "Transport endpoint is already connected",
    [107] = "Transport endpoint is not connected",
    [108] = "Cannot send after transport endpoint shutdown",
    [109] = "Too many references: cannot splice",
    [110] = "Connection timed out",
    [111] = "Connection refused",
    [112] = "Host is down",
    [113] = "No route to host",
    [114] = "Operation already in progress",
    [115] = "Operation now in progress",
    [116] = "Stale file handle",
    [117] = "Structure needs cleaning",
    [118] = "Not a XENIX named type file",
    [119] = "No XENIX semaphores available",
    [120] = "Is a named type file",
    [121] = "Remote I/O error",
    [122] = "Disk quota exceeded",
    [123] = "No medium found",
    [124] = "Wrong medium type",
    [125] = "Operation canceled",
    [126] = "Required key not available",
    [127] = "Key has expired",
    [128] = "Key has been revoked",
    [129] = "Key was rejected by service",
    [130] = "Owner died",
    [131] = "State not recoverable",
    [132] = "Operation not possible due to RF-kill",
    [133] = "Memory page has hardware error",
};
#endif

char *s21_strerror(int errnum);
/*----*/

/*--Sprintf--*/

/*--Вспомогательные функции обработки значений--*/
void init_default_precision(SP_FLAGS *params);
void check_flags(SP_FLAGS *params, const char *format);
char *check_specs(char *str, s21_size_t *str_len, va_list *arg_ptr,
                  SP_FLAGS *params);
void move_right_str(char *str);
void input_str_flags_handler(SP_FLAGS *params, char *str);
void sharp_flag_handler(SP_FLAGS *params, char *str);
void input_str_width_handler(SP_FLAGS *params, char *str);
void input_str_precision_handler(SP_FLAGS *params, char *str);
int round_handler(SP_FLAGS *params, long double number);
void del_insignificant_zeros(SP_FLAGS *params, char *str);
void add_mantissa(SP_FLAGS *params, char *mantissa, int order);
/*----*/

/*--Вспомогательные функции конвертации--*/
void wchart_to_string(char *buf, wchar_t *tmp, s21_size_t buf_len);
void reverse_str(char *str);
void int_to_char(SP_FLAGS *params, char *copy, long double number);
void float_to_char(char *copy, long double number, SP_FLAGS *params);
char *char_to_int(int *number, const char *format, va_list *arg_ptr);
void unslong_to_char(SP_FLAGS *params, char *copy, unsigned long long number);
void unslong_to_char_x8(char *copy, unsigned long long number, int x8_sign);
void unslong_to_char_x16(SP_FLAGS *params, char *copy,
                         unsigned long long number);
void convert_scientific_notation(SP_FLAGS *params, char *copy,
                                 long double number);
void convert_general_notation(SP_FLAGS *params, char *copy, long double number);
/*----*/

/*--Обработчики спецификаторов--*/
void c_handler(char *str, va_list *arg_ptr, SP_FLAGS *params);
void di_handler(char *str, va_list *arg_ptr, SP_FLAGS *params);
void f_handler(char *str, va_list *arg_ptr, SP_FLAGS *params);
void s_handler(char *str, va_list *arg_ptr, SP_FLAGS *params);
void u_handler(char *str, va_list *arg_ptr, SP_FLAGS *params);
void percentage_handler(char *str, SP_FLAGS *params);
void n_handler(s21_size_t const *str_len, va_list *arg_ptr);
void p_handler(char *str, va_list *arg_ptr, SP_FLAGS *params);
void o_handler(char *str, va_list *arg_ptr, SP_FLAGS *params);
void xX_handler(char *str, va_list *arg_ptr, SP_FLAGS *params);
void eE_handler(char *str, va_list *arg_ptr, SP_FLAGS *params);
void gG_handler(char *str, va_list *arg_ptr, SP_FLAGS *params);
/*----*/
int s21_sprintf(char *str, const char *format, ...);
/*----*/

/*--Sscanf--*/

void writeFlag(specifiers *spec, char ch);
int checkEnd(char c);
int isNum(char c);
double checkNAN(char *str);
double checkINF(char *str);
int getChar(char *str);
void skipSpace(char **src);
void getWidth(char **src, char **buf, char **temp, int *len,
              currentFlagParameters *f);
int getFloatLength(char *str);
int searchSpecificators(int *index, const char *format, specifiers *specifier);
void searchLengthFlags(currentFlagParameters *fl, const char *ch, int i);
int searchTypeSpecificators(int *begin, const char *format,
                            currentFlagParameters *flags);
int searchWidth(int *start, const char *format, currentFlagParameters *flags);
long double convertToDouble(char *str);
void convertSizeDouble(long double num, void *ptr, currentFlagParameters *f);
long long int convertToInt(const char *str);
void convertSizeInt(long long int num, void *ptr, currentFlagParameters *f);
void convertSizeUnsigned(va_list args, char *temp, currentFlagParameters *flag);
void getHexadecimal(char **src, char *buf, specifiers *spec, int *len,
                    int *sdvig);
void convertSizeHexadecimal(currentFlagParameters *f, va_list args,
                            long long unsigned int *num, specifiers *spec);
void getString(va_list args, currentFlagParameters *flag, char *t1,
               specifiers *s);
int parser(const char *format, int *index, specifiers *spec,
           currentFlagParameters *fl, int *stop);
void scan_d(char **src, currentFlagParameters *flag, va_list args, int *count,
            int *stop_scan, int *for_n);
void scan_i(char **src, specifiers *spec);
void scan_u(char **src, currentFlagParameters *flag, va_list args, int *count,
            int *stop_scan, int *for_n);
void scan_n(va_list args, currentFlagParameters *flag, int *stop_scan,
            int *for_n);
void scan_f(char **src, va_list args, currentFlagParameters *flag, int *count,
            int *stop_scan, int *for_n);
void scan_s(char **str, va_list args, currentFlagParameters *flag, int *count,
            specifiers *s, int *stop_scan, int *skip, int *for_n);
void scan_x(char **src, currentFlagParameters *f, va_list args,
            specifiers *spec, int *result, int *stop_scan, int *for_n);

long long unsigned int convertToHexadecimal(char *str, specifiers *spec,
                                            int *sign);

void checkPowerHexadecimal(char *str, long long unsigned int *num, int *i,
                           int *powd, specifiers *spec);

void convertTo16(char *str, long long unsigned int *num, int *i, int *powd);

int searchHexadecimalValue(const char *str, specifiers *spec);
int s21_sscanf(const char *str, const char *format, ...);
wchar_t *s21_wcscpy(wchar_t *dest, const wchar_t *src);
/*----*/
void *s21_memmove(void *dest, const void *src, s21_size_t n);
char *s21_strcat(char *dest, const char *src);
#endif  // SRC_S21_STRING_H
