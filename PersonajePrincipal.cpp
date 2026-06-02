//
// Created by cesar on 1/6/2026.
//

#include "PersonajePrincipal.h"

PersonajePrincipal::PersonajePrincipal(const string &nombre, char genero) : Personaje() {
    this->genero = genero;
    this->nombre = nombre;
}

string PersonajePrincipal::getInfo() {
    stringstream s;
    s<<"---------Personaje principal--------"<<endl
    <<"Nombre: "<<nombre<<endl
    <<"Genero: "<<(genero == 'M' ? "masculino" : genero == 'F' ? "Femenino" : "otro")<<endl
    <<"Vida: "<<vida<<endl
    <<nombre<<(vivo ? " sigue con vida" : " ya no sigue con vida :c")<<endl;
    return s.str();
}
