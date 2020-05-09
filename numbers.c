#include "array.h"
#include "array_void.h"

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

Object increment(Object value)
{
  int incremented_value = (*(int *)value + 1);
  Object new_value;
  memcpy(new_value, &incremented_value, sizeof(int));
  return new_value;
}

Object to_upper_case(Object character)
{
  char alphabet_ascii = *(char *)character;
  char upper_case = alphabet_ascii >= 97 && alphabet_ascii <= 122 ? alphabet_ascii - 32 : alphabet_ascii;
  Object alphabet;
  memcpy(alphabet, &upper_case, sizeof(char));
  return alphabet;
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
  // ---------------------array void part-----------------------
  ArrayVoid_ptr src_void = create_void_array(size);
  IS_MEMORY_NOT_ALLOCATED(src_void)
  {
    return 0;
  }
  src_void->array = (Object)numbers;
  ArrayVoid_ptr mapped_void_array = map_void(src_void, &increment);
  mapped_void_array = map_void(src_void, &to_upper_case);
  return 0;
}