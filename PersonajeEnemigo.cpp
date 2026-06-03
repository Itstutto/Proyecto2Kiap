//
// Created by yense on 6/2/2026.
//

#include "PersonajeEnemigo.h"

PersonajeEnemigo::PersonajeEnemigo(const string &nombre, char genero): Personaje() {
    this->nombre = nombre;
    this->genero = genero;
}

string PersonajeEnemigo::getInfo() {
    stringstream s;
    s<<"---------Personaje Enemigo--------"<<endl
    <<"Nombre: "<<nombre<<endl
    <<"Genero: "<<(genero == 'M' ? "masculino" : genero == 'F' ? "Femenino" : "otro")<<endl
    <<"Vida: "<<vida<<endl
    <<nombre<<(vivo ? " sigue con vida" : " ya no sigue con vida :c")<<endl;
    return s.str();
}
