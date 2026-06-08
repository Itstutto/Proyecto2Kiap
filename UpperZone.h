//
// Created by cesar on 3/6/2026.
//

#ifndef PROYECTO2KIAP_ZONASUPERIOR_H
#define PROYECTO2KIAP_ZONASUPERIOR_H
#include <iostream>
#include <vector>

#include "Vectors.h"

#include "BodyZones.h"
using namespace std;

class UpperZone : public Vectors<BodyZone>{
private:
    static UpperZone* instance;
    UpperZone() = default;
public:
    UpperZone(const UpperZone&) = delete;
    UpperZone& operator=(const UpperZone&) = delete;

    static UpperZone* getInstance();




};


#endif //PROYECTO2KIAP_ZONASUPERIOR_H