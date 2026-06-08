//
// Created by cesar on 6/6/2026.
//

#ifndef PROYECTO2KIAP_ESTRATEGIACOMBATE_H
#define PROYECTO2KIAP_ESTRATEGIACOMBATE_H
#include "Character.h"


class EstrategiaCombate {
public:
    virtual ~EstrategiaCombate() = default;
    virtual Movimiento* ejecutarEstrategia(Character* p, Character* c) = 0;
};


#endif //PROYECTO2KIAP_ESTRATEGIACOMBATE_H