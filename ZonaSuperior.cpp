//
// Created by cesar on 3/6/2026.
//

#include "ZonaSuperior.h"
ZonaSuperior* ZonaSuperior::instancia = nullptr;

ZonaSuperior * ZonaSuperior::getInstancia() {
    if (!instancia) instancia = new ZonaSuperior();
    return instancia;
}
