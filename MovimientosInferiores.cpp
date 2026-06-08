//
// Created by cesar on 3/6/2026.
//

#include "MovimientosInferiores.h"

MovimientosInferiores::MovimientosInferiores(string name, double danio,double impacto,string info,
    string extremidad, string zonaImpacto, double dificultad, int costo) : Movimiento(name, extremidad, zonaImpacto, danio,impacto, info,dificultad,costo) {
}

std::string MovimientosInferiores::mostrar() {
    stringstream s;
    s<<"Movimiento: "<<name<<endl
    <<"Extremidad: "<<extremidad<<endl
    <<"Zona de impacto: "<<zonaImpacto<<endl
    <<"Daño: "<<danio<<endl
    <<"Descripcion: "<<info<<endl;
    return s.str();
}
