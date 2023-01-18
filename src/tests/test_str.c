#include "tests.h"

START_TEST(test_strcat) {
  // Test concatenating two empty strings
  {
    char dest1[20] = {0};
    char dest2[20] = {0};
    s21_strcat(dest1, "");
    strcat(dest2, "");
    ck_assert_str_eq(dest1, dest2);
  }

  // Test concatenating a non-empty string to an empty string
  {
    char dest1[20] = {0};
    char dest2[20] = {0};

    s21_strcat(dest1, "hello");
    strcat(dest2, "hello");
    ck_assert_str_eq(dest1, dest2);

    s21_strcat(dest1, " world");
    strcat(dest2, " world");
    ck_assert_str_eq(dest1, dest2);
  }

  // Test concatenating two non-empty strings
  {
    char dest1[20] = {0};
    char dest2[20] = {0};

    s21_strcat(dest1, "hello world");
    strcat(dest2, "hello world");
    ck_assert_str_eq(dest1, dest2);

    s21_strcat(dest1, "!");
    strcat(dest2, "!");
    ck_assert_str_eq(dest1, dest2);
  }
}
END_TEST

START_TEST(test_strchr) {
  // Test a string that contains the character we are searching for
  {
    char *str = "hello world";
    ck_assert_str_eq(s21_strchr(str, 'l'), strchr(str, 'l'));
    ck_assert_str_eq(s21_strchr(str, 'o'), strchr(str, 'o'));
  }

  // Test a string that does not contain the character we are searching for
  {
    char *str = "abcdefg";
    ck_assert_ptr_eq(s21_strchr(str, 'x'), strchr(str, 'x'));
  }

  // Test the empty string
  {
    char *str = "";
    ck_assert_ptr_eq(s21_strchr(str, 'x'), strchr(str, 'x'));
  }

  // Test a string that contains the null character
  {
    char *str = "abc\0def";
    ck_assert_ptr_eq(s21_strchr(str, '\0'), strchr(str, '\0'));
    ck_assert_ptr_eq(s21_strchr(str, 'd'), strchr(str, 'd'));
  }
}
END_TEST

START_TEST(test_strcmp) {
  ck_assert_int_eq(s21_strcmp("abc", "abc"), strcmp("abc", "abc"));
  ck_assert_int_lt(s21_strcmp("abc", "abd"), 0);
  ck_assert_int_lt(s21_strcmp("abcd", "abce"), 0);
  ck_assert_int_gt(s21_strcmp("abce", "abcd"), 0);
  ck_assert_int_lt(s21_strcmp("abcd", "abce"), 0);
  ck_assert_int_lt(s21_strcmp("abc", "def"), 0);
  ck_assert_int_eq(s21_strcmp("", ""), strcmp("", ""));
  ck_assert_int_gt(s21_strcmp("a", ""), 0);
  ck_assert_int_lt(s21_strcmp("", "a"), 0);
}
END_TEST

START_TEST(test_strcpy) {
  // Test simple copy
  {
    char dest1[20] = {0};
    char dest2[20] = {0};
    char *source = "hello";
    s21_strcpy(dest1, source);
    strcpy(dest2, source);
    ck_assert_str_eq(dest1, dest2);
  }

  // Test copy with larger destination array
  {
    char dest1[20] = {0};
    char dest2[20] = {0};
    char *source = "hello world";
    s21_strcpy(dest1, source);
    strcpy(dest2, source);
    ck_assert_str_eq(dest1, dest2);
  }

  // Test copy with overlapping src and dest
  {
    char dest1[20] = "hello";
    s21_strcpy(dest1, dest1);
    ck_assert_str_eq(dest1, "hello");
  }
}
END_TEST

START_TEST(test_strcspn) {
  ck_assert_int_eq(s21_strcspn("abcdefg", "xyz"), strcspn("abcdefg", "xyz"));
  ck_assert_int_eq(s21_strcspn("abcdefg", "efg"), strcspn("abcdefg", "efg"));
  ck_assert_int_eq(s21_strcspn("abcdefg", "abc"), strcspn("abcdefg", "abc"));
  ck_assert_int_eq(s21_strcspn("", "abc"), strcspn("", "abc"));
  ck_assert_int_eq(s21_strcspn("abcdefg", ""), strcspn("abcdefg", ""));
}
END_TEST

START_TEST(test_strerror) {
  for (int i = -5; i < 130; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
}
END_TEST

START_TEST(test_strlen) {
  // Test length of an empty string
  const char *empty_string = "";
  ck_assert_int_eq(s21_strlen(empty_string), strlen(empty_string));

  // Test length of a non-empty string
  const char *non_empty_string = "Hello, world!";
  ck_assert_int_eq(s21_strlen(non_empty_string), strlen(non_empty_string));

  // Test length of a string with embedded null characters
  const char *embedded_nulls_string = "Hello\0world!";
  ck_assert_int_eq(s21_strlen(embedded_nulls_string),
                   strlen(embedded_nulls_string));
}
END_TEST

START_TEST(test_strncat) {
  // Test the s21_strncat function with a small destination string and a small
  {
    char dest1[10] = "abc";
    char dest2[10] = "abc";
    const char *src = "def";
    size_t n = 2;
    s21_strncat(dest1, src, n);
    strncat(dest2, src, n);
    ck_assert_str_eq(dest1, dest2);
  }

  // Test the s21_strncat function with a small destination string and a large
  {
    char dest1[10] = "abc";
    char dest2[10] = "abc";
    const char *src = "defghijklmno";
    size_t n = 5;
    s21_strncat(dest1, src, n);
    strncat(dest2, src, n);
    ck_assert_str_eq(dest1, dest2);
  }

  // Test the s21_strncat function with a large destination string and a small
  {
    char dest1[15] = "abcdefghij";
    char dest2[15] = "abcdefghij";
    const char *src = "klm";
    size_t n = 3;
    s21_strncat(dest1, src, n);
    strncat(dest2, src, n);
    ck_assert_str_eq(dest1, dest2);
  }

  // Test the s21_strncat function with an empty source string
  {
    char dest1[10] = "abc";
    char dest2[10] = "abc";
    const char *src = "";
    size_t n = 10;
    s21_strncat(dest1, src, n);
    strncat(dest2, src, n);
    ck_assert_str_eq(dest1, dest2);
  }

  // Test the s21_strncat function with an empty destination string
  {
    char dest1[10] = "";
    char dest2[10] = "";
    const char *src = "abc";
    size_t n = 10;
    s21_strncat(dest1, src, n);
    strncat(dest2, src, n);
    ck_assert_str_eq(dest1, dest2);
  }

  // Test the s21_strncat function with a null destination string
  {
    char dest1[10] = {0};
    char dest2[10] = {0};
    const char *src = "abc";
    size_t n = 10;
    s21_strncat(dest1, src, n);
    strncat(dest2, src, n);
    ck_assert_str_eq(dest1, dest2);
  }
}
END_TEST

START_TEST(test_strncmp) {
  ck_assert_int_eq(s21_strncmp("abc", "abc", 3), strncmp("abc", "abc", 3));
  ck_assert_int_eq(s21_strncmp("abc", "abd", 3), strncmp("abc", "abd", 3));
  ck_assert_int_eq(s21_strncmp("abcd", "abce", 3), strncmp("abcd", "abce", 3));
  ck_assert_int_eq(s21_strncmp("abce", "abcd", 3), strncmp("abce", "abcd", 3));
  ck_assert_int_eq(s21_strncmp("abcd", "abce", 4), strncmp("abcd", "abce", 4));
  ck_assert_int_eq(s21_strncmp("abc", "def", 2), strncmp("abc", "def", 2));
  ck_assert_int_eq(s21_strncmp("", "", 1), strncmp("", "", 1));
  ck_assert_int_eq(s21_strncmp("a", "", 1), strncmp("a", "", 1));
  ck_assert_int_eq(s21_strncmp("", "a", 1), strncmp("", "a", 1));
}
END_TEST

START_TEST(test_strncpy) {
  char dest[30];

  // Test copy a short string to a long string
  ck_assert_str_eq(s21_strncpy(dest, "abc", 10), strncpy(dest, "abc", 10));

  // Test copy a long string to a short string
  ck_assert_str_eq(s21_strncpy(dest, "abcdefghijklmnopqrstuvwxyz", 27),
                   strncpy(dest, "abcdefghijklmnopqrstuvwxyz", 27));

  // Test copy a string of length 0
  ck_assert_str_eq(s21_strncpy(dest, "", 10), strncpy(dest, "", 10));

  // Test copy a string with n = 1
  ck_assert_str_eq(s21_strncpy(dest, "abcdefghij", 11),
                   strncpy(dest, "abcdefghij", 11));
}
END_TEST

START_TEST(test_strpbrk) {
  ck_assert_str_eq(s21_strpbrk("hello", "l"), strpbrk("hello", "l"));
  ck_assert_str_eq(s21_strpbrk("hello", "o"), strpbrk("hello", "o"));
  ck_assert_ptr_eq(s21_strpbrk("hello", "z"), strpbrk("hello", "z"));
  ck_assert_ptr_eq(s21_strpbrk("", "l"), strpbrk("", "l"));
  ck_assert_ptr_eq(s21_strpbrk("hello", ""), strpbrk("hello", ""));
}
END_TEST

START_TEST(test_strrchr) {
  //   Test a string that contains the character we are searching for
  {
    char *str = "hello world";
    ck_assert_str_eq(s21_strrchr(str, 'l'), strrchr(str, 'l'));
    ck_assert_str_eq(s21_strrchr(str, 'o'), strrchr(str, 'o'));
  }

  // Test a string that does not contain the character we are searching for
  {
    char *str = "abcdefg";
    ck_assert_ptr_eq(s21_strrchr(str, 'x'), strrchr(str, 'x'));
  }

  // Test the empty string
  {
    char *str = "";
    ck_assert_ptr_eq(s21_strrchr(str, 'x'), strrchr(str, 'x'));
  }

  // Test a string that contains the null character
  {
    char *str = "abc\0def";
    ck_assert_ptr_eq(s21_strrchr(str, '\0'), strrchr(str, '\0'));
    ck_assert_ptr_eq(s21_strrchr(str, 'd'), strrchr(str, 'd'));
  }
}
END_TEST

START_TEST(test_strspn) {
  ck_assert_int_eq(s21_strspn("abcdef", "abc"), strspn("abcdef", "abc"));
  ck_assert_int_eq(s21_strspn("abcdef", "def"), strspn("abcdef", "def"));
  ck_assert_int_eq(s21_strspn("abcdef", "abcdef"), strspn("abcdef", "abcdef"));
  ck_assert_int_eq(s21_strspn("abcdef", "ghijkl"), strspn("abcdef", "ghijkl"));
  ck_assert_int_eq(s21_strspn("", "abcdef"), strspn("", "abcdef"));
  ck_assert_int_eq(s21_strspn("abcdef", ""), strspn("abcdef", ""));
}
END_TEST

START_TEST(test_strstr) {
  ck_assert_str_eq(s21_strstr("", ""), strstr("", ""));
  ck_assert_str_eq(s21_strstr("hello", ""), strstr("hello", ""));
  ck_assert_ptr_eq(s21_strstr("", "world"), strstr("", "world"));
  ck_assert_ptr_eq(s21_strstr("hello", "world"), strstr("hello", "world"));
  ck_assert_str_eq(s21_strstr("hello", "he"), strstr("hello", "he"));
  ck_assert_str_eq(s21_strstr("hello", "lo"), strstr("hello", "lo"));
  ck_assert_str_eq(s21_strstr("hello", "ll"), strstr("hello", "ll"));
  ck_assert_str_eq(s21_strstr("hello", "hello"), strstr("hello", "hello"));
  ck_assert_str_eq(s21_strstr("hellohello", "hello"),
                   strstr("hellohello", "hello"));
}
END_TEST

START_TEST(test_strtok) {
  char input[100] = "Hello, World!";
  char *delim = " ,";  // delimiters are comma and space
  char *token;

  // Test splitting input string into tokens
  token = s21_strtok(input, delim);
  ck_assert_str_eq(token, "Hello");

  token = s21_strtok(NULL, delim);
  ck_assert_str_eq(token, "World!");

  token = s21_strtok(NULL, delim);
  ck_assert_ptr_eq(token, NULL);
}
END_TEST

Suite *s21_string_suite() {
  Suite *s1 = suite_create("s21_string");
  TCase *tc1 = tcase_create("Core");

  tcase_add_test(tc1, test_strcat);
  tcase_add_test(tc1, test_strchr);
  tcase_add_test(tc1, test_strcmp);
  tcase_add_test(tc1, test_strcpy);
  tcase_add_test(tc1, test_strcspn);
  tcase_add_test(tc1, test_strerror);
  tcase_add_test(tc1, test_strlen);
  tcase_add_test(tc1, test_strncat);
  tcase_add_test(tc1, test_strncmp);
  tcase_add_test(tc1, test_strncpy);
  tcase_add_test(tc1, test_strpbrk);
  tcase_add_test(tc1, test_strrchr);
  tcase_add_test(tc1, test_strspn);
  tcase_add_test(tc1, test_strstr);
  tcase_add_test(tc1, test_strtok);

  suite_add_tcase(s1, tc1);

  return s1;
}

int test_str() {
  int no_failed = 0;

  Suite *s1 = s21_string_suite();
  SRunner *runner = srunner_create(s1);

  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return no_failed;
}