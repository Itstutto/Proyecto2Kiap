//
// Created by cesar on 4/6/2026.
//

#ifndef PROYECTO2KIAP_CARGAPERSONAJEPRINCIPAL_H
#define PROYECTO2KIAP_CARGAPERSONAJEPRINCIPAL_H
#include <iostream>
#include <fstream>
using namespace std;
#include "PersonajePrincipal.h"

class CargaPersonajePrincipal {
public:
    static Personaje* cargarPersonaje(const string& nombreArchivo) {
        ifstream archivo(nombreArchivo);
        if (!archivo.is_open()) {
            archivo.close();

            //crear si no esta creado
            ofstream nuevoArchivo(nombreArchivo);
            nuevoArchivo.close();
            archivo.open(nombreArchivo);
        }
        string nombre;
        string generoStr;
        string vidaStr;

        char genero;
        double vida;
        if (!getline(archivo,nombre,',')) {
            cout<<"Ingrese el nombre del personaje: ";
            getline(cin, nombre);
        }
        if (!getline(archivo,generoStr,',')) {
            cout<<"Ingrese el genero del personaje (M/F/O): ";
            cin>>genero;
        }else{
            genero = generoStr.empty() ? 'O' : generoStr[0];
        }
        if (!getline(archivo,vidaStr)) {
            vida = 100; // Valor por defecto
        }
        else {
            try {
                vida = stod(vidaStr);
            } catch (const invalid_argument& e) {
                throw invalid_argument("Vida no es un número válido: " + vidaStr);
            }
        }


        return new PersonajePrincipal(nombre, genero,vida);
    }

    static Personaje* guardarPersonaje(PersonajePrincipal);
};


#endif //PROYECTO2KIAP_CARGAPERSONAJEPRINCIPAL_H