//
// Created by cesar on 3/6/2026.
//

#ifndef PROYECTO2KIAP_ZONAINFERIOR_H
#define PROYECTO2KIAP_ZONAINFERIOR_H
#include <iostream>
#include <vector>

#include "ZonaCuerpoBase.h"
#include "ZonasDelCuerpo.h"
using namespace std;

class ZonaInferior : public ZonaCuerpoBase{
private:
    static ZonaInferior* instancia;
    ZonaInferior() = default;
public:
    ZonaInferior(const ZonaInferior&) = delete;
    ZonaInferior& operator=(const ZonaInferior&) = delete;

    static ZonaInferior* getInstancia();
};


#endif //PROYECTO2KIAP_ZONAINFERIOR_H