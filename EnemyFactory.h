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

class EnemyFactory {
private:
    static void loadEasyMovements(Character* enemy) {
        //se elige al azar 4 movements con damage base menor a 20
        random_device rd;
        mt19937 engine(rd());
        uniform_int_distribution<int> distribution(0, LowerMovList::getInstance()->getElements().size() - 1);
        int amount = 0;
        while (amount < 2) {
            int selection = distribution(engine);
            Movement* mov = LowerMovList::getInstance()->getElements()[selection];
            if (mov->getDamage() <= 20) {
                try {
                    enemy->addMovement(mov->getName(), mov->getLimb());
                } catch (const invalid_argument& e) {
                    // Si el movimiento ya fue agregado, simplemente se ignora y se intenta con other
                    continue;
                }
                amount++;
            }

        }
    }

    static void loadMediumMovements(Character* enemy) {
        //se elige al azar 4 movements con damage base entre 20 y 40
        random_device rd;
        mt19937 engine(rd());
        uniform_int_distribution<int> distribution(0, LowerMovList::getInstance()->getElements().size() - 1);
        int amount = 0;
        while (amount < 2) {
            int selection = distribution(engine);
            Movement* mov = LowerMovList::getInstance()->getElements()[selection];
            if (mov->getDamage() >= 20 && mov->getDamage() < 40) {
                try {
                    enemy->addMovement(mov->getName(), mov->getLimb());
                } catch (const invalid_argument& e) {
                    // Si el movimiento ya fue agregado, simplemente se ignora y se intenta con other
                    continue;
                }
                amount++;
            }
        }
    }

    static void loadHardMovements(Character* enemy) {
        //se elige al azar 4 movements con damage base mayor a 40
        random_device rd;
        mt19937 engine(rd());
        uniform_int_distribution<int> distribution(0, LowerMovList::getInstance()->getElements().size() - 1);
        int amount = 0;
        while (amount < 2) {
            int selection = distribution(engine);
            Movement* mov = LowerMovList::getInstance()->getElements()[selection];
            if (mov->getDamage() >= 40) {
                try {
                    enemy->addMovement(mov->getName(), mov->getLimb());
                } catch (const invalid_argument& e) {
                    // Si el movimiento ya fue agregado, simplemente se ignora y se intenta con other
                    continue;
                }
                amount++;
            }
        }
    }
public:
    static vector<Character*> createEnemy(const string& name, string difficulty) {
        ifstream file(name);
        if (!file.is_open()) {
            throw runtime_error("No se pudo abrir el file de enemies: " + name);
        }
        vector<Character*> enemies;
        string line;
        int numberLine = 0;

        while (getline(file, line)) {
            numberLine++;

            // Ignorar líneas vacías
            if (line.empty()) {
                continue;
            }

            stringstream ss(line);
            string difficultyFile, enemyName, genderStr, damageStr, healthStr;

            // Leer difficulty del file
            if (!getline(ss, difficultyFile, ',')) {
                throw invalid_argument("Línea " + to_string(numberLine) + ": Falta la difficulty en el file de enemies");
            }

            // Verificar si la difficulty coincide
            if (difficultyFile != difficulty) {
                continue; // Saltar enemies que no coincidan con la difficulty
            }
            // Leer los demás campos
            if (!getline(ss, enemyName, ',')) {
                throw invalid_argument("Línea " + to_string(numberLine) + ": Falta el name del enemy");
            }

            if (enemyName.empty()) {
                throw invalid_argument("Línea " + to_string(numberLine) + ": El name del enemy no puede estar vacío");
            }

            if (!getline(ss, genderStr, ',')) {
                throw invalid_argument("Línea " + to_string(numberLine) + ": Falta el género del enemy");
            }

            if (!getline(ss, damageStr, ',')) {
                throw invalid_argument("Línea " + to_string(numberLine) + ": Falta el daño base del enemy");
            }

            if (!getline(ss, healthStr)) {
                throw invalid_argument("Línea " + to_string(numberLine) + ": Falta la health del enemy");
            }

            // Convertir strings a números con validación
            double damage;
            double health;
            try {
                damage = stod(damageStr);
            } catch (const invalid_argument& e) {
                throw invalid_argument("Línea " + to_string(numberLine) + ": Daño base no es un número válido: " + damageStr);
            } catch (const out_of_range& e) {
                throw invalid_argument("Línea " + to_string(numberLine) + ": Daño base fuera de rango: " + damageStr);
            }

            try {
                health = stod(healthStr);
            } catch (const invalid_argument& e) {
                throw invalid_argument("Línea " + to_string(numberLine) + ": Vida no es un número válido: " + healthStr);
            } catch (const out_of_range& e) {
                throw invalid_argument("Línea " + to_string(numberLine) + ": Vida fuera de rango: " + healthStr);
            }

            // Validar género
            char gender = genderStr.empty() ? 'O' : genderStr[0]; // 'O' para other si no se especifica
            if (gender != 'M' && gender != 'F' && gender != 'O') {
                throw invalid_argument("Línea " + to_string(numberLine) + ": Género inválido: " + string(1, gender));
            }
            // Crear el enemy (el constructor validará los valores)
            Enemy* enemy = new Enemy(difficulty, enemyName, gender, damage, health);
            if (difficulty == "Facil") {
                loadEasyMovements(enemy);
            } else if (difficulty == "Media") {
                loadMediumMovements(enemy);
            } else if (difficulty == "Dificil") {
                loadHardMovements(enemy);
            } else {
                throw invalid_argument("Dificultad desconocida: " + difficulty);
            }
            enemies.push_back(enemy);

        }

        file.close();
        return enemies;
    }

};


#endif //PROYECTO2KIAP_FACTORYENEMIGOS_H