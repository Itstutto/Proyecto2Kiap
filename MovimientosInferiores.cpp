//
// Created by cesar on 3/6/2026.
//

#include "MovimientosInferiores.h"

MovimientosInferiores::MovimientosInferiores(string nombre, double danio, string info, string extremidad,
    string zonaImpacto) : Movimiento(nombre, extremidad, zonaImpacto, danio, info) {
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
