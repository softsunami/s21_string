#include "tests.h"

START_TEST(test_memchr) {
  char str[] = "Hello, world!";

  // Test finding 'H' in the string
  {
    void *ptr1 = s21_memchr(str, 'H', strlen(str));
    void *ptr2 = memchr(str, 'H', strlen(str));
    if (ptr1 && ptr2) {
      ck_assert_ptr_eq(ptr1, ptr2);
    }
  }

  // Test finding 'o' in the string
  {
    void *ptr1 = s21_memchr(str, 'o', strlen(str));
    void *ptr2 = memchr(str, 'o', strlen(str));
    if (ptr1 && ptr2) {
      ck_assert_ptr_eq(ptr1, ptr2);
    }
  }

  // Test the behavior of s21_memchr when given a large value as the third
  // argument
  {
    void *ptr1 = s21_memchr(str, 'H', strlen(str));
    void *ptr2 = memchr(str, 'H', strlen(str));
    if (ptr1 && ptr2) {
      ck_assert_ptr_eq(ptr1, ptr2);
    }
  }

  // Test the behavior of s21_memchr when given a string that contains multiple
  // instances of the search character
  {
    char multi_str[] = "Hello, Hello, world!";
    void *ptr1 = s21_memchr(multi_str, 'H', strlen(str));
    void *ptr2 = memchr(multi_str, 'H', strlen(str));
    if (ptr1 && ptr2) {
      ck_assert_ptr_eq(ptr1, ptr2);
    }
  }

  //   Test the behavior of s21_memchr when given a string that contains the
  //   search character at the end
  {
    char end_str[] = "Hello, wo\0rld!H";
    void *ptr1 = s21_memchr(end_str, '\0', 14);
    void *ptr2 = memchr(end_str, '\0', 14);
    if (ptr1 && ptr2) {
      ck_assert_ptr_eq(ptr1, ptr2);
    }
  }
}
END_TEST

START_TEST(test_memcmp) {
  // Test equal strings
  char *str1 = "hello";
  char *str2 = "hello";
  ck_assert_int_eq(s21_memcmp(str1, str2, strlen(str1)),
                   memcmp(str1, str2, strlen(str1)));
  ck_assert_int_eq(s21_memcmp(str1, str2, strlen(str2)),
                   memcmp(str1, str2, strlen(str2)));

  // Test different strings
  char *str3 = "hello";
  char *str4 = "world";
  ck_assert_int_eq(s21_memcmp(str3, str4, strlen(str3)),
                   memcmp(str3, str4, strlen(str3)));
  ck_assert_int_eq(s21_memcmp(str3, str4, strlen(str4)),
                   s21_memcmp(str3, str4, strlen(str4)));

  // Test different lengths
  char *str5 = "hello";
  char *str6 = "he";
  ck_assert_int_eq(s21_memcmp(str5, str6, strlen(str5)),
                   s21_memcmp(str5, str6, strlen(str5)));
  ck_assert_int_eq(s21_memcmp(str5, str6, strlen(str6)),
                   s21_memcmp(str5, str6, strlen(str6)));

  // Test n = 0
  char *str7 = "hello";
  char *str8 = "world";
  ck_assert_int_eq(s21_memcmp(str7, str8, 0), memcmp(str7, str8, 0));
}
END_TEST

START_TEST(test_memcpy) {
  // Test normal usage
  {
    char src[20] = "hello world";
    char dest1[20] = {0};
    char dest2[20] = {0};
    s21_memcpy(dest1, src, 11);
    memcpy(dest2, src, 11);
    ck_assert_str_eq(dest1, dest2);
  }

  // Test zero size
  {
    char src[20] = "hello world";
    char dest1[20] = {0};
    char dest2[20] = {0};
    s21_memcpy(dest1, src, 0);
    memcpy(dest2, src, 0);
    ck_assert_str_eq(dest1, dest2);
  }

  // Test with terminator zero
  {
    char src[20] = "hel\0lo world";
    char dest1[20] = {0};
    char dest2[20] = {0};
    s21_memcpy(dest1, src, 8);
    memcpy(dest2, src, 8);
    ck_assert_str_eq(dest1, dest2);
  }
}
END_TEST

START_TEST(test_memmove) {
  unsigned char src[4] = {0x01, 0x02, 0x03, 0x04};
  unsigned char dest[4];

  s21_memmove(dest, src, 4);
  ck_assert_mem_eq(dest, src, 4);

  s21_memmove(dest, src + 1, 3);
  ck_assert_mem_eq(dest, src + 1, 3);
  ck_assert_int_eq(dest[3], 0x04);

  s21_memmove(dest + 1, src, 3);
  ck_assert_mem_eq(dest + 1, src, 3);
}
END_TEST

START_TEST(test_memset) {
  // Test setting a small block of memory to 0
  {
    char s21_buffer[10];
    char buffer2[10];
    s21_memset(s21_buffer, 0, 10);
    memset(buffer2, 0, 10);
    for (int i = 0; i < 10; i++) {
      ck_assert_int_eq(s21_buffer[i], buffer2[i]);
    }
  }

  {
    char *s21_buffer = malloc(1000);
    char *buffer2 = malloc(1000);
    s21_memset(s21_buffer, 0, 1000);
    memset(buffer2, 0, 1000);
    for (int i = 0; i < 1000; i++) {
      ck_assert_int_eq(s21_buffer[i], buffer2[i]);
    }
    free(s21_buffer);
    free(buffer2);
  }
}
END_TEST

Suite *s21_memory_suite() {
  Suite *s1 = suite_create("s21_memory functions");
  TCase *tc1 = tcase_create("Core");

  tcase_add_test(tc1, test_memchr);
  tcase_add_test(tc1, test_memcmp);
  tcase_add_test(tc1, test_memcpy);
  tcase_add_test(tc1, test_memmove);
  tcase_add_test(tc1, test_memset);

  suite_add_tcase(s1, tc1);

  return s1;
}

int test_mem() {
  int no_failed = 0;

  Suite *s1 = s21_memory_suite();
  SRunner *runner = srunner_create(s1);

  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return no_failed;
}