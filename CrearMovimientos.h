//
// Created by cesar on 3/6/2026.
//

#ifndef PROYECTO2KIAP_CREARMOVIMIENTOS_H
#define PROYECTO2KIAP_CREARMOVIMIENTOS_H
#include "Movimientos.h"


class CrearMovimientos {
public:
        virtual ~CrearMovimientos() = default;
        virtual Movimiento* crearMovimiento(const string& nombre, double danio, string info, string extremidad, string zonaImpacto) = 0;
};


#endif //PROYECTO2KIAP_CREARMOVIMIENTOS_H