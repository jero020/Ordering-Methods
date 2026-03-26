#include <iostream>
#include <vector>// Asegúrate de incluir el encabezado correcto para leer datos
#include "Leerdatos.cpp" // Asegúrate de incluir el archivo correcto para leer datos
// Función que implementa el algoritmo de Bubble Sort
void bubbleSort(int arr[], int n) {
    // Bucle externo para controlar el número de pasadas
    for (int i = 0; i < n - 1; i++) {
        // Bucle interno para comparar elementos adyacentes
        for (int j = 0; j < n - i - 1; j++) {
            // Si el elemento actual es mayor que el siguiente,
            // los intercambia
            if (arr[j] > arr[j + 1]) {
                // Intercambio de valores
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Función para imprimir el arreglo
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Función principal para probar el algoritmo
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Arreglo original: ";
    printArray(arr, n);

    bubbleSort(arr, n);

    std::cout << "Arreglo ordenado: ";
    printArray(arr, n);

    return 0;
}
