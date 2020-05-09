#ifndef __ARRAY_VOID_H
#define __ARRAY_VOID_H
#include "array.h"
#include <string.h>

typedef void *Object;

typedef Object (*MapperVoid)(Object);
typedef Bool (*PredicateVoid)(Object);
typedef Object (*ReducerVoid)(Object, Object);
typedef void (*Display)(Object);

typedef struct
{
  Object *array;
  int length;
} ArrayVoid;

typedef ArrayVoid *ArrayVoid_ptr;
ArrayVoid_ptr create_void_array(int);
ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper);
ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate);
Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer);

void print_void_array(ArrayVoid_ptr src, Display displayer);
void print_int(Object);
void print_char(Object);

#endif