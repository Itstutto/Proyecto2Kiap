//
// Created by cesar on 4/6/2026.
//

#ifndef PROYECTO2KIAP_VECTORES_H
#define PROYECTO2KIAP_VECTORES_H
#include "IMostrar.h"
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
template <typename T>
class Vectores : public IMostrar{
protected:
    vector<T*> elementos;
public:
    void agregarElemento(T* elemento) {

        for (const auto x : elementos) {
            if (x == elemento) {
                throw invalid_argument("Ya existe un elemento con ese name");
            }
        }
        T* copia = new T(*elemento); // Crear una copia independiente en el heap
        elementos.push_back(copia);
    }
    void agregarElemento(vector<T*> elementos) {
        for (const auto x : elementos) {
            agregarElemento(x);
        }
    }


    T* getElemento(const string& name) {
        for (const auto x : elementos) {
            if (x->getName() == name) {
                return x;
            }
        }
        throw invalid_argument("No existe un elemento con ese name");
    }

    vector<T*> getElementos() {
        vector<T*> copia;
        copia.reserve(elementos.size());
        for (const auto z : elementos) {
            if (z) {
                // crea una copia independiente en el heap
                copia.push_back(new T(*z));
            } else {
                copia.push_back(nullptr);
            }
        }
        return copia;
    }

    std::string mostrar() override {
        stringstream s;
        int cant = 1;
        for (const auto x : elementos) {
            s<<cant++<<". "<<x->mostrar();
        }

        return s.str();
    }

    void vaciar() {
        for (auto& elemento : elementos) {
            delete elemento; // Liberar memoria de cada elemento
        }
        elementos.clear(); // Limpiar el vector
    }
};


#endif //PROYECTO2KIAP_VECTORES_H