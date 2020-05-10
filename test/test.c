#include "../array.h"
#include "../array_void.h"
#include "test.h"

void print_status(Bool status)
{
  if (status)
    printf("✅\n");
  else
    printf("❌\n");
}

void it(Char_ptr message)
{
  printf("%s", message);
}

void describe(Char_ptr message)
{
  static int test_number = 1;
  printf("\n%d => %s\n", test_number, message);
  test_number++;
}

Bool assert_is_int_equal(Object actual_value, Object expected_value)
{
  return *(int *)actual_value == *(int *)expected_value;
}

Bool assert_is_char_equal(Object actual_value, Object expected_value)
{
  return *(char *)actual_value == *(char *)expected_value;
}

void assert_void_equal(Object actual_value, Object expected_value)
{
  print_status(assert_is_int_equal(actual_value, expected_value));
}

void assert_void_deep_equal(ArrayVoid_ptr actual, ArrayVoid_ptr expected, Tester test_func)
{
  Bool result = actual->length == expected->length;
  for (int i = 0; i < actual->length; i++)
  {
    if (!(*test_func)(actual->array[i], expected->array[i]))
    {
      result = False;
    }
  }
  print_status(result);
}

void assert_equal(int actual, int expected)
{
  Bool status = actual == expected;
  print_status(status);
}

void assert_is_deep_equal(Array_ptr actual, Int_ptr expected_array, int length)
{
  Bool status = actual->length == length;
  for (int i = 0; i < actual->length; i++)
  {
    if (actual->array[i] != expected_array[i])
    {
      status = False;
    }
  }
  print_status(status);
}