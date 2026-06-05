cmake_minimum_required(VERSION 4.1)
project(Proyecto2Kiap)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyecto2Kiap main.cpp
        Personaje.cpp
        Personaje.h
        PersonajePrincipal.cpp
        PersonajePrincipal.h
        Movimientos.h
        PersonajeEnemigo.cpp
        PersonajeEnemigo.h
        Movimiento.cpp
        ZonaSuperior.cpp
        ZonaSuperior.h
        ZonasDelCuerpo.h
        IMostrar.h
        ZonaInferior.cpp
        ZonaInferior.h
        FactoryZonas.cpp
        FactoryZonas.h
        MovimientosSuperiores.cpp
        MovimientosSuperiores.h
        MovimientosInferiores.cpp
        MovimientosInferiores.h
        FactoryMovimientos.cpp
        FactoryMovimientos.h
        CreadorMovimientosSuperiores.h
        CrearMovimientos.h
        CreadorMovimientosInferiores.cpp
        CreadorMovimientosInferiores.h
        Vectores.cpp
        Vectores.h
        ListMovSuperiores.cpp
        ListMovSuperiores.h
        ListMovInferiores.cpp
        ListMovInferiores.h
        Pelea.cpp
        Pelea.h
        FactoryEnemigos.h
        Simulacion.cpp
        Simulacion.h
        CargaPersonajePrincipal.h
        ISerializar.h
)
