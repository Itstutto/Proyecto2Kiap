//
// Created by cesar on 3/6/2026.
//

#include "ObjectMovement.h"

ObjectMovement::ObjectMovement(string name, double damage,double impact,string info,
                               string limb, string impactZone, double difficulty, int cost) : Movement(name, limb, impactZone, damage,impact, info,difficulty,cost) {
}

std::string ObjectMovement::show() {
    stringstream s;
    s<<"Movimiento: "<<name<<endl
    <<"Extremidad: "<<limb<<endl
    <<"Zona de impact: "<<impactZone<<endl
    <<"Daño: "<<damage<<endl
    <<"Descripcion: "<<info<<endl;
    return s.str();
}
