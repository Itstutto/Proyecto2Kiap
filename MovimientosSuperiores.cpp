//
// Created by cesar on 3/6/2026.
//

#include "MovimientosSuperiores.h"

MovimientosSuperiores::MovimientosSuperiores(string nombre, double danio, string info, string extremidad,
    string zonaImpacto) : Movimiento(nombre,extremidad,zonaImpacto, danio, info) {

}

std::string MovimientosSuperiores::mostrar() {
    stringstream s;
    s<<"Movimiento: "<<nombre<<endl
    <<"Extremidad: "<<extremidad<<endl
    <<"Zona de impacto: "<<zonaImpacto<<endl
    <<"Daño: "<<danio<<endl
    <<"Descripcion: "<<info<<endl;
    return s.str();
}

