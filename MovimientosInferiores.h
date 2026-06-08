//
// Created by cesar on 3/6/2026.
//

#ifndef PROYECTO2KIAP_MOVIMIENTOSINFERIORES_H
#define PROYECTO2KIAP_MOVIMIENTOSINFERIORES_H
#include "Movimientos.h"
#include <sstream>

class MovimientosInferiores : public Movimiento{
public:
    MovimientosInferiores(string name, double danio,double impacto,string info, string extremidad, string zonaImpacto, double difficulty, int costo);
    std::string mostrar() override;
};


#endif //PROYECTO2KIAP_MOVIMIENTOSINFERIORES_H