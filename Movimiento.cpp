//
// Created by cesar on 3/6/2026.
//

#include "Movimientos.h"

Movimiento::Movimiento(string nombre,string extremidad, string zonaImpacto, double danio,double impacto, string info) {
    if (nombre.empty()) {
        throw invalid_argument("El nombre del movimiento no puede estar vacío");
    }
    if (extremidad.empty()) {
        throw invalid_argument("La extremidad no puede estar vacía");
    }
    if (zonaImpacto.empty()) {
        throw invalid_argument("La zona de impacto no puede estar vacía");
    }
    if (danio < 0) {
        throw invalid_argument("El daño no puede ser negativo: " + to_string(danio));
    }
    if (impacto < 0 || impacto > 1) {
        throw invalid_argument("El impacto debe estar entre 0 y 1, recibido: " + to_string(impacto));
    }

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
