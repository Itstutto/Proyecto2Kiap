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
        PersonajeEnemigo.h)
