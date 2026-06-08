//
// Created by cesar on 7/6/2026.
//

#ifndef PROYECTO2KIAP_GUARDAR_H
#define PROYECTO2KIAP_GUARDAR_H
#include <iostream>
#include <fstream>
#include "Character.h"
#include "PersonajePrincipal.h"
#include "Vectores.h"
using namespace std;

class Guardar {
public:
    static void guardarPersonajePrincipal(Character* p, string &ruta){
        ofstream archivo(ruta);
        if (!archivo.is_open()) {
            throw runtime_error("No se pudo abrir el archivo para guardar el personaje principal: " + ruta);
        }
        archivo << p->serializar() << endl;
        archivo.close();
    }
    static void guardarEnemigos(vector<Character*> enemigos, string &ruta) {
        ofstream archivo(ruta , ios::app); // Abrir en modo append para agregar al final del archivo
        if (!archivo.is_open()) {
            throw runtime_error("No se pudo abrir el archivo para guardar los enemigos: " + ruta);
        }
        for (auto enemigo : enemigos) {
            archivo << enemigo->serializar() << endl;
        }
        archivo.close();
    }

};


#endif //PROYECTO2KIAP_GUARDAR_H