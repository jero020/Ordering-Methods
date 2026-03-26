#include "../Leerdatos.h"
#include <fstream>
#include <stdexcept>
#include <string>

std::vector<std::string> leerDatos(const std::string& ruta) {
    std::ifstream archivo(ruta);
    if (!archivo) {
        throw std::runtime_error("No se puede abrir el archivo: " + ruta);
    }

    std::vector<std::string> datos;
    std::string linea;
    while (std::getline(archivo, linea)) {
        if (!linea.empty()) {
            datos.push_back(linea);
        }
    }
    return datos;
}
