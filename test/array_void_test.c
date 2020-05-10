#include "../array_void.h"
#include "test.h"

Object increment(Object value)
{
  int incremented_value = (*(int *)value + 1);
  Object new_value = malloc(sizeof(int));
  memcpy(new_value, &incremented_value, sizeof(incremented_value));
  return new_value;
}

Object to_upper_case(Object character)
{
  char alphabet_ascii = *(char *)character;
  char upper_case = alphabet_ascii >= 97 && alphabet_ascii <= 122 ? alphabet_ascii - 32 : alphabet_ascii;
  Object alphabet = malloc(sizeof(char));
  memcpy(alphabet, &upper_case, sizeof(char));
  return alphabet;
}

void run_map_void(ArrayVoid_ptr actual_list)
{
  describe("Map void:");
  ArrayVoid_ptr expected_list = create_void_array(3);
  int numbers[] = {2, 3, 4};
  expected_list->array[0] = numbers;
  expected_list->array[1] = numbers + 1;
  expected_list->array[2] = numbers + 2;
  it("should increment every number in the list");
  ArrayVoid_ptr mapped_list = map_void(actual_list, &increment);
  assert_void_deep_equal(mapped_list, expected_list, &assert_is_int_equal);
}

void runtests()
{
  int size = DEFAULT_LENGTH;
  ArrayVoid_ptr actual_list = create_void_array(size);
  int numbers[] = DEFAULT_NUMBERS;
  actual_list->array[0] = numbers;
  actual_list->array[1] = numbers + 1;
  actual_list->array[2] = numbers + 2;
  run_map_void(actual_list);
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