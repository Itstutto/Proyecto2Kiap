//
// Created by cesar on 1/6/2026.
//

#include "Character.h"

#include "ListMovInferiores.h"

#include "ZonaInferior.h"

Character::Character() {

    name = "Desconocido";
    gender = 'O';
    health = 100.0;
    damage = 5.0;
    alive = true;
    ZonaInferior* zonaInf = ZonaInferior::getInstancia();
    ZonaSuperior* zonaSup = ZonaSuperior::getInstancia();


    auto zonasInf = zonaInf->getElementos();
    auto zonasSup = zonaSup->getElementos();

    bodyZones.insert(bodyZones.end(), zonasInf.begin(), zonasInf.end());
    bodyZones.insert(bodyZones.end(), zonasSup.begin(), zonasSup.end());

}

Character::Character(const string &name, char gender, double health, double damage) {
    if (name.empty()) {
        throw invalid_argument("El name del Character no puede estar vacío");
    }
    if (gender != 'M' && gender != 'F' && gender != 'O') {
        throw invalid_argument("Género inválido: '" + string(1, gender) + "'. Debe ser M, F u O");
    }
    if (health <= 0) {
        throw invalid_argument("La health del Character debe ser mayor a 0, recibido: " + to_string(health));
    }
    if (damage < 0) {
        throw invalid_argument("El daño base del Character no puede ser negativo, recibido: " + to_string(damage));
    }
    this->gender = gender;
    this->name = name;
    this->health = health;
    this->damage = damage;
    alive=true;
    ZonaSuperior* zonaSup = ZonaSuperior::getInstancia();
    ZonaInferior* zonaInf = ZonaInferior::getInstancia();

    auto zonasSup = zonaSup->getElementos();
    auto zonasInf = zonaInf->getElementos();

    bodyZones.insert(bodyZones.end(), zonasSup.begin(), zonasSup.end());
    bodyZones.insert(bodyZones.end(), zonasInf.begin(), zonasInf.end());
}

Character::Character(const string &name, char gender, double health) {
    if (name.empty()) {
        throw invalid_argument("El name del Character no puede estar vacío");
    }
    if (gender != 'M' && gender != 'F' && gender != 'O') {
        throw invalid_argument("Género inválido: '" + string(1, gender) + "'. Debe ser M, F u O");
    }
    if (health <= 0) {
        throw invalid_argument("La health del Character debe ser mayor a 0, recibido: " + to_string(health));
    }
    this->gender = gender;
    this->name = name;
    this->health = health;
    this->damage = 5.0; // Valor por defecto
    alive=true;
    ZonaSuperior* zonaSup = ZonaSuperior::getInstancia();
    ZonaInferior* zonaInf = ZonaInferior::getInstancia();

    auto zonasSup = zonaSup->getElementos();
    auto zonasInf = zonaInf->getElementos();

    bodyZones.insert(bodyZones.end(), zonasSup.begin(), zonasSup.end());
    bodyZones.insert(bodyZones.end(), zonasInf.begin(), zonasInf.end());
}


double Character::getDamage() {
    //temporal, para ver fucionalidad
    return damage;
}

void Character::hurt(double amount) {
    health -= amount;
    if (health<0) {
        health = 0;
        alive = false;
    }
}

bool Character::canMakeMove(Movimiento *mov) {
    for (const auto x : movements.getElementos()) {
        bool realizar = *x==*mov;
        if (realizar) {
            return true;
        }
    }
    return false;
}

string Character::getMovements() {
    return movements.mostrar();
}

void Character::addMovement(string name, string zone) {

    Movimiento* mov = ListMovInferiores::getInstancia()->getMovimiento(name, zone);

    movements.agregarElemento(mov);


}

Movimiento * Character::getIndexMovement(int index) {
    auto movs = movements.getElementos();
    if (index < 1 || index > movs.size()) {
        throw invalid_argument("Índice de movimiento fuera de rango, recibido: " + to_string(index));
    }
    return movs[index - 1];
}

int Character::getAmountMovements() {
    return movements.getElementos().size();
}

ZonaDelCuerpo * Character::getZone(string zoneName) {
    for (const auto x : bodyZones) {
        if (x->getName() == zoneName) {
            return x;
        }
    }
    return nullptr;
}

double Character::getHealth() {
    return health;
}

void Character::setName(const string &name) {
    if (name.empty()) {
        throw invalid_argument("El name del Character no puede estar vacío");
    }
    this->name = name;
}

void Character::setGender(char gender) {
    if (gender != 'M' && gender != 'F' && gender != 'O') {
        throw invalid_argument("Género inválido: '" + string(1, gender) + "'. Debe ser M, F u O");
    }
    this->gender = gender;
}

void Character::resetStats() {
    health = 100.0;
    damage = 5.0;
    bool cond = alive = true;
    movements.vaciar();
    for (const auto& zone : bodyZones) {
        if (zone) {
            delete zone; // Liberar memoria de cada zone
        }
    }
    bodyZones.clear(); // Limpiar el vector de zonas

    ZonaInferior* zonaInf = ZonaInferior::getInstancia();
    ZonaSuperior* zonaSup = ZonaSuperior::getInstancia();


    auto zonasInf = zonaInf->getElementos();
    auto zonasSup = zonaSup->getElementos();

    bodyZones.insert(bodyZones.end(), zonasInf.begin(), zonasInf.end());
    bodyZones.insert(bodyZones.end(), zonasSup.begin(), zonasSup.end());


}

bool Character::isAlive() {
    return health>0;
}


