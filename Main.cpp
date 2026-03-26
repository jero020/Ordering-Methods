#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm> // por ejemplo para std::sort
#include "FuncionesMetodos/Leerdatos.cpp" // Asegúrate de incluir el archivo correcto para leer datos
int main() {
    std::vector<int> datos = leerDatos();
    for (size_t i = 0; i < datos.size(); i++)
    {
        std::cout << datos[i] << " ";
    }
    
}

long long TimeSorting(){
  std::vector<int> a = {5, 3, 8, 1, 2}; // ejemplo de vector a ordenarºº

    auto t1 = std::chrono::high_resolution_clock::now();
    std::sort(a.begin(), a.end()); // ordenamos el vector
    auto t2 = std::chrono::high_resolution_clock::now();
    auto dur = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout << "Tiempo: " << dur << " microsegundos\n";
    return dur;
}
