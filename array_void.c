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

Object reduce_void(ArrayVoid_ptr src, Object accumulator, ReducerVoid reducer)
{
  REPEAT(src->length)
  {
    accumulator = (*reducer)(src->array[idx], accumulator);
  }
  return accumulator;
}