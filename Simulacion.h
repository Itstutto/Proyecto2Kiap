//
// Created by cesar on 4/6/2026.
//

#ifndef PROYECTO2KIAP_SIMULACION_H
#define PROYECTO2KIAP_SIMULACION_H
#include "Personaje.h"
#include "PersonajeEnemigo.h"
#include <random>


class Simulacion {
private:
    //atributos para manejar la simulacion, como personajes, movimientos, etc

    Personaje* personajePrincipal;
    Personaje* enemigoActual;
    vector<Personaje*> enemigosFacil;
    vector<Personaje*> enemigosMedia;
    vector<Personaje*> enemigosDificil;

    string rutaPersonajePrincipal;
    string rutaEnemigos;
    string rutaMovimientosSuperiores;
    string rutaMovimientosInferiores;
    string rutaZonaSuperior;
    string rutaZonaInferior;

public:
    Simulacion();
    void ejecutarSimulacion();
    void zonaPelea(char tipo); //tipo facil, medio, dificil
    Movimiento* menuPersonajePrincipal();
};


#endif //PROYECTO2KIAP_SIMULACION_H