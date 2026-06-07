//
// Created by cesar on 4/6/2026.
//

#ifndef PROYECTO2KIAP_CARGAPERSONAJEPRINCIPAL_H
#define PROYECTO2KIAP_CARGAPERSONAJEPRINCIPAL_H
#include <iostream>
#include <fstream>

#include "ListMovInferiores.h"
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
        string puntosCuracionStr;
        string puntosExperienciaStr;

        char genero;
        double vida;
        int puntosCuracion;
        int puntosExperiencia;

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
        if (!getline(archivo,vidaStr,',') || vidaStr.empty()) {
            vida = 100; // Valor por defecto
        }
        else {
            try {
                vida = stod(vidaStr);
            } catch (const invalid_argument& e) {
                throw invalid_argument("Vida no es un número válido: '" + vidaStr + "'");
            } catch (const out_of_range& e) {
                throw invalid_argument("Vida fuera de rango: '" + vidaStr + "'");
            }
        }
        if (!getline(archivo,puntosCuracionStr,',')) {
            puntosCuracion = 3; // Valor por defecto
        }
        else {
            try {
                puntosCuracion = stoi(puntosCuracionStr);
            } catch (const invalid_argument& e) {
                throw invalid_argument("Puntos de curación no es un número válido: '" + puntosCuracionStr + "'");
            } catch (const out_of_range& e) {
                throw invalid_argument("Puntos de curación fuera de rango: '" + puntosCuracionStr + "'");
            }
        }
        if (!getline(archivo,puntosExperienciaStr)) {
            puntosExperiencia = 0; // Valor por defecto
        }
        else {
            try {
                puntosExperiencia = stoi(puntosExperienciaStr);
            } catch (const invalid_argument& e) {
                throw invalid_argument("Puntos de experiencia no es un número válido: '" + puntosExperienciaStr + "'");
            } catch (const out_of_range& e) {
                throw invalid_argument("Puntos de experiencia fuera de rango: '" + puntosExperienciaStr + "'");
            }
        }


        // Validar vida positiva
        if (vida <= 0) {
            throw invalid_argument("La vida debe ser mayor a 0, recibido: " + to_string(vida));
        }

        PersonajePrincipal* p = new PersonajePrincipal(nombre, genero,vida, puntosCuracion, puntosExperiencia);
        stringstream ss;
        string linea;
        string zona;

        //Las siguiente linea son solo nombres de movimientos y su zona

        while (getline(archivo, linea)) {
            if (linea.empty()) {
                continue; // Saltar líneas vacías
            }
            ss.clear();
            ss.str(linea);

            getline(ss,nombre,',');
            getline(ss,zona,',');
            try {

                p->agregarMovimiento(nombre ,zona);
            }catch (const invalid_argument& e) {
                cout << "Error al agregar movimiento '" << nombre << "' con zona '" << zona << "': " << e.what() << endl;
            }
        }




        archivo.close();


        // Devolver el personaje que acabamos de poblar (no crear uno nuevo vacío)
        return p;
    }

    static Personaje* guardarPersonaje(PersonajePrincipal);
};


#endif //PROYECTO2KIAP_CARGAPERSONAJEPRINCIPAL_H