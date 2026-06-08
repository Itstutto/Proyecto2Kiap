//
// Created by cesar on 4/6/2026.
//

#ifndef PROYECTO2KIAP_FACTORYENEMIGOS_H
#define PROYECTO2KIAP_FACTORYENEMIGOS_H
#include "Enemy.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <random>
using namespace std;

class FactoryEnemigos {
private:
    static void cargarMovimientosFacil(Character* enemigo) {
        //se elige al azar 4 movements con danio base menor a 20
        random_device rd;
        mt19937 motor(rd());
        uniform_int_distribution<int> distribucion(0, ListMovInferiores::getInstancia()->getElementos().size() - 1);
        int amount = 0;
        while (amount < 2) {
            int seleccion = distribucion(motor);
            Movimiento* mov = ListMovInferiores::getInstancia()->getElementos()[seleccion];
            if (mov->getDamage() <= 20) {
                try {
                    enemigo->addMovement(mov->getName(), mov->getExtremidad());
                } catch (const invalid_argument& e) {
                    // Si el movimiento ya fue agregado, simplemente se ignora y se intenta con other
                    continue;
                }
                amount++;
            }

        }
    }

    static void cargarMovimientosMedia(Character* enemigo) {
        //se elige al azar 4 movements con danio base entre 20 y 40
        random_device rd;
        mt19937 motor(rd());
        uniform_int_distribution<int> distribucion(0, ListMovInferiores::getInstancia()->getElementos().size() - 1);
        int amount = 0;
        while (amount < 2) {
            int seleccion = distribucion(motor);
            Movimiento* mov = ListMovInferiores::getInstancia()->getElementos()[seleccion];
            if (mov->getDamage() >= 20 && mov->getDamage() < 40) {
                try {
                    enemigo->addMovement(mov->getName(), mov->getExtremidad());
                } catch (const invalid_argument& e) {
                    // Si el movimiento ya fue agregado, simplemente se ignora y se intenta con other
                    continue;
                }
                amount++;
            }
        }
    }

    static void cargarMovimientosDificil(Character* enemigo) {
        //se elige al azar 4 movements con danio base mayor a 40
        random_device rd;
        mt19937 motor(rd());
        uniform_int_distribution<int> distribucion(0, ListMovInferiores::getInstancia()->getElementos().size() - 1);
        int amount = 0;
        while (amount < 2) {
            int seleccion = distribucion(motor);
            Movimiento* mov = ListMovInferiores::getInstancia()->getElementos()[seleccion];
            if (mov->getDamage() >= 40) {
                try {
                    enemigo->addMovement(mov->getName(), mov->getExtremidad());
                } catch (const invalid_argument& e) {
                    // Si el movimiento ya fue agregado, simplemente se ignora y se intenta con other
                    continue;
                }
                amount++;
            }
        }
    }
public:
    static vector<Character*> crearEnemigo(const string& name, string difficulty) {
        ifstream archivo(name);
        if (!archivo.is_open()) {
            throw runtime_error("No se pudo abrir el archivo de enemigos: " + name);
        }
        vector<Character*> enemigos;
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

            // Leer difficulty del archivo
            if (!getline(ss, dificultadArchivo, ',')) {
                throw invalid_argument("Línea " + to_string(numeroLinea) + ": Falta la difficulty en el archivo de enemigos");
            }

            // Verificar si la difficulty coincide
            if (dificultadArchivo != difficulty) {
                continue; // Saltar enemigos que no coincidan con la difficulty
            }
            // Leer los demás campos
            if (!getline(ss, nombreEnemigo, ',')) {
                throw invalid_argument("Línea " + to_string(numeroLinea) + ": Falta el name del enemigo");
            }

            if (nombreEnemigo.empty()) {
                throw invalid_argument("Línea " + to_string(numeroLinea) + ": El name del enemigo no puede estar vacío");
            }

            if (!getline(ss, generoStr, ',')) {
                throw invalid_argument("Línea " + to_string(numeroLinea) + ": Falta el género del enemigo");
            }

            if (!getline(ss, danioBaseStr, ',')) {
                throw invalid_argument("Línea " + to_string(numeroLinea) + ": Falta el daño base del enemigo");
            }

            if (!getline(ss, vidaStr)) {
                throw invalid_argument("Línea " + to_string(numeroLinea) + ": Falta la health del enemigo");
            }

            // Convertir strings a números con validación
            double damage;
            double health;
            try {
                damage = stod(danioBaseStr);
            } catch (const invalid_argument& e) {
                throw invalid_argument("Línea " + to_string(numeroLinea) + ": Daño base no es un número válido: " + danioBaseStr);
            } catch (const out_of_range& e) {
                throw invalid_argument("Línea " + to_string(numeroLinea) + ": Daño base fuera de rango: " + danioBaseStr);
            }

            try {
                health = stod(vidaStr);
            } catch (const invalid_argument& e) {
                throw invalid_argument("Línea " + to_string(numeroLinea) + ": Vida no es un número válido: " + vidaStr);
            } catch (const out_of_range& e) {
                throw invalid_argument("Línea " + to_string(numeroLinea) + ": Vida fuera de rango: " + vidaStr);
            }

            // Validar género
            char gender = generoStr.empty() ? 'O' : generoStr[0]; // 'O' para other si no se especifica
            if (gender != 'M' && gender != 'F' && gender != 'O') {
                throw invalid_argument("Línea " + to_string(numeroLinea) + ": Género inválido: " + string(1, gender));
            }
            // Crear el enemigo (el constructor validará los valores)
            Enemy* enemigo = new Enemy(difficulty, nombreEnemigo, gender, damage, health);
            if (difficulty == "Facil") {
                cargarMovimientosFacil(enemigo);
            } else if (difficulty == "Media") {
                cargarMovimientosMedia(enemigo);
            } else if (difficulty == "Dificil") {
                cargarMovimientosDificil(enemigo);
            } else {
                throw invalid_argument("Dificultad desconocida: " + difficulty);
            }
            enemigos.push_back(enemigo);

        }

        archivo.close();
        return enemigos;
    }

};


#endif //PROYECTO2KIAP_FACTORYENEMIGOS_H