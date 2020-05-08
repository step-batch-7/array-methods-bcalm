#! /bin/bash
executable=$1
rm -rf *.o
gcc -c array_test.c test.c ../array.c
gcc -o $1 *.o
./$1
rm -rf $1
rm -rf *.o