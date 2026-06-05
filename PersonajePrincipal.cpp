//
// Created by cesar on 1/6/2026.
//

#include "PersonajePrincipal.h"

PersonajePrincipal::PersonajePrincipal(const string &nombre, char genero, double vida) : Personaje() {
    if (nombre.empty()) {
        throw invalid_argument("El nombre del personaje principal no puede estar vacío");
    }
    if (genero != 'M' && genero != 'F' && genero != 'O') {
        throw invalid_argument("Género inválido: '" + string(1, genero) + "'. Debe ser M, F u O");
    }
    if (vida <= 0) {
        throw invalid_argument("La vida del personaje principal debe ser mayor a 0, recibido: " + to_string(vida));
    }
    this->genero = genero;
    this->nombre = nombre;
}

string PersonajePrincipal::getNombre() {
    return nombre;
}

std::string PersonajePrincipal::mostrar(){
    stringstream s;
    s<<"---------Personaje Principal--------"<<endl
    <<"Nombre: "<<nombre<<endl
    <<"Genero: "<<(genero == 'M' ? "masculino" : genero == 'F' ? "Femenino" : "otro")<<endl
    <<"Vida: "<<vida<<endl
    <<nombre<<(vivo ? " sigue con vida" : " ya no sigue con vida :c")<<endl;
    return s.str();
}
