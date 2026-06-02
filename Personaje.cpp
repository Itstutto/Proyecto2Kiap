//
// Created by cesar on 1/6/2026.
//

#include "Personaje.h"

Personaje::Personaje() {
    vida = 100.0;
    danioBase = 5.0;
    vivo = true;
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

double Personaje::getVida() {
    return vida;
}

void Personaje::sanar(double cantidad) {
    vida+=cantidad;
    if (vida>100.0) {
        vida = 100.0;
    }
}
