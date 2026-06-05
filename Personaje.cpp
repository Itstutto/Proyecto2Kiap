//
// Created by cesar on 1/6/2026.
//

#include "Personaje.h"

#include "ListMovInferiores.h"
#include "ListMovSuperiores.h"
#include "ZonaInferior.h"

Personaje::Personaje() {
    vida = 100.0;
    danioBase = 5.0;
    vivo = true;
    ZonaSuperior* zonaSup = ZonaSuperior::getInstancia();
    ZonaInferior* zonaInf = ZonaInferior::getInstancia();
    zonasCuerpo.insert(zonasCuerpo.end(), zonaSup->getElementos().begin(), zonaSup->getElementos().end());
    zonasCuerpo.insert(zonasCuerpo.end(), zonaInf->getElementos().begin(), zonaInf->getElementos().end());


}

Personaje::Personaje(double vida, double danioBase) {
    this->vida = vida;
    this->danioBase = danioBase;
    vivo=true;
}


double Personaje::getDanio() {
    //temporal, para ver fucionalidad
    return danioBase;
}

void Personaje::daniar(double cantidad) {
    vida -= cantidad;
    if (vida<0) {
        vida = 0;
        vivo = false;
    }
}

bool Personaje::puedeRealizarMovimiento(Movimiento *mov) {
    for (const auto x : movimientos) {
        if (x->getNombre() == mov->getNombre()) {
            return true;
        }
    }
    return false;
}

ZonaDelCuerpo * Personaje::getZona(string nombreZona) {
    for (const auto x : zonasCuerpo) {
        if (x->getNombre() == nombreZona) {
            return x;
        }
    }
    return nullptr;
}

double Personaje::getVida() {
    return vida;
}

bool Personaje::isVivo() {
    return vida>0;
}

void Personaje::sanar(double cantidad) {
    vida+=cantidad;
    if (vida>100.0) {
        vida = 100.0;
    }
}
