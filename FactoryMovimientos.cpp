//
// Created by cesar on 3/6/2026.
//

#include "FactoryMovimientos.h"

#include "CreadorMovimientosInferiores.h"
#include "CreadorMovimientosSuperiores.h"
#include "CrearMovimientos.h"

vector<Movimiento *> FactoryMovimientos::crearMovimientos(const string &nombre) {
    /*sintaxis de archivos
     *tipo: inferior/superior
     *nombre,extremidad,zonaImpacto,danio,descripcion
     *nombre,extremidad,zonaImpacto,danio,descripcion
     *...
     */
    vector<Movimiento*> movimientos;
    ifstream archivo(nombre);
    if (!archivo.is_open()) {
        throw runtime_error("No se pudo abrir el archivo: " + nombre);
    }

    string linea;
    getline(archivo, linea);
    CrearMovimientos* creador;
    if (linea == "superior") {
        creador = new CreadorMovimientosSuperiores();
    } else if (linea == "inferior") {
        creador = new CreadorMovimientosInferiores();
    } else {
        throw runtime_error("Tipo de movimiento no reconocido: " + linea);
    }

    while (getline(archivo, linea)) {
        if (!linea.empty()) {
            stringstream ss(linea);
            string nombre, extremidad, zonaImpacto, danioStr,impactoStr, descripcion;
            getline(ss, nombre, ',');
            getline(ss, extremidad, ',');
            getline(ss, zonaImpacto, ',');
            getline(ss, danioStr, ',');
            getline(ss, impactoStr, ',');
            getline(ss, descripcion);

            double danio;
            double impacto;
            try {
                danio = stod(danioStr);
            } catch (const invalid_argument& e) {
                throw invalid_argument("Daño no es un número válido: " + danioStr);
            }
            try {
                impacto = stod(impactoStr);
            } catch (const invalid_argument& e) {
                throw invalid_argument("Impacto no es un número válido: " + impactoStr);
            }
            movimientos.push_back(creador->crearMovimiento(nombre, danio,impacto, descripcion, extremidad, zonaImpacto));
        }
    }
    return movimientos;
}
