//
// Created by cesar on 3/6/2026.
//

#ifndef PROYECTO2KIAP_CREADORMOVIMIENTOSINFERIORES_H
#define PROYECTO2KIAP_CREADORMOVIMIENTOSINFERIORES_H
#include "CrearMovimientos.h"
#include "MovimientosInferiores.h"


class CreadorMovimientosInferiores : public CrearMovimientos{
public:
    Movimiento* crearMovimiento(const string& nombre, double danio, double impacto, string info, string extremidad, string zonaImpacto, double dificultad) override {
        return new MovimientosInferiores(nombre, danio, impacto, info, extremidad, zonaImpacto, dificultad);
    }

};


#endif //PROYECTO2KIAP_CREADORMOVIMIENTOSINFERIORES_H