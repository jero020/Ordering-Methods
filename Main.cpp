#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include "Leerdatos.h"
#include "BubbleSort.h"
#include "quickSort.h"

std::vector<std::string> datos;

int main() {
    //std::vector<std::string>vector={"a", "caca", "bobo", "boba", "estupido", "pendejo"};
   try {
        datos = leerDatos("dataset.txt");
        }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    std::vector<std::string> datos2=bubbleSort(datos, datos.size());
    printArray(datos2, datos2.size());
    std::cout << std::endl;
    std::vector<std::string> datos3 = quickSort(datos, 0, (int)datos.size() - 1);
    printArrayQ(datos3, datos3.size());
    return 0;
}