#include "../array.h"
#include "test.h"

int increment_five(int number)
{
  return number + 5;
}

Bool is_odd(int number)
{
  return number % 2;
}

int mul(int num1, int num2)
{
  return num1 * num2;
}

void run_map()
{
  int numbers[] = DEFAULT_NUMBERS;
  int size = DEFAULT_LENGTH;
  Array_ptr src = create_array(size);
  src->array = numbers;

  Array_ptr mapped_array = map(src, &increment_five);
  describe("Map: ");
  int expected_array[] = {6, 7, 8, 9, 10};
  int expected_length = 5;
  it("should map list with numbers");
  assert_is_deep_equal(mapped_array, expected_array, expected_length);

  it("should map an empty list");
  int empty_array[0] = {};
  src->array = empty_array;
  src->length = 0;
  mapped_array = map(src, &increment_five);
  assert_is_deep_equal(mapped_array, empty_array, 0);
}

void run_filter()
{
  int numbers[] = DEFAULT_NUMBERS;
  int size = DEFAULT_LENGTH;
  Array_ptr src = create_array(size);
  src->array = numbers;

  Array_ptr filtered_array = filter(src, &is_odd);
  describe("Filter: ");
  int expected_array[] = {1, 3, 5};
  int expected_length = 3;
  it("should filter list with numbers");
  assert_is_deep_equal(filtered_array, expected_array, expected_length);

  it("should filter an empty list");
  int empty_array[0] = {};
  src->array = empty_array;
  src->length = 0;
  filtered_array = filter(src, &is_odd);
  assert_is_deep_equal(filtered_array, empty_array, 0);
}

void run_reduce()
{
  int numbers[] = DEFAULT_NUMBERS;
  int size = DEFAULT_LENGTH;
  Array_ptr src = create_array(size);
  src->array = numbers;

  int mul_of_all_digit = reduce(src, 1, &mul);
  describe("Reduce: ");
  it("should mul all given number with initial value");
  assert_equal(mul_of_all_digit, 120);

  int empty_array[0] = {};
  src->array = empty_array;
  src->length = 0;
  mul_of_all_digit = reduce(src, 1, &mul);
  it("should return initial value when list is empty");
  assert_equal(mul_of_all_digit, 1);
}

void runtests()
{
  run_map();
  run_filter();
  run_reduce();
}

int main(void)
{
  printf("Testing start\n");
  printf(".............\n");
  runtests();
  printf(".............\n");
  printf("Testing end\n");
  return 0;
}