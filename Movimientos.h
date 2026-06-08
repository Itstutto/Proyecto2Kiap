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
    double difficulty; //determina que tan dificil es realizar el movimiento, con mayor difficulty menor probabilidad de realizarlo
    string info;
    int costo;
public:
    Movimiento(string name, string extremidad, string zonaImpacto, double danio,double impacto,string info, double difficulty,int costo);
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

        if (posibilidad>difficulty*100) {
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

    bool operator==(const Movimiento &other) const {
        return name == other.name &&
               extremidad == other.extremidad &&
               zonaImpacto == other.zonaImpacto;
    }


};



#endif //PROYECTO2KIAP_MOVIMIENTOS_H
