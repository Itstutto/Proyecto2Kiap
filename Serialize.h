//
// Created by cesar on 7/6/2026.
//

#ifndef PROYECTO2KIAP_SERIALIZAR_H
#define PROYECTO2KIAP_SERIALIZAR_H
#include <iostream>
using namespace std;

class Serialize {
public:
    virtual ~Serialize() = default;
    virtual string serialize() = 0;
};


#endif //PROYECTO2KIAP_SERIALIZAR_H