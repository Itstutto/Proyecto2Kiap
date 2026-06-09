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

};


#endif //PROYECTO2KIAP_GUARDAR_H