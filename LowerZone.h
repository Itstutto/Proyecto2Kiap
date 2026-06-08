//
// Created by cesar on 3/6/2026.
//

#ifndef PROYECTO2KIAP_ZONAINFERIOR_H
#define PROYECTO2KIAP_ZONAINFERIOR_H
#include <iostream>
#include <vector>

#include "Vectors.h"
#include "BodyZones.h"
using namespace std;

class LowerZone : public Vectors<BodyZone>{
private:
    static LowerZone* instance;
    LowerZone() = default;
public:
    LowerZone(const LowerZone&) = delete;
    LowerZone& operator=(const LowerZone&) = delete;

    static LowerZone* getInstance();
};


#endif //PROYECTO2KIAP_ZONAINFERIOR_H