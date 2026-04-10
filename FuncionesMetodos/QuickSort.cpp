#include "../quickSort.h"
#include "../Leerdatos.h"
#include <iostream>

int partition(std::vector<std::string>& arr, int low, int high) {
    // Usar elemento aleatorio como pivot
    int random_idx = low + rand() % (high - low + 1);
    std::swap(arr[random_idx], arr[high]);  // Mover a final
    
    std::string pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortHelper(std::vector<std::string>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    
    }
}


void printArrayQ(std::vector<std::string> arr, int size){
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}