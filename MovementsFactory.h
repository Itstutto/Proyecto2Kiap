//
// Created by cesar on 3/6/2026.
//

#ifndef PROYECTO2KIAP_FACTORYMOVIMIENTOS_H
#define PROYECTO2KIAP_FACTORYMOVIMIENTOS_H
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Movement.h"
#include "ObjectMovement.h"

//cr

class MovementsFactory {
public:
    static vector<Movement*> createMovements(const string& name);

};



#endif //PROYECTO2KIAP_FACTORYMOVIMIENTOS_H
