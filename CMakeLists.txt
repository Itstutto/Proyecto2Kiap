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
        ZonaCuerpoBase.cpp
        ZonaCuerpoBase.h
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
)
