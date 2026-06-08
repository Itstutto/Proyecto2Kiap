//
// Created by cesar on 7/6/2026.
//

#ifndef PROYECTO2KIAP_GUARDAR_H
#define PROYECTO2KIAP_GUARDAR_H
#include <iostream>
#include <fstream>
#include "Character.h"
#include "Player.h"
#include "Vectores.h"
using namespace std;

class Guardar {
public:
    static void guardarPersonajePrincipal(Character* p, string &ruta){
        ofstream file(ruta);
        if (!file.is_open()) {
            throw runtime_error("No se pudo abrir el file para guardar el personaje principal: " + ruta);
        }
        file << p->serializar() << endl;
        file.close();
    }
    static void guardarEnemigos(vector<Character*> enemigos, string &ruta) {
        ofstream file(ruta , ios::app); // Abrir en modo append para agregar al final del file
        if (!file.is_open()) {
            throw runtime_error("No se pudo abrir el file para guardar los enemigos: " + ruta);
        }
        for (auto enemy : enemigos) {
            file << enemy->serializar() << endl;
        }
        file.close();
    }

};


#endif //PROYECTO2KIAP_GUARDAR_H