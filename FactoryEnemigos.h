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
        int numeroLinea = 0;

        while (getline(archivo, linea)) {
            numeroLinea++;

            // Ignorar líneas vacías
            if (linea.empty()) {
                continue;
            }

            stringstream ss(linea);
            string dificultadArchivo, nombreEnemigo, generoStr, danioBaseStr, vidaStr;

            // Leer dificultad del archivo
            if (!getline(ss, dificultadArchivo, ',')) {
                throw invalid_argument("Línea " + to_string(numeroLinea) + ": Falta la dificultad en el archivo de enemigos");
            }

            // Verificar si la dificultad coincide
            if (dificultadArchivo != dificultad) {
                continue; // Saltar enemigos que no coincidan con la dificultad
            }
            // Leer los demás campos
            if (!getline(ss, nombreEnemigo, ',')) {
                throw invalid_argument("Línea " + to_string(numeroLinea) + ": Falta el nombre del enemigo");
            }

            if (nombreEnemigo.empty()) {
                throw invalid_argument("Línea " + to_string(numeroLinea) + ": El nombre del enemigo no puede estar vacío");
            }

            if (!getline(ss, generoStr, ',')) {
                throw invalid_argument("Línea " + to_string(numeroLinea) + ": Falta el género del enemigo");
            }

            if (!getline(ss, danioBaseStr, ',')) {
                throw invalid_argument("Línea " + to_string(numeroLinea) + ": Falta el daño base del enemigo");
            }

            if (!getline(ss, vidaStr)) {
                throw invalid_argument("Línea " + to_string(numeroLinea) + ": Falta la vida del enemigo");
            }

            // Convertir strings a números con validación
            double danioBase;
            double vida;
            try {
                danioBase = stod(danioBaseStr);
            } catch (const invalid_argument& e) {
                throw invalid_argument("Línea " + to_string(numeroLinea) + ": Daño base no es un número válido: " + danioBaseStr);
            } catch (const out_of_range& e) {
                throw invalid_argument("Línea " + to_string(numeroLinea) + ": Daño base fuera de rango: " + danioBaseStr);
            }

            try {
                vida = stod(vidaStr);
            } catch (const invalid_argument& e) {
                throw invalid_argument("Línea " + to_string(numeroLinea) + ": Vida no es un número válido: " + vidaStr);
            } catch (const out_of_range& e) {
                throw invalid_argument("Línea " + to_string(numeroLinea) + ": Vida fuera de rango: " + vidaStr);
            }

            // Validar género
            char genero = generoStr.empty() ? 'O' : generoStr[0]; // 'O' para otro si no se especifica
            if (genero != 'M' && genero != 'F' && genero != 'O') {
                throw invalid_argument("Línea " + to_string(numeroLinea) + ": Género inválido: " + string(1, genero));
            }
            // Crear el enemigo (el constructor validará los valores)
            enemigos.push_back(new PersonajeEnemigo(dificultad, nombreEnemigo, genero, danioBase, vida));

        }

        archivo.close();
        return enemigos;
    }

};


#endif //PROYECTO2KIAP_FACTORYENEMIGOS_H