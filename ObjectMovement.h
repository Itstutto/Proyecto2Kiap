//
// Created by cesar on 3/6/2026.
//

#ifndef PROYECTO2KIAP_MOVIMIENTOSINFERIORES_H
#define PROYECTO2KIAP_MOVIMIENTOSINFERIORES_H
#include "Movement.h"
#include <sstream>

class ObjectMovement : public Movement{
public:
    ObjectMovement(string name, double damage,double impact,string info, string limb, string impactZone, double difficulty, int cost);
    std::string show() override;
};


#endif //PROYECTO2KIAP_MOVIMIENTOSINFERIORES_H