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
    string limb; //brazo derecho, brazo izquierdo, cabeza, etc
    string impactZone; //cabeza, torso, brazo, pierna, etc
    double damage;
    double impact;
    double difficulty; //determina que tan dificil es realizar el movimiento, con mayor difficulty menor probabilidad de realizarlo
    string info;
    int cost;
public:
    Movimiento(string name, string limb, string impactZone, double damage,double impact,string info, double difficulty,int cost);
    virtual ~Movimiento() = default;
    string getName();
    double getDamage();
    double getImpacto();
    int getCosto();

    bool realizarMovimiento() {
        random_device rd;
        mt19937 engine(rd());
        uniform_int_distribution<int> distribucion(1,100);

        int posibilidad = distribucion(engine);

        if (posibilidad>difficulty*100) {
            return false;
        }
        return true;
    }

    string getExtremidad(){
        return limb;
    }
    string getZonaImpacto(){
        return impactZone;
    }

    std::string mostrar() override;

    bool operator==(const Movimiento &other) const {
        return name == other.name &&
               limb == other.limb &&
               impactZone == other.impactZone;
    }


};



#endif //PROYECTO2KIAP_MOVIMIENTOS_H
