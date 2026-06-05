//
// Created by cesar on 3/6/2026.
//

#ifndef PROYECTO2KIAP_CREADORMOVIMIENTOSSUPERIORES_H
#define PROYECTO2KIAP_CREADORMOVIMIENTOSSUPERIORES_H
#include "CrearMovimientos.h"
#include "MovimientosSuperiores.h"


class CreadorMovimientosSuperiores : public CrearMovimientos{
public:
    Movimiento* crearMovimiento(const string& nombre, double danio,double impacto, string info, string extremidad, string zonaImpacto) override {
        return new MovimientosSuperiores(nombre, danio,impacto, info, extremidad, zonaImpacto);
    }
};


#endif //PROYECTO2KIAP_CREADORMOVIMIENTOSSUPERIORES_H