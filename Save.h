//
// Created by cesar on 7/6/2026.
//

#ifndef PROYECTO2KIAP_GUARDAR_H
#define PROYECTO2KIAP_GUARDAR_H
#include <iostream>
#include <fstream>
#include "Character.h"
#include "Player.h"
#include "Vectors.h"
using namespace std;

class Save {
private:
    static bool alreadySaved; // Switch between app and trunc on the logfile
public:
    static void savePlayer(Character* p, string &path){
        ofstream file(path);
        if (!file.is_open()) {
            throw runtime_error("No se pudo abrir el archivo para guardar el personaje principal: " + path);
        }
        file << p->serialize() << endl;
        file.close();
    }
    static void saveEnemies(const vector<Character*> &enemies, const string &path) {
        ofstream file(path , ios::app); // Open in append mode to add to the end of the file
        if (!file.is_open()) {
            throw runtime_error("No se pudo abrir el archivo para guardar los enemigos: " + path);
        }
        for (auto enemy : enemies) {
            file << enemy->serialize() << endl;
        }
        file.close();
    }

    static void logBattle(const string &path, Character* p1, Character* enemy, int round) {
        ofstream file;
        if (alreadySaved) {
            file.open(path, ios::app); // Append to the existing log
        } else {
            file.open(path); // Create a new log file (truncates if it already exists)
            alreadySaved = true; // Set the flag to true after the first save
        }
        if (!file.is_open()) {
            throw runtime_error("No se pudo abrir el archivo para guardar el log de batalla: " + path);
        }
        if (p1->isAlive()) {
            file << p1->getName() << " ha ganado el round "<<round<<" con " << p1->getHealth() << " puntos de salud restantes." << endl;
            if (round == 5) {
                file << p1->getName() << " ha ganado la simulacion!" << endl;
            }
        }else {
            file << p1->getName() << " ha perdido el round" << " contra " << enemy->getName() << "." << endl;
        }


        file.close();
    }

};


#endif //PROYECTO2KIAP_GUARDAR_H