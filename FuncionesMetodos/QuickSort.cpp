#include "../quickSort.h"
#include <iostream>

// Función de partición: reorganiza el arreglo alrededor de un pivote.
// Todo elemento menor o igual al pivote queda a su izquierda,
// y todo elemento mayor queda a su derecha.
// Retorna el índice final donde quedó el pivote.
int partition(std::vector<std::string>& arr, int low, int high) {
    std::string pivot = arr[high];  // Se toma el último elemento como pivote
    int i = low - 1;               // i apunta al último elemento menor que el pivote

    for (int j = low; j < high; j++) {
        // Si el elemento actual es menor o igual al pivote (comparación alfabética),
        // se mueve hacia la zona izquierda
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);  // Intercambia para colocarlo a la izquierda
        }
    }

    // Coloca el pivote en su posición correcta (entre menores y mayores)
    std::swap(arr[i + 1], arr[high]);
    return i + 1;  // Retorna el índice donde quedó el pivote
}

// Helper recursivo interno: realiza el ordenamiento en sitio sin copias innecesarias.
static void quickSortHelper(std::vector<std::string>& arr, int low, int high) {
    if (low < high) {  // Caso base: si hay más de un elemento
        int pi = partition(arr, low, high);      // Particiona y obtiene índice del pivote
        quickSortHelper(arr, low, pi - 1);       // Ordena la mitad izquierda
        quickSortHelper(arr, pi + 1, high);      // Ordena la mitad derecha
    }
}

// Función pública QuickSort: ordena el arreglo y retorna una copia ordenada.
std::vector<std::string> quickSort(std::vector<std::string>& arr, int low, int high) {
    quickSortHelper(arr, low, high);
    return arr;
}

// Función para imprimir el arreglo
void printArrayQ(std::vector<std::string> arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
