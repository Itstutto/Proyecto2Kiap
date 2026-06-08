//
// Created by cesar on 1/6/2026.
//

#ifndef PROYECTO2KIAP_PERSONAJE_H
#define PROYECTO2KIAP_PERSONAJE_H
#include <iostream>

#include "Movimientos.h"
#include "Serializar.h"
#include "ZonaSuperior.h"
using namespace std;

class Character : public IMostrar, public Serializar{
protected:

    //decorator de equipamiento de proteccion, pendiente
    //decorator de objetos para hacer daño, pendiente
    string name;
    char gender;
    double health;
    double damage;
    bool alive;
    vector<ZonaDelCuerpo*> bodyZones; //para determinar que zonas del cuerpo tiene el personaje, y asi determinar que movements puede realizar
    Vectores<Movimiento> movements;
public:
    Character();
    Character(const string &name,char gender,double health, double damage);
    Character(const string &name,char gender,double health);
    virtual ~Character() = default;

    virtual string getName() = 0;
    double getHealth();
    void setName(const string& name);
    void setGender(char gender);
    virtual void resetStats();

    bool isAlive();
    virtual bool heal(int amount) = 0;
    void hurt(double amount);

    bool canMakeMove(Movimiento* mov);
    string getMovements();
    void addMovement(string name, string zone);
    Movimiento* getIndexMovement(int index);
    int getAmountMovements();

    ZonaDelCuerpo* getZone(string zoneName);

    double getDamage();

};


#endif //PROYECTO2KIAP_PERSONAJE_H
