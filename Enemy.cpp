//
// Created by yense on 6/2/2026.
//

#include "Enemy.h"

Enemy::Enemy(const string &difficulty,const string &name, char gender, double damage, double health ): Character(name,gender,health, damage) {
    if (difficulty != "Facil" && difficulty != "Media" && difficulty != "Dificil") {
        throw invalid_argument("Dificultad inválida: '" + difficulty + "'. Debe ser 'Facil', 'Media' o 'Dificil'");
    }
    if (name.empty()) {
        throw invalid_argument("El nombre del enemigo no puede estar vacío");
    }
    if (gender != 'M' && gender != 'F' && gender != 'O') {
        throw invalid_argument("Género inválido: '" + string(1, gender) + "'. Debe ser M, F u O");
    }
    if (damage < 0) {
        throw invalid_argument("El daño base no puede ser negativo: " + to_string(damage));
    }
    if (health <= 0) {
        throw invalid_argument("La vida del enemigo debe ser mayor a 0, recibido: " + to_string(health));
    }

    this->difficulty = difficulty;
}

std::string Enemy::show() {
    stringstream s;
    s<<"---------Personaje Enemigo--------"<<endl
    <<"Nombre: "<<name<<endl
    <<"Dificultad: "<<difficulty<<endl
    <<"Genero: "<<(gender == 'M' ? "Masculino" : gender == 'F' ? "Femenino" : "Other")<<endl
    <<"Vida: "<<health<<endl
    <<"Daño Base: "<<damage<<endl
    <<name<<(alive ? " sigue con vida" : " ya no sigue con vida :c")<<endl;
    return s.str();
}

string Enemy::getName() {
    return name;
}

string Enemy::getDifficulty() {
    return difficulty;
}

bool Enemy::operator==(const Enemy &other) const {
    return name == other.name;
}

bool Enemy::heal(int amount) {
    if (amount < 0) {
        throw invalid_argument("La cantidad a sanar no puede ser negativa: " + to_string(amount));
    }
    if (!alive) {
        return false; // You cannot heal a dead character
    }
    health += amount;
    if (health > 100) {
        health = 100; //Limit maximum health to 100
    }
    return true;
}

string Enemy::serialize() {
    stringstream ss;
    ss << difficulty << "," << name << "," << gender << "," << damage << "," << health;
    return ss.str();
}

void Enemy::resetStats() {
    health = 100.0;
    damage = 5.0;
    alive = true;
}

