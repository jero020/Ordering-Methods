#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include "Leerdatos.h"
#include "BubbleSort.h"


long long TimeSorting() {
    std::vector<int> a = {5, 3, 8, 1, 2};
    auto t1 = std::chrono::high_resolution_clock::now();
    std::sort(a.begin(), a.end());
    auto t2 = std::chrono::high_resolution_clock::now();
    auto dur = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout << "Tiempo: " << dur << " microsegundos" << std::endl;
    return dur;
}

int main() {
   try {
        std::vector<std::string> datos = leerDatos("dataset.txt");
        for (size_t i = 0; i < datos.size(); i++) {
            //std::cout << datos[i] << " " << std::endl;
        }
        std::cout << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    //return 0;
    TimeSorting();
    bubbleSort;
    return 0;
}
