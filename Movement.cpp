//
// Created by cesar on 3/6/2026.
//

#include "Movement.h"

Movement::Movement(string name,string limb, string impactZone, double damage,double impact, string info, double difficulty, int cost) {
    if (name.empty()) {
        throw invalid_argument("El name del movimiento no puede estar vacío");
    }
    if (limb.empty()) {
        throw invalid_argument("La limb no puede estar vacía");
    }
    if (impactZone.empty()) {
        throw invalid_argument("La zone de impact no puede estar vacía");
    }
    if (damage < 0) {
        throw invalid_argument("El daño no puede ser negativo: " + to_string(damage));
    }
    if (impact < 0 || impact > 1) {
        throw invalid_argument("El impact debe estar entre 0 y 1, recibido: " + to_string(impact));
    }

    this->name = name;
    this->limb = limb;
    this->impactZone = impactZone;
    this->damage = damage;
    this->impact = impact;
    this->info = info;
    this->difficulty = difficulty;
    if (cost < 0) {
        throw invalid_argument("El cost no puede ser negativo: " + to_string(cost));
    }
    this->cost = cost;
}

string Movement::getName() {
    return name;
}

double Movement::getDamage() {
    return damage;
}

double Movement::getImpact() {
    return impact;
}

int Movement::getCost() {
    return cost;
}

std::string Movement::show() {
    std::stringstream s;
    s << "Movimiento: " << name << " (Extremidad: " << limb
      << ", Zona: " << impactZone << ", Daño: " << damage <<", Costo: "<< cost<< ")" << std::endl;
    return s.str();
}
