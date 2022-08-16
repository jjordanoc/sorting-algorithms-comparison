#include "counting_sort.h"
#include <fstream>

void run_test(int n, std::ofstream &results) {
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
    counting_sort(a, n);
    auto end = std::chrono::steady_clock::now();
    double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    results << n << "," << duration << "\n";
    delete[] a;
}

int main() {
    std::ofstream results("../results.csv");
    results << "n,duration(ns)" << "\n";
    for (int i = 10; i <= pow(10, 7); i *= 10) {
        run_test(i, results);
    }
}