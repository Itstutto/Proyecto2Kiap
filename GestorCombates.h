//
// Created by cesar on 6/6/2026.
//

#ifndef PROYECTO2KIAP_GESTORCOMBATES_H
#define PROYECTO2KIAP_GESTORCOMBATES_H
#include "EstrategiaCombate.h"


class GestorCombates {
private:
        EstrategiaCombate* estrategia;
public:
    GestorCombates() {
        estrategia = nullptr;
    }
    ~GestorCombates() {
        delete estrategia;
    }
    Movimiento* ejecutarEstrategia(Personaje* p, Personaje* c) {
        if (!estrategia) {
            throw runtime_error("No se ha establecido una estrategia de combate");
        }
        return estrategia->ejecutarEstrategia(p,c);
    }
    void setEstrategia(EstrategiaCombate* nuevaEstrategia) {
        if (estrategia) {
            delete estrategia;
        }
        estrategia = nuevaEstrategia;
    }

};


#endif //PROYECTO2KIAP_GESTORCOMBATES_H