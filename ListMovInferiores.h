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

    Movimiento* getMovimiento(const string& nombre, const string& zona) {

        for (const auto x : elementos) {

            if (x->getNombre() == nombre && x->getExtremidad() == zona) {
                return x;
            }
        }
        throw invalid_argument("No existe un movimiento con ese nombre y zona");
    }

    static ListMovInferiores* getInstancia();
};


#endif //PROYECTO2KIAP_LISTMOVINFERIORES_H