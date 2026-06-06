//
// Created by cesar on 3/6/2026.
//

#ifndef PROYECTO2KIAP_FACTORYMOVIMIENTOS_H
#define PROYECTO2KIAP_FACTORYMOVIMIENTOS_H
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Movimientos.h"
#include "MovimientosInferiores.h"

//cr

class FactoryMovimientos {
public:
    static vector<Movimiento*> crearMovimientos(const string& nombre);

};



#endif //PROYECTO2KIAP_FACTORYMOVIMIENTOS_H
