//
// Created by cesar on 6/6/2026.
//

#ifndef PROYECTO2KIAP_ESTRATEGIACOMBATE_H
#define PROYECTO2KIAP_ESTRATEGIACOMBATE_H
#include "Character.h"


class CombatStrategy {
public:
    virtual ~CombatStrategy() = default;
    virtual Movimiento* executeStrategy(Character* p, Character* c) = 0;
};


#endif //PROYECTO2KIAP_ESTRATEGIACOMBATE_H