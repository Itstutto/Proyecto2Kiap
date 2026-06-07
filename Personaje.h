//
// Created by cesar on 1/6/2026.
//

#ifndef PROYECTO2KIAP_PERSONAJE_H
#define PROYECTO2KIAP_PERSONAJE_H
#include <iostream>

#include "Movimientos.h"
#include "Serializar.h"
#include "ZonaSuperior.h"
using namespace std;

class Personaje : public IMostrar, public Serializar{
protected:

    //decorator de equipamiento de proteccion, pendiente
    //decorator de objetos para hacer daño, pendiente
    string nombre;
    char genero;
    double vida;
    double danioBase;
    bool vivo;
    vector<ZonaDelCuerpo*> zonasCuerpo; //para determinar que zonas del cuerpo tiene el personaje, y asi determinar que movimientos puede realizar
    Vectores<Movimiento> movimientos;
public:
    Personaje();
    Personaje(const string &nombre,char genero,double vida, double danioBase);
    Personaje(const string &nombre,char genero,double vida);
    virtual ~Personaje() = default;

    virtual string getNombre() = 0;
    double getVida();
    void setNombre(const string& nombre);
    void setGenero(char genero);
    virtual void reiniciarEstadisticas();

    bool isVivo();
    virtual bool sanar(int cantidad) = 0;
    void daniar(double cantidad);

    bool puedeRealizarMovimiento(Movimiento* mov);
    string getMovimientos();
    void agregarMovimiento(string nombre, string zona);
    Movimiento* getMovimientoIndice(int indice);
    int getCantidadMovimientos();

    ZonaDelCuerpo* getZona(string nombreZona);

    double getDanio();

};


#endif //PROYECTO2KIAP_PERSONAJE_H
