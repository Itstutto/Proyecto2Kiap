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
        //Four movements with base damage less than 20 are randomly selected
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
                    // If the move has already been added, simply ignore it and try another one.
                    continue;
                }
                amount++;
            }

        }
    }

    static void loadMediumMovements(Character* enemy) {
        //Four moves with base damage between 20 and 40 are randomly selected
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
                    // If the move has already been added, simply ignore it and try another one.
                    continue;
                }
                amount++;
            }
        }
    }

    static void loadHardMovements(Character* enemy) {
        //Four movements with a base damage greater than 40 are randomly selected
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
                    // If the move has already been added, simply ignore it and try another one.
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
            throw runtime_error("No se pudo abrir el archivo de enemies: " + name);
        }
        vector<Character*> enemies;
        string line;
        int numberLine = 0;

        while (getline(file, line)) {
            numberLine++;

            //Ignore empty lines
            if (line.empty()) {
                continue;
            }

            stringstream ss(line);
            string difficultyFile, enemyName, genderStr, damageStr, healthStr;

            //Read difficulty of the file
            if (!getline(ss, difficultyFile, ',')) {
                throw invalid_argument("Línea " + to_string(numberLine) + ": Falta la dificultad en el archivo de enemigos");
            }

            // Check if the difficulty matches
            if (difficultyFile != difficulty) {
                continue; // Skipping enemies that don't match the difficulty
            }
            // Read the other fields
            if (!getline(ss, enemyName, ',')) {
                throw invalid_argument("Línea " + to_string(numberLine) + ": Falta el nombre del enemigo");
            }

            if (enemyName.empty()) {
                throw invalid_argument("Línea " + to_string(numberLine) + ": El nombre del enemigo no puede estar vacío");
            }

            if (!getline(ss, genderStr, ',')) {
                throw invalid_argument("Línea " + to_string(numberLine) + ": Falta el género del enemigo");
            }

            if (!getline(ss, damageStr, ',')) {
                throw invalid_argument("Línea " + to_string(numberLine) + ": Falta el daño base del enemigo");
            }

            if (!getline(ss, healthStr)) {
                throw invalid_argument("Línea " + to_string(numberLine) + ": Falta la vida del enemigo");
            }

            // Convert strings to numbers with validation
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

            // Validate gender
            char gender = genderStr.empty() ? 'O' : genderStr[0]; //'O' for other if not specified
            if (gender != 'M' && gender != 'F' && gender != 'O') {
                throw invalid_argument("Línea " + to_string(numberLine) + ": Género inválido: " + string(1, gender));
            }
            // Create the enemy (the constructor will validate the values)
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