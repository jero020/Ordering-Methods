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
        datos = leerDatos("dataset.txt");
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    // Bubble Sort
    auto start = std::chrono::high_resolution_clock::now();
    //std::vector<std::string> datos2 = bubbleSort(datos, datos.size());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    //std::cout << "Bubble Sort tomó " << duration.count() << " ms" << std::endl;
    //std::cout << "bubble sorted" << std::endl;


    // Quick Sort
    start = std::chrono::high_resolution_clock::now();
    std::vector<std::string> datos3 = quickSort(datos, 0, (int)datos.size() - 1);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Quick Sort tomó " << duration.count() << " ms" << std::endl;
    std::cout << "quick sorted" << std::endl;

    // Insertion Sort
    start = std::chrono::high_resolution_clock::now();
    std::vector<std::string> datos4 = insertionSort(datos);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Insertion Sort tomó " << duration.count() << " ms" << std::endl;
    std::cout << "insertion sorted" << std::endl;

    // Merge Sort
    start = std::chrono::high_resolution_clock::now();
    std::vector<std::string> datos5 = mergeSort(datos, 0, (int)datos.size() - 1);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Merge Sort tomó " << duration.count() << " ms" << std::endl;
    std::cout << "merge sorted" << std::endl;

    return 0;
}
