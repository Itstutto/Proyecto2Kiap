//
// Created by cesar on 3/6/2026.
//

#ifndef PROYECTO2KIAP_IMOSTRAR_H
#define PROYECTO2KIAP_IMOSTRAR_H
#include <iostream>

class IShow {
public:
    virtual ~IShow() = default;
    virtual std::string show() = 0;
};


#endif //PROYECTO2KIAP_IMOSTRAR_H