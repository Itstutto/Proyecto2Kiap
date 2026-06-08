//
// Created by cesar on 6/6/2026.
//

#ifndef PROYECTO2KIAP_GESTORCOMBATES_H
#define PROYECTO2KIAP_GESTORCOMBATES_H
#include "CombatStrategy.h"


class CombatManager {
private:
        CombatStrategy* strategy;
public:
    CombatManager() {
        strategy = nullptr;
    }
    ~CombatManager() {
        delete strategy;
    }
    Movement* executeStrategy(Character* p, Character* c) {
        if (!strategy) {
            throw runtime_error("No se ha establecido una strategy de combate");
        }
        return strategy->executeStrategy(p,c);
    }
    void setStrategy(CombatStrategy* newStrategy) {
        if (strategy) {
            delete strategy;
        }
        strategy = newStrategy;
    }

};


#endif //PROYECTO2KIAP_GESTORCOMBATES_H