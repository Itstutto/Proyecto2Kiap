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
        if (nombre.empty()) { // Validar nombre no vacío
            throw invalid_argument("El nombre del personaje no puede estar vacío");
        }
        if (!getline(archivo,generoStr,',')) {
            cout<<"Ingrese el genero del personaje (M/F/O): ";
            cin>>genero;
            cin.ignore();
        }else{
            genero = generoStr.empty() ? 'O' : generoStr[0];
        }
        // Validar género válido
        if (genero != 'M' && genero != 'F' && genero != 'O') {
            throw invalid_argument("Género inválido: '" + string(1, genero) + "'. Debe ser M, F u O");
        }
        if (!getline(archivo,vidaStr)) {
            vida = 100; // Valor por defecto
            cout << "Vida no especificada. Se usará valor por defecto: " << vida << endl;
        }
        else {
            if (vidaStr.empty()) {
                vida = 100; // Valor por defecto si está vacío
                cout << "Vida vacía. Se usará valor por defecto: " << vida << endl;
            } else {
                try {
                    vida = stod(vidaStr);
                } catch (const invalid_argument& e) {
                    throw invalid_argument("Vida no es un número válido: '" + vidaStr + "'");
                } catch (const out_of_range& e) {
                    throw invalid_argument("Vida fuera de rango: '" + vidaStr + "'");
                }
            }
        }

        // Validar vida positiva
        if (vida <= 0) {
            throw invalid_argument("La vida debe ser mayor a 0, recibido: " + to_string(vida));
        }

        archivo.close();


        return new PersonajePrincipal(nombre, genero,vida);
    }

    static Personaje* guardarPersonaje(PersonajePrincipal);
};


#endif //PROYECTO2KIAP_CARGAPERSONAJEPRINCIPAL_H