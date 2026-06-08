//
// Created by cesar on 3/6/2026.
//

#include "FactoryMovimientos.h"

#include "CreadorMovimientosInferiores.h"
#include "CrearMovimientos.h"

vector<Movimiento *> FactoryMovimientos::crearMovimientos(const string &name) {
    /*sintaxis de archivos
     *tipo: inferior/superior
     *name,extremidad,zonaImpacto,danio,impacto,descripcion,difficulty
     *name,extremidad,zonaImpacto,danio,impacto,descripcion,difficulty
     *...
     */
    vector<Movimiento*> movements;
    ifstream archivo(name);
    if (!archivo.is_open()) {
        throw runtime_error("No se pudo abrir el archivo: " + name);
    }

    string linea;


    CrearMovimientos* creador;
    creador = new CreadorMovimientosInferiores();


    int numeroLinea = 1; // contador de líneas

    while (getline(archivo, linea)) {
        numeroLinea++;

        // Ignorar líneas vacías
        if (linea.empty()) {
            continue;
        }

        stringstream ss(linea);
        string nombreMov, extremidad, zonaImpacto, danioStr, impactoStr, descripcion, dificultadStr,costoStr;

        // Leer todos los campos separados por coma
        if (!getline(ss, nombreMov, ',')) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": Falta el name del movimiento");
        }

        if (nombreMov.empty()) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": El name del movimiento no puede estar vacío");
        }

        if (!getline(ss, extremidad, ',')) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": Falta la extremidad");
        }
        if (extremidad.empty()) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": La extremidad no puede estar vacía");
        }

        if (!getline(ss, zonaImpacto, ',')) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": Falta la zone de impacto");
        }

        if (zonaImpacto.empty()) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": La zone de impacto no puede estar vacía");
        }
        if (!getline(ss, danioStr, ',')) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": Falta el daño");
        }

        if (!getline(ss, impactoStr, ',')) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": Falta el impacto");
        }

        if (!getline(ss, descripcion, ',')) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": Falta la descripción");
        }

        if (!getline(ss, dificultadStr, ',')) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": Falta la difficulty");
        }

        if (!getline(ss, costoStr)) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": Falta el costo");
        }

        // Convertir a números con validación
        double danio;
        double impacto;
        double difficulty;
        int costo;
        try {
            danio = stod(danioStr);
        } catch (const invalid_argument& e) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": Daño no es un número válido: '" + danioStr + "'");
        } catch (const out_of_range& e) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": Daño fuera de rango: '" + danioStr + "'");
        }

        try {
            impacto = stod(impactoStr);
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
            costo = stoi(costoStr);
        } catch (const invalid_argument& e) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": Costo no es un número válido: '" + costoStr + "'");
        } catch (const out_of_range& e) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": Costo fuera de rango: '" + costoStr + "'");
        }

        movements.push_back(creador->crearMovimiento(nombreMov, danio, impacto, descripcion, extremidad, zonaImpacto, difficulty,costo));
    }

    archivo.close();

    return movements;
}
