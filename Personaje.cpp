//
// Created by cesar on 1/6/2026.
//

#include "Personaje.h"

#include "ListMovInferiores.h"

#include "ZonaInferior.h"

Personaje::Personaje() {

    nombre = "Desconocido";
    genero = 'O';
    vida = 100.0;
    danioBase = 5.0;
    vivo = true;
    ZonaInferior* zonaInf = ZonaInferior::getInstancia();
    ZonaSuperior* zonaSup = ZonaSuperior::getInstancia();


    auto zonasInf = zonaInf->getElementos();
    auto zonasSup = zonaSup->getElementos();

    zonasCuerpo.insert(zonasCuerpo.end(), zonasInf.begin(), zonasInf.end());
    zonasCuerpo.insert(zonasCuerpo.end(), zonasSup.begin(), zonasSup.end());

}

Personaje::Personaje(const string &nombre, char genero, double vida, double danioBase) {
    if (nombre.empty()) {
        throw invalid_argument("El nombre del personaje no puede estar vacío");
    }
    if (genero != 'M' && genero != 'F' && genero != 'O') {
        throw invalid_argument("Género inválido: '" + string(1, genero) + "'. Debe ser M, F u O");
    }
    if (vida <= 0) {
        throw invalid_argument("La vida del personaje debe ser mayor a 0, recibido: " + to_string(vida));
    }
    if (danioBase < 0) {
        throw invalid_argument("El daño base del personaje no puede ser negativo, recibido: " + to_string(danioBase));
    }
    this->genero = genero;
    this->nombre = nombre;
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

Personaje::Personaje(const string &nombre, char genero, double vida) {
    if (nombre.empty()) {
        throw invalid_argument("El nombre del personaje no puede estar vacío");
    }
    if (genero != 'M' && genero != 'F' && genero != 'O') {
        throw invalid_argument("Género inválido: '" + string(1, genero) + "'. Debe ser M, F u O");
    }
    if (vida <= 0) {
        throw invalid_argument("La vida del personaje debe ser mayor a 0, recibido: " + to_string(vida));
    }
    this->genero = genero;
    this->nombre = nombre;
    this->vida = vida;
    this->danioBase = 5.0; // Valor por defecto
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

void Personaje::setNombre(const string &nombre) {
    if (nombre.empty()) {
        throw invalid_argument("El nombre del personaje no puede estar vacío");
    }
    this->nombre = nombre;
}

void Personaje::setGenero(char genero) {
    if (genero != 'M' && genero != 'F' && genero != 'O') {
        throw invalid_argument("Género inválido: '" + string(1, genero) + "'. Debe ser M, F u O");
    }
    this->genero = genero;
}

void Personaje::reiniciarEstadisticas() {
    vida = 100.0;
    danioBase = 5.0;
    bool cond = vivo = true;
    movimientos.vaciar();
    for (const auto& zona : zonasCuerpo) {
        if (zona) {
            delete zona; // Liberar memoria de cada zona
        }
    }
    zonasCuerpo.clear(); // Limpiar el vector de zonas

    ZonaInferior* zonaInf = ZonaInferior::getInstancia();
    ZonaSuperior* zonaSup = ZonaSuperior::getInstancia();


    auto zonasInf = zonaInf->getElementos();
    auto zonasSup = zonaSup->getElementos();

    zonasCuerpo.insert(zonasCuerpo.end(), zonasInf.begin(), zonasInf.end());
    zonasCuerpo.insert(zonasCuerpo.end(), zonasSup.begin(), zonasSup.end());


}

bool Personaje::isVivo() {
    return vida>0;
}


