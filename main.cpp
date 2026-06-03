#include <iostream>

#include "Personaje.h"
#include "PersonajeEnemigo.h"
#include "PersonajePrincipal.h"
using namespace std;
int main() {
    Personaje* p1 = new PersonajePrincipal("Fernanda",'F');

    p1->daniar(15);
    cout<<p1->getInfo()<<endl;
    p1->daniar(100);
    cout<<p1->getInfo()<<endl;

    Personaje* p2 = new PersonajeEnemigo("Cesar",'M');
    p2->daniar(20);
    cout<<p2->getInfo()<<endl;
    p2->daniar(100);
    cout<<p2->getInfo()<<endl;

    return 0;
}