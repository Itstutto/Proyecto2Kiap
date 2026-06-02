//
// Created by cesar on 1/6/2026.
//

#ifndef PROYECTO2KIAP_PERSONAJEPRINCIPAL_H
#define PROYECTO2KIAP_PERSONAJEPRINCIPAL_H
#include "Personaje.h"
#include <sstream>

class PersonajePrincipal : public Personaje{
    char genero;
    string nombre;
public:
    PersonajePrincipal(const string &nombre, char genero);
    string getInfo() override;

};


#endif //PROYECTO2KIAP_PERSONAJEPRINCIPAL_H