//
// Created by cesar on 3/6/2026.
//

#ifndef PROYECTO2KIAP_ZONASDELCUERPO_H
#define PROYECTO2KIAP_ZONASDELCUERPO_H
#include <iostream>
#include <random>
#include <sstream>
#include "IShow.h"
using namespace std;

class BodyZone : public IShow{
private:
    string name;
    double condition; //It determines how likely a movement is to occur; a lower condition means lower probability.
public:
    BodyZone(string name) {
        if (name.empty()) {
            throw invalid_argument("El nombre de la zona no puede estar vacío");
        }
        this->name = name;
        condition = 1;
    }

    string getName() const { return name; }
    void setName(const std::string& n) { name = n; }

    double getCondicion() const { return condition; }

    void use(double impact) {
        condition -= impact;
        if (condition < 0) {
            condition = 0;
        }
    }

    bool available() {
        random_device rd;
        mt19937 engine(rd());
        uniform_int_distribution<int> distribution(1,100);

        int posibility = distribution(engine);
        if (posibility>condition*100) {
            return false;
        }
        return true;
    }

    std::string show() override {
        stringstream s;
        s<<"Zona: "<<name<<", Condicion: "<<condition*100<<"% "<<endl;
        return s.str();
    }

    bool operator==(const BodyZone &other) const {
        return name == other.name;
    }

};


#endif //PROYECTO2KIAP_ZONASDELCUERPO_H