//
// Created by cesar on 4/6/2026.
//

#ifndef PROYECTO2KIAP_VECTORES_H
#define PROYECTO2KIAP_VECTORES_H
#include "IShow.h"
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
template <typename T>
class Vectors : public IShow{
protected:
    vector<T*> elements;
public:
    ~Vectors() {
        for (auto& element : elements) {
            delete element; //Free up memory for each item.
        }
    }
    void addElement(T* element) {

        for (const auto x : elements) {
            if (x == element) {
                throw invalid_argument("Ya existe un elemento con ese nombre");
            }
        }
        T* copy = new T(*element); //Create a separate copy in the heap
        elements.push_back(copy);
    }
    void addElement(vector<T*> elements) {
        for (const auto x : elements) {
            addElement(x);
        }
    }


    T* getElement(const string& name) {
        for (const auto x : elements) {
            if (x->getName() == name) {
                return x;
            }
        }
        throw invalid_argument("No existe un elemento con ese nombre");
    }

    vector<T*> getElements() {
        vector<T*> copy;
        copy.reserve(elements.size());
        for (const auto z : elements) {
            if (z) {
                // creates a separate copy in the heap
                copy.push_back(new T(*z));
            } else {
                copy.push_back(nullptr);
            }
        }
        return copy;
    }

    std::string show() override {
        stringstream s;
        int amo = 1;
        for (const auto x : elements) {
            s<<amo++<<". "<<x->show();
        }

        return s.str();
    }

    void clear() {
        for (auto& element : elements) {
            delete element; //Free up memory for each item.
        }
        elements.clear(); //Clean the vector
    }
};


#endif //PROYECTO2KIAP_VECTORES_H