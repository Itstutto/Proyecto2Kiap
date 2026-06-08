//
// Created by cesar on 3/6/2026.
//

#ifndef PROYECTO2KIAP_FACTORYZONAS_H
#define PROYECTO2KIAP_FACTORYZONAS_H
#include "ZonasDelCuerpo.h"
#include <fstream>
//Fabrica zonas del cuerpo a partir de un file de texto

class FactoryZonas {
public:
    static vector<ZonaDelCuerpo*> crearZonas(const string& fileName) {
        vector<ZonaDelCuerpo*> zonas;
        ifstream file(fileName);
        if (!file.is_open()) {
            throw runtime_error("No se pudo abrir el file: " + fileName);
        }

        string line;
        int numeroLinea = 0;

        while (getline(file, line)) {
            numeroLinea++;

            // Ignorar líneas vacías
            if (line.empty()) {
                continue;
            }

            // Validar que el name de zone no esté vacío
            if (line.length() == 0) {
                throw invalid_argument("Línea " + to_string(numeroLinea) + ": El name de la zone no puede estar vacío");
            }

            // Verificar si ya existe la zone (evitar duplicados)
            for (const auto& zonaExistente : zonas) {
                if (zonaExistente->getName() == line) {
                    throw invalid_argument("Línea " + to_string(numeroLinea) + ": La zone '" + line + "' ya existe");
                }
            }
            // Crear la zone (el constructor de ZonaDelCuerpo también validará)
            zonas.push_back(new ZonaDelCuerpo(line));
        }

        file.close();

        // Validar que se cargó al menos una zone
        if (zonas.empty()) {
            throw runtime_error("Archivo de zonas vacío o sin datos válidos: " + fileName);
        }

        return zonas;

    }
};


#endif //PROYECTO2KIAP_FACTORYZONAS_H