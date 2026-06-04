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
        while (getline(archivo, linea)) {
            if (!linea.empty()) {
                zonas.push_back(new ZonaDelCuerpo(linea));
            }
        }

        archivo.close();
        return zonas;
    }
};


#endif //PROYECTO2KIAP_FACTORYZONAS_H