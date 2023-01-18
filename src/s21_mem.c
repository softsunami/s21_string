#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *buffer = (unsigned char *)str;
  unsigned char *result = S21_NULL;
  for (s21_size_t i = 0; i < n; i++) {
    if (buffer[i] == c) {
      result = &buffer[i];
      i = n + 1;
    }
  }
  return result;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int flag = 0;
  int result = 0;
  if (str1 == S21_NULL || str2 == S21_NULL) {
    flag = -1;
  }

  if (n == 0) {
    result = 0;
    flag = -1;
  }

  if (flag == 0) {
    const unsigned char *s1 = str1;
    const unsigned char *s2 = str2;

    for (s21_size_t i = 0; i < n; i++) {
      if (s1[i] != s2[i]) {
        result = (int)(s1[i] - s2[i]);
        break;
      }
    }
  }
  return result;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *dest2 = (unsigned char *)dest;
  unsigned char *src2 = (unsigned char *)src;

  for (s21_size_t i = 0; i < n; i++) {
    dest2[i] = src2[i];
  }
  return dest;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  unsigned char *d = (unsigned char *)dest;
  unsigned char *s = (unsigned char *)src;
  if (d < s) {
    for (s21_size_t i = 0; i < n; i++) {
      d[i] = s[i];
    }
  } else if (d > s) {
    for (s21_size_t i = n; i > 0; i--) {
      d[i - 1] = s[i - 1];
    }
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  char *temp = (char *)str;
  for (s21_size_t i = 0; i < n; i++) {
    temp[i] = c;
  }
  return str;
}
