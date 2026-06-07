//
// Created by cesar on 1/6/2026.
//

#include "Personaje.h"

#include "ListMovInferiores.h"

#include "ZonaInferior.h"

Personaje::Personaje() {

    vida = 100.0;
    danioBase = 5.0;
    vivo = true;
    ZonaSuperior* zonaSup = ZonaSuperior::getInstancia();
    ZonaInferior* zonaInf = ZonaInferior::getInstancia();

    auto zonasSup = zonaSup->getElementos();
    auto zonasInf = zonaInf->getElementos();

    zonasCuerpo.insert(zonasCuerpo.end(), zonasSup.begin(), zonasSup.end());
    zonasCuerpo.insert(zonasCuerpo.end(), zonasInf.begin(), zonasInf.end());

}

Personaje::Personaje(double vida, double danioBase) {
    this->vida = vida;
    this->danioBase = danioBase;
    vivo=true;
    ZonaSuperior* zonaSup = ZonaSuperior::getInstancia();
    ZonaInferior* zonaInf = ZonaInferior::getInstancia();

    auto zonasSup = zonaSup->getElementos();
    auto zonasInf = zonaInf->getElementos();

    zonasCuerpo.insert(zonasCuerpo.end(), zonasSup.begin(), zonasSup.end());
    zonasCuerpo.insert(zonasCuerpo.end(), zonasInf.begin(), zonasInf.end());
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
    for (const auto x : movimientos.getElementos()) {
        bool realizar = *x==*mov;
        if (realizar) {
            return true;
        }
    }
    return false;
}

string Personaje::getMovimientos() {
    return movimientos.mostrar();
}

void Personaje::agregarMovimiento(string nombre, string zona) {

    Movimiento* mov = ListMovInferiores::getInstancia()->getMovimiento(nombre, zona);

    movimientos.agregarElemento(mov);


}

Movimiento * Personaje::getMovimientoIndice(int indice) {
    auto movs = movimientos.getElementos();
    if (indice < 1 || indice > movs.size()) {
        throw invalid_argument("Índice de movimiento fuera de rango, recibido: " + to_string(indice));
    }
    return movs[indice - 1];
}

int Personaje::getCantidadMovimientos() {
    return movimientos.getElementos().size();
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


