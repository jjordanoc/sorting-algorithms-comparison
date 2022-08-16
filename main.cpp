#include <iostream>

#include "counting_sort.h"
#include "intro_sort.h"
#include "selection_sort.h"

template<int size>
void print_array(int (&a)[size]) {
    for (int i = 0; i < size; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    // ejemplo 1
    int a1[] = {18, 17, 6, 2, 18, 6, 14, 0, 1};
    print_array(a1);
    counting_sort(a1, 9);
    print_array(a1);
    // ejemplo 2
    int a2[] = {39, 34, 11, 17, 42, 40, 44, 31, 19};
    print_array(a2);
    counting_sort(a2, 9);
    print_array(a2);
}
