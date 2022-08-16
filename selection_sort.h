#ifndef ORDENAMIENTO_SELECTION_SORT_H
#define ORDENAMIENTO_SELECTION_SORT_H

#include <cmath>

void selection_sort(int *a, int size) {
    for (int i = 0; i < size - 1; ++i) {
        int m = a[i];
        int mpos = i;
        // 1. encontrar la posicion del minimo elemento
        for (int j = i; j < size; ++j) {
            if (a[j] < m) {
                m = a[j];
                mpos = j;
            }
        }
        // 2. intercambiar el minimo con el valor en la i-esima posicion del arreglo
        int tmp = a[i];
        a[i] = a[mpos];
        a[mpos] = tmp;
    }
}

#endif //ORDENAMIENTO_SELECTION_SORT_H
