#include "array_void.h"

ArrayVoid_ptr create_void_array(int length)
{
  ArrayVoid_ptr src = malloc(sizeof(ArrayVoid));
  if (src == NULL)
  {
    return src;
  }
  src->array = length ? malloc(length * sizeof(Object)) : NULL;
  src->length = length;
  return src;
}

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper)
{
  ArrayVoid_ptr mapped_list = create_void_array(src->length);
  IS_MEMORY_NOT_ALLOCATED(mapped_list)
  {
    return mapped_list;
  }
  REPEAT(src->length)
  {
    mapped_list->array[idx] = (*mapper)(src->array[idx]);
  }
  return mapped_list;
}

ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate)
{
  int count = 0;
  ArrayVoid_ptr filtered_src = create_void_array(src->length);

  IS_MEMORY_NOT_ALLOCATED(filtered_src)
  {
    return filtered_src;
  }

  REPEAT(src->length)
  {
    if ((*predicate)(src->array[idx]))
    {
      filtered_src->array[count] = src->array[idx];
      count++;
    }
  }
  filtered_src->array = realloc(filtered_src->array, count * sizeof(Object));
  filtered_src->length = count;
  return filtered_src;
}

Object reduce_void(ArrayVoid_ptr src, Object accumulator, ReducerVoid reducer)
{
  REPEAT(src->length)
  {
    accumulator = (*reducer)(src->array[idx], accumulator);
  }
  return accumulator;
}

void print_int(Object value)
{
  printf("%d\n", *(int *)value);
}

void print_char(Object value)
{
  printf("%c\n", *(int *)value);
}

void print_void_array(ArrayVoid_ptr src, Display displayer)
{
  REPEAT(src->length)
  {
    (*displayer)(src->array[idx]);
  }
}