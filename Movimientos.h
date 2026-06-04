//
// Created by cesar on 1/6/2026.
//

#ifndef PROYECTO2KIAP_MOVIMIENTOS_H
#define PROYECTO2KIAP_MOVIMIENTOS_H
#include <iostream>
#include <random>
#include "IMostrar.h"
using namespace std;

class Movimiento : public IMostrar{
protected:
    string nombre;
    string extremidad; //brazo derecho, brazo izquierdo, cabeza, etc
    string zonaImpacto; //cabeza, torso, brazo, pierna, etc
    double danio;
    double dificultad; //determina que tan dificil es realizar el movimiento, con mayor dificultad menor probabilidad de realizarlo
    string info;
public:
    Movimiento(string nombre, string extremidad, string zonaImpacto, double danio,string info);
    virtual ~Movimiento() = default;
    string getNombre();
    double getDanio();

    bool realizarMovimiento() {
        random_device rd;
        mt19937 motor(rd());
        uniform_int_distribution<int> distribucion(1,100);

        int posibilidad = distribucion(motor);
        if (posibilidad>dificultad*100) {
            return false;
        }
        return true;
    }

    string getExtremidad(){
        return extremidad;
    }
    string getZonaImpacto(){
        return zonaImpacto;
    }



};



#endif //PROYECTO2KIAP_MOVIMIENTOS_H
