#include "../array.h"
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