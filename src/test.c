#include "tests/tests.h"

int main() {
  int no_failed = 0;

  no_failed |= test_mem();
  no_failed |= test_str();
  no_failed |= test_csharp();
  no_failed |= test_sprintf1();
  no_failed |= test_sprintf2();
  no_failed |= test_sprintf3();

  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}