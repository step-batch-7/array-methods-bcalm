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

Bool is_even(Object number)
{
  int num = *(int *)number;
  return num % 2 == 0;
}

Bool is_vowel(Object character)
{
  Object capital_letter = to_upper_case(character);
  char alphabet = *(char *)capital_letter;
  return alphabet == 'A' || alphabet == 'E' || alphabet == 'I' || alphabet == 'O' || alphabet == 'U';
}

void run_map_void(ArrayVoid_ptr int_list, ArrayVoid_ptr char_list)
{
  describe("Map void:");
  ArrayVoid_ptr expected_list = create_void_array(3);
  int numbers[] = {2, 3, 4};
  expected_list->array[0] = numbers;
  expected_list->array[1] = numbers + 1;
  expected_list->array[2] = numbers + 2;
  it("should increment every number in the list");
  ArrayVoid_ptr mapped_list = map_void(int_list, &increment);
  assert_void_deep_equal(mapped_list, expected_list, &assert_is_int_equal);

  it("should change all lower case alphabets to upper case");
  char alphabets[] = {'A', 'B', 'C'};
  expected_list->array[0] = alphabets;
  expected_list->array[1] = alphabets + 1;
  expected_list->array[2] = alphabets + 2;
  mapped_list = map_void(char_list, &to_upper_case);
  assert_void_deep_equal(mapped_list, expected_list, &assert_is_char_equal);
}

void run_filter_void(ArrayVoid_ptr int_list, ArrayVoid_ptr char_list)
{
  describe("Filter void:");
  ArrayVoid_ptr expected_list = create_void_array(1);
  int numbers[] = {2};
  expected_list->array[0] = numbers;
  it("should filter the even number in the list");
  ArrayVoid_ptr filtered_list = filter_void(int_list, &is_even);
  assert_void_deep_equal(filtered_list, expected_list, &assert_is_int_equal);

  it("should filter all vowels present in the list");
  char alphabets[] = {'a'};
  expected_list->array[0] = alphabets;
  filtered_list = filter_void(char_list, &is_vowel);
  assert_void_deep_equal(filtered_list, expected_list, &assert_is_char_equal);
}

void runtests()
{
  int size = DEFAULT_LENGTH;
  ArrayVoid_ptr int_list = create_void_array(size);
  int numbers[] = DEFAULT_NUMBERS;
  int_list->array[0] = numbers;
  int_list->array[1] = numbers + 1;
  int_list->array[2] = numbers + 2;

  ArrayVoid_ptr char_list = create_void_array(3);
  char alphabets[] = {'a', 'b', 'c'};
  char_list->array[0] = alphabets;
  char_list->array[1] = alphabets + 1;
  char_list->array[2] = alphabets + 2;
  run_map_void(int_list, char_list);
  run_filter_void(int_list, char_list);
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