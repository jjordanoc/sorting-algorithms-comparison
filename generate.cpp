#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include <chrono>


void generate_input_files(int n) {
    srand(time(NULL));
    std::ofstream outfile("../inputs/" + std::to_string(n) + ".in");
    for (int i = 0; i < n; ++i) {
        outfile << rand() % n << "\n";
    }
    outfile.close();
}

void generate_files() {
    for (int i = 10; i <= pow(10, 7); i *= 10) {
        generate_input_files(i);
    }
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    generate_files();
    auto end = std::chrono::high_resolution_clock::now();
    double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << "Ejecucion exitosa en " << duration * 1e-9 << " s" << std::endl;
    return 0;
}