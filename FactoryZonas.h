//
// Created by cesar on 3/6/2026.
//

#ifndef PROYECTO2KIAP_FACTORYZONAS_H
#define PROYECTO2KIAP_FACTORYZONAS_H
#include "ZonasDelCuerpo.h"
#include <fstream>
//Fabrica zonas del cuerpo a partir de un archivo de texto

class FactoryZonas {
public:
    static vector<ZonaDelCuerpo*> crearZonas(const string& nombreArchivo) {
        vector<ZonaDelCuerpo*> zonas;
        ifstream archivo(nombreArchivo);
        if (!archivo.is_open()) {
            throw runtime_error("No se pudo abrir el archivo: " + nombreArchivo);
        }

        string linea;
        int numeroLinea = 0;

        while (getline(archivo, linea)) {
            numeroLinea++;

            // Ignorar líneas vacías
            if (linea.empty()) {
                continue;
            }

            // Validar que el nombre de zona no esté vacío
            if (linea.length() == 0) {
                throw invalid_argument("Línea " + to_string(numeroLinea) + ": El nombre de la zona no puede estar vacío");
            }

            // Verificar si ya existe la zona (evitar duplicados)
            for (const auto& zonaExistente : zonas) {
                if (zonaExistente->getNombre() == linea) {
                    throw invalid_argument("Línea " + to_string(numeroLinea) + ": La zona '" + linea + "' ya existe");
                }
            }
            // Crear la zona (el constructor de ZonaDelCuerpo también validará)
            zonas.push_back(new ZonaDelCuerpo(linea));
        }

        archivo.close();

        // Validar que se cargó al menos una zona
        if (zonas.empty()) {
            throw runtime_error("Archivo de zonas vacío o sin datos válidos: " + nombreArchivo);
        }

        return zonas;

    }
};


#endif //PROYECTO2KIAP_FACTORYZONAS_H