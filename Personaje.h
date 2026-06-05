//
// Created by cesar on 1/6/2026.
//

#ifndef PROYECTO2KIAP_PERSONAJE_H
#define PROYECTO2KIAP_PERSONAJE_H
#include <iostream>

#include "Movimientos.h"
#include "ZonaSuperior.h"
using namespace std;

class Personaje : public IMostrar{
protected:

    //decorator de equipamiento de proteccion, pendiente
    //decorator de objetos para hacer daño, pendiente

    double vida;
    double danioBase;
    bool vivo;
    vector<ZonaDelCuerpo*> zonasCuerpo; //para determinar que zonas del cuerpo tiene el personaje, y asi determinar que movimientos puede realizar
    vector<Movimiento*> movimientos; //para determinar que movimientos puede realizar el personaje, y asi determinar que zonas del cuerpo puede atacar
public:
    Personaje();
    Personaje(double vida, double danioBase);
    virtual ~Personaje() = default;

    virtual string getNombre() = 0;
    double getVida();
    bool isVivo();
    void sanar(double cantidad);
    void daniar(double cantidad);

    bool puedeRealizarMovimiento(Movimiento* mov);

    ZonaDelCuerpo* getZona(string nombreZona);

    double getDanio();

};


#endif //PROYECTO2KIAP_PERSONAJE_H
