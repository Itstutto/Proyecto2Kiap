//
// Created by cesar on 1/6/2026.
//

#include "Character.h"

#include "LowerMovList.h"

#include "LowerZone.h"

Character::Character() {

    name = "Desconocido";
    gender = 'O';
    health = 100.0;
    damage = 5.0;
    alive = true;
    LowerZone* zonaInf = LowerZone::getInstance();
    UpperZone* zonaSup = UpperZone::getInstance();


    auto zonasInf = zonaInf->getElements();
    auto zonasSup = zonaSup->getElements();

    bodyZones.insert(bodyZones.end(), zonasInf.begin(), zonasInf.end());
    bodyZones.insert(bodyZones.end(), zonasSup.begin(), zonasSup.end());

}

Character::Character(const string &name, char gender, double health, double damage) {
    if (name.empty()) {
        throw invalid_argument("El nombre del personaje no puede estar vacío");
    }
    if (gender != 'M' && gender != 'F' && gender != 'O') {
        throw invalid_argument("Género inválido: '" + string(1, gender) + "'. Debe ser M, F u O");
    }
    if (health < 0) {
        throw invalid_argument("La vida del personaje debe ser mayor a 0, recibido: " + to_string(health));
    }
    if (damage < 0) {
        throw invalid_argument("El daño base del personaje no puede ser negativo, recibido: " + to_string(damage));
    }
    this->gender = gender;
    this->name = name;
    this->health = health;
    this->damage = damage;
    alive=true;
    UpperZone* zonaSup = UpperZone::getInstance();
    LowerZone* zonaInf = LowerZone::getInstance();

    auto zonasSup = zonaSup->getElements();
    auto zonasInf = zonaInf->getElements();

    bodyZones.insert(bodyZones.end(), zonasSup.begin(), zonasSup.end());
    bodyZones.insert(bodyZones.end(), zonasInf.begin(), zonasInf.end());
}

Character::Character(const string &name, char gender, double health) {
    if (name.empty()) {
        throw invalid_argument("El nombre del personaje no puede estar vacío");
    }
    if (gender != 'M' && gender != 'F' && gender != 'O') {
        throw invalid_argument("Género inválido: '" + string(1, gender) + "'. Debe ser M, F u O");
    }
    if (health <= 0) {
        throw invalid_argument("La vida del personaje debe ser mayor a 0, recibido: " + to_string(health));
    }
    this->gender = gender;
    this->name = name;
    this->health = health;
    this->damage = 5.0; // Default value
    alive=true;
    UpperZone* zonaSup = UpperZone::getInstance();
    LowerZone* zonaInf = LowerZone::getInstance();

    auto zonasSup = zonaSup->getElements();
    auto zonasInf = zonaInf->getElements();

    bodyZones.insert(bodyZones.end(), zonasSup.begin(), zonasSup.end());
    bodyZones.insert(bodyZones.end(), zonasInf.begin(), zonasInf.end());
}


double Character::getDamage() {
    //temporary, to see functionality
    return damage;
}

void Character::hurt(double amount) {
    health -= amount;
    if (health<0) {
        health = 0;
        alive = false;
    }
}

bool Character::canMakeMove(Movement *mov) {
    for (const auto x : movements.getElements()) {
        bool realizar = *x==*mov;
        if (realizar) {
            return true;
        }
    }
    return false;
}

string Character::getMovements() {
    return movements.show();
}

void Character::addMovement(string name, string zone) {

    Movement* mov = LowerMovList::getInstance()->getMovement(name, zone);

    movements.addElement(mov);


}

Movement * Character::getIndexMovement(int index) {
    auto movs = movements.getElements();
    if (index < 1 || index > movs.size()) {
        throw invalid_argument("Índice de movimiento fuera de rango, recibido: " + to_string(index));
    }
    return movs[index - 1];
}

int Character::getAmountMovements() {
    return movements.getElements().size();
}

BodyZone * Character::getZone(string zoneName) {
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
        throw invalid_argument("El nombre del personaje no puede estar vacío");
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
    movements.clear();
    for (const auto& zone : bodyZones) {
        if (zone) {
            delete zone; // Free up memory from each zone
        }
    }
    bodyZones.clear(); // Clear the vector of zones

    LowerZone* zonaInf = LowerZone::getInstance();
    UpperZone* zonaSup = UpperZone::getInstance();


    auto zonasInf = zonaInf->getElements();
    auto zonasSup = zonaSup->getElements();

    bodyZones.insert(bodyZones.end(), zonasInf.begin(), zonasInf.end());
    bodyZones.insert(bodyZones.end(), zonasSup.begin(), zonasSup.end());


}

bool Character::isAlive() {
    return health>0;
}


