//
// Created by cesar on 4/6/2026.
//

#ifndef PROYECTO2KIAP_SIMULACION_H
#define PROYECTO2KIAP_SIMULACION_H
#include "Character.h"
#include "Enemy.h"
#include <random>

#include "CombatManager.h"
#include "Save.h"


class Simulation {
private:
    //atributos para manejar la simulacion, como personajes, movements, etc

    Character* player1;
    Character* actualEnemy;
    vector<Character*> easyEnemies;
    vector<Character*> mediumEnemies;
    vector<Character*> hardEnemies;
    CombatManager combatManager;

    string player1Path;
    string enemiesPath;
    string movementsPath;
    string upperZonePath;
    string lowerZonePath;

public:
    Simulation();
    void execSimulation();
    void starMenu();
    void betweenFightsMenu();
    void store();
    void fightZone(char type); //type facil, medio, dificil

};


#endif //PROYECTO2KIAP_SIMULACION_H