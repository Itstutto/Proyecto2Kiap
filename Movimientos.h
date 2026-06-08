//
// Created by cesar on 1/6/2026.
//

#ifndef PROYECTO2KIAP_MOVIMIENTOS_H
#define PROYECTO2KIAP_MOVIMIENTOS_H
#include <iostream>
#include <random>
#include <sstream>
#include "IMostrar.h"
using namespace std;

class Movimiento : public IMostrar{
protected:
    string name;
    string extremidad; //brazo derecho, brazo izquierdo, cabeza, etc
    string zonaImpacto; //cabeza, torso, brazo, pierna, etc
    double danio;
    double impacto;
    double dificultad; //determina que tan dificil es realizar el movimiento, con mayor dificultad menor probabilidad de realizarlo
    string info;
    int costo;
public:
    Movimiento(string name, string extremidad, string zonaImpacto, double danio,double impacto,string info, double dificultad,int costo);
    virtual ~Movimiento() = default;
    string getName();
    double getDamage();
    double getImpacto();
    int getCosto();

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

    std::string mostrar() override;

    bool operator==(const Movimiento &otro) const {
        return name == otro.name &&
               extremidad == otro.extremidad &&
               zonaImpacto == otro.zonaImpacto;
    }


};



#endif //PROYECTO2KIAP_MOVIMIENTOS_H
