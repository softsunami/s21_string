#include <stdlib.h>

#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  s21_size_t len1 = s21_strlen(src);
  s21_size_t len2 = s21_strlen(str);
  int flag = 0;
  char *result = S21_NULL;

  if ((int)start_index < 0 || start_index > len1) {
    flag = 1;
  }
  if (!flag) {
    result = (char *)calloc(len1 + len2 + 1, sizeof(char));
    s21_size_t src_i = 0, str_i = 0, res_i = 0;

    while (res_i < len1 + len2) {
      if (res_i >= start_index && res_i < start_index + len2) {
        result[res_i] = str[str_i];
        str_i++;
      } else {
        result[res_i] = src[src_i];
        src_i++;
      }
      res_i++;
    }
    result[res_i] = '\0';
  }
  return result;
}

void *s21_to_lower(const char *str) {
  s21_size_t len = s21_strlen(str);
  char *result = (char *)calloc(len + 1, sizeof(char));
  if (result != S21_NULL) {
    for (s21_size_t i = 0; i < len; i++) {
      if (str[i] >= 'A' && str[i] <= 'Z') {
        result[i] = str[i] + 32;
      } else {
        result[i] = str[i];
      }
    }
  }
  return result;
}

void *s21_to_upper(const char *str) {
  s21_size_t len = s21_strlen(str);
  char *result = (char *)calloc(len + 1, sizeof(char));
  if (result != S21_NULL) {
    for (s21_size_t i = 0; i < len; i++) {
      if (str[i] >= 'a' && str[i] <= 'z') {
        result[i] = str[i] - 32;
      } else {
        result[i] = str[i];
      }
    }
  }
  return result;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *result = S21_NULL;
  if (src) {
    if (!trim_chars) {
      trim_chars = " ";
    }
    char *ptr_str = (char *)src;
    char *end_str = (char *)src + s21_strlen(src);
    for (; *ptr_str && s21_strchr(trim_chars, *ptr_str); ptr_str++)
      ;
    for (; end_str != ptr_str && s21_strchr(trim_chars, *(end_str - 1));
         end_str--)
      ;
    result = (char *)calloc(end_str - ptr_str + 1, sizeof(char));
    if (result) {
      s21_strncpy(result, ptr_str, end_str - ptr_str);
      *(result + (end_str - ptr_str)) = '\0';
    }
  }
  return result;
}
