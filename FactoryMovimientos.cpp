//
// Created by cesar on 3/6/2026.
//

#include "FactoryMovimientos.h"

#include "CreadorMovimientosInferiores.h"
#include "CrearMovimientos.h"

vector<Movimiento *> FactoryMovimientos::crearMovimientos(const string &nombre) {
    /*sintaxis de archivos
     *tipo: inferior/superior
     *nombre,extremidad,zonaImpacto,danio,impacto,descripcion,dificultad
     *nombre,extremidad,zonaImpacto,danio,impacto,descripcion,dificultad
     *...
     */
    vector<Movimiento*> movimientos;
    ifstream archivo(nombre);
    if (!archivo.is_open()) {
        throw runtime_error("No se pudo abrir el archivo: " + nombre);
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
        string nombreMov, extremidad, zonaImpacto, danioStr, impactoStr, descripcion, dificultadStr;

        // Leer todos los campos separados por coma
        if (!getline(ss, nombreMov, ',')) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": Falta el nombre del movimiento");
        }

        if (nombreMov.empty()) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": El nombre del movimiento no puede estar vacío");
        }

        if (!getline(ss, extremidad, ',')) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": Falta la extremidad");
        }
        if (extremidad.empty()) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": La extremidad no puede estar vacía");
        }

        if (!getline(ss, zonaImpacto, ',')) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": Falta la zona de impacto");
        }

        if (zonaImpacto.empty()) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": La zona de impacto no puede estar vacía");
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

        if (!getline(ss, dificultadStr)) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": Falta la dificultad");
        }

        // Convertir a números con validación
        double danio;
        double impacto;
        double dificultad;
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
            dificultad = stod(dificultadStr);
        } catch (const invalid_argument& e) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": Dificultad no es un número válido: '" + dificultadStr + "'");
        } catch (const out_of_range& e) {
            throw invalid_argument("Línea " + to_string(numeroLinea) + ": Dificultad fuera de rango: '" + dificultadStr + "'");
        }

        movimientos.push_back(creador->crearMovimiento(nombreMov, danio, impacto, descripcion, extremidad, zonaImpacto, dificultad));
    }

    archivo.close();

    return movimientos;
}
