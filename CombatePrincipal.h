//
// Created by cesar on 6/6/2026.
//

#ifndef PROYECTO2KIAP_COMBATEPRINCIPAL_H
#define PROYECTO2KIAP_COMBATEPRINCIPAL_H
#include "EstrategiaCombate.h"
#include "Player.h"


class CombatePrincipal : public EstrategiaCombate{
public:
    ~CombatePrincipal() override = default;
    Movimiento* ejecutarEstrategia(Character* p, Character* c) override {
        cout<<p->getName()<<", Vida: "<<p->getHealth()<<endl;

        cout<<"Elija una accion: "<<endl;


        int opcion = 0;
        while (opcion < 1 || opcion > 3) {
            cout<<"1. Atacar"<<endl;
            cout<<"2. Ver informacion del rival"<<endl;
            cout<<"Opcion: ";
            cin >> opcion;
            if (cin.fail()) {
                cout << "Entrada inválida. Por favor, ingrese un número entre 1 y 2." << endl;
                cin.clear(); // Limpiar el estado de error
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar la entrada inválida
                continue;
            } else if (opcion < 1 || opcion > 3) {
                cout << "Opción no válida. Por favor, ingrese un número entre 1 y 2." << endl;
                continue;
            }



            switch (opcion) {
                case 1: {
                    cout<<"Elija un movimiento: "<<endl;
                    cout<<p->getMovements()<<endl;
                    int opcionMovimiento = -1;
                    while (opcionMovimiento < 1 || opcionMovimiento > p->getAmountMovements()) {
                        cout<<"Opcion: ";
                        cin>>opcionMovimiento;
                        // Validar que la opción sea un número válido
                        if (cin.fail() || opcionMovimiento < 1 || opcionMovimiento > p->getMovements().size()) {
                            cout << "Opción inválida. Por favor, ingrese un número entre 1 y " << p->getMovements().size() << "." << endl;
                            cin.clear(); // Limpiar el estado de error
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar la entrada inválida
                        }
                    }
                    return p->getIndexMovement(opcionMovimiento);
                }
                case 2: {
                    cout<<"Informacion del rival: "<<endl;
                    cout<<c->mostrar()<<endl;
                    opcion = 0;
                    break;
                }
                case 3: {

                    Player* pp = dynamic_cast<Player*>(p);
                    if (pp) {
                        cout<<"Puntos de curacion disponibles: "<<pp->getHealPoints()<<endl;
                        cout<<"Vida: "<<pp->getHealth()<<endl;
                        cout<<"Ingrese la amount de puntos de curacion a usar: ";
                        int healPoints = 0;
                        try {
                            cin>>healPoints;
                            if (cin.fail()){
                                throw invalid_argument("Entrada inválida. Por favor, ingrese un número entero para los puntos de curación.");
                            }
                            pp->heal(healPoints);

                        }catch (const invalid_argument& e) {
                            cout<<"No se ingreso un numero valido"<<endl;
                            cin.clear(); // Limpiar el estado de error
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
                        }
                        return nullptr; // No se realiza un movimiento, solo se cura
                    } else {
                        cout<<"Error: No se pudo acceder a los puntos de curación del personaje principal."<<endl;
                        continue;
                    }

                }
                default:
                    cout<<"Opcion no valida"<<endl;
            }
        }
        return nullptr;

    }
};


#endif //PROYECTO2KIAP_COMBATEPRINCIPAL_H