//
// Created by cesar on 3/6/2026.
//

#include "Movimientos.h"

Movimiento::Movimiento(string nombre,string extremidad, string zonaImpacto, double danio,double impacto, string info) {
    this->nombre = nombre;
    this->extremidad = extremidad;
    this->zonaImpacto = zonaImpacto;
    this->danio = danio;
    this->impacto = impacto;
    this->info = info;
}

string Movimiento::getNombre() {
    return nombre;
}

double Movimiento::getDanio() {
    return danio;
}

double Movimiento::getImpacto() {
    return impacto;
}

std::string Movimiento::mostrar() {
    std::stringstream s;
    s << "Movimiento: " << nombre << " (Extremidad: " << extremidad
      << ", Zona: " << zonaImpacto << ", Daño: " << danio << ")" << std::endl;
    return s.str();
}
