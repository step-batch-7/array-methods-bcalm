#! /bin/bash
executable=$1
rm -rf *.o
gcc -c array_void_test.c test.c ../array_void.c
gcc -o $1 *.o
./$1
rm -rf $1
rm -rf *.o