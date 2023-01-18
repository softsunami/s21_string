#include "s21_string.h"

char *s21_strcat(char *dest, const char *src) {
  s21_size_t dest_len = s21_strlen(dest);
  s21_size_t i;
  for (i = 0; src[i] != '\0'; i++) {
    dest[dest_len + i] = src[i];
  }
  dest[dest_len + i] = '\0';
  return dest;
}

char *s21_strchr(const char *str, int c) {
  int i = 0;
  while (str[i] && str[i] != c) i++;
  return c == str[i] ? (char *)str + i : S21_NULL;
}

int s21_strcmp(const char *str1, const char *str2) {
  int result = 0;
  if (str1 && str2) {
    int i = 0;
    while (str1[i] && str1[i] == str2[i]) {
      i++;
    }
    result = str1[i] - str2[i];
  }

  return result;
}

char *s21_strcpy(char *dest, const char *src) {
  s21_size_t i = 0;
  for (; src[i] != '\0'; i++) {
    dest[i] = src[i];
  }
  dest[i] = '\0';
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t result = 0;
  while (str1[result] && !s21_strchr(str2, str1[result])) {
    result++;
  }
  return result;
}

char *s21_strerror(int errnum) {
  static const char *errors[] = {
      "Undefined error: 0",
      "Operation not permitted",
      "No such file or directory",
      "No such process",
      "Interrupted system call",
      "Input/output error",
      "Device not configured",
      "Argument list too long",
      "Exec format error",
      "Bad file descriptor",
      "No child processes",
      "Resource deadlock avoided",
      "Cannot allocate memory",
      "Permission denied",
      "Bad address",
      "Block device required",
      "Resource busy",
      "File exists",
      "Cross-device link",
      "Operation not supported by device",
      "Not a directory",
      "Is a directory",
      "Invalid argument",
      "Too many open files in system",
      "Too many open files",
      "Inappropriate ioctl for device",
      "Text file busy",
      "File too large",
      "No space left on device",
      "Illegal seek",
      "Read-only file system",
      "Too many links",
      "Broken pipe",
      "Numerical argument out of domain",
      "Result too large",
      "Resource temporarily unavailable",
      "Operation now in progress",
      "Operation already in progress",
      "Socket operation on non-socket",
      "Destination address required",
      "Message too long",
      "Protocol wrong type for socket",
      "Protocol not available",
      "Protocol not supported",
      "Socket type not supported",
      "Operation not supported",
      "Protocol family not supported",
      "Address family not supported by protocol family",
      "Address already in use",
      "Can't assign requested address",
      "Network is down",
      "Network is unreachable",
      "Network dropped connection on reset",
      "Software caused connection abort",
      "Connection reset by peer",
      "No buffer space available",
      "Socket is already connected",
      "Socket is not connected",
      "Can't send after socket shutdown",
      "Too many references: can't splice",
      "Operation timed out",
      "Connection refused",
      "Too many levels of symbolic links",
      "File name too long",
      "Host is down",
      "No route to host",
      "Directory not empty",
      "Too many processes",
      "Too many users",
      "Disc quota exceeded",
      "Stale NFS file handle",
      "Too many levels of remote in path",
      "RPC struct is bad",
      "RPC version wrong",
      "RPC prog. not avail",
      "Program version wrong",
      "Bad procedure for program",
      "No locks available",
      "Function not implemented",
      "Inappropriate file type or format",
      "Authentication error",
      "Need authenticator",
      "Device power is off",
      "Device error",
      "Value too large to be stored in data type",
      "Bad executable (or shared library)",
      "Bad CPU type in executable",
      "Shared library version mismatch",
      "Malformed Mach-o file",
      "Operation canceled",
      "Identifier removed",
      "No message of desired type",
      "Illegal byte sequence",
      "Attribute not found",
      "Bad message",
      "EMULTIHOP (Reserved)",
      "No message available on STREAM",
      "ENOLINK (Reserved)",
      "No STREAM resources",
      "Not a STREAM",
      "Protocol error",
      "STREAM ioctl timeout",
      "Operation not supported on socket",
      "Policy not found",
      "State not recoverable",
      "Previous owner died",
      "Interface output queue is full"};

  static char buffer[80];
  if (errnum < 0 || errnum > 106) {
    s21_sprintf(buffer, "Unknown error: %d", errnum);
  } else {
    s21_strcpy(buffer, errors[errnum]);
  }

  return buffer;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t result = 0;
  if (str == S21_NULL) {
    result = 0;
  } else {
    while (str[result] != '\0') {
      result++;
    }
  }
  return result;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t dest_len = s21_strlen(dest);
  s21_size_t i;
  for (i = 0; src[i] != '\0' && i < n; i++) {
    dest[dest_len + i] = src[i];
  }
  dest[dest_len + i] = '\0';
  return dest;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  if (str1 && str2 && n > 0) {
    for (s21_size_t i = 0; i < n; i++) {
      if (str1[i] == '\0' || str1[i] != str2[i]) {
        result = str1[i] - str2[i];
        break;
      }
    }
  }
  return result;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;
  for (; src[i] != '\0' && i < n; i++) {
    dest[i] = src[i];
  }
  dest[i] = '\0';
  return dest;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = S21_NULL;
  for (const char *a = str1; *a; a++) {
    for (const char *b = str2; *b; b++) {
      if (*a == *b) {
        result = (char *)a;
        break;
      }
    }
    if (result) {
      break;
    }
  }
  return result;
}

char *s21_strrchr(const char *str, int c) {
  char *result = S21_NULL;
  int i = 0;
  for (; str[i]; i++) {
    if (str[i] == c) {
      result = (char *)str + i;
    }
  }
  if (c == '\0') {
    result = (char *)str + i;
  }
  return result;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t len1 = s21_strlen(str1);
  s21_size_t len2 = s21_strlen(str2);
  s21_size_t result = 0;
  for (s21_size_t i = 0; i < len1; i++) {
    int found = 0;
    for (s21_size_t j = 0; j < len2; j++) {
      if (str1[i] == str2[j]) {
        found = 1;
        break;
      }
    }
    if (!found) {
      break;
    }
    result++;
  }
  return result;
}

char *s21_strstr(const char *haystack, const char *needle) {
  s21_size_t len1 = s21_strlen(haystack);
  s21_size_t len2 = s21_strlen(needle);
  char *result = S21_NULL;
  int flag = 0;

  if (len2 > len1) {
    flag = -1;
  }
  if (len2 == 0) {
    flag = -1;
    result = (char *)(haystack);
  }

  if (flag == 0) {
    for (s21_size_t i = 0; i <= len1 - len2; i++) {
      if (s21_strncmp(haystack + i, needle, len2) == 0) {
        result = (char *)(haystack + i);
        break;
      }
    }
  }

  return result;
}

char *s21_strtok(char *str, const char *delim) {
  static char *new = S21_NULL;
  int flag = 0;
  if (!str) {
    str = new;
    if (str == S21_NULL) {
      flag = -1;
    }
  }
  if (flag == 0) {
    str += s21_strspn(str, delim);
    if (s21_strlen(str) == 0) {
      flag = -1;
    }
  }
  if (flag == 0) {
    new = str + s21_strcspn(str, delim);
    if (s21_strlen(new) != 0) {
      *new = '\0';
      new ++;
    } else {
      new = S21_NULL;
    }
  }
  return str;
}
