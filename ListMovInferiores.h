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

    static ListMovInferiores* getInstancia();
};


#endif //PROYECTO2KIAP_LISTMOVINFERIORES_H