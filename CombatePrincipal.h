//
// Created by cesar on 6/6/2026.
//

#ifndef PROYECTO2KIAP_COMBATEPRINCIPAL_H
#define PROYECTO2KIAP_COMBATEPRINCIPAL_H
#include "EstrategiaCombate.h"
#include "PersonajePrincipal.h"


class CombatePrincipal : public EstrategiaCombate{
public:
    ~CombatePrincipal() override = default;
    Movimiento* ejecutarEstrategia(Personaje* p, Personaje* c) override {
        cout<<p->getNombre()<<", Vida: "<<p->getVida()<<endl;

        cout<<"Elija una accion: "<<endl;
        cout<<"1. Atacar"<<endl;
        cout<<"2. Ver informacion del rival"<<endl;

        int opcion = 0;
        while (opcion < 1 || opcion > 3) {
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
                    cout<<p->getMovimientos()<<endl;
                    int opcionMovimiento = -1;
                    while (opcionMovimiento < 1 || opcionMovimiento > p->getCantidadMovimientos()) {
                        cout<<"Opcion: ";
                        cin>>opcionMovimiento;
                        // Validar que la opción sea un número válido
                        if (cin.fail() || opcionMovimiento < 1 || opcionMovimiento > p->getMovimientos().size()) {
                            cout << "Opción inválida. Por favor, ingrese un número entre 1 y " << p->getMovimientos().size() << "." << endl;
                            cin.clear(); // Limpiar el estado de error
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar la entrada inválida
                        }
                    }
                    return p->getMovimientoIndice(opcionMovimiento);
                }
                case 2: {
                    cout<<"Informacion del rival: "<<endl;
                    cout<<c->mostrar()<<endl;
                }
                case 3: {

                    PersonajePrincipal* pp = dynamic_cast<PersonajePrincipal*>(p);
                    if (pp) {
                        cout<<"Puntos de curacion disponibles: "<<pp->getPuntosCuracion()<<endl;
                        cout<<"Vida: "<<pp->getVida()<<endl;
                        cout<<"Ingrese la cantidad de puntos de curacion a usar: ";
                        int puntosCuracion = 0;
                        try {
                            cin>>puntosCuracion;
                            if (cin.fail()){
                                throw invalid_argument("Entrada inválida. Por favor, ingrese un número entero para los puntos de curación.");
                            }
                            pp->sanar(puntosCuracion);

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