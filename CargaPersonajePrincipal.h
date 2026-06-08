//
// Created by cesar on 4/6/2026.
//

#ifndef PROYECTO2KIAP_CARGAPERSONAJEPRINCIPAL_H
#define PROYECTO2KIAP_CARGAPERSONAJEPRINCIPAL_H
#include <iostream>
#include <fstream>

#include "ListMovInferiores.h"
using namespace std;
#include "Player.h"

class CargaPersonajePrincipal {
public:
    static Character* cargarPersonaje(const string& nombreArchivo) {
        ifstream archivo(nombreArchivo);
        if (!archivo.is_open()) {
            archivo.close();

            //crear si no esta creado
            ofstream nuevoArchivo(nombreArchivo);
            nuevoArchivo.close();
            archivo.open(nombreArchivo);
        }
        string name;
        string generoStr;
        string vidaStr;
        string puntosCuracionStr;
        string puntosExperienciaStr;

        char gender;
        double health;
        int healPoints;
        int expPoints;

        if (!getline(archivo,name,',')) {
            cout<<"Ingrese el name del personaje: ";
            getline(cin, name);
        }
        if (name.empty()) { // Validar name no vacío
            throw invalid_argument("El name del personaje no puede estar vacío");
        }
        if (!getline(archivo,generoStr,',')) {
            cout<<"Ingrese el gender del personaje (M/F/O): ";
            cin>>gender;
            cin.ignore();
        }else{
            gender = generoStr.empty() ? 'O' : generoStr[0];
        }
        // Validar género válido
        if (gender != 'M' && gender != 'F' && gender != 'O') {
            throw invalid_argument("Género inválido: '" + string(1, gender) + "'. Debe ser M, F u O");
        }
        if (!getline(archivo,vidaStr,',') || vidaStr.empty()) {
            health = 100; // Valor por defecto
        }
        else {
            try {
                health = stod(vidaStr);
            } catch (const invalid_argument& e) {
                throw invalid_argument("Vida no es un número válido: '" + vidaStr + "'");
            } catch (const out_of_range& e) {
                throw invalid_argument("Vida fuera de rango: '" + vidaStr + "'");
            }
        }
        if (!getline(archivo,puntosCuracionStr,',')) {
            healPoints = 3; // Valor por defecto
        }
        else {
            try {
                healPoints = stoi(puntosCuracionStr);
            } catch (const invalid_argument& e) {
                throw invalid_argument("Puntos de curación no es un número válido: '" + puntosCuracionStr + "'");
            } catch (const out_of_range& e) {
                throw invalid_argument("Puntos de curación fuera de rango: '" + puntosCuracionStr + "'");
            }
        }
        if (!getline(archivo,puntosExperienciaStr)) {
            expPoints = 0; // Valor por defecto
        }
        else {
            try {
                expPoints = stoi(puntosExperienciaStr);
            } catch (const invalid_argument& e) {
                throw invalid_argument("Puntos de experiencia no es un número válido: '" + puntosExperienciaStr + "'");
            } catch (const out_of_range& e) {
                throw invalid_argument("Puntos de experiencia fuera de rango: '" + puntosExperienciaStr + "'");
            }
        }


        // Validar health positiva
        if (health <= 0) {
            throw invalid_argument("La health debe ser mayor a 0, recibido: " + to_string(health));
        }

        Player* p = new Player(name, gender,health, healPoints, expPoints);
        stringstream ss;
        string linea;
        string zone;

        //Las siguiente linea son solo nombres de movements y su zone

        while (getline(archivo, linea)) {
            if (linea.empty()) {
                continue; // Saltar líneas vacías
            }
            ss.clear();
            ss.str(linea);

            getline(ss,name,',');
            getline(ss,zone,',');
            try {

                p->addMovement(name ,zone);
            }catch (const invalid_argument& e) {
                cout << "Error al agregar movimiento '" << name << "' con zone '" << zone << "': " << e.what() << endl;
            }
        }




        archivo.close();


        // Devolver el personaje que acabamos de poblar (no crear uno nuevo vacío)
        return p;
    }

    static Character* guardarPersonaje(Player);
};


#endif //PROYECTO2KIAP_CARGAPERSONAJEPRINCIPAL_H