#include <iostream>
#include "sort.h"

auto main() -> int {
    Sort< Arr< 6, 5, 0, 2, 7, 9, 4, 1, 8, 3 > >::Result arr = 0;
    return 0;
}

/*
main.cpp: In function ‘int main()’:
main.cpp:5:63: error: conversion from ‘int’ to non-scalar type ‘Sort<Arr<6, 5, 0, 2, 7, 9, 4, 1, 8, 3> >::Result’ {aka ‘Arr<0, 1, 2, 3, 4, 5, 6, 7, 8, 9>’} requested
    5 |     Sort< Arr< 6, 5, 0, 2, 7, 9, 4, 1, 8, 3 > >::Result arr = 0;
      |
*/
