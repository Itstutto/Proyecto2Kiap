//
// Created by cesar on 4/6/2026.
//

#ifndef PROYECTO2KIAP_LISTMOVINFERIORES_H
#define PROYECTO2KIAP_LISTMOVINFERIORES_H
#include "Vectors.h"
#include "Movement.h"

class LowerMovList : public Vectors<Movement> {
private:
    static LowerMovList* instance;
    LowerMovList() = default;
public:
    LowerMovList(const LowerMovList&) = delete;
    LowerMovList& operator=(const LowerMovList&) = delete;

    Movement* getMovement(const string& name, const string& zone) {

        for (const auto x : elements) {

            if (x->getName() == name && x->getLimb() == zone) {
                return x;
            }
        }
        throw invalid_argument("No existe un movimiento con ese nombre y zona");
    }

    static LowerMovList* getInstance();
};


#endif //PROYECTO2KIAP_LISTMOVINFERIORES_H