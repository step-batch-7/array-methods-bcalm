#ifndef __ARRAY_TEST_H
#define __ARRAY_TEST_H

typedef char *Char_ptr;
typedef int *Int_ptr;

void print_status(Bool);
void describe(Char_ptr);
void it(Char_ptr);
void assert_equal(int, int);
void assert_is_deep_equal(Array_ptr, Int_ptr, int);

#endif