#include <iostream>
#include <vector>
// Función que implementa el algoritmo de Bubble Sort
std::vector<std::string> bubbleSort(std::vector<std::string>& arr, int n) {
    // Bucle externo para controlar el número de pasadas
    for (int i = 0; i < n - 1; i++) {
        // Bucle interno para comparar elementos adyacentes
        for (int j = 0; j < n - i - 1; j++) {
            // Si el elemento actual es mayor que el siguiente,
            // los intercambia
            if (arr[j] > arr[j + 1]) {
                // Intercambio de valores
                std::string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr;

}

// Función para imprimir el arreglo
void printArray(std::vector<std::string> arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


