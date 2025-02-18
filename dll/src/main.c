#include "list.h"
#include "munit/munit.h"

void *test_setup(__attribute__((unused)) const MunitParameter *params,
                 __attribute__((unused)) void *fixture) {
  return list_init();
}

void test_teardown(void *fixture) {
  list_t *list = fixture;
  list_destroy(list);
}

MunitResult test_init(__attribute__((unused)) const MunitParameter *params,
                      void *fixture) {
  list_t *strings = fixture;

  munit_assert_ptr_not_null(strings);
  munit_assert_ptr_null(strings->head);

  return MUNIT_OK;
}

MunitResult test_add(__attribute__((unused)) const MunitParameter *params,
                     void *fixture) {
  list_t *strings = fixture;
  char *msg = "Hello";

  if (strings == NULL) {
    return MUNIT_ERROR;
  }
  if (list_add(strings, msg) != List_OK) {
    return MUNIT_FAIL;
  }
  munit_assert_ptr_not_null(strings->head);
  munit_assert_ptr_not_null(strings->head->string);
  munit_assert_string_equal(strings->head->string, msg);
  munit_assert_ptr_null(strings->head->next);

  if (list_add(strings, msg) != List_OK) {
    return MUNIT_FAIL;
  }
  node_t *node = strings->head->next;
  munit_assert_ptr_not_null(node);
  munit_assert_ptr_not_null(node->string);
  munit_assert_string_equal(node->string, msg);
  munit_assert_ptr_null(node->next);
  munit_assert_ptr_equal(node->prev, strings->head);
  return MUNIT_OK;
}

MunitResult test_insert(__attribute__((unused)) const MunitParameter *params,
                        __attribute__((unused)) void *fixture) {
  return MUNIT_SKIP;
};

MunitResult test_update(__attribute__((unused)) const MunitParameter *params,
                        __attribute__((unused)) void *fixture) {
  return MUNIT_SKIP;
}
MunitResult test_remove(__attribute__((unused)) const MunitParameter *params,
                        __attribute__((unused)) void *fixture) {
  return MUNIT_SKIP;
}

MunitResult test_lookup(__attribute__((unused)) const MunitParameter *params,
                        __attribute__((unused)) void *fixture) {
  return MUNIT_SKIP;
}

MunitResult test_destroy(__attribute__((unused)) const MunitParameter *params,
                         __attribute__((unused)) void *fixture) {
  return MUNIT_SKIP;
}

MunitTest tests[] = {{
                         "/create",
                         test_init,
                         test_setup,
                         test_teardown,
                         MUNIT_TEST_OPTION_NONE,
                         NULL,
                     },
                     {
                         "/add",
                         test_add,
                         test_setup,
                         test_teardown,
                         MUNIT_TEST_OPTION_NONE,
                         NULL,
                     },
                     {
                         "/insert",
                         test_insert,
                         NULL,
                         NULL,
                         MUNIT_TEST_OPTION_NONE,
                         NULL,
                     },
                     {
                         "/update",
                         test_update,
                         NULL,
                         NULL,
                         MUNIT_TEST_OPTION_NONE,
                         NULL,
                     },
                     {
                         "/remove",
                         test_remove,
                         NULL,
                         NULL,
                         MUNIT_TEST_OPTION_NONE,
                         NULL,
                     },
                     {
                         "/free",
                         test_destroy,
                         NULL,
                         NULL,
                         MUNIT_TEST_OPTION_NONE,
                         NULL,
                     },
                     {
                         NULL,
                         NULL,
                         NULL,
                         NULL,
                         MUNIT_TEST_OPTION_NONE,
                         NULL,
                     }};

MunitSuite suite = {
    "dll", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE,
};

int main(int argc, char **argv) {
  return munit_suite_main(&suite, NULL, argc, argv);
}
