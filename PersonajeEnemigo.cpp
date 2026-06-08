//
// Created by yense on 6/2/2026.
//

#include "PersonajeEnemigo.h"

PersonajeEnemigo::PersonajeEnemigo(const string &dificultad,const string &name, char gender, double damage, double health ): Character(name,gender,health, damage) {
    if (dificultad != "Facil" && dificultad != "Media" && dificultad != "Dificil") {
        throw invalid_argument("Dificultad inválida: '" + dificultad + "'. Debe ser 'Facil', 'Media' o 'Dificil'");
    }
    if (name.empty()) {
        throw invalid_argument("El name del enemigo no puede estar vacío");
    }
    if (gender != 'M' && gender != 'F' && gender != 'O') {
        throw invalid_argument("Género inválido: '" + string(1, gender) + "'. Debe ser M, F u O");
    }
    if (damage < 0) {
        throw invalid_argument("El daño base no puede ser negativo: " + to_string(damage));
    }
    if (health <= 0) {
        throw invalid_argument("La health del enemigo debe ser mayor a 0, recibido: " + to_string(health));
    }

    this->dificultad = dificultad;
}

std::string PersonajeEnemigo::mostrar() {
    stringstream s;
    s<<"---------Character Enemigo--------"<<endl
    <<"Nombre: "<<name<<endl
    <<"Dificultad: "<<dificultad<<endl
    <<"Genero: "<<(gender == 'M' ? "masculino" : gender == 'F' ? "Femenino" : "otro")<<endl
    <<"Vida: "<<health<<endl
    <<"Daño Base: "<<damage<<endl
    <<name<<(alive ? " sigue con health" : " ya no sigue con health :c")<<endl;
    return s.str();
}

string PersonajeEnemigo::getName() {
    return name;
}

string PersonajeEnemigo::getDificultad() {
    return dificultad;
}

bool PersonajeEnemigo::operator==(const PersonajeEnemigo &otro) const {
    return name == otro.name;
}

bool PersonajeEnemigo::heal(int amount) {
    if (amount < 0) {
        throw invalid_argument("La amount a heal no puede ser negativa: " + to_string(amount));
    }
    if (!alive) {
        return false; // No se puede heal a un personaje muerto
    }
    health += amount;
    if (health > 100) {
        health = 100; // Limitar la health máxima a 100
    }
    return true;
}

string PersonajeEnemigo::serializar() {
    stringstream ss;
    ss << dificultad << "," << name << "," << gender << "," << damage << "," << health;
    return ss.str();
}

void PersonajeEnemigo::resetStats() {
    health = 100.0;
    damage = 5.0;
    alive = true;
}

