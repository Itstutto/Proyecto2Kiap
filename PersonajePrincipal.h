//
// Created by cesar on 1/6/2026.
//

#ifndef PROYECTO2KIAP_PERSONAJEPRINCIPAL_H
#define PROYECTO2KIAP_PERSONAJEPRINCIPAL_H
#include "Personaje.h"
#include <sstream>

class PersonajePrincipal : public Personaje{
private:
    int puntosCuracion;
    int puntosExperiencia;
public:
    PersonajePrincipal(const string &nombre, char genero, double vida, int puntosCuracion, int puntosExperiencia);
    string getNombre() override;
    int getPuntosCuracion();
    int getPuntosExperiencia();
    void ganarExperiencia(int cantidad);
    void comprar(int cantidad);
    std::string mostrar() override;
    bool sanar(int cantidad) override;
    void reiniciarEstadisticas() override;
    string serializar() override;

};


#endif //PROYECTO2KIAP_PERSONAJEPRINCIPAL_H