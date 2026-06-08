//
// Created by cesar on 4/6/2026.
//

#ifndef PROYECTO2KIAP_LISTMOVINFERIORES_H
#define PROYECTO2KIAP_LISTMOVINFERIORES_H
#include "Vectores.h"
#include "Movimientos.h"

class ListMovInferiores : public Vectores<Movimiento> {
private:
    static ListMovInferiores* instancia;
    ListMovInferiores() = default;
public:
    ListMovInferiores(const ListMovInferiores&) = delete;
    ListMovInferiores& operator=(const ListMovInferiores&) = delete;

    Movimiento* getMovimiento(const string& name, const string& zone) {

        for (const auto x : elementos) {

            if (x->getName() == name && x->getExtremidad() == zone) {
                return x;
            }
        }
        throw invalid_argument("No existe un movimiento con ese name y zone");
    }

    static ListMovInferiores* getInstancia();
};


#endif //PROYECTO2KIAP_LISTMOVINFERIORES_H