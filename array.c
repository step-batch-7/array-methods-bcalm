#include "array.h"

Array_ptr create_array(int size)
{
  Array_ptr src = malloc(sizeof(Array_ptr));
  if (src == NULL)
  {
    return NULL;
  }
  src->array = size ? malloc(size * sizeof(int)) : NULL;
  src->length = size;
  return src;
}

Array_ptr map(Array_ptr src, Mapper mapper)
{
  Array_ptr mapped_src = create_array(src->length);

  IS_MEMORY_NOT_ALLOCATED(mapped_src)
  {
    return NULL;
  }
  REPEAT(src->length)
  {
    mapped_src->array[idx] = (*mapper)(src->array[idx]);
  }
  return mapped_src;
}

Array_ptr filter(Array_ptr src, Predicate predicate)
{
  int count = 0;
  Array_ptr filtered_src = create_array(src->length);

  IS_MEMORY_NOT_ALLOCATED(filtered_src)
  {
    return NULL;
  }

  REPEAT(src->length)
  {
    if ((*predicate)(src->array[idx]))
    {
      filtered_src->array[count] = src->array[idx];
      count++;
    }
  }
  filtered_src->array = realloc(filtered_src->array, count * sizeof(int));
  filtered_src->length = count;
  return filtered_src;
}

int reduce(Array_ptr src, int accumulator, Reducer reducer)
{
  REPEAT(src->length)
  {
    accumulator = (*reducer)(src->array[idx], accumulator);
  }
  return accumulator;
}