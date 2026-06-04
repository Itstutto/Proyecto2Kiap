#include <iostream>

#include "FactoryZonas.h"
#include "Personaje.h"
#include "PersonajeEnemigo.h"
#include "PersonajePrincipal.h"
#include "ZonaInferior.h"
using namespace std;
int main() {

    ZonaInferior* zonas = ZonaInferior::getInstancia();

    zonas->agregarZona(FactoryZonas::crearZonas("ZonasDelCuerpo.txt"));
    ZonaInferior* zonas2 = ZonaInferior::getInstancia();

    cout<<zonas2->mostrar();
    return 0;
}