//
// Created by cesar on 3/6/2026.
//

#ifndef PROYECTO2KIAP_CREADORMOVIMIENTOSINFERIORES_H
#define PROYECTO2KIAP_CREADORMOVIMIENTOSINFERIORES_H
#include "CrearMovimientos.h"
#include "MovimientosInferiores.h"


class CreadorMovimientosInferiores : public CrearMovimientos{
public:
    Movimiento* crearMovimiento(const string& nombre, double danio, string info, string extremidad, string zonaImpacto) override {
        return new MovimientosInferiores(nombre, danio, info, extremidad, zonaImpacto);
    }

};


#endif //PROYECTO2KIAP_CREADORMOVIMIENTOSINFERIORES_H