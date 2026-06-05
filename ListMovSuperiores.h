//
// Created by cesar on 4/6/2026.
//

#ifndef PROYECTO2KIAP_LISTMOVSUPERIORES_H
#define PROYECTO2KIAP_LISTMOVSUPERIORES_H
#include "Vectores.h"
#include "Movimientos.h"

class ListMovSuperiores : public Vectores<Movimiento> {
private:
    static ListMovSuperiores* instancia;
    ListMovSuperiores() = default;
public:
    ListMovSuperiores(const ListMovSuperiores&) = delete;
    ListMovSuperiores& operator=(const ListMovSuperiores&) = delete;

    static ListMovSuperiores* getInstancia();
};


#endif //PROYECTO2KIAP_LISTMOVSUPERIORES_H
