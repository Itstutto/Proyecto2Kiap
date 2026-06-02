//
// Created by cesar on 1/6/2026.
//

#ifndef PROYECTO2KIAP_PERSONAJE_H
#define PROYECTO2KIAP_PERSONAJE_H
#include <iostream>
using namespace std;

class Personaje {
protected:

    //decorator de equipamiento de proteccion, pendiente
    //decorator de objetos para hacer daño, pendiente

    double vida;
    double danioBase;
    bool vivo;

public:
    Personaje();
    Personaje(double vida, double danioBase);
    virtual ~Personaje() = default;

    double getVida();
    void sanar(double cantidad);
    void daniar(double cantidad);

    double getDanio();

    virtual string getInfo() = 0;

};


#endif //PROYECTO2KIAP_PERSONAJE_H