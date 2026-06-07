//
// Created by cesar on 6/6/2026.
//

#ifndef PROYECTO2KIAP_COMBATEENEMIGO_H
#define PROYECTO2KIAP_COMBATEENEMIGO_H
#include "EstrategiaCombate.h"
#include "PersonajeEnemigo.h"


class CombateEnemigo : EstrategiaCombate{
public:
    ~CombateEnemigo() override = default;
    Movimiento* ejecutarEstrategia(Personaje* p, Personaje* c) override {
        //seleccionar un movimiento al azar de los movimientos disponibles del enemigo
        int adicionalDificultad = 0;
        if (dynamic_cast<PersonajeEnemigo*>(p)) {
            PersonajeEnemigo* enemigo = dynamic_cast<PersonajeEnemigo*>(p);
            if (enemigo->getDificultad() == "Facil") {
                adicionalDificultad = 10;
            } else if (enemigo->getDificultad() == "Media") {
                adicionalDificultad = 20;
            } else if (enemigo->getDificultad() == "Dificil") {
                adicionalDificultad = 30;
            }
        }
        random_device rd;
        mt19937 motor(rd());
        uniform_int_distribution<int> distribucion1(1, p->getCantidadMovimientos()+5);
        uniform_int_distribution<int> distribucion2(0+adicionalDificultad, 15+adicionalDificultad);

        int indiceMovimiento = distribucion1(motor);

        if (indiceMovimiento > p->getCantidadMovimientos()) {
            int cantidadSanar = distribucion2(motor);
            cout<<p->getNombre()<<" ha decidido sanar en este turno, recuperando "<<cantidadSanar<<" puntos de vida"<<endl;
            p->sanar(cantidadSanar);
            return nullptr;
        }

        return p->getMovimientoIndice(indiceMovimiento);
    }
};


#endif //PROYECTO2KIAP_COMBATEENEMIGO_H