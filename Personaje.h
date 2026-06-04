//
// Created by cesar on 1/6/2026.
//

#ifndef PROYECTO2KIAP_PERSONAJE_H
#define PROYECTO2KIAP_PERSONAJE_H
#include <iostream>

#include "ZonaSuperior.h"
using namespace std;

class Personaje : public IMostrar{
protected:

    //decorator de equipamiento de proteccion, pendiente
    //decorator de objetos para hacer daño, pendiente

    double vida;
    double danioBase;
    bool vivo;
    vector<ZonaDelCuerpo*> zonasCuerpo; //pendiente, para determinar que zonas del cuerpo tiene el personaje, y asi determinar que movimientos puede realizar

public:
    Personaje();
    Personaje(double vida, double danioBase);
    virtual ~Personaje() = default;

    double getVida();
    void sanar(double cantidad);
    void daniar(double cantidad);

    double getDanio();

};


#endif //PROYECTO2KIAP_PERSONAJE_H