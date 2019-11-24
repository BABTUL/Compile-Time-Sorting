#include <iostream>
#include "sort.h"

template< int X, int... Xs >
auto print(Arr< X, Xs... >) {
    std::cout << X << ' ';
    print(Arr< Xs... >());
};

template< int X >
auto print(Arr< X >) {
    std::cout << X << '\n';
}

auto print(int) {
    std::cout << "[]\n";
}

auto main() -> int {
    Sort< Arr< 6, 5, 0, 2, 7, 9, 4, 1, 8, 3 > >::Result arr = 0;
    return 0;
}