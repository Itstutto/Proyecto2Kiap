//
// Created by cesar on 3/6/2026.
//

#include "MovimientosInferiores.h"

MovimientosInferiores::MovimientosInferiores(string nombre, double danio,double impacto,string info,
    string extremidad, string zonaImpacto, double dificultad) : Movimiento(nombre, extremidad, zonaImpacto, danio,impacto, info,dificultad) {
}

std::string MovimientosInferiores::mostrar() {
    stringstream s;
    s<<"Movimiento: "<<nombre<<endl
    <<"Extremidad: "<<extremidad<<endl
    <<"Zona de impacto: "<<zonaImpacto<<endl
    <<"Daño: "<<danio<<endl
    <<"Descripcion: "<<info<<endl;
    return s.str();
}
