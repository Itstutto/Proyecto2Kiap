//
// Created by cesar on 3/6/2026.
//

#ifndef PROYECTO2KIAP_ZONASDELCUERPO_H
#define PROYECTO2KIAP_ZONASDELCUERPO_H
#include <iostream>
#include <random>
#include <sstream>
#include "IMostrar.h"
using namespace std;

class ZonaDelCuerpo : public IMostrar{
private:
    string name;
    double condicion; //determina que tan probable es que se realize un movimiento, con menor condicion menor probabilidad
public:
    ZonaDelCuerpo(string name) {
        if (name.empty()) {
            throw invalid_argument("El name de la zone no puede estar vacío");
        }
        this->name = name;
        condicion = 1;
    }

    string getName() const { return name; }
    void setName(const std::string& n) { name = n; }

    double getCondicion() const { return condicion; }

    void utilizar(double impacto) {
        condicion -= impacto;
        if (condicion < 0) {
            condicion = 0;
        }
    }

    bool disponible() {
        random_device rd;
        mt19937 motor(rd());
        uniform_int_distribution<int> distribucion(1,100);

        int posibilidad = distribucion(motor);
        if (posibilidad>condicion*100) {
            return false;
        }
        return true;
    }

    std::string mostrar() override {
        stringstream s;
        s<<"Zona: "<<name<<", Condicion: "<<condicion*100<<"% "<<endl;
        return s.str();
    }

    bool operator==(const ZonaDelCuerpo &otro) const {
        return name == otro.name;
    }

};


#endif //PROYECTO2KIAP_ZONASDELCUERPO_H