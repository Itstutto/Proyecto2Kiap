//
// Created by cesar on 1/6/2026.
//

#ifndef PROYECTO2KIAP_PERSONAJEPRINCIPAL_H
#define PROYECTO2KIAP_PERSONAJEPRINCIPAL_H
#include "Character.h"
#include <sstream>

class PersonajePrincipal : public Character{
private:
    int puntosCuracion;
    int puntosExperiencia;
public:
    PersonajePrincipal(const string &name, char gender, double health, int puntosCuracion, int puntosExperiencia);
    string getName() override;
    int getPuntosCuracion();
    int getPuntosExperiencia();
    void ganarExperiencia(int amount);
    void comprar(int amount);
    std::string mostrar() override;
    bool heal(int amount) override;
    void resetStats() override;
    string serializar() override;

};


#endif //PROYECTO2KIAP_PERSONAJEPRINCIPAL_H