//
// Created by cesar on 1/6/2026.
//

#ifndef PROYECTO2KIAP_PERSONAJE_H
#define PROYECTO2KIAP_PERSONAJE_H
#include <iostream>

#include "Movement.h"
#include "Serialize.h"
#include "UpperZone.h"
using namespace std;

class Character : public IShow, public Serialize{
protected:

    //decorator of protective equipment, pending
    //decorator of objects to cause harm, earring
    string name;
    char gender;
    double health;
    double damage;
    bool alive;
    vector<BodyZone*> bodyZones; //to determine which body zones the character has, and thus determine what movements they can perform
    Vectors<Movement> movements;
public:
    Character();
    Character(const string &name,char gender,double health, double damage);
    Character(const string &name,char gender,double health);
    virtual ~Character();

    virtual string getName() = 0;
    double getHealth();
    void setName(const string& name);
    void setGender(char gender);
    virtual void resetStats();

    bool isAlive();
    virtual bool heal(int amount) = 0;
    void hurt(double amount);

    bool canMakeMove(Movement* mov);
    string getMovements();
    void addMovement(string name, string zone);
    Movement* getIndexMovement(int index);
    int getAmountMovements();

    BodyZone* getZone(string zoneName);

    double getDamage();

};


#endif //PROYECTO2KIAP_PERSONAJE_H
