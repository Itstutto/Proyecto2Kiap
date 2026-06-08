//
// Created by cesar on 3/6/2026.
//

#ifndef PROYECTO2KIAP_FACTORYZONAS_H
#define PROYECTO2KIAP_FACTORYZONAS_H
#include "BodyZones.h"
#include <fstream>
//Fabrica zones del cuerpo a partir de un file de texto

class ZonesFactory {
public:
    static vector<BodyZone*> createZones(const string& fileName) {
        vector<BodyZone*> zones;
        ifstream file(fileName);
        if (!file.is_open()) {
            throw runtime_error("No se pudo abrir el file: " + fileName);
        }

        string line;
        int numberLine = 0;

        while (getline(file, line)) {
            numberLine++;

            // Ignorar líneas vacías
            if (line.empty()) {
                continue;
            }

            // Validar que el name de zone no esté vacío
            if (line.length() == 0) {
                throw invalid_argument("Línea " + to_string(numberLine) + ": El name de la zone no puede estar vacío");
            }

            // Verificar si ya existe la zone (evitar duplicados)
            for (const auto& existingZone : zones) {
                if (existingZone->getName() == line) {
                    throw invalid_argument("Línea " + to_string(numberLine) + ": La zone '" + line + "' ya existe");
                }
            }
            // Crear la zone (el constructor de BodyZone también validará)
            zones.push_back(new BodyZone(line));
        }

        file.close();

        // Validar que se cargó al menos una zone
        if (zones.empty()) {
            throw runtime_error("Archivo de zones vacío o sin datos válidos: " + fileName);
        }

        return zones;

    }
};


#endif //PROYECTO2KIAP_FACTORYZONAS_H