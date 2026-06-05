//
// Created by cesar on 4/6/2026.
//

#include "Simulacion.h"

#include "CargaPersonajePrincipal.h"
#include "FactoryEnemigos.h"
#include "FactoryMovimientos.h"
#include "FactoryZonas.h"
#include "ListMovInferiores.h"
#include "ListMovSuperiores.h"
#include "MovimientosSuperiores.h"
#include "ZonaInferior.h"

Simulacion::Simulacion() {
    // Inicializar rutas de archivos
    rutaPersonajePrincipal = "personaje_principal.txt";
    rutaEnemigos = "enemigos.txt";
    rutaMovimientosSuperiores = "movimientos_superiores.txt";
    rutaMovimientosInferiores = "movimientos_inferiores.txt";
    rutaZonaSuperior = "zona_superior.txt";
    rutaZonaInferior = "zona_inferior.txt";
    try {
        // Cargar personaje principal
        personajePrincipal = CargaPersonajePrincipal::cargarPersonaje(rutaPersonajePrincipal);

        // Cargar enemigos
        enemigosFacil = FactoryEnemigos::crearEnemigo(rutaEnemigos, "Facil"); // Cargar enemigos de dificultad fácil
        enemigosMedia = FactoryEnemigos::crearEnemigo(rutaEnemigos, "Media"); // Cargar enemigos de dificultad media
        enemigosDificil = FactoryEnemigos::crearEnemigo(rutaEnemigos, "Dificil"); // Cargar enemigos de dificultad difícil
        ListMovInferiores::getInstancia()->agregarElemento(FactoryMovimientos::crearMovimientos(rutaMovimientosInferiores)); // Cargar movimientos inferiores
        ListMovSuperiores::getInstancia()->agregarElemento(FactoryMovimientos::crearMovimientos(rutaMovimientosSuperiores)); // Cargar movimientos superiores
        ZonaSuperior::getInstancia()->agregarElemento(FactoryZonas::crearZonas(rutaZonaSuperior)); // Cargar zonas superiores
        ZonaInferior::getInstancia()->agregarElemento(FactoryZonas::crearZonas(rutaZonaInferior)); // Cargar zonas inferiores


    } catch (const exception& e) {
        cout<<"Error al cargar los archivos, verifique que los archivos existan y tengan el formato correcto: "<<e.what()<<endl;
        exit(1); // Salir del programa si hay un error al cargar los archivos
    }
    enemigoActual = nullptr;
}
