//
// Created by cesar on 3/6/2026.
//

#ifndef PROYECTO2KIAP_MOVIMIENTOSSUPERIORES_H
#define PROYECTO2KIAP_MOVIMIENTOSSUPERIORES_H
#include "Movimientos.h"
#include <sstream>

class MovimientosSuperiores : public Movimiento{
public:
    MovimientosSuperiores(string nombre, double danio,double impacto,string info, string extremidad, string zonaImpacto);
    std::string mostrar() override;
};


#endif //PROYECTO2KIAP_MOVIMIENTOSSUPERIORES_H