#ifndef ORDENAMIENTO_TEST_H
#define ORDENAMIENTO_TEST_H

#include "counting_sort.h"
#include "intro_sort.h"
#include "selection_sort.h"
#include <chrono>
#include <fstream>
#include <iostream>

template<typename Function>
void run_test(int n, std::ofstream &results, Function &sorting_algorithm) {
    std::ifstream infile("../inputs/" + std::to_string(n) + ".in");
    if (!infile.is_open()) {
        std::cout << "Error." << std::endl;
        return;
    }
    std::string buf;
    int *a = new int[n];
    int i = 0;
    while (std::getline(infile, buf)) {
        a[i] = std::stoi(buf);
        ++i;
    }
    auto start = std::chrono::steady_clock::now();
    sorting_algorithm(a, n);
    auto end = std::chrono::steady_clock::now();
    double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    results << n << "," << duration << "\n";
    delete[] a;
}

template<typename Function>
void test_sorting_algorithm(Function &sorting_algorithm, const std::string &filename) {
    std::ofstream results("../analisis/" + filename);
    results << "n,duration(ns)"
            << "\n";
    for (int i = 10; i <= pow(10, 6); i *= 10) {
        run_test(i, results, sorting_algorithm);
    }
}

#endif//ORDENAMIENTO_TEST_H
