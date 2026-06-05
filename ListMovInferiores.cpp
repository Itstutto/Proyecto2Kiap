//
// Created by cesar on 4/6/2026.
//

#include "ListMovInferiores.h"
ListMovInferiores* ListMovInferiores::instancia = nullptr;

ListMovInferiores * ListMovInferiores::getInstancia() {
    if (!instancia) instancia = new ListMovInferiores();
    return instancia;
}
