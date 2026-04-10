#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include "Leerdatos.h"
#include "BubbleSort.h"
#include "quickSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"

std::vector<std::string> datos;

int main() {
    std::vector<std::string> datos;
    try {
        datos = leerDatos("dataset2.txt");
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    // Copia fresca para cada algoritmo
    std::vector<std::string> copia1 = datos;
    std::vector<std::string> copia2 = datos;
    std::vector<std::string> copia3 = datos;
    std::vector<std::string> copia4 = datos;

    // Quick Sort
    auto start = std::chrono::high_resolution_clock::now();
    quickSortHelper(copia1, 0, (int)copia1.size() - 1); // ✅ size - 1
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "Quick Sort tomó " << duration.count() << " ms" << std::endl;

    // Insertion Sort
    start = std::chrono::high_resolution_clock::now();
    insertionSort(copia2); // ✅ copia fresca
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Insertion Sort tomó " << duration.count() << " ms" << std::endl;

    // Merge Sort
    start = std::chrono::high_resolution_clock::now();
    mergeSort(copia3, 0, (int)copia3.size() - 1); // ✅ copia fresca
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Merge Sort tomó " << duration.count() << " ms" << std::endl;

    // Bubble Sort
    start = std::chrono::high_resolution_clock::now();
    bubbleSort(copia4, (int)copia4.size()); // ✅ copia fresca
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Bubble Sort tomó " << duration.count() << " ms" << std::endl;

    return 0;
}
