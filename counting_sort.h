#ifndef ORDENAMIENTO_COUNTING_SORT_H
#define ORDENAMIENTO_COUNTING_SORT_H

#include <cmath>

// enteros de 0 a k
void counting_sort(int *a, int size) {
    int k = 0;
    // 1. encontrar el maximo elemento
    for (int i = 0; i < size; ++i) {
        k = std::max(a[i], k);
    }
    k++;
    // 2. crear arreglo auxiliar
    int *c = new int[k];
    for (int i = 0; i < k; ++i) {
        c[i] = 0;
    }
    // 3. contar apariciones de cada elemento
    for (int i = 0; i < size; ++i) {
        c[a[i]]++;
    }
    // 4. acumular cuenta
    for (int i = 1; i < k; ++i) {
        c[i] = c[i] + c[i - 1];
    }
    // 5. crear nuevo arreglo
    int *b = new int[size];
    for (int i = size - 1; i >= 0; --i) {
        b[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }
    std::copy(b, b + size, a);
    delete[] b;
    delete[] c;
}


// enteros de nk a k (todos los enteros en un rango finito)
void counting_sort_extended(int *a, int size) {
    // 1. encontrar el elemento minimo
    int nk = a[0];
    for (int i = 0; i < size; ++i) {
        nk = std::min(nk, a[i]);
    }
    // 2. quitar a cada elemento el minimo
    for (int i = 0; i < size; ++i) {
        a[i] = a[i] - nk;
    }
    // 3. utilizar counting sort normal
    counting_sort(a, size);
    // 4. sumar el minimo a cada elemento
    for (int i = 0; i < size; ++i) {
        a[i] = a[i] + nk;
    }
}

#endif //ORDENAMIENTO_COUNTING_SORT_H
