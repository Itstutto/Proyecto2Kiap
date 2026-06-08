//
// Created by cesar on 6/6/2026.
//

#ifndef PROYECTO2KIAP_GESTORCOMBATES_H
#define PROYECTO2KIAP_GESTORCOMBATES_H
#include "CombatStrategy.h"


class GestorCombates {
private:
        CombatStrategy* estrategia;
public:
    GestorCombates() {
        estrategia = nullptr;
    }
    ~GestorCombates() {
        delete estrategia;
    }
    Movimiento* executeStrategy(Character* p, Character* c) {
        if (!estrategia) {
            throw runtime_error("No se ha establecido una estrategia de combate");
        }
        return estrategia->executeStrategy(p,c);
    }
    void setEstrategia(CombatStrategy* nuevaEstrategia) {
        if (estrategia) {
            delete estrategia;
        }
        estrategia = nuevaEstrategia;
    }

};


#endif //PROYECTO2KIAP_GESTORCOMBATES_H