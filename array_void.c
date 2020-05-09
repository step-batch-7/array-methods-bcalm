#include "array_void.h"

ArrayVoid_ptr create_void_array(int size)
{
  ArrayVoid_ptr src = malloc(sizeof(ArrayVoid_ptr));
  if (src == NULL)
  {
    return NULL;
  }
  src->array = size ? malloc(size * sizeof(void)) : NULL;
  src->length = size;
  return src;
}

Object reduce_void(ArrayVoid_ptr src, Object accumulator, ReducerVoid reducer)
{
  REPEAT(src->length)
  {
    accumulator = (*reducer)(src->array[idx], accumulator);
  }
  return accumulator;
}