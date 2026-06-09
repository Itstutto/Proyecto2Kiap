//
// Created by cesar on 1/6/2026.
//

#include "Player.h"

#include "LowerMovList.h"

Player::Player(const string &name, char gender, double health, int healPoints, int expPoints) : Character(name, gender, health) {

    if (name.empty()) {
        throw invalid_argument("El nombre del personaje principal no puede estar vacío");
    }
    if (gender != 'M' && gender != 'F' && gender != 'O') {
        throw invalid_argument("Género inválido: '" + string(1, gender) + "'. Debe ser M, F u O");
    }
    if (health <0) { // Health can be 0 because the character can be dead, but not negative
        throw invalid_argument("La vida del personaje principal debe ser mayor a 0, recibido: " + to_string(health));
    }
    this->healPoints = healPoints;
    this->expPoints = expPoints;
}

string Player::getName() {
    return name;
}

int Player::getHealPoints() {
        return healPoints;
}

int Player::getExpPoints() {
    return expPoints;
}

void Player::gainExp(int amount) {
    if (amount < 0) {
        throw invalid_argument("La cantidad de experiencia ganada no puede ser negativa: " + to_string(amount));
    }
    expPoints += amount;
}

void Player::buy(int amount) {
    if (amount < 0) {
        throw invalid_argument("La cantidad a comprar no puede ser negativa: " + to_string(amount));
    }
    if (amount>expPoints) {
        throw invalid_argument("No tienes suficientes puntos de experiencia para comprar esta cantidad de puntos de curación, te faltan " + to_string(amount-expPoints) + " puntos");
    }
    expPoints -= amount;
}

std::string Player::show(){
    stringstream s;
    s<<"---------Character Principal--------"<<endl
    <<"Nombre: "<<name<<endl
    <<"Genero: "<<(gender == 'M' ? "masculino" : gender == 'F' ? "Femenino" : "Otro")<<endl
    <<"Vida: "<<health<<endl
    <<name<<(alive ? " sigue con vida" : " ya no sigue con vida :c")<<endl;
    return s.str();
}

bool Player::heal(int amount) {
    if (amount < 0) {
        throw invalid_argument("La cantidad de curación no puede ser negativa: " + to_string(amount));
    }

    if (healPoints <= amount || amount <= 0) {
        return false; //There are not enough healing points
    }
    health+=amount;
    if (health>100) {
        health = 100;
    }
    healPoints-=amount;
    return true;


}

void Player::resetStats() {
    Character::resetStats();
    healPoints = 0;
    expPoints = 0;
    movements.addElement(LowerMovList::getInstance()->getMovement("Ap Chagui", "Pie derecho"));
    movements.addElement(LowerMovList::getInstance()->getMovement("Ap Chagui", "Pie izquierdo"));
}

string Player::serialize() {
    stringstream ss;
    ss<<name<<","<<gender<<","<<health<<","<<healPoints<<","<<expPoints<<endl;
    for (const auto& mov : movements.getElements()) {
        ss << mov->getName() << "," << mov->getLimb()<<endl;
    }

    return ss.str();
}
