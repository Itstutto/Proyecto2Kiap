//
// Created by cesar on 3/6/2026.
//

#include "MovementsFactory.h"

#include "MovementMaker.h"
#include "MakeMoves.h"

vector<Movement *> MovementsFactory::createMovements(const string &name) {
    /*file syntax
      *type: bottom/top
      *name,limb,impactZone,damage,impact,description,difficulty
      *name,limb,impactZone,damage,impact,description,difficulty
     *...
     */
    vector<Movement*> movements;
    ifstream file(name);
    if (!file.is_open()) {
        throw runtime_error("No se pudo abrir el archivo: " + name);
    }

    string line;


    MakeMoves* creator;
    creator = new MovementMaker();


    int numberLine = 1; // line counter

    while (getline(file, line)) {
        numberLine++;

        // Ignore empty lines
        if (line.empty()) {
            continue;
        }

        stringstream ss(line);
        string nombreMov, limb, impactZone, danioStr, impactoStr, descripcion, dificultadStr,costoStr;

        // Read all comma-separated fields
        if (!getline(ss, nombreMov, ',')) {
            throw invalid_argument("Línea " + to_string(numberLine) + ": Falta el nombre del movimiento");
        }

        if (nombreMov.empty()) {
            throw invalid_argument("Línea " + to_string(numberLine) + ": El nombre del movimiento no puede estar vacío");
        }

        if (!getline(ss, limb, ',')) {
            throw invalid_argument("Línea " + to_string(numberLine) + ": Falta la extremidad");
        }
        if (limb.empty()) {
            throw invalid_argument("Línea " + to_string(numberLine) + ": La extremidad no puede estar vacía");
        }

        if (!getline(ss, impactZone, ',')) {
            throw invalid_argument("Línea " + to_string(numberLine) + ": Falta la zona de impacto");
        }

        if (impactZone.empty()) {
            throw invalid_argument("Línea " + to_string(numberLine) + ": La zona de impacto no puede estar vacía");
        }
        if (!getline(ss, danioStr, ',')) {
            throw invalid_argument("Línea " + to_string(numberLine) + ": Falta el daño");
        }

        if (!getline(ss, impactoStr, ',')) {
            throw invalid_argument("Línea " + to_string(numberLine) + ": Falta el impacto");
        }

        if (!getline(ss, descripcion, ',')) {
            throw invalid_argument("Línea " + to_string(numberLine) + ": Falta la descripción");
        }

        if (!getline(ss, dificultadStr, ',')) {
            throw invalid_argument("Línea " + to_string(numberLine) + ": Falta la dificultad");
        }

        if (!getline(ss, costoStr)) {
            throw invalid_argument("Línea " + to_string(numberLine) + ": Falta el costo");
        }

        //Convert to numbers with validation
        double damage;
        double impact;
        double difficulty;
        int cost;
        try {
            damage = stod(danioStr);
        } catch (const invalid_argument& e) {
            throw invalid_argument("Línea " + to_string(numberLine) + ": Daño no es un número válido: '" + danioStr + "'");
        } catch (const out_of_range& e) {
            throw invalid_argument("Línea " + to_string(numberLine) + ": Daño fuera de rango: '" + danioStr + "'");
        }

        try {
            impact = stod(impactoStr);
        } catch (const invalid_argument& e) {
            throw invalid_argument("Línea " + to_string(numberLine) + ": Impacto no es un número válido: '" + impactoStr + "'");
        } catch (const out_of_range& e) {
            throw invalid_argument("Línea " + to_string(numberLine) + ": Impacto fuera de rango: '" + impactoStr + "'");
        }
        try {
            difficulty = stod(dificultadStr);
        } catch (const invalid_argument& e) {
            throw invalid_argument("Línea " + to_string(numberLine) + ": Dificultad no es un número válido: '" + dificultadStr + "'");
        } catch (const out_of_range& e) {
            throw invalid_argument("Línea " + to_string(numberLine) + ": Dificultad fuera de rango: '" + dificultadStr + "'");
        }

        try {
            cost = stoi(costoStr);
        } catch (const invalid_argument& e) {
            throw invalid_argument("Línea " + to_string(numberLine) + ": Costo no es un número válido: '" + costoStr + "'");
        } catch (const out_of_range& e) {
            throw invalid_argument("Línea " + to_string(numberLine) + ": Costo fuera de rango: '" + costoStr + "'");
        }

        movements.push_back(creator->makeMove(nombreMov, damage, impact, descripcion, limb, impactZone, difficulty,cost));
    }

    file.close();
    delete creator;

    return movements;
}
