//
// Created by cesar on 3/6/2026.
//

#include "Movimientos.h"

Movimiento::Movimiento(string nombre,string extremidad, string zonaImpacto, double danio, string info) {
    this->nombre = nombre;
    this->extremidad = extremidad;
    this->zonaImpacto = zonaImpacto;
    this->danio = danio;
    this->info = info;
}

string Movimiento::getNombre() {
    return nombre;
}

double Movimiento::getDanio() {
    return danio;
}




