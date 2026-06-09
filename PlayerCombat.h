//
// Created by cesar on 6/6/2026.
//

#ifndef PROYECTO2KIAP_COMBATEPRINCIPAL_H
#define PROYECTO2KIAP_COMBATEPRINCIPAL_H
#include "CombatStrategy.h"
#include "Player.h"


class PlayerCombat : public CombatStrategy{
public:
    ~PlayerCombat() override = default;
    Movement* executeStrategy(Character* p, Character* c) override {
        cout<<p->getName()<<", Vida: "<<p->getHealth()<<endl;

        cout<<"Elija una accion: "<<endl;


        int option = 0;
        while (option < 1 || option > 3) {
            cout<<"1. Atacar"<<endl;
            cout<<"2. Ver informacion del rival"<<endl;
            cout<<"3. Curarse"<<endl;
            cout<<"Opcion: ";
            cin >> option;
            if (cin.fail()) {
                cout << "Entrada inválida. Por favor, ingrese un número entre 1 y 2." << endl;
                cin.clear(); // Clear the error state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                continue;
            } else if (option < 1 || option > 3) {
                cout << "Opción no válida. Por favor, ingrese un número entre 1 y 2." << endl;
                continue;
            }



            switch (option) {
                case 1: {
                    cout<<"Elija un movimiento: "<<endl;
                    cout<<p->getMovements()<<endl;
                    int movementOption = -1;
                    while (movementOption < 1 || movementOption > p->getAmountMovements()) {
                        cout<<"Opcion: ";
                        cin>>movementOption;
                        // Validate that the option is a valid number
                        if (cin.fail() || movementOption < 1 || movementOption > p->getMovements().size()) {
                            cout << "Opción inválida. Por favor, ingrese un número entre 1 y " << p->getMovements().size() << "." << endl;
                            cin.clear(); // Clear the error state
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                        }
                    }
                    return p->getIndexMovement(movementOption);
                }
                case 2: {
                    cout<<"Informacion del rival: "<<endl;
                    cout<<c->show()<<endl;
                    option = 0;
                    break;
                }
                case 3: {

                    Player* pp = dynamic_cast<Player*>(p);
                    if (pp) {
                        cout<<"Puntos de curacion disponibles: "<<pp->getHealPoints()<<endl;
                        cout<<"Vida: "<<pp->getHealth()<<endl;
                        cout<<"Ingrese la cantidad de puntos de curacion a usar: ";
                        int healPoints = 0;
                        try {
                            cin>>healPoints;
                            if (cin.fail()){
                                throw invalid_argument("Entrada inválida. Por favor, ingrese un número entero para los puntos de curación.");
                            }
                            pp->heal(healPoints);

                        }catch (const invalid_argument& e) {
                            cout<<"No se ingreso un numero valido"<<endl;
                            cin.clear(); // Clear the error state
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
                        }
                        return nullptr; // No movement is made, only healing occurs.
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