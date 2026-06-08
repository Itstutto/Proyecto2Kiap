//
// Created by cesar on 3/6/2026.
//

#ifndef PROYECTO2KIAP_MOVIMIENTOSINFERIORES_H
#define PROYECTO2KIAP_MOVIMIENTOSINFERIORES_H
#include "Movimientos.h"
#include <sstream>

class MovimientosInferiores : public Movimiento{
public:
    MovimientosInferiores(string name, double damage,double impact,string info, string limb, string impactZone, double difficulty, int cost);
    std::string mostrar() override;
};


#endif //PROYECTO2KIAP_MOVIMIENTOSINFERIORES_H