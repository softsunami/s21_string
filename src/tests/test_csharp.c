#include "tests.h"

START_TEST(test_to_upper) {
  // Test default sentence with small and large letters
  {
    char *str1 = "Default sentence with numbers: 123";
    char *result = s21_to_upper(str1);
    ck_assert_str_eq(result, "DEFAULT SENTENCE WITH NUMBERS: 123");
    free(result);
  }

  // Test empty sentence
  {
    char *str1 = "";
    char *result = s21_to_upper(str1);
    ck_assert_str_eq(result, "");
    free(result);
  }

  // Test sentence with only large letters
  {
    char *str1 = "LARGE LETTERS";
    char *result = s21_to_upper(str1);
    ck_assert_str_eq(result, "LARGE LETTERS");
    free(result);
  }

  // Test sentence with formats
  {
    char *str1 = "Another\n one SenTenCE\t wWith\0 words";
    char *result = s21_to_upper(str1);
    ck_assert_str_eq(result, "ANOTHER\n ONE SENTENCE\t WWITH");
    free(result);
  }
}
END_TEST

START_TEST(test_to_lower) {
  // Test default sentence with small and large letters
  {
    char *str1 = "Default sentence with numbers: 123";
    char *result = s21_to_lower(str1);
    ck_assert_str_eq(result, "default sentence with numbers: 123");
    free(result);
  }

  // Test empty sentence
  {
    char *str1 = "";
    char *result = s21_to_lower(str1);
    ck_assert_str_eq(result, "");
    free(result);
  }

  // Test sentence with only large letters
  {
    char *str1 = "LARGE LETTERS";
    char *result = s21_to_lower(str1);
    ck_assert_str_eq(result, "large letters");
    free(result);
  }

  // Test sentence with formats
  {
    char *str1 = "Another\n one SenTenCE\t wWith\0 words";
    char *result = s21_to_lower(str1);
    ck_assert_str_eq(result, "another\n one sentence\t wwith\0 words");
    free(result);
  }
}
END_TEST

START_TEST(test_insert) {
  // Default test case 1
  {
    char *result = s21_insert("Hello", " world", 5);
    ck_assert_str_eq(result, "Hello world");
    free(result);
  }

  // Default test case 2
  {
    char *result = s21_insert(" ", "Hello world", 0);
    ck_assert_str_eq(result, "Hello world ");
    free(result);
  }

  // Test case with 0 index
  {
    char *result = s21_insert("Hello", " world", 0);
    ck_assert_str_eq(result, " worldHello");
    free(result);
  }

  // Test case with negative index
  {
    char *result = s21_insert("Hello", " world", -1);
    ck_assert_ptr_eq(result, S21_NULL);
    free(result);
  }

  // Test case with index bigger that word len
  {
    char *result = s21_insert("Hello", " world", 15);
    ck_assert_ptr_eq(result, S21_NULL);
    free(result);
  }

  // Test case with adding empty string
  {
    char *result = s21_insert("Hello world", "", 5);
    ck_assert_str_eq(result, "Hello world");
    free(result);
  }
}
END_TEST

START_TEST(test_trim) {
  // Empty src and trim_chars
  {
    char *result = s21_trim("", "");
    ck_assert_str_eq(result, "");
    free(result);
  }

  // Test case with emtpy source string
  {
    char *result = s21_trim("", "abcdefg");
    ck_assert_str_eq(result, "");
    free(result);
  }

  // Test case with empty trim chars
  {
    char *result = s21_trim("one more message", "");
    ck_assert_str_eq(result, "one more message");
    free(result);
  }

  // Test case with src equal trim_chars
  {
    char *result = s21_trim("one more message", "one more message");
    ck_assert_str_eq(result, "");
    free(result);
  }

  // Another tests...
  {
    char *result = s21_trim("+!!++Abo+ba++00", "+!0-");
    ck_assert_str_eq(result, "Abo+ba");
    free(result);
  }

  {
    char *result = s21_trim("+!!++Abo+ba++00", "+!0-");
    ck_assert_str_eq(result, "Abo+ba");
    free(result);
  }

  {
    char *result = s21_trim("Ab000cd0", "003");
    ck_assert_str_eq(result, "Ab000cd");
    free(result);
  }

  {
    char *result = s21_trim("DoNotTouch", "Not");
    ck_assert_str_eq(result, "DoNotTouch");
    free(result);
  }

  {
    char *result = s21_trim(" Good morning!    ", " ");
    ck_assert_str_eq(result, "Good morning!");
    free(result);
  }

  {
    char *result = s21_trim(" qwertyuiop ", NULL);
    ck_assert_str_eq(result, "qwertyuiop");
    free(result);
  }
}
END_TEST

Suite *s21_csharp_suite() {
  Suite *s1 = suite_create("s21_csharp functions");
  TCase *tc1 = tcase_create("Core");

  tcase_add_test(tc1, test_to_upper);
  tcase_add_test(tc1, test_to_lower);
  tcase_add_test(tc1, test_insert);
  tcase_add_test(tc1, test_trim);

  suite_add_tcase(s1, tc1);

  return s1;
}

int test_csharp() {
  int no_failed = 0;

  Suite *s1 = s21_csharp_suite();
  SRunner *runner = srunner_create(s1);

  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return no_failed;
}
