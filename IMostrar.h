//
// Created by cesar on 3/6/2026.
//

#ifndef PROYECTO2KIAP_IMOSTRAR_H
#define PROYECTO2KIAP_IMOSTRAR_H
#include <iostream>

class IMostrar {
public:
    virtual ~IMostrar() = default;
    virtual std::string mostrar() = 0;
};


#endif //PROYECTO2KIAP_IMOSTRAR_H