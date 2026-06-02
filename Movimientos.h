//
// Created by cesar on 1/6/2026.
//

#ifndef PROYECTO2KIAP_MOVIMIENTOS_H
#define PROYECTO2KIAP_MOVIMIENTOS_H
#include <iostream>
using namespace std;

class Movimiento {
private:
    string nombre;
    double danio;
public:
    Movimiento(string nombre, double danio);
    virtual ~Movimiento() = default;
    string getNombre();
    double getDanio();

    virtual string getExtremidad() = 0;
    virtual string getZonaImpacto() = 0;



};


#endif //PROYECTO2KIAP_MOVIMIENTOS_H