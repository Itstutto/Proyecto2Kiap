//
// Created by cesar on 3/6/2026.
//

#include "FactoryMovimientos.h"

#include "MovementMaker.h"
#include "MakeMoves.h"

vector<Movimiento *> FactoryMovimientos::crearMovimientos(const string &name) {
    /*sintaxis de archivos
     *tipo: inferior/superior
     *name,limb,impactZone,damage,impact,descripcion,difficulty
     *name,limb,impactZone,damage,impact,descripcion,difficulty
     *...
     */
    vector<Movimiento*> movements;
    ifstream file(name);
    if (!file.is_open()) {
        throw runtime_error("No se pudo abrir el file: " + name);
    }

    string line;


    MakeMoves* creador;
    creador = new MovementMaker();


    int numeroLinea = 1; // contador de líneas

    while (getline(file, line)) {
        numeroLinea++;

        // Ignorar líneas vacías
        if (line.empty()) {
            continue;
        }

        stringstream ss(line);
        string nombreMov, limb, impactZone, danioStr, impactoStr, descripcion, dificultadStr,costoStr;

        // Leer todos los campos separados por coma
        if (!getline(ss, nombreMov, ',')) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": Falta el name del movimiento");
        }

        if (nombreMov.empty()) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": El name del movimiento no puede estar vacío");
        }

        if (!getline(ss, limb, ',')) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": Falta la limb");
        }
        if (limb.empty()) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": La limb no puede estar vacía");
        }

        if (!getline(ss, impactZone, ',')) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": Falta la zone de impact");
        }

        if (impactZone.empty()) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": La zone de impact no puede estar vacía");
        }
        if (!getline(ss, danioStr, ',')) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": Falta el daño");
        }

        if (!getline(ss, impactoStr, ',')) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": Falta el impact");
        }

        if (!getline(ss, descripcion, ',')) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": Falta la descripción");
        }

        if (!getline(ss, dificultadStr, ',')) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": Falta la difficulty");
        }

        if (!getline(ss, costoStr)) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": Falta el cost");
        }

        // Convertir a números con validación
        double damage;
        double impact;
        double difficulty;
        int cost;
        try {
            damage = stod(danioStr);
        } catch (const invalid_argument& e) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": Daño no es un número válido: '" + danioStr + "'");
        } catch (const out_of_range& e) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": Daño fuera de rango: '" + danioStr + "'");
        }

        try {
            impact = stod(impactoStr);
        } catch (const invalid_argument& e) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": Impacto no es un número válido: '" + impactoStr + "'");
        } catch (const out_of_range& e) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": Impacto fuera de rango: '" + impactoStr + "'");
        }
        try {
            difficulty = stod(dificultadStr);
        } catch (const invalid_argument& e) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": Dificultad no es un número válido: '" + dificultadStr + "'");
        } catch (const out_of_range& e) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": Dificultad fuera de rango: '" + dificultadStr + "'");
        }

        try {
            cost = stoi(costoStr);
        } catch (const invalid_argument& e) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": Costo no es un número válido: '" + costoStr + "'");
        } catch (const out_of_range& e) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": Costo fuera de rango: '" + costoStr + "'");
        }

        movements.push_back(creador->makeMove(nombreMov, damage, impact, descripcion, limb, impactZone, difficulty,cost));
    }

    file.close();

    return movements;
}
