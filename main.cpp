#include <iostream>

#include "LoadPlayer.h"
#include "MovementsFactory.h"
#include "ZonesFactory.h"
#include "LowerMovList.h"
#include "Movement.h"
#include "Character.h"
#include "Enemy.h"
#include "Player.h"
#include "Simulation.h"
#include "LowerZone.h"
using namespace std;
int main() {
    Simulation simulacion;
    simulacion.execSimulation();

    return 0;
}