//
// Created by cesar on 3/6/2026.
//

#ifndef PROYECTO2KIAP_CREADORMOVIMIENTOSINFERIORES_H
#define PROYECTO2KIAP_CREADORMOVIMIENTOSINFERIORES_H
#include "MakeMoves.h"
#include "ObjectMovement.h"


class MovementMaker : public MakeMoves{
public:
    Movement* makeMove(const string& name, double damage, double impact, string info, string limb, string impactZone, double difficulty, int cost) override {
        return new ObjectMovement(name, damage, impact, info, limb, impactZone, difficulty,cost);
    }

};


#endif //PROYECTO2KIAP_CREADORMOVIMIENTOSINFERIORES_H