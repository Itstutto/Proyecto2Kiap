//
// Created by cesar on 4/6/2026.
//

#ifndef PROYECTO2KIAP_FACTORYENEMIGOS_H
#define PROYECTO2KIAP_FACTORYENEMIGOS_H
#include "PersonajeEnemigo.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

class FactoryEnemigos {
public:
    static vector<Personaje*> crearEnemigo(const string& nombre, string dificultad) {
        ifstream archivo(nombre);
        if (!archivo.is_open()) {
            throw runtime_error("No se pudo abrir el archivo de enemigos: " + nombre);
        }
        vector<Personaje*> enemigos;
        string linea;
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string dif;
            if (dif != dificultad) {
                continue; // Saltar enemigos que no coincidan con la dificultad
            }
            string nombreEnemigo, generoStr, danioBaseStr, vidaStr;
            getline(ss, nombreEnemigo, ',');
            getline(ss, generoStr, ',');
            getline(ss, danioBaseStr, ',');
            getline(ss, vidaStr, ',');
            char genero = generoStr.empty() ? 'O' : generoStr[0]; // 'O' para otro si no se especifica
            double danioBase = stod(danioBaseStr);
            double vida = stod(vidaStr);
            enemigos.push_back(new PersonajeEnemigo(dificultad, nombreEnemigo, genero, danioBase, vida));
        }

        archivo.close();
        return enemigos;

    }
};


#endif //PROYECTO2KIAP_FACTORYENEMIGOS_H