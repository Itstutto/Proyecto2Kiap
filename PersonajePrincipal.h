//
// Created by cesar on 1/6/2026.
//

#ifndef PROYECTO2KIAP_PERSONAJEPRINCIPAL_H
#define PROYECTO2KIAP_PERSONAJEPRINCIPAL_H
#include "Personaje.h"
#include <sstream>

class PersonajePrincipal : public Personaje{
private:
    string nombre;
    char genero;
    int puntosCuracion;
    int puntosExperiencia;
public:
    PersonajePrincipal(const string &nombre, char genero, double vida);
    string getNombre() override;
    int getPuntosCuracion();
    int getPuntosExperiencia();
    std::string mostrar() override;
    bool sanar(int cantidad) override;
;

};


#endif //PROYECTO2KIAP_PERSONAJEPRINCIPAL_H