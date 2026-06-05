//
// Created by cesar on 4/6/2026.
//

#include "ListMovSuperiores.h"
ListMovSuperiores* ListMovSuperiores::instancia = nullptr;

ListMovSuperiores * ListMovSuperiores::getInstancia() {
    if (!instancia) instancia = new ListMovSuperiores();
    return instancia;
}
