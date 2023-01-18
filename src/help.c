#include <math.h>
#include <stdlib.h>
#include <wchar.h>

#include "s21_string.h"

// Parser
void parser(const char *format, arguments *args) {
  const char *specifiers = "cdieEfgGosuxXpn%";
  int arg_index = 0, is_argument = 0;

  for (int formatIndex = 0; format[formatIndex] != '\0'; formatIndex++) {
    if (format[formatIndex] == '%') {
      is_argument = 1;
      formatIndex++;
    }
    for (; is_argument && format[formatIndex] != '\0'; formatIndex++) {
      if (s21_strchr(specifiers, format[formatIndex])) {
        args[arg_index].specifier = format[formatIndex];
        arg_index++;
        is_argument = 0;
        break;
      }
      if (format[formatIndex] == '-') {
        args[arg_index].minus = 1;
      } else if (format[formatIndex] == '+') {
        args[arg_index].plus = 1;
      } else if (format[formatIndex] == ' ') {
        args[arg_index].space = 1;
      } else if (format[formatIndex] == '#') {
        args[arg_index].sharp = 1;
      } else if (format[formatIndex] == '0') {
        args[arg_index].zero = 1;
      } else if (is_digit(format[formatIndex]) || format[formatIndex] == '*') {
        args[arg_index].width = parseWidth(format, &formatIndex);
      } else if (format[formatIndex] == '.') {
        formatIndex++;
        args[arg_index].isAccSet = 1;
        args[arg_index].accuracy = parseAccuracy(format, &formatIndex);
      } else if (format[formatIndex] == 'h') {
        args[arg_index].len = 'h';
      } else if (format[formatIndex] == 'l') {
        args[arg_index].len = 'l';
      } else if (format[formatIndex] == 'L') {
        args[arg_index].len = 'L';
      }
    }
  }
}

int is_digit(char ch) {
  int res = 0;
  if (ch >= '0' && ch <= '9') {
    res = 1;
  }
  return res;
}

int s21_atoi(char *str) {
  int res = 0;

  if (str[0] == '-') {
    for (int i = 1; str[i] != '\0'; i++) {
      res = res * 10 + str[i] - '0';
    }
    res *= -1;
  } else {
    for (int i = 0; str[i] != '\0'; i++) {
      res = res * 10 + str[i] - '0';
    }
  }

  return res;
}

int args_counter(const char *format) {
  int counter = 0;
  for (int i = 0; format[i] != '\0'; i++) {
    if (format[i] == '%' && format[i + 1] != '%') {
      counter++;
    }
  }
  return counter;
}

int parseAccuracy(const char *format, int *formatIndex) {
  int result = 0;
  if (format[*formatIndex] == '*') {
    result = '*';
  } else {
    char buffer[10] = {0};
    int i = 0;
    for (; i < 10 && is_digit(format[*formatIndex]); (*formatIndex)++, i++) {
      buffer[i] = format[*formatIndex];
    }
    if (i != 0) {
      result = s21_atoi(buffer);
    }
    (*formatIndex)--;
  }
  return result;
}

int parseWidth(const char *format, int *formatIndex) {
  int result = 0;
  if (format[*formatIndex] == '*') {
    result = '*';
  } else {
    char buffer[10] = {0};
    int i = 0;
    for (; i < 10 && is_digit(format[*formatIndex]); i++, (*formatIndex)++) {
      buffer[i] = format[*formatIndex];
    }
    if (i != 0) {
      result = s21_atoi(buffer);
    }
    (*formatIndex)--;
  }
  return result;
}

arguments *initArguments(const char *format) {
  int args_count = args_counter(format);
  arguments *args = S21_NULL;
  if (args_count > 0) {
    args = calloc(args_count, sizeof(arguments));
    if (args) parser(format, args);
  }
  return args;
}

// Other
char *argToString(arguments arg, va_list va) {
  char *result = S21_NULL;
  if (arg.specifier == 'c') {
    if (arg.len == 'l') {
      wchar_t w_ch = va_arg(va, wchar_t);
      result = (char *)calloc(MB_CUR_MAX + 1, sizeof(char));
      wctomb(result, w_ch);
    } else {
      char ch = va_arg(va, int);
      result = (char *)calloc(2, sizeof(char));
      result[0] = ch;
    }
  } else if (arg.specifier == 'd' || arg.specifier == 'i') {
    int64_t value = va_arg(va, int64_t);

    if (arg.len == 'h') {
      value = (int16_t)value;
    } else if (arg.len == 0) {
      value = (int32_t)value;
    } else if (arg.len == 'l') {
      value = (int64_t)value;
    }
    result = int_to_str(value);
  } else if (arg.specifier == 'f') {
    long double value = 0;
    if (arg.len == 'L') {
      value = va_arg(va, long double);
    } else {
      value = va_arg(va, double);
    }
    result = double_to_str(value, arg);
  } else if (arg.specifier == 'o' || arg.specifier == 'x' ||
             arg.specifier == 'X' || arg.specifier == 'u') {
    int base = 10;
    uint64_t value = va_arg(va, uint64_t);
    if (arg.specifier == 'o') {
      base = 8;
    } else if (arg.specifier == 'x' || arg.specifier == 'X') {
      base = 16;
    }

    if (arg.len == 'h') {
      value = (uint16_t)value;
    } else if (arg.len == 0) {
      value = (uint32_t)value;
    } else if (arg.len == 'l') {
      value = (uint64_t)value;
    }
    result = uint_to_str(value, base);
    if (arg.specifier == 'X') {
      char *temp = s21_to_upper(result);
      free(result);
      result = temp;
    }
  } else if (arg.specifier == 's') {
    if (arg.len == 'l') {
      wchar_t *w_str = va_arg(va, wchar_t *);
      result = (char *)calloc(wcslen(w_str) * MB_CUR_MAX + 1, sizeof(char));
      wcstombs(result, w_str, wcslen(w_str) * MB_CUR_MAX);
    } else {
      char *temp = va_arg(va, char *);
      result = (char *)calloc(s21_strlen(temp) + 1, sizeof(char));
      s21_strcat(result, temp);
    }
  } else if (arg.specifier == 'p') {
    uintptr_t address = (uintptr_t)va_arg(va, uintptr_t);
    result = uint_to_str(address, 16);
    char *temp = s21_insert(result, "0x", 0);
    free(result);
    result = temp;
  }
  return result;
}

char *int_to_str(int64_t number) {
  int minusFlag = 0;
  if (number < 0) {
    number = -number;
    minusFlag = 1;
  }
  int64_t temp = number;
  int len = 0;
  if (number == 0) len = 1;

  while (temp != 0) {
    temp = temp / 10;
    len++;
  }
  char *result = (char *)calloc(len + minusFlag + 1, sizeof(char));

  for (int i = len - 1; i >= 0; i--) {
    result[i] = (char)(number % 10) + 48;
    number = number / 10;
  }
  if (minusFlag == 1) {
    char *temp = s21_insert(result, "-", 0);
    free(result);
    result = temp;
  }
  return result;
}

char *uint_to_str(uint64_t number, int base) {
  uint64_t temp = number;
  int len = 0;
  if (number == 0) len = 1;

  while (temp != 0) {
    temp = temp / base;
    len++;
  }

  char *result = (char *)calloc(len + 1, sizeof(char));

  for (int i = len - 1; i >= 0; i--) {
    temp = number % base;
    if (temp < 10) {
      result[i] = (char)temp + 48;
    } else {
      result[i] = (char)temp + 87;
    }
    number = number / base;
  }

  return result;
}

char *double_to_str(long double num, arguments arg) {
  char *result = S21_NULL;
  int minusFlag = 0;
  if (num < 0) {
    num = -num;
    minusFlag = 1;
  }

  uint64_t left_int = 0;

  if (arg.accuracy == 0 && arg.isAccSet == 1) {
    left_int = (uint64_t)roundl(num);
    result = uint_to_str(left_int, 10);
    if (minusFlag == 1) {
      char *temp = (char *)calloc(s21_strlen(result) + 2, sizeof(char));
      s21_strcat(temp, "-");
      s21_strcat(temp, result);
      free(result);
      result = temp;
    }
  } else {
    if (arg.isAccSet == 0) arg.accuracy = 6;
    if (arg.accuracy < 0) arg.accuracy = 0;

    long double left_dbl = (uint64_t)num, right_dbl = num - left_dbl;

    char right_str[512] = {'\0'};
    char *left_str = S21_NULL;
    long double pogr = 0.05;
    if (arg.accuracy <= 6) pogr = 0.0005;
    if (arg.accuracy >= 12) pogr = 5e-2;

    for (int i = 0; i < arg.accuracy && i < 512; i++) {
      right_dbl = right_dbl * 10;
      if (i + 1 == arg.accuracy) {
        uint64_t temp = (uint64_t)(right_dbl * 10 + 0.05) % 10;
        if (temp >= 5) {
          right_dbl++;
          if (arg.accuracy == 1) left_dbl++;
        }
      }
      right_str[i] = '0' + ((uint64_t)(right_dbl + pogr)) % 10;
    }

    left_int = (uint64_t)left_dbl;
    left_str = uint_to_str(left_int, 10);

    s21_size_t len1 = s21_strlen(left_str);
    s21_size_t len2 = s21_strlen(right_str);

    result = (char *)calloc(len1 + len2 + 3, sizeof(char));

    if (minusFlag == 1) {
      s21_strcat(result, "-");
    }
    s21_strcat(result, left_str);
    s21_strcat(result, ".");
    s21_strcat(result, right_str);
    free(left_str);
  }
  return result;
}

// For sprintf
char *add_width(char *source, int num, char ch) {
  int src_len = (int)s21_strlen(source);
  int numIsPositive = 1;

  if (num < 0) {
    numIsPositive = 0;
    num = -num;
  }

  char *str = S21_NULL;
  if (src_len >= num) {
    str = (char *)calloc(src_len + 1, sizeof(char));
    s21_strcat(str, source);
  } else {
    str = (char *)calloc(num + 1, sizeof(char));
    if (numIsPositive == 1) {
      if (ch == ' ') {
        int i = 0;
        for (; i < num - src_len; i++) {
          str[i] = ch;
        }
        for (int a = 0; i < num && a < src_len; i++, a++) {
          str[i] = source[a];
        }
      } else if (ch == '0') {
        int minusFlag = 0;
        if (source[0] == '-') {
          minusFlag = 1;
        }
        if (minusFlag) str[0] = '-';
        int i = minusFlag;
        for (; i < num - src_len + minusFlag; i++) {
          str[i] = ch;
        }
        for (int a = 0; i < num && a < src_len; a++) {
          if (source[a] != '-') {
            str[i] = source[a];
            i++;
          }
        }
      }
    } else {
      int i = 0;
      for (; i < src_len; i++) {
        str[i] = source[i];
      }
      for (; i < num; i++) {
        str[i] = ch;
      }
    }
  }

  return str;
}

char *add_sign(char *str) {
  s21_size_t len = s21_strlen(str);
  char *src = S21_NULL;
  if (str) {
    if (str[0] != '-') {
      src = (char *)calloc(len + 2, sizeof(char));
      src[0] = '+';
      for (int i = 1; i <= (int)len; i++) {
        src[i] = str[i - 1];
      }
    } else {
      src = (char *)calloc(len + 1, sizeof(char));
      for (int i = 0; i < (int)len; i++) {
        src[i] = str[i];
      }
    }
  }

  return src;
}

char *accuracy_str(char *str, int acc) {
  char *src = S21_NULL;
  if (acc < (int)s21_strlen(str)) {
    src = (char *)calloc(acc + 1, sizeof(char));
    for (int i = 0; i < acc; i++) {
      src[i] = str[i];
    }
  } else {
    src = (char *)calloc(s21_strlen(str) + 1, sizeof(char));
    s21_strcat(src, str);
  }
  return src;
}

char *accuracy_float(char *str, int acc) {
  char *src = S21_NULL;
  int dotIndex = 0;
  int strLen = (int)s21_strlen(str);

  for (int i = 0; i < strLen; i++) {
    if (str[i] == '.') {
      dotIndex = i;
    }
  }

  int fractPart = strLen - dotIndex - 1;
  src = (char *)calloc(dotIndex + acc + 3, sizeof(char));
  if (fractPart >= acc) {
    int tempFlag = 0;
    if (acc != 0) tempFlag = 1;
    s21_strncat(src, str, dotIndex + acc + tempFlag);
  } else {
    s21_strncat(src, str, strLen);
    int tempFlag = 0;
    if (dotIndex == 0) {
      s21_strcat(src, ".");
      tempFlag = 1;
    }
    for (int i = strLen + tempFlag; i < dotIndex + acc + tempFlag + 1; i++) {
      src[i] = '0';
    }
  }

  return src;
}

char *accuracy_int(char *str, int acc) {
  char *src = S21_NULL;

  int strLen = (int)s21_strlen(str);
  int signFlag = 0;
  if (str[0] == '+' || str[0] == '-') {
    signFlag = 1;
  }

  int realAccuracy = acc - strLen + signFlag;

  if (acc == 0 && (s21_atoi(str) == 0)) {
    src = (char *)calloc(1, sizeof(char));
  } else {
    if (realAccuracy <= 0) {
      src = (char *)calloc(strLen + 1, sizeof(char));
      s21_strcat(src, str);
    } else {
      src = (char *)calloc(acc + signFlag + 1, sizeof(char));
      if (signFlag == 1) src[0] = str[0];
      int i = 0;
      for (; i < realAccuracy; i++) {
        s21_strcat(src, "0");
      }
      i += signFlag;
      for (int j = signFlag; j < strLen; j++, i++) {
        src[i] = str[j];
      }
    }
  }
  return src;
}

char *sign_space(char *str) {
  char *src = S21_NULL;
  if (*str != '-') {
    src = s21_insert(str, " ", 0);
  } else {
    src = (char *)calloc(s21_strlen(str) + 1, sizeof(char));
    s21_strcat(src, str);
  }
  return src;
}
