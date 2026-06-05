//
// Created by cesar on 4/6/2026.
//

#ifndef PROYECTO2KIAP_ISERIALIZAR_H
#define PROYECTO2KIAP_ISERIALIZAR_H
#include <iostream>
using namespace std;

class ISerializar {
public:
    virtual ~ISerializar() = default;
    virtual string serializar() const = 0;
};


#endif //PROYECTO2KIAP_ISERIALIZAR_H