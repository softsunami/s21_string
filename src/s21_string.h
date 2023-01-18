#ifndef SRC_S21_STRING_H
#define SRC_S21_STRING_H

#include <stdarg.h>
#include <stdint.h>

#define S21_NULL ((void *)0)
#define OK 0
#define ERROR 1

typedef unsigned long int s21_size_t;

typedef struct arguments {
  char specifier;
  int minus;
  int plus;
  int space;
  int sharp;
  int zero;
  int width;
  int accuracy;
  int isAccSet;
  char len;
} arguments;

// s21_str.c
char *s21_strcat(char *dest, const char *src);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
char *s21_strcpy(char *dest, const char *src);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

// s21_mem.c
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);

// s21_csharp.c
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_to_lower(const char *str);
void *s21_to_upper(const char *str);
void *s21_trim(const char *src, const char *trim_chars);

// s21_sprintf.c
// parse functions
arguments *initArguments(const char *format);
void parser(const char *format, arguments *args);
int parseAccuracy(const char *format, int *formatIndex);
int parseWidth(const char *format, int *formatIndex);
int args_counter(const char *format);
int is_digit(char ch);
int s21_atoi(char *str);

// convert to string functions
char *argToString(arguments arg, va_list va);
char *int_to_str(int64_t number);
char *uint_to_str(uint64_t number, int base);
char *double_to_str(long double num, arguments arg);

// processing functions
int s21_sprintf(char *str, const char *format, ...);
char *process_flags(arguments *arg, char *buffer);
char *process_width(arguments *arg, char *buffer);
char *process_accuracy(arguments *arg, char *buffer);

// helps
char *add_width(char *source, int num, char ch);
char *add_sign(char *str);
char *accuracy_str(char *str, int acc);
char *accuracy_float(char *str, int acc);
char *accuracy_int(char *str, int acc);
char *sign_space(char *str);

#endif  // SRC_S21_STRING_H
