//
// Created by cesar on 1/6/2026.
//

#ifndef PROYECTO2KIAP_PERSONAJEPRINCIPAL_H
#define PROYECTO2KIAP_PERSONAJEPRINCIPAL_H
#include "Character.h"
#include <sstream>

class Player : public Character{
private:
    int healPoints;
    int expPoints;
public:
    Player(const string &name, char gender, double health, int healPoints, int expPoints);
    string getName() override;
    int getHealPoints();
    int getExpPoints();
    void gainExp(int amount);
    void gainHealP(int amount);
    void buy(int amount);
    std::string show() override;
    bool heal(int amount) override;
    void resetStats() override;
    string serialize() override;

};


#endif //PROYECTO2KIAP_PERSONAJEPRINCIPAL_H