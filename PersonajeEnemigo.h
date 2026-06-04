//
// Created by yense on 6/2/2026.
//

#ifndef PROYECTO2KIAP_PERSONAJEENEMIGO_H
#define PROYECTO2KIAP_PERSONAJEENEMIGO_H
#include<iostream>
#include<sstream>

#include "Personaje.h"
using namespace std;

class PersonajeEnemigo : public Personaje {
private:
    string nombre;
    char genero;

public:
    PersonajeEnemigo(const string &nombre, char genero);
    std::string mostrar() override;

};


#endif //PROYECTO2KIAP_PERSONAJEENEMIGO_H