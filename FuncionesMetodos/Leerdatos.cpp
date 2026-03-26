#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>

std::vector<int> leerDatos() {
    std::string ruta="dataset.txt"; // Asegúrate de que esta ruta sea correcta y el archivo exista
    std::ifstream archivo(ruta);
    if (!archivo) {
        throw std::runtime_error("No se puede abrir el archivo: " + ruta);
    }

    std::vector<int> datos;
    int valor;
    while (archivo >> valor) {
        datos.push_back(valor);
    }
    return datos;
}
