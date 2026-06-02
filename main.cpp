#include <iostream>

#include "Personaje.h"
#include "PersonajePrincipal.h"
using namespace std;
int main() {
    Personaje* p1 = new PersonajePrincipal("Fernanda",'F');

    p1->daniar(15);
    cout<<p1->getInfo()<<endl;
    p1->daniar(100);
    cout<<p1->getInfo()<<endl;

    return 0;
}