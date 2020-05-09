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

int main(void)
{
  int size = DEFAULT_LENGTH;
  ArrayVoid_ptr int_list = create_void_array(size);
  int numbers[] = DEFAULT_NUMBERS;
  int_list->array[0] = numbers;
  int_list->array[1] = numbers + 1;
  int_list->array[2] = numbers + 2;
  Display displayer = &print_int;
  printf("Given list :");
  print_void_array(int_list, displayer);
  printf("Mapped list :");
  ArrayVoid_ptr mapped_list = map_void(int_list, &increment);
  print_void_array(mapped_list, displayer);

  ArrayVoid_ptr char_list = create_void_array(3);
  char alphabets[3] = {'a', 'b', 'c'};
  char_list->array[0] = alphabets;
  char_list->array[1] = alphabets + 1;
  char_list->array[2] = alphabets + 2;
  char_list->length = 3;
  displayer = &print_char;
  printf("Given list :");
  print_void_array(char_list, displayer);
  printf("List in capital letters :");
  ArrayVoid_ptr capital_letters = map_void(char_list, &to_upper_case);
  print_void_array(capital_letters, displayer);
  return 0;
}