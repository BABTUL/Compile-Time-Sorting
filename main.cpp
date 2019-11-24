#include "sort.h"

auto main() -> int {
    Sort< Arr< 6, 5, 0, 2, 7, 9, 4, 1, 8, 3 >, std::less   < int > >::Result l = 0;
    Sort< Arr< 6, 5, 0, 2, 7, 9, 4, 1, 8, 3 >, std::greater< int > >::Result g = 0;
    return 0;
}

/*
main.cpp: In function ‘int main()’:
main.cpp:4:82: error: conversion from ‘int’ to non-scalar type ‘Sort<Arr<6, 5, 0, 2, 7, 9, 4, 1, 8, 3>, std::less<int> >::Result’ {aka ‘Arr<0, 1, 2, 3, 4, 5, 6, 7, 8, 9>’} requested
    4 |     Sort< Arr< 6, 5, 0, 2, 7, 9, 4, 1, 8, 3 >, std::less   < int > >::Result l = 0;
      |                                                                                  ^
main.cpp:5:82: error: conversion from ‘int’ to non-scalar type ‘Sort<Arr<6, 5, 0, 2, 7, 9, 4, 1, 8, 3>, std::greater<int> >::Result’ {aka ‘Arr<9, 8, 7, 6, 5, 4, 3, 2, 1, 0>’} requested
    5 |     Sort< Arr< 6, 5, 0, 2, 7, 9, 4, 1, 8, 3 >, std::greater< int > >::Result g = 0;
      |
*/
