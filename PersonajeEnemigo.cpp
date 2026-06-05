//
// Created by yense on 6/2/2026.
//

#include "PersonajeEnemigo.h"

PersonajeEnemigo::PersonajeEnemigo(const string &dificultad,const string &nombre, char genero, double danioBase, double vida ): Personaje(vida, danioBase) {
    if (dificultad != "Facil" && dificultad != "Media" && dificultad != "Dificil") {
        throw invalid_argument("Dificultad inválida: '" + dificultad + "'. Debe ser 'Facil', 'Media' o 'Dificil'");
    }
    if (nombre.empty()) {
        throw invalid_argument("El nombre del enemigo no puede estar vacío");
    }
    if (genero != 'M' && genero != 'F' && genero != 'O') {
        throw invalid_argument("Género inválido: '" + string(1, genero) + "'. Debe ser M, F u O");
    }
    if (danioBase < 0) {
        throw invalid_argument("El daño base no puede ser negativo: " + to_string(danioBase));
    }
    if (vida <= 0) {
        throw invalid_argument("La vida del enemigo debe ser mayor a 0, recibido: " + to_string(vida));
    }

    this->dificultad = dificultad;
    this->nombre = nombre;
    this->genero = genero;
}

std::string PersonajeEnemigo::mostrar() {
    stringstream s;
    s<<"---------Personaje Enemigo--------"<<endl
    <<"Nombre: "<<nombre<<endl
    <<"Dificultad: "<<dificultad<<endl
    <<"Genero: "<<(genero == 'M' ? "masculino" : genero == 'F' ? "Femenino" : "otro")<<endl
    <<"Vida: "<<vida<<endl
    <<"Daño Base: "<<danioBase<<endl
    <<nombre<<(vivo ? " sigue con vida" : " ya no sigue con vida :c")<<endl;
    return s.str();
}

string PersonajeEnemigo::getNombre() {
    return nombre;
}

