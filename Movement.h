//
// Created by cesar on 1/6/2026.
//

#ifndef PROYECTO2KIAP_MOVIMIENTOS_H
#define PROYECTO2KIAP_MOVIMIENTOS_H
#include <iostream>
#include <random>
#include <sstream>
#include "IShow.h"
using namespace std;

class Movement : public IShow{
protected:
    string name;
    string limb; //right arm, left arm, head, etc.
    string impactZone; //head, torso, arm, leg, etc.
    double damage;
    double impact;
    double difficulty; //It determines how difficult the movement is to perform; the greater the difficulty, the lower the probability of performing it.
    string info;
    int cost;
public:
    Movement(string name, string limb, string impactZone, double damage,double impact,string info, double difficulty,int cost);
    ~Movement() override = default;
    string getName();
    double getDamage();
    double getImpact();
    int getCost();

    bool makeMove() {
        random_device rd;
        mt19937 engine(rd());
        uniform_int_distribution<int> distribution(1,100);

        int posibility = distribution(engine);

        if (posibility>difficulty*100) {
            return false;
        }
        return true;
    }

    string getLimb(){
        return limb;
    }
    string getImpactZone(){
        return impactZone;
    }

    std::string show() override;

    bool operator==(const Movement &other) const {
        return name == other.name &&
               limb == other.limb &&
               impactZone == other.impactZone;
    }


};



#endif //PROYECTO2KIAP_MOVIMIENTOS_H
