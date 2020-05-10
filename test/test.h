#ifndef __ARRAY_TEST_H
#define __ARRAY_TEST_H

typedef Bool (*Tester)(Object, Object);
typedef char *Char_ptr;
typedef int *Int_ptr;

void print_status(Bool);
void describe(Char_ptr);
void it(Char_ptr);
void assert_equal(int, int);
void assert_is_deep_equal(Array_ptr, Int_ptr, int);
Bool assert_is_int_equal(Object, Object);
Bool assert_is_char_equal(Object, Object);
void assert_void_equal(Object actual_value, Object expected_value);
void assert_void_deep_equal(ArrayVoid_ptr, ArrayVoid_ptr, Tester);

#endif