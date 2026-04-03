#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include "Leerdatos.h"
#include "BubbleSort.h"

std::vector<std::string> datos;

int main() {
    
   try {
        datos = leerDatos("dataset.txt");
        }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
     std::vector<std::string> datos2=bubbleSort(datos, datos.size());
    printArray(datos2, datos2.size());

    return 0;
}
