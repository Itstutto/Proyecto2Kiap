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
    string nombre;
    double condicion; //determina que tan probable es que se realize un movimiento, con menor condicion menor probabilidad
public:
    ZonaDelCuerpo(string nombre) {
        this->nombre = nombre;
        condicion = 1;
    }

    string getNombre() const { return nombre; }
    void setNombre(const std::string& n) { nombre = n; }

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
        s<<"Zona: "<<nombre<<", Condicion: "<<condicion*100<<"% "<<endl;
        return s.str();
    }

};


#endif //PROYECTO2KIAP_ZONASDELCUERPO_H