//
// Created by yense on 6/2/2026.
//

#ifndef PROYECTO2KIAP_PERSONAJEENEMIGO_H
#define PROYECTO2KIAP_PERSONAJEENEMIGO_H
#include<iostream>
#include<sstream>

#include "Character.h"
using namespace std;

class Enemy : public Character {
private:
    string difficulty;

public:
    Enemy(const string &difficulty,const string &name, char gender, double damage, double health = 100);
    std::string mostrar() override;
    string getName() override;
    string getDifficulty();
    bool operator==(const Enemy &other) const;
    bool heal(int amount) override;
    string serializar() override;
    void resetStats() override;


};


#endif //PROYECTO2KIAP_PERSONAJEENEMIGO_H