//
// Created by cesar on 4/6/2026.
//

#ifndef PROYECTO2KIAP_SIMULACION_H
#define PROYECTO2KIAP_SIMULACION_H
#include "Personaje.h"
#include "PersonajeEnemigo.h"
#include <random>

#include "GestorCombates.h"
#include "Guardar.h"


class Simulacion {
private:
    //atributos para manejar la simulacion, como personajes, movimientos, etc

    Personaje* personajePrincipal;
    Personaje* enemigoActual;
    vector<Personaje*> enemigosFacil;
    vector<Personaje*> enemigosMedia;
    vector<Personaje*> enemigosDificil;
    GestorCombates gestorCombates;

    string rutaPersonajePrincipal;
    string rutaEnemigos;
    string rutaMovimientosSuperiores;
    string rutaMovimientosInferiores;
    string rutaZonaSuperior;
    string rutaZonaInferior;

public:
    Simulacion();
    void ejecutarSimulacion();
    void menuInicial();
    void menuEntrePeleas();
    void tienda();
    void zonaPelea(char tipo); //tipo facil, medio, dificil

};


#endif //PROYECTO2KIAP_SIMULACION_H