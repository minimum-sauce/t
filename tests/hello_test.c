#include "test/hello.h"
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <CUnit/TestDB.h>
#include <stdbool.h>

int init_suite() { return 0; }
int clean_suite() { return 0; }

void test() { CU_ASSERT_EQUAL(1, 1); }
void add_positive() { CU_ASSERT_EQUAL(3, add(1, 2)); }

bool add_tests_to_suite(CU_pSuite *suite) {
  if ((CU_add_test(*suite, "1 == 1", test) == NULL) ||
      (CU_add_test(*suite, "add to positives", add_positive) == NULL) || 0) {
    return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  if (CU_initialize_registry() != CUE_SUCCESS) {
    return CU_get_error();
  }

  CU_pSuite suite = CU_add_suite("hello suite", init_suite, clean_suite);
  if (suite == NULL) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  add_tests_to_suite(&suite);

  CU_basic_set_mode(CU_BRM_VERBOSE);

  CU_basic_run_tests();

  CU_cleanup_registry();
  return CU_get_error();
}
