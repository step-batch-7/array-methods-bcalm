#ifndef __ARRAY_H
#define __ARRAY_H

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_NUMBERS \
  {                     \
    1, 2, 3, 4, 5       \
  }

#define DEFAULT_LENGTH 5
#define IS_MEMORY_NOT_ALLOCATED(src) if (src == NULL)
#define REPEAT(length) for (int idx = 0; idx < length; idx++)

typedef enum
{
  False,
  True
} Bool;

typedef int (*Mapper)(int);
typedef Bool (*Predicate)(int);
typedef int (*Reducer)(int, int);

typedef struct
{
  int *array;
  int length;
} Array;

typedef Array *Array_ptr;

Array_ptr map(Array_ptr src, Mapper mapper);
Array_ptr filter(Array_ptr src, Predicate predicate);
int reduce(Array_ptr src, int init, Reducer reducer);
Array_ptr create_array(int size);

#endif
