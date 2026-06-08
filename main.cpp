#include <iostream>

#include "CargaPersonajePrincipal.h"
#include "FactoryMovimientos.h"
#include "FactoryZonas.h"
#include "ListMovInferiores.h"
#include "Movimientos.h"
#include "Character.h"
#include "Enemy.h"
#include "Player.h"
#include "Simulacion.h"
#include "ZonaInferior.h"
using namespace std;
int main() {
    Simulacion simulacion;
    simulacion.ejecutarSimulacion();

    return 0;
}