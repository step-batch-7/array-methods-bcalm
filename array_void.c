#include "array_void.h"

ArrayVoid_ptr create_void_array(int size)
{
  ArrayVoid_ptr src = malloc(sizeof(ArrayVoid_ptr));
  if (src == NULL)
  {
    return NULL;
  }
  src->array = size ? malloc(sizeof(Object)) : NULL;
  src->length = size;
  return src;
}

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper)
{
  ArrayVoid_ptr mapped_src = create_void_array(src->length);

  IS_MEMORY_NOT_ALLOCATED(mapped_src)
  {
    return mapped_src;
  }
  REPEAT(src->length)
  {
    mapped_src->array[idx] = (*mapper)(src->array[idx]);
  }
  return mapped_src;
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
  filtered_src->array = realloc(filtered_src->array, count * sizeof(void));
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