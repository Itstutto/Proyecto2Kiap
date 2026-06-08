//
// Created by cesar on 1/6/2026.
//

#include "PersonajePrincipal.h"

#include "ListMovInferiores.h"

PersonajePrincipal::PersonajePrincipal(const string &name, char gender, double health, int puntosCuracion, int puntosExperiencia) : Character(name, gender, health) {

    if (name.empty()) {
        throw invalid_argument("El name del personaje principal no puede estar vacío");
    }
    if (gender != 'M' && gender != 'F' && gender != 'O') {
        throw invalid_argument("Género inválido: '" + string(1, gender) + "'. Debe ser M, F u O");
    }
    if (health <= 0) {
        throw invalid_argument("La health del personaje principal debe ser mayor a 0, recibido: " + to_string(health));
    }
    this->puntosCuracion = puntosCuracion;
    this->puntosExperiencia = puntosExperiencia;
}

string PersonajePrincipal::getName() {
    return name;
}

int PersonajePrincipal::getPuntosCuracion() {
        return puntosCuracion;
}

int PersonajePrincipal::getPuntosExperiencia() {
    return puntosExperiencia;
}

void PersonajePrincipal::ganarExperiencia(int amount) {
    if (amount < 0) {
        throw invalid_argument("La amount de experiencia ganada no puede ser negativa: " + to_string(amount));
    }
    puntosExperiencia += amount;
}

void PersonajePrincipal::comprar(int amount) {
    if (amount < 0) {
        throw invalid_argument("La amount a comprar no puede ser negativa: " + to_string(amount));
    }
    if (amount>puntosExperiencia) {
        throw invalid_argument("No tienes suficientes puntos de experiencia para comprar esta amount de puntos de curación, te faltan " + to_string(amount-puntosExperiencia) + " puntos");
    }
    puntosExperiencia -= amount;
}

std::string PersonajePrincipal::mostrar(){
    stringstream s;
    s<<"---------Character Principal--------"<<endl
    <<"Nombre: "<<name<<endl
    <<"Genero: "<<(gender == 'M' ? "masculino" : gender == 'F' ? "Femenino" : "otro")<<endl
    <<"Vida: "<<health<<endl
    <<name<<(alive ? " sigue con health" : " ya no sigue con health :c")<<endl;
    return s.str();
}

bool PersonajePrincipal::heal(int amount) {
    if (amount < 0) {
        throw invalid_argument("La amount de curación no puede ser negativa: " + to_string(amount));
    }

    if (puntosCuracion <= amount || amount <= 0) {
        return false; // No hay suficientes puntos de curación
    }
    health+=amount;
    if (health>100) {
        health = 100;
    }
    puntosCuracion-=amount;
    return true;


}

void PersonajePrincipal::resetStats() {
    Character::resetStats();
    puntosCuracion = 0;
    puntosExperiencia = 0;
    movements.agregarElemento(ListMovInferiores::getInstancia()->getMovimiento("Ap Chagui", "Pie derecho"));
    movements.agregarElemento(ListMovInferiores::getInstancia()->getMovimiento("Ap Chagui", "Pie izquierdo"));
}

string PersonajePrincipal::serializar() {
    stringstream ss;
    ss<<name<<","<<gender<<","<<health<<","<<puntosCuracion<<","<<puntosExperiencia<<endl;
    for (const auto& mov : movements.getElementos()) {
        ss << mov->getName() << "," << mov->getExtremidad()<<endl;
    }

    return ss.str();
}
