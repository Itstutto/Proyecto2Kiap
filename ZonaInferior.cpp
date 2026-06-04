//
// Created by cesar on 3/6/2026.
//

#include "ZonaInferior.h"
ZonaInferior* ZonaInferior::instancia = nullptr;

ZonaInferior * ZonaInferior::getInstancia() {
    if (!instancia) instancia = new ZonaInferior();
    return instancia;
}
