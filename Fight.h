//
// Created by cesar on 4/6/2026.
//

#ifndef PROYECTO2KIAP_PELEA_H
#define PROYECTO2KIAP_PELEA_H
#include "Movement.h"
#include "Character.h"
#include <sstream>

class Fight {
public:
    static string fight(Character* p1, Movement* mov, Character* p2) {
        stringstream s;
        if (!p1->isAlive()) {
            throw invalid_argument("El personaje 1 está muerto y no puede atacar");
        }
        if (!p2->isAlive()) {
            throw invalid_argument("El personaje 2 está muerto y no puede ser atacado");
        }
        if (!p1->canMakeMove(mov)) {
            s<<p1->getName()<<" no pudo golpear a "<<p2->getName()<<" porque no sabe realizar el movimiento "<<mov->getName()<<endl;
            return s.str();
        }

        BodyZone* zoneUsed = p1->getZone(mov->getLimb());

        if (!zoneUsed) {
            s<<p1->getName()<<" no pudo golpear a "<<p2->getName()<<" porque no tiene la limb "<<mov->getLimb()<<endl;
            return s.str();
        }
        else if (!zoneUsed->available()) {
            s<<p1->getName()<<" no pudo golpear a "<<p2->getName()<<" por cansancio"<<endl;
        }
        else if (!mov->makeMove()) {
            s<<p1->getName()<<" fallo el golpe"<<endl;
        }
        else {
            p2->hurt(mov->getDamage());
            zoneUsed->use(mov->getImpact() / 100);

            s<<p1->getName()<<" golpeó a "<<p2->getName()<<" con el movimiento "<<mov->getName()<<", causando "<<mov->getDamage()<<" de daño"<<endl;
        }
        return s.str();
    }
};


#endif //PROYECTO2KIAP_PELEA_H