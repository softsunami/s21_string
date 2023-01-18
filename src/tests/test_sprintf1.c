#include "tests.h"

START_TEST(sprintf_impossible) {
  char str[100];
  s21_sprintf(str, "%-06d", 25);
  ck_assert_str_eq(str, "25    ");
}
END_TEST

START_TEST(sprintf_c_check) {
  char str[510];
  char str2[510];
  sprintf(str, "%11c %c", 'A', 'b');
  s21_sprintf(str2, "%11c %c", 'A', 'b');
  ck_assert_str_eq(str, str2);
  sprintf(str, "%c %97c", 'n', 'j');
  s21_sprintf(str2, "%c %97c", 'n', 'j');
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-c %-3c", 'j', 'z');
  s21_sprintf(str2, "%-c %-3c", 'j', 'z');
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-c %-3c %c %c %c %c", 'j', 'z', 'z', 'z', 'z', 'z');
  s21_sprintf(str2, "%-c %-3c %c %c %c %c", 'j', 'z', 'z', 'z', 'z', 'z');
  ck_assert_str_eq(str, str2);
  sprintf(str, "%c", 'A');
  s21_sprintf(str2, "%c", 'A');
  ck_assert_str_eq(str, str2);
  char *check = int_to_str(25);
  ck_assert_str_eq(check, "25");
  free(check);
  char *kek = int_to_str(-10);
  ck_assert_str_eq(kek, "-10");
  free(kek);
  char *lol = int_to_str(0);
  ck_assert_str_eq(lol, "0");
  free(lol);
}
END_TEST

START_TEST(sprintf_s_check) {
  char str[100];
  char str2[100];
  sprintf(str, "%s", "abcde");
  s21_sprintf(str2, "%s", "abcde");
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.1s", "abcde");
  s21_sprintf(str2, "%.1s", "abcde");
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.20s", "abcde");
  s21_sprintf(str2, "%.20s", "abcde");
  ck_assert_str_eq(str, str2);
  sprintf(str, "%10s", "abcde");
  s21_sprintf(str2, "%10s", "abcde");
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10s", "abcde");
  s21_sprintf(str2, "%-10s", "abcde");
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_u_check) {
  char str[100];
  char str2[100];
  sprintf(str, "%hu", (unsigned short)4);
  s21_sprintf(str2, "%hu", (unsigned short)4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2u", (unsigned int)4);
  s21_sprintf(str2, "%2u", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.5u", (unsigned int)4);
  s21_sprintf(str2, "%2.5u", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-u", (unsigned int)6);
  s21_sprintf(str2, "%-u", 6);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_d_check) {
  char str[100];
  char str2[100];
  sprintf(str, "%d", 0);
  s21_sprintf(str2, "%d", 0);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%d", 4);
  s21_sprintf(str2, "%d", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%d", -4);
  s21_sprintf(str2, "%d", -4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.3d", 4);
  s21_sprintf(str2, "%-10.3d", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.3d", -4);
  s21_sprintf(str2, "%-10.3d", -4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-3.10d", 4);
  s21_sprintf(str2, "%-3.10d", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-3.10d", -4);
  s21_sprintf(str2, "%-3.10d", -4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+2.2d", 4000000);
  s21_sprintf(str2, "%+2.2d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+2.2d", -4000000);
  s21_sprintf(str2, "%+2.2d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+.2d", 4000000);
  s21_sprintf(str2, "%+.2d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+2.d", 4000000);
  s21_sprintf(str2, "%+2.d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+.2d", -4000000);
  s21_sprintf(str2, "%+.2d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.15d", 4000000);
  s21_sprintf(str2, "%15.15d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%16.15d", -4000000);
  s21_sprintf(str2, "%16.15d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.15d", -4000000);
  s21_sprintf(str2, "%15.15d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%12.2d", -4000000);
  s21_sprintf(str2, "%12.2d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%12.2d", 4000000);
  s21_sprintf(str2, "%12.2d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.12d", 4000000);
  s21_sprintf(str2, "%2.12d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.12d", -4000000);
  s21_sprintf(str2, "%2.12d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2d", 4000000);
  s21_sprintf(str2, "%2.2d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2d", -4000000);
  s21_sprintf(str2, "%2.2d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+2.2d", 4000000);
  s21_sprintf(str2, "%+2.2d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+2.2d", -4000000);
  s21_sprintf(str2, "%+2.2d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%d%%\n", 4000000);
  s21_sprintf(str2, "%d%%\n", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.2d", 4000000);
  s21_sprintf(str2, "%.2d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-2.2d", 4000000);
  s21_sprintf(str2, "%+-2.2d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-2.2d", -4000000);
  s21_sprintf(str2, "%+-2.2d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-15.15d", 4000000);
  s21_sprintf(str2, "%-15.15d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-15.15d", -4000000);
  s21_sprintf(str2, "%-15.15d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-12.2d", -4000000);
  s21_sprintf(str2, "%-12.2d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-12.2d", 4000000);
  s21_sprintf(str2, "%-12.2d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.12d", 4000000);
  s21_sprintf(str2, "%-2.12d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.12d", -4000000);
  s21_sprintf(str2, "%-2.12d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-2.2d", 4000000);
  s21_sprintf(str2, "%+-2.2d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-2.2d", 4000000);
  s21_sprintf(str2, "%+-2.2d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-d%%\n", 4000000);
  s21_sprintf(str2, "%-d%%\n", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-.2d", 4000000);
  s21_sprintf(str2, "%-.2d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2d", 4000000);
  s21_sprintf(str2, "%-2d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10d", 4000000);
  s21_sprintf(str2, "%-10d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-2d", 4000000);
  s21_sprintf(str2, "%+-2d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-10d", 4000000);
  s21_sprintf(str2, "%+-10d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%11.10d", 4000000);
  s21_sprintf(str2, "%11.10d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "% 2.2d", 4000000);
  s21_sprintf(str2, "% 2.2d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.15d", -4000000);
  s21_sprintf(str2, "%.15d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.15d", 4000000);
  s21_sprintf(str2, "%.15d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+.15d", 4000000);
  s21_sprintf(str2, "%+.15d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+.15d", -4000000);
  s21_sprintf(str2, "%+.15d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.2d", 4000000);
  s21_sprintf(str2, "%15.2d", 4000000);
  sprintf(str, "%+15.2d", 4000000);
  s21_sprintf(str2, "%+15.2d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+15.2d", -4000000);
  s21_sprintf(str2, "%+15.2d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.8d", -4000000);
  s21_sprintf(str2, "%15.8d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-.8d", -4000000);
  s21_sprintf(str2, "%-.8d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+.8d", 4000000);
  s21_sprintf(str2, "%+.8d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-.8d", 4000000);
  s21_sprintf(str2, "%+-.8d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-11d", -4000000);
  s21_sprintf(str2, "%+-11d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+050d", -4000000);
  s21_sprintf(str2, "%+050d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-10.8d", -4000000);
  s21_sprintf(str2, "%+-10.8d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-10.8d", 4000000);
  s21_sprintf(str2, "%+-10.8d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-10.8d", -4000000);
  s21_sprintf(str2, "%+-10.8d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+13.10d", -4000000);
  s21_sprintf(str2, "%+13.10d", -4000000);
  ck_assert_str_eq(str, str2);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-11.11d", 4000000);
  s21_sprintf(str2, "%+-11.11d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-5.11d", 4000000);
  s21_sprintf(str2, "%+-5.11d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-9.7d", 4000000);
  s21_sprintf(str2, "%+-9.7d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%u", (unsigned int)-4000000);
  s21_sprintf(str2, "%u", -4000000);
  ck_assert_str_eq(str, str2);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_X_check) {
  char str[100];
  char str2[100];
  sprintf(str, "%X", 0);
  s21_sprintf(str2, "%X", 0);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%X", 4);
  s21_sprintf(str2, "%X", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%X", -4);
  s21_sprintf(str2, "%X", -4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.3X", 4);
  s21_sprintf(str2, "%-10.3X", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.3X", -4);
  s21_sprintf(str2, "%-10.3X", -4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-3.10X", 4);
  s21_sprintf(str2, "%-3.10X", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-3.10X", -4);
  s21_sprintf(str2, "%-3.10X", -4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2X", 4000000);
  s21_sprintf(str2, "%+2.2X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2X", -4000000);
  s21_sprintf(str2, "%+2.2X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.2X", 4000000);
  s21_sprintf(str2, "%+.2X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.X", 4000000);
  s21_sprintf(str2, "%+2.X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.2X", -4000000);
  s21_sprintf(str2, "%.2X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.15X", 4000000);
  s21_sprintf(str2, "%15.15X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%16.15X", -4000000);
  s21_sprintf(str2, "%16.15X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.15X", -4000000);
  s21_sprintf(str2, "%15.15X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%12.2X", -4000000);
  s21_sprintf(str2, "%12.2X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%12.2X", 4000000);
  s21_sprintf(str2, "%12.2X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.12X", 4000000);
  s21_sprintf(str2, "%2.12X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.12X", -4000000);
  s21_sprintf(str2, "%2.12X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2X", 4000000);
  s21_sprintf(str2, "%2.2X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2X", -4000000);
  s21_sprintf(str2, "%2.2X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2X", 4000000);
  s21_sprintf(str2, "%2.2X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2X", -4000000);
  s21_sprintf(str2, "%2.2X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%X%%\n", 4000000);
  s21_sprintf(str2, "%X%%\n", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.2X", 4000000);
  s21_sprintf(str2, "%.2X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.2X", 4000000);
  s21_sprintf(str2, "%-2.2X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.2X", -4000000);
  s21_sprintf(str2, "%-2.2X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-15.15X", 4000000);
  s21_sprintf(str2, "%-15.15X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-15.15X", -4000000);
  s21_sprintf(str2, "%-15.15X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-12.2X", -4000000);
  s21_sprintf(str2, "%-12.2X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-12.2X", 4000000);
  s21_sprintf(str2, "%-12.2X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.12X", 4000000);
  s21_sprintf(str2, "%-2.12X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.12X", -4000000);
  s21_sprintf(str2, "%-2.12X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.2X", 4000000);
  s21_sprintf(str2, "%-2.2X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.2X", 4000000);
  s21_sprintf(str2, "%-2.2X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-X%%\n", 4000000);
  s21_sprintf(str2, "%-X%%\n", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-.2X", 4000000);
  s21_sprintf(str2, "%-.2X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2X", 4000000);
  s21_sprintf(str2, "%-2X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10X", 4000000);
  s21_sprintf(str2, "%-10X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2X", 4000000);
  s21_sprintf(str2, "%-2X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10X", 4000000);
  s21_sprintf(str2, "%-10X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%11.10X", 4000000);
  s21_sprintf(str2, "%11.10X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2X", 4000000);
  s21_sprintf(str2, "% 2.2X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.15X", -4000000);
  s21_sprintf(str2, "%.15X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.15X", 4000000);
  s21_sprintf(str2, "%.15X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.15X", 4000000);
  s21_sprintf(str2, "%.15X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.15X", -4000000);
  s21_sprintf(str2, "%.15X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.2X", 4000000);
  s21_sprintf(str2, "%15.2X", 4000000);
  sprintf(str, "%15.2X", 4000000);
  s21_sprintf(str2, "%15.2X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.2X", -4000000);
  s21_sprintf(str2, "%15.2X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.8X", -4000000);
  s21_sprintf(str2, "%15.8X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-.8X", -4000000);
  s21_sprintf(str2, "%-.8X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.8X", 4000000);
  s21_sprintf(str2, "%.8X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-.8X", 4000000);
  s21_sprintf(str2, "%-.8X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-11X", -4000000);
  s21_sprintf(str2, "%-11X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-5X", -4000000);
  s21_sprintf(str2, "%-5X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.8X", -4000000);
  s21_sprintf(str2, "%-10.8X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.8X", 4000000);
  s21_sprintf(str2, "%-10.8X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.8X", -4000000);
  s21_sprintf(str2, "%-10.8X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%13.10X", -4000000);
  s21_sprintf(str2, "%13.10X", -4000000);
  ck_assert_str_eq(str, str2);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-11.11X", 4000000);
  s21_sprintf(str2, "%-11.11X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-5.11X", 4000000);
  s21_sprintf(str2, "%-5.11X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-9.7X", 4000000);
  s21_sprintf(str2, "%-9.7X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%u", (unsigned int)-4000000);
  s21_sprintf(str2, "%u", -4000000);
  ck_assert_str_eq(str, str2);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_o_check) {
  char str[100];
  char str2[100];
  sprintf(str, "%#o", 0);
  s21_sprintf(str2, "%#o", 0);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%o", 4);
  s21_sprintf(str2, "%o", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%o", -4);
  s21_sprintf(str2, "%o", -4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%#-10.3o", 4);
  s21_sprintf(str2, "%#-10.3o", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.3o", -4);
  s21_sprintf(str2, "%-10.3o", -4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-3.10o", 4);
  s21_sprintf(str2, "%-3.10o", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-3.10o", -4);
  s21_sprintf(str2, "%-3.10o", -4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2o", 4000000);
  s21_sprintf(str2, "%2.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2o", -4000000);
  s21_sprintf(str2, "%2.2o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.2o", 4000000);
  s21_sprintf(str2, "%.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.o", 4000000);
  s21_sprintf(str2, "%2.o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.2o", -4000000);
  s21_sprintf(str2, "%.2o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.15o", 4000000);
  s21_sprintf(str2, "%15.15o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%16.15o", -4000000);
  s21_sprintf(str2, "%16.15o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.15o", -4000000);
  s21_sprintf(str2, "%15.15o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%12.2o", -4000000);
  s21_sprintf(str2, "%12.2o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%12.2o", 4000000);
  s21_sprintf(str2, "%12.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.12o", 4000000);
  s21_sprintf(str2, "%2.12o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.12o", -4000000);
  s21_sprintf(str2, "%2.12o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2o", 4000000);
  s21_sprintf(str2, "%2.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2o", -4000000);
  s21_sprintf(str2, "%2.2o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2o", 4000000);
  s21_sprintf(str2, "%2.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2o", -4000000);
  s21_sprintf(str2, "%2.2o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%o%%\n", 4000000);
  s21_sprintf(str2, "%o%%\n", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.2o", 4000000);
  s21_sprintf(str2, "%.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.2o", 4000000);
  s21_sprintf(str2, "%-2.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.2o", -4000000);
  s21_sprintf(str2, "%-2.2o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-15.15o", 4000000);
  s21_sprintf(str2, "%-15.15o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-15.15o", -4000000);
  s21_sprintf(str2, "%-15.15o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-12.2o", -4000000);
  s21_sprintf(str2, "%-12.2o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-12.2o", 4000000);
  s21_sprintf(str2, "%-12.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.12o", 4000000);
  s21_sprintf(str2, "%-2.12o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.12o", -4000000);
  s21_sprintf(str2, "%-2.12o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.2o", 4000000);
  s21_sprintf(str2, "%-2.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.2o", 4000000);
  s21_sprintf(str2, "%-2.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-o%%\n", 4000000);
  s21_sprintf(str2, "%-o%%\n", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-.2o", 4000000);
  s21_sprintf(str2, "%-.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2o", 4000000);
  s21_sprintf(str2, "%-2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10o", 4000000);
  s21_sprintf(str2, "%-10o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2o", 4000000);
  s21_sprintf(str2, "%-2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10o", 4000000);
  s21_sprintf(str2, "%-10o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%11.10o", 4000000);
  s21_sprintf(str2, "%11.10o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2o", 4000000);
  s21_sprintf(str2, "% 2.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.15o", -4000000);
  s21_sprintf(str2, "%.15o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.15o", 4000000);
  s21_sprintf(str2, "%.15o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.15o", 4000000);
  s21_sprintf(str2, "%.15o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.15o", -4000000);
  s21_sprintf(str2, "%.15o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.2o", 4000000);
  s21_sprintf(str2, "%15.2o", 4000000);
  sprintf(str, "%15.2o", 4000000);
  s21_sprintf(str2, "%15.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.2o", -4000000);
  s21_sprintf(str2, "%15.2o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.8o", -4000000);
  s21_sprintf(str2, "%15.8o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-.8o", -4000000);
  s21_sprintf(str2, "%-.8o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.8o", 4000000);
  s21_sprintf(str2, "%.8o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-.8o", 4000000);
  s21_sprintf(str2, "%-.8o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-11o", -4000000);
  s21_sprintf(str2, "%-11o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-5o", -4000000);
  s21_sprintf(str2, "%-5o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.8o", -4000000);
  s21_sprintf(str2, "%-10.8o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.8o", 4000000);
  s21_sprintf(str2, "%-10.8o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.8o", -4000000);
  s21_sprintf(str2, "%-10.8o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%13.10o", -4000000);
  s21_sprintf(str2, "%13.10o", -4000000);
  ck_assert_str_eq(str, str2);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-11.11o", 4000000);
  s21_sprintf(str2, "%-11.11o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-5.11o", 4000000);
  s21_sprintf(str2, "%-5.11o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-9.7o", 4000000);
  s21_sprintf(str2, "%-9.7o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%u", (unsigned int)-4000000);
  s21_sprintf(str2, "%u", -4000000);
  ck_assert_str_eq(str, str2);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_x_check) {
  char str[100];
  char str2[100];
  sprintf(str, "%x", 0);
  s21_sprintf(str2, "%x", 0);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%#x", 4);
  s21_sprintf(str2, "%#x", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%x", -4);
  s21_sprintf(str2, "%x", -4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.3x", 4);
  s21_sprintf(str2, "%-10.3x", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.3x", -4);
  s21_sprintf(str2, "%-10.3x", -4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-3.10x", 4);
  s21_sprintf(str2, "%-3.10x", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-3.10x", -4);
  s21_sprintf(str2, "%-3.10x", -4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2x", 4000000);
  s21_sprintf(str2, "%2.2x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2x", -4000000);
  s21_sprintf(str2, "%2.2x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.2x", 4000000);
  s21_sprintf(str2, "%.2x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.x", 4000000);
  s21_sprintf(str2, "%2.x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.2x", -4000000);
  s21_sprintf(str2, "%.2x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.15x", 4000000);
  s21_sprintf(str2, "%15.15x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%16.15x", -4000000);
  s21_sprintf(str2, "%16.15x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.15x", -4000000);
  s21_sprintf(str2, "%15.15x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%12.2x", -4000000);
  s21_sprintf(str2, "%12.2x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%12.2x", 4000000);
  s21_sprintf(str2, "%12.2x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.12x", 4000000);
  s21_sprintf(str2, "%2.12x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.12x", -4000000);
  s21_sprintf(str2, "%2.12x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2x", 4000000);
  s21_sprintf(str2, "%2.2x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2x", -4000000);
  s21_sprintf(str2, "%2.2x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2x", 4000000);
  s21_sprintf(str2, "%2.2x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2x", -4000000);
  s21_sprintf(str2, "%2.2x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%x%%\n", 4000000);
  s21_sprintf(str2, "%x%%\n", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.2x", 4000000);
  s21_sprintf(str2, "%.2x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.2x", 4000000);
  s21_sprintf(str2, "%-2.2x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.2x", -4000000);
  s21_sprintf(str2, "%-2.2x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-15.15x", 4000000);
  s21_sprintf(str2, "%-15.15x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-15.15x", -4000000);
  s21_sprintf(str2, "%-15.15x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-12.2x", -4000000);
  s21_sprintf(str2, "%-12.2x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-12.2x", 4000000);
  s21_sprintf(str2, "%-12.2x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.12x", 4000000);
  s21_sprintf(str2, "%-2.12x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.12x", -4000000);
  s21_sprintf(str2, "%-2.12x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.2x", 4000000);
  s21_sprintf(str2, "%-2.2x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.2x", 4000000);
  s21_sprintf(str2, "%-2.2x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-x%%\n", 4000000);
  s21_sprintf(str2, "%-x%%\n", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-.2x", 4000000);
  s21_sprintf(str2, "%-.2x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2x", 4000000);
  s21_sprintf(str2, "%-2x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10x", 4000000);
  s21_sprintf(str2, "%-10x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2x", 4000000);
  s21_sprintf(str2, "%-2x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10x", 4000000);
  s21_sprintf(str2, "%-10x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%11.10x", 4000000);
  s21_sprintf(str2, "%11.10x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2x", 4000000);
  s21_sprintf(str2, "% 2.2x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.15x", -4000000);
  s21_sprintf(str2, "%.15x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.15x", 4000000);
  s21_sprintf(str2, "%.15x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.15x", 4000000);
  s21_sprintf(str2, "%.15x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.15x", -4000000);
  s21_sprintf(str2, "%.15x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.2x", 4000000);
  s21_sprintf(str2, "%15.2x", 4000000);
  sprintf(str, "%15.2x", 4000000);
  s21_sprintf(str2, "%15.2x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.2x", -4000000);
  s21_sprintf(str2, "%15.2x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.8x", -4000000);
  s21_sprintf(str2, "%15.8x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-.8x", -4000000);
  s21_sprintf(str2, "%-.8x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.8x", 4000000);
  s21_sprintf(str2, "%.8x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-.8x", 4000000);
  s21_sprintf(str2, "%-.8x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-11x", -4000000);
  s21_sprintf(str2, "%-11x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-5x", -4000000);
  s21_sprintf(str2, "%-5x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.8x", -4000000);
  s21_sprintf(str2, "%-10.8x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.8x", 4000000);
  s21_sprintf(str2, "%-10.8x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.8x", -4000000);
  s21_sprintf(str2, "%-10.8x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%13.10x", -4000000);
  s21_sprintf(str2, "%13.10x", -4000000);
  ck_assert_str_eq(str, str2);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-11.11x", 4000000);
  s21_sprintf(str2, "%-11.11x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-5.11x", 4000000);
  s21_sprintf(str2, "%-5.11x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-9.7x", 4000000);
  s21_sprintf(str2, "%-9.7x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%u", (unsigned int)-4000000);
  s21_sprintf(str2, "%u", -4000000);
  ck_assert_str_eq(str, str2);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_f_check) {
  char str[100];
  char str2[100];
  sprintf(str, "%.2f", 4000.1);
  s21_sprintf(str2, "%.2f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.2f", -4000.1);
  s21_sprintf(str2, "%.2f", -4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%f", 4000.1);
  s21_sprintf(str2, "%f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%f", -4000.1);
  s21_sprintf(str2, "%f", -4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2f", -4000.1);
  s21_sprintf(str2, "%2f", -4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2f", 4000.1);
  s21_sprintf(str2, "%2f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "% 2f", 4000.1);
  s21_sprintf(str2, "% 2f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%- 2f", 4000.1);
  s21_sprintf(str2, "%- 2f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.0f", 4000.6);
  s21_sprintf(str2, "%.0f", 4000.6);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.0f", 0.9);
  s21_sprintf(str2, "%.0f", 0.99);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%0f", 4000.1);
  s21_sprintf(str2, "%0f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%0f", -4000.1);
  s21_sprintf(str2, "%0f", -4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+f %+f", 4000.1, 30.9);
  s21_sprintf(str2, "%+f %+f", 4000.1, 30.9);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-15f", 4000.1);
  s21_sprintf(str2, "%-15f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+15f", 4000.1);
  s21_sprintf(str2, "%+15f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-15f", -4000.1);
  s21_sprintf(str2, "%-15f", -4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+15f", -4000.1);
  s21_sprintf(str2, "%+15f", -4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-15f", 4000.1);
  s21_sprintf(str2, "%+-15f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-15f", -4000.1);
  s21_sprintf(str2, "%+-15f", -4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%8.2f", 4000.1);
  s21_sprintf(str2, "%8.2f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%8.2f", -4000.1);
  s21_sprintf(str2, "%8.2f", -4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.8f", 4000.1);
  s21_sprintf(str2, "%2.8f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.8f", 4000.1);
  s21_sprintf(str2, "%2.8f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.8f", -4000.1);
  s21_sprintf(str2, "%2.8f", -4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%8.8f", -4000.1);
  s21_sprintf(str2, "%8.8f", -4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%8.8f", 4000.1);
  s21_sprintf(str2, "%8.8f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-8.2f", 4000.1);
  s21_sprintf(str2, "%-8.2f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-8.2f", -4000.1);
  s21_sprintf(str2, "%-8.2f", -4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.8f", 4000.1);
  s21_sprintf(str2, "%-2.8f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.8f", 4000.1);
  s21_sprintf(str2, "%-2.8f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.8f", -4000.1);
  s21_sprintf(str2, "%-2.8f", -4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-8.8f", -4000.1);
  s21_sprintf(str2, "%-8.8f", -4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-8.8f", 4000.1);
  s21_sprintf(str2, "%-8.8f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%9.0f", 4000.1);
  s21_sprintf(str2, "%9.0f", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%9.0Lf", (long double)4000.1);
  s21_sprintf(str2, "%9.0Lf", (long double)4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%9.0Lf", (long double)-4000.1);
  s21_sprintf(str2, "%9.0Lf", (long double)-4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.1f", 5.99);
  s21_sprintf(str2, "%.1f", 5.99);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.6f", 5.99);
  s21_sprintf(str2, "%.6f", 5.99);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_i_check) {
  char str[100];
  char str2[100];
  sprintf(str, "%i", 4);
  s21_sprintf(str2, "%i", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%10i", 4);
  s21_sprintf(str2, "%10i", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-10i", 4);
  s21_sprintf(str2, "%-+10i", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10i", 4);
  s21_sprintf(str2, "%-10i", 4);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_lhidu_check) {
  char str[100];
  char str2[100];
  long int s = 4;
  sprintf(str, "%ld", s);
  s21_sprintf(str2, "%ld", s);
  ck_assert_str_eq(str, str2);
  long unsigned f = 10;
  sprintf(str, "%lu", f);
  s21_sprintf(str2, "%lu", f);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%hd", (short int)4);
  s21_sprintf(str2, "%hd", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%hd", (short int)4);
  s21_sprintf(str2, "%hd", 4);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_p_check) {
  char str[100];
  char str2[100];
  s21_sprintf(str, "%p", str);
  sprintf(str2, "%p", str);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_n_check) {
  char str1[100];
  char str2[100];
  int num1 = -1, num2 = -1;
  s21_sprintf(str1, "%n", &num1);
  sprintf(str2, "%n", &num2);
  ck_assert_int_eq(num1, num2);

  s21_sprintf(str1, "123: %n", &num1);
  sprintf(str2, "123: %n", &num2);
  ck_assert_int_eq(num1, num2);
}
END_TEST

Suite *s21_sprintf1_suite() {
  Suite *s1 = suite_create("s21_sprintf1");
  TCase *tc1 = tcase_create("Core");

  tcase_add_test(tc1, sprintf_impossible);
  tcase_add_test(tc1, sprintf_c_check);
  tcase_add_test(tc1, sprintf_s_check);
  tcase_add_test(tc1, sprintf_u_check);
  tcase_add_test(tc1, sprintf_d_check);
  tcase_add_test(tc1, sprintf_o_check);
  tcase_add_test(tc1, sprintf_x_check);
  tcase_add_test(tc1, sprintf_X_check);
  tcase_add_test(tc1, sprintf_f_check);
  tcase_add_test(tc1, sprintf_i_check);
  tcase_add_test(tc1, sprintf_p_check);
  tcase_add_test(tc1, sprintf_n_check);
  tcase_add_test(tc1, sprintf_lhidu_check);

  suite_add_tcase(s1, tc1);

  return s1;
}

int test_sprintf1() {
  int no_failed = 0;

  Suite *s1 = s21_sprintf1_suite();
  SRunner *runner = srunner_create(s1);

  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return no_failed;
}