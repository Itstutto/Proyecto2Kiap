//
// Created by cesar on 3/6/2026.
//

#ifndef PROYECTO2KIAP_ZONASUPERIOR_H
#define PROYECTO2KIAP_ZONASUPERIOR_H
#include <iostream>
#include <vector>

#include "Vectores.h"

#include "ZonasDelCuerpo.h"
using namespace std;

class ZonaSuperior : public Vectores<ZonaDelCuerpo>{
private:
    static ZonaSuperior* instancia;
    ZonaSuperior() = default;
public:
    ZonaSuperior(const ZonaSuperior&) = delete;
    ZonaSuperior& operator=(const ZonaSuperior&) = delete;

    static ZonaSuperior* getInstancia();




};


#endif //PROYECTO2KIAP_ZONASUPERIOR_H