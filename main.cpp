#include <iostream>

#include "CargaPersonajePrincipal.h"
#include "FactoryMovimientos.h"
#include "FactoryZonas.h"
#include "ListMovInferiores.h"
#include "Movimientos.h"
#include "Personaje.h"
#include "PersonajeEnemigo.h"
#include "PersonajePrincipal.h"
#include "Simulacion.h"
#include "ZonaInferior.h"
using namespace std;
int main() {
    Simulacion simulacion;
    simulacion.zonaPelea('f');

    return 0;
}