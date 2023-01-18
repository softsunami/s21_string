#include <stdlib.h>

#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  int strIndex = 0, formatIndex = 0, flag = OK;
  arguments *args = S21_NULL;

  va_list va;
  va_start(va, format);

  if (args_counter(format) == 0) {
    s21_strcat(str, format);
    strIndex = s21_strlen(str);
    flag = ERROR;
  }

  if (flag == OK) {
    args = initArguments(format);
    if (!args) flag = ERROR;
  }
  if (flag == OK) {
    int argIndex = 0;
    char specifier = '\0';
    char *buffer = S21_NULL;

    while (format[formatIndex] != '\0') {
      if (format[formatIndex] != '%') {
        str[strIndex] = format[formatIndex];
        strIndex++;
        formatIndex++;
        continue;
      }
      formatIndex++;
      specifier = args[argIndex].specifier;
      if (args[argIndex].width == '*') args[argIndex].width = va_arg(va, int);
      if (args[argIndex].accuracy == '*')
        args[argIndex].accuracy = va_arg(va, int);

      if (specifier == 'n') {
        int *temp = va_arg(va, int *);
        *temp = strIndex;
        formatIndex++;
        continue;
      } else if (specifier == '%') {
        str[strIndex] = '%';
        strIndex++;
        formatIndex++;
        continue;
      } else if (s21_strchr("cdifoxXusp", specifier)) {
        buffer = argToString(args[argIndex], va);
        if (specifier != 'p') {
          buffer = process_accuracy(&args[argIndex], buffer);
          buffer = process_flags(&args[argIndex], buffer);
          buffer = process_width(&args[argIndex], buffer);
        }
        for (int i = 0; buffer[i] != '\0'; i++, strIndex++) {
          str[strIndex] = buffer[i];
        }
        free(buffer);

        while (s21_strchr("cdieEfgGosuxXpn%", format[formatIndex]) ==
               S21_NULL) {
          formatIndex++;
        }
        formatIndex++;
        argIndex++;
      }
    }
    free(args);
    str[strIndex] = '\0';
    va_end(va);
  }

  return s21_strlen(str);
}

char *process_flags(arguments *arg, char *buffer) {
  char *temp = buffer;

  // Process #
  int isAllZeros = 1;
  for (int i = 0; buffer[i] != '\0'; i++) {
    if (buffer[i] != '0') {
      isAllZeros = 0;
      break;
    }
  }
  if (s21_strchr("oxX", arg->specifier)) {
    if (arg->sharp != 0 && isAllZeros != 1) {
      if (arg->specifier == 'o') {
        temp = s21_insert(buffer, "0", 0);
      } else if (arg->specifier == 'x') {
        temp = s21_insert(buffer, "0x", 0);
      } else if (arg->specifier == 'X') {
        temp = s21_insert(buffer, "0X", 0);
      }
      free(buffer);
      buffer = temp;
    }
  }

  // Proccess -
  if (arg->minus != 0) {
    arg->zero = 0;
    arg->width = -arg->width;
  }

  // Process +
  if (s21_strchr("dif", arg->specifier)) {
    if (arg->plus != 0) {
      arg->space = 0;
      temp = add_sign(buffer);
      free(buffer);
      buffer = temp;
    }

    // Prorcess space
    if (arg->space != 0) {
      temp = sign_space(buffer);
      free(buffer);
      buffer = temp;
    }
  }
  return buffer;
}

char *process_width(arguments *arg, char *buffer) {
  char *temp = buffer;
  char ch = ' ';
  if (arg->zero != 0) {
    if (s21_strchr("dixX", arg->specifier) && arg->isAccSet != 0) {
      ch = ' ';
    } else {
      ch = '0';
    }
  }

  if (arg->width != 0) {
    temp = add_width(buffer, arg->width, ch);
    free(buffer);
    buffer = temp;
  }
  return buffer;
}

char *process_accuracy(arguments *arg, char *buffer) {
  char *temp = buffer;

  if (arg->accuracy < 0) arg->accuracy = 0;

  if (arg->isAccSet == 0) {
    if (arg->specifier != 's') arg->accuracy = 1;
    if (arg->specifier == 'f') {
      arg->accuracy = 6;
      arg->isAccSet = 1;
    }
  }
  if (arg->sharp != 0 && arg->specifier == 'o') arg->accuracy--;

  if (s21_strchr("diouxXs", arg->specifier) && arg->isAccSet == 1) {
    if (s21_strchr("diouxX", arg->specifier)) {
      temp = accuracy_int(buffer, arg->accuracy);
    } else if (arg->specifier == 'f') {
      //      temp = accuracy_float(buffer, arg->accuracy);
    } else if (arg->specifier == 's') {
      temp = accuracy_str(buffer, arg->accuracy);
    }
    free(buffer);
    buffer = temp;
  }
  return buffer;
}