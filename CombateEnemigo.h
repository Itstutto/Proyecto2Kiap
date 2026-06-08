//
// Created by cesar on 6/6/2026.
//

#ifndef PROYECTO2KIAP_COMBATEENEMIGO_H
#define PROYECTO2KIAP_COMBATEENEMIGO_H
#include "EstrategiaCombate.h"
#include "Enemy.h"


class CombateEnemigo : public EstrategiaCombate{
public:
    ~CombateEnemigo() override = default;
    Movimiento* ejecutarEstrategia(Character* p, Character* c) override {
        //seleccionar un movimiento al azar de los movements disponibles del enemigo
        int adicionalDificultad = 0;
        if (dynamic_cast<Enemy*>(p)) {
            Enemy* enemigo = dynamic_cast<Enemy*>(p);
            if (enemigo->getDifficulty() == "Facil") {
                adicionalDificultad = 10;
            } else if (enemigo->getDifficulty() == "Media") {
                adicionalDificultad = 20;
            } else if (enemigo->getDifficulty() == "Dificil") {
                adicionalDificultad = 30;
            }
        }
        random_device rd;
        mt19937 motor(rd());
        uniform_int_distribution<int> distribucion1(1, p->getAmountMovements()+5);
        uniform_int_distribution<int> distribucion2(0+adicionalDificultad, 15+adicionalDificultad);

        int indiceMovimiento = distribucion1(motor);

        if (indiceMovimiento > p->getAmountMovements()) {
            int cantidadSanar = distribucion2(motor);
            cout<<p->getName()<<" ha decidido heal en este turno, recuperando "<<cantidadSanar<<" puntos de health"<<endl;
            p->heal(cantidadSanar);
            return nullptr;
        }

        return p->getIndexMovement(indiceMovimiento);
    }
};


#endif //PROYECTO2KIAP_COMBATEENEMIGO_H