//
// Created by cesar on 3/6/2026.
//

#ifndef PROYECTO2KIAP_CREARMOVIMIENTOS_H
#define PROYECTO2KIAP_CREARMOVIMIENTOS_H
#include "Movement.h"


class MakeMoves {
public:
        virtual ~MakeMoves() = default;
        virtual Movement* makeMove(const string& name, double damage, double impact, string info, string limb, string impactZone, double difficulty, int cost) = 0;
};


#endif //PROYECTO2KIAP_CREARMOVIMIENTOS_H