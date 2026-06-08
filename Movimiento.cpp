//
// Created by cesar on 3/6/2026.
//

#include "Movimientos.h"

Movimiento::Movimiento(string name,string extremidad, string zonaImpacto, double danio,double impacto, string info, double dificultad, int costo) {
    if (name.empty()) {
        throw invalid_argument("El name del movimiento no puede estar vacío");
    }
    if (extremidad.empty()) {
        throw invalid_argument("La extremidad no puede estar vacía");
    }
    if (zonaImpacto.empty()) {
        throw invalid_argument("La zone de impacto no puede estar vacía");
    }
    if (danio < 0) {
        throw invalid_argument("El daño no puede ser negativo: " + to_string(danio));
    }
    if (impacto < 0 || impacto > 1) {
        throw invalid_argument("El impacto debe estar entre 0 y 1, recibido: " + to_string(impacto));
    }

    this->name = name;
    this->extremidad = extremidad;
    this->zonaImpacto = zonaImpacto;
    this->danio = danio;
    this->impacto = impacto;
    this->info = info;
    this->dificultad = dificultad;
    if (costo < 0) {
        throw invalid_argument("El costo no puede ser negativo: " + to_string(costo));
    }
    this->costo = costo;
}

string Movimiento::getName() {
    return name;
}

double Movimiento::getDamage() {
    return danio;
}

double Movimiento::getImpacto() {
    return impacto;
}

int Movimiento::getCosto() {
    return costo;
}

std::string Movimiento::mostrar() {
    std::stringstream s;
    s << "Movimiento: " << name << " (Extremidad: " << extremidad
      << ", Zona: " << zonaImpacto << ", Daño: " << danio <<", Costo: "<< costo<< ")" << std::endl;
    return s.str();
}
