//
// Created by cesar on 4/6/2026.
//

#ifndef PROYECTO2KIAP_PELEA_H
#define PROYECTO2KIAP_PELEA_H
#include "Movimientos.h"
#include "Personaje.h"
#include <sstream>

class Pelea {
public:
    static string pelear(Personaje* p1, Movimiento* mov, Personaje* p2) {
        stringstream s;
        if (!p1->isVivo()) {
            throw invalid_argument("El personaje 1 está muerto y no puede atacar");
        }
        if (!p2->isVivo()) {
            throw invalid_argument("El personaje 2 está muerto y no puede ser atacado");
        }
        if (!p1->puedeRealizarMovimiento(mov)) {
            s<<p1->getNombre()<<" no pudo golpear a "<<p2->getNombre()<<" porque no sabe realizar el movimiento "<<mov->getNombre()<<endl;
        }

        ZonaDelCuerpo* zonaUtilizada = p1->getZona(mov->getExtremidad());

        if (!zonaUtilizada) {
            s<<p1->getNombre()<<" no pudo golpear a "<<p2->getNombre()<<" porque no tiene la extremidad "<<mov->getExtremidad()<<endl;
            return s.str();
        }
        else if (!zonaUtilizada->disponible()) {
            s<<p1->getNombre()<<" no pudo golpear a "<<p2->getNombre()<<" por cansancio"<<endl;
        }
        else if (!mov->realizarMovimiento()) {
            s<<p1->getNombre()<<" fallo el golpe"<<endl;
        }
        else {
            p2->daniar(mov->getDanio());
            zonaUtilizada->utilizar(mov->getImpacto() / 100);

            s<<p1->getNombre()<<" golpeó a "<<p2->getNombre()<<" con el movimiento "<<mov->getNombre()<<", causando "<<mov->getDanio()<<" de daño"<<endl;
        }
        return s.str();
    }
};


#endif //PROYECTO2KIAP_PELEA_H