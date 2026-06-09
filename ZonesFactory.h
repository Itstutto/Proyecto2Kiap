//
// Created by cesar on 3/6/2026.
//

#ifndef PROYECTO2KIAP_FACTORYZONAS_H
#define PROYECTO2KIAP_FACTORYZONAS_H
#include "BodyZones.h"
#include <fstream>
//Create body zones from a text file

class ZonesFactory {
public:
    static vector<BodyZone*> createZones(const string& fileName) {
        vector<BodyZone*> zones;
        ifstream file(fileName);
        if (!file.is_open()) {
            throw runtime_error("No se pudo abrir el archivo: " + fileName);
        }

        string line;
        int numberLine = 0;

        while (getline(file, line)) {
            numberLine++;

            // Ignore empty lines
            if (line.empty()) {
                continue;
            }

            // Validate that the zone name is not empty.
            if (line.length() == 0) {
                throw invalid_argument("Línea " + to_string(numberLine) + ": El nombre de la zona no puede estar vacío");
            }

            // Check if the area already exists (avoid duplicates)
            for (const auto& existingZone : zones) {
                if (existingZone->getName() == line) {
                    throw invalid_argument("Línea " + to_string(numberLine) + ": La zona '" + line + "' ya existe");
                }
            }
            // Create the zone (the BodyZone builder will also validate)
            zones.push_back(new BodyZone(line));
        }

        file.close();

        // Validate that at least one zone was loaded
        if (zones.empty()) {
            throw runtime_error("Archivo de zonas vacío o sin datos válidos: " + fileName);
        }

        return zones;

    }
};


#endif //PROYECTO2KIAP_FACTORYZONAS_H