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
    string dificultad;

public:
    PersonajeEnemigo(const string &dificultad,const string &nombre, char genero, double danioBase, double vida = 100);
    std::string mostrar() override;
    string getNombre() override;
    string getDificultad();
    bool operator==(const PersonajeEnemigo &otro) const;
    bool sanar(int cantidad) override;
    string serializar() override;



};


#endif //PROYECTO2KIAP_PERSONAJEENEMIGO_H