#include "array.h"

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

int main(void)
{
  int numbers[] = DEFAULT_NUMBERS;
  int size = DEFAULT_LENGTH;
  Array_ptr src = create_array(size);
  IS_MEMORY_NOT_ALLOCATED(src)
  {
    return 0;
  }
  src->array = numbers;
  Array_ptr mapped_array = map(src, &increment_five);
  Array_ptr filtered_array = filter(src, &is_odd);
  int sum_of_all = reduce(src, 1, &mul);
  return 0;
}