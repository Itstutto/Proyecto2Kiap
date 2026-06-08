//
// Created by cesar on 6/6/2026.
//

#ifndef PROYECTO2KIAP_COMBATEENEMIGO_H
#define PROYECTO2KIAP_COMBATEENEMIGO_H
#include "CombatStrategy.h"
#include "Enemy.h"


class EnemyCombat : public CombatStrategy{
public:
    ~EnemyCombat() override = default;
    Movement* executeStrategy(Character* p, Character* c) override {
        //seleccionar un movimiento al azar de los movements disponibles del enemy
        int extraDifficulty = 0;
        if (dynamic_cast<Enemy*>(p)) {
            Enemy* enemy = dynamic_cast<Enemy*>(p);
            if (enemy->getDifficulty() == "Facil") {
                extraDifficulty = 10;
            } else if (enemy->getDifficulty() == "Media") {
                extraDifficulty = 20;
            } else if (enemy->getDifficulty() == "Dificil") {
                extraDifficulty = 30;
            }
        }
        random_device rd;
        mt19937 engine(rd());
        uniform_int_distribution<int> distribution1(1, p->getAmountMovements()+5);
        uniform_int_distribution<int> distribution2(0+extraDifficulty, 15+extraDifficulty);

        int movementIndex = distribution1(engine);

        if (movementIndex > p->getAmountMovements()) {
            int healAmount = distribution2(engine);
            cout<<p->getName()<<" ha decidido sanar en este turno, recuperando "<<healAmount<<" puntos de vida"<<endl;
            p->heal(healAmount);
            return nullptr;
        }

        return p->getIndexMovement(movementIndex);
    }
};


#endif //PROYECTO2KIAP_COMBATEENEMIGO_H