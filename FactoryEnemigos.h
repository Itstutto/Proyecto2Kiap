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
    static void cargarMovimientosFacil(Character* enemy) {
        //se elige al azar 4 movements con damage base menor a 20
        random_device rd;
        mt19937 engine(rd());
        uniform_int_distribution<int> distribucion(0, ListMovInferiores::getInstancia()->getElementos().size() - 1);
        int amount = 0;
        while (amount < 2) {
            int seleccion = distribucion(engine);
            Movimiento* mov = ListMovInferiores::getInstancia()->getElementos()[seleccion];
            if (mov->getDamage() <= 20) {
                try {
                    enemy->addMovement(mov->getName(), mov->getExtremidad());
                } catch (const invalid_argument& e) {
                    // Si el movimiento ya fue agregado, simplemente se ignora y se intenta con other
                    continue;
                }
                amount++;
            }

        }
    }

    static void cargarMovimientosMedia(Character* enemy) {
        //se elige al azar 4 movements con damage base entre 20 y 40
        random_device rd;
        mt19937 engine(rd());
        uniform_int_distribution<int> distribucion(0, ListMovInferiores::getInstancia()->getElementos().size() - 1);
        int amount = 0;
        while (amount < 2) {
            int seleccion = distribucion(engine);
            Movimiento* mov = ListMovInferiores::getInstancia()->getElementos()[seleccion];
            if (mov->getDamage() >= 20 && mov->getDamage() < 40) {
                try {
                    enemy->addMovement(mov->getName(), mov->getExtremidad());
                } catch (const invalid_argument& e) {
                    // Si el movimiento ya fue agregado, simplemente se ignora y se intenta con other
                    continue;
                }
                amount++;
            }
        }
    }

    static void cargarMovimientosDificil(Character* enemy) {
        //se elige al azar 4 movements con damage base mayor a 40
        random_device rd;
        mt19937 engine(rd());
        uniform_int_distribution<int> distribucion(0, ListMovInferiores::getInstancia()->getElementos().size() - 1);
        int amount = 0;
        while (amount < 2) {
            int seleccion = distribucion(engine);
            Movimiento* mov = ListMovInferiores::getInstancia()->getElementos()[seleccion];
            if (mov->getDamage() >= 40) {
                try {
                    enemy->addMovement(mov->getName(), mov->getExtremidad());
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
        ifstream file(name);
        if (!file.is_open()) {
            throw runtime_error("No se pudo abrir el file de enemigos: " + name);
        }
        vector<Character*> enemigos;
        string line;
        int numeroLinea = 0;

        while (getline(file, line)) {
            numeroLinea++;

            // Ignorar líneas vacías
            if (line.empty()) {
                continue;
            }

            stringstream ss(line);
            string dificultadArchivo, nombreEnemigo, genderStr, danioBaseStr, healthStr;

            // Leer difficulty del file
            if (!getline(ss, dificultadArchivo, ',')) {
                throw invalid_argument("Línea " + to_string(numeroLinea) + ": Falta la difficulty en el file de enemigos");
            }

            // Verificar si la difficulty coincide
            if (dificultadArchivo != difficulty) {
                continue; // Saltar enemigos que no coincidan con la difficulty
            }
            // Leer los demás campos
            if (!getline(ss, nombreEnemigo, ',')) {
                throw invalid_argument("Línea " + to_string(numeroLinea) + ": Falta el name del enemy");
            }

            if (nombreEnemigo.empty()) {
                throw invalid_argument("Línea " + to_string(numeroLinea) + ": El name del enemy no puede estar vacío");
            }

            if (!getline(ss, genderStr, ',')) {
                throw invalid_argument("Línea " + to_string(numeroLinea) + ": Falta el género del enemy");
            }

            if (!getline(ss, danioBaseStr, ',')) {
                throw invalid_argument("Línea " + to_string(numeroLinea) + ": Falta el daño base del enemy");
            }

            if (!getline(ss, healthStr)) {
                throw invalid_argument("Línea " + to_string(numeroLinea) + ": Falta la health del enemy");
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
                health = stod(healthStr);
            } catch (const invalid_argument& e) {
                throw invalid_argument("Línea " + to_string(numeroLinea) + ": Vida no es un número válido: " + healthStr);
            } catch (const out_of_range& e) {
                throw invalid_argument("Línea " + to_string(numeroLinea) + ": Vida fuera de rango: " + healthStr);
            }

            // Validar género
            char gender = genderStr.empty() ? 'O' : genderStr[0]; // 'O' para other si no se especifica
            if (gender != 'M' && gender != 'F' && gender != 'O') {
                throw invalid_argument("Línea " + to_string(numeroLinea) + ": Género inválido: " + string(1, gender));
            }
            // Crear el enemy (el constructor validará los valores)
            Enemy* enemy = new Enemy(difficulty, nombreEnemigo, gender, damage, health);
            if (difficulty == "Facil") {
                cargarMovimientosFacil(enemy);
            } else if (difficulty == "Media") {
                cargarMovimientosMedia(enemy);
            } else if (difficulty == "Dificil") {
                cargarMovimientosDificil(enemy);
            } else {
                throw invalid_argument("Dificultad desconocida: " + difficulty);
            }
            enemigos.push_back(enemy);

        }

        file.close();
        return enemigos;
    }

};


#endif //PROYECTO2KIAP_FACTORYENEMIGOS_H