//
// Created by cesar on 3/6/2026.
//

#ifndef PROYECTO2KIAP_CREARMOVIMIENTOS_H
#define PROYECTO2KIAP_CREARMOVIMIENTOS_H
#include "Movimientos.h"


class CrearMovimientos {
public:
        virtual ~CrearMovimientos() = default;
        virtual Movimiento* crearMovimiento(const string& name, double danio, double impacto, string info, string extremidad, string zonaImpacto, double dificultad, int costo) = 0;
};


#endif //PROYECTO2KIAP_CREARMOVIMIENTOS_H