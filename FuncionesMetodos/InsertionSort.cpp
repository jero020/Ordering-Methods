#include "../InsertionSort.h"
#include "../Leerdatos.h"
#include <iostream>

std::vector<std::string> insertionSort(std::vector<std::string>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        std::string key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return arr;
}


void printArrayI(std::vector<std::string> arr, int size);
