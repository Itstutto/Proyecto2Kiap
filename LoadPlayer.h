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

class LoadPlayer {
public:
    static Character* loadPlayer(const string& fileName) {
        ifstream file(fileName);
        if (!file.is_open()) {
            file.close();

            //crear si no esta creado
            ofstream newFile(fileName);
            newFile.close();
            file.open(fileName);
        }
        string name;
        string genderStr;
        string healthStr;
        string healPointsStr;
        string expPointsStr;

        char gender;
        double health;
        int healPoints;
        int expPoints;

        if (!getline(file,name,',')) {
            cout<<"Ingrese el nombre del personaje: ";
            getline(cin, name);
        }
        if (name.empty()) { // Validar name no vacío
            throw invalid_argument("El nombre del personaje no puede estar vacío");
        }
        if (!getline(file,genderStr,',')) {
            cout<<"Ingrese el genero del personaje (M/F/O): ";
            cin>>gender;
            cin.ignore();
        }else{
            gender = genderStr.empty() ? 'O' : genderStr[0];
        }
        // Validar género válido
        if (gender != 'M' && gender != 'F' && gender != 'O') {
            throw invalid_argument("Genero invalido: '" + string(1, gender) + "'. Debe ser M, F u O");
        }
        if (!getline(file,healthStr,',') || healthStr.empty()) {
            health = 100; // Valor por defecto
        }
        else {
            try {
                health = stod(healthStr);
            } catch (const invalid_argument& e) {
                throw invalid_argument("Vida no es un número válido: '" + healthStr + "'");
            } catch (const out_of_range& e) {
                throw invalid_argument("Vida fuera de rango: '" + healthStr + "'");
            }
        }
        if (!getline(file,healPointsStr,',')) {
            healPoints = 3; // Valor por defecto
        }
        else {
            try {
                healPoints = stoi(healPointsStr);
            } catch (const invalid_argument& e) {
                throw invalid_argument("Puntos de curación no es un número válido: '" + healPointsStr + "'");
            } catch (const out_of_range& e) {
                throw invalid_argument("Puntos de curación fuera de rango: '" + healPointsStr + "'");
            }
        }
        if (!getline(file,expPointsStr)) {
            expPoints = 0; // Valor por defecto
        }
        else {
            try {
                expPoints = stoi(expPointsStr);
            } catch (const invalid_argument& e) {
                throw invalid_argument("Puntos de experiencia no es un número valido: '" + expPointsStr + "'");
            } catch (const out_of_range& e) {
                throw invalid_argument("Puntos de experiencia fuera de rango: '" + expPointsStr + "'");
            }
        }


        // Validar health positiva
        if (health <= 0) {
            throw invalid_argument("La vida debe ser mayor a 0, recibido: " + to_string(health));
        }

        Player* p = new Player(name, gender,health, healPoints, expPoints);
        stringstream ss;
        string line;
        string zone;

        //Las siguiente line son solo nombres de movements y su zone

        while (getline(file, line)) {
            if (line.empty()) {
                continue; // Saltar líneas vacías
            }
            ss.clear();
            ss.str(line);

            getline(ss,name,',');
            getline(ss,zone,',');
            try {

                p->addMovement(name ,zone);
            }catch (const invalid_argument& e) {
                cout << "Error al agregar movimiento '" << name << "' con zone '" << zone << "': " << e.what() << endl;
            }
        }




        file.close();


        // Devolver el personaje que acabamos de poblar (no crear uno nuevo vacío)
        return p;
    }

    static Character* guardarPersonaje(Player);
};


#endif //PROYECTO2KIAP_CARGAPERSONAJEPRINCIPAL_H