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
    try {
        datos = leerDatos("dataset2.txt");
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;


    // Quick Sort
    start = std::chrono::high_resolution_clock::now();
    quickSortHelper(datos, 0, (int)datos.size()/2);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Quick Sort tomó " << duration.count() << " ms" << std::endl;
    std::cout << "quick sorted" << std::endl;

    // Insertion Sort
    start = std::chrono::high_resolution_clock::now();
    insertionSort(datos);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Insertion Sort tomó " << duration.count() << " ms" << std::endl;
    std::cout << "insertion sorted" << std::endl;

    // Merge Sort
    start = std::chrono::high_resolution_clock::now();
    mergeSort(datos, 0, (int)datos.size() - 1);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Merge Sort tomó " << duration.count() << " ms" << std::endl;
    std::cout << "merge sorted" << std::endl;

    // Bubble Sort
    start = std::chrono::high_resolution_clock::now();
    bubbleSort(datos, (int)datos.size());
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Bubble Sort tomó " << duration.count() << " ms" << std::endl;
    std::cout << "bubble sorted" << std::endl;

    return 0;
}
