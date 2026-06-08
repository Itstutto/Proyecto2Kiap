//
// Created by cesar on 3/6/2026.
//

#include "MovimientosInferiores.h"

MovimientosInferiores::MovimientosInferiores(string name, double damage,double impact,string info,
    string limb, string impactZone, double difficulty, int cost) : Movimiento(name, limb, impactZone, damage,impact, info,difficulty,cost) {
}

std::string MovimientosInferiores::mostrar() {
    stringstream s;
    s<<"Movimiento: "<<name<<endl
    <<"Extremidad: "<<limb<<endl
    <<"Zona de impact: "<<impactZone<<endl
    <<"Daño: "<<damage<<endl
    <<"Descripcion: "<<info<<endl;
    return s.str();
}
