//
// Created by cesar on 3/6/2026.
//

#include "ZonaCuerpoBase.h"

void ZonaCuerpoBase::agregarZona(ZonaDelCuerpo *zona)  {
    for (const auto x : zonas) {
        if (x->getNombre() == zona->getNombre()) {
            throw invalid_argument("Ya existe una zona con ese nombre");
        }
    }
    zonas.push_back(zona);
}

void ZonaCuerpoBase::agregarZona(vector<ZonaDelCuerpo *> zonas) {
    for (const auto x : zonas) {
        agregarZona(x);
    }
}

vector<ZonaDelCuerpo *> ZonaCuerpoBase::getZonas()  {
    vector<ZonaDelCuerpo*> copia;
    copia.reserve(zonas.size());
    for (const ZonaDelCuerpo* z : zonas) {
        if (z) {
            // crea una copia independiente en el heap
            copia.push_back(new ZonaDelCuerpo(*z));
        } else {
            copia.push_back(nullptr);
        }
    }
    return copia;
}

std::string ZonaCuerpoBase::mostrar() {
    stringstream s;
    int cant = 1;
    for (const auto x : zonas) {
        s<<cant++<<". "<<x->mostrar();
    }

    return s.str();
}