//
// Created by cesar on 3/6/2026.
//

#ifndef PROYECTO2KIAP_ZONACUERPOBASE_H
#define PROYECTO2KIAP_ZONACUERPOBASE_H
#include <iostream>
#include "ZonasDelCuerpo.h"
using namespace std;
class ZonaCuerpoBase : public  IMostrar {
private:
    vector<ZonaDelCuerpo*> zonas;
public:


    void agregarZona(ZonaDelCuerpo* zona);
    void agregarZona(vector<ZonaDelCuerpo*> zonas);

    vector<ZonaDelCuerpo*> getZonas();

    std::string mostrar() override;

};


#endif //PROYECTO2KIAP_ZONACUERPOBASE_H