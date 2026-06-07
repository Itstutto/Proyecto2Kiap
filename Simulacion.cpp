//
// Created by cesar on 4/6/2026.
//

#include "Simulacion.h"

#include "CargaPersonajePrincipal.h"
#include "FactoryEnemigos.h"
#include "FactoryMovimientos.h"
#include "FactoryZonas.h"
#include "ListMovInferiores.h"
#include "Pelea.h"
#include "ZonaInferior.h"

Simulacion::Simulacion() {
    // Inicializar rutas de archivos
    rutaPersonajePrincipal = "personaje_principal.txt";
    rutaEnemigos = "enemigos.txt";
    rutaMovimientosInferiores = "movimientos_inferiores.txt";
    rutaZonaSuperior = "zona_superior.txt";
    rutaZonaInferior = "zona_inferior.txt";
    try {
        ListMovInferiores::getInstancia()->agregarElemento(FactoryMovimientos::crearMovimientos(rutaMovimientosInferiores)); // Cargar movimientos inferiores
        ZonaSuperior::getInstancia()->agregarElemento(FactoryZonas::crearZonas(rutaZonaSuperior)); // Cargar zonas superiores
        ZonaInferior::getInstancia()->agregarElemento(FactoryZonas::crearZonas(rutaZonaInferior)); // Cargar zonas inferiores
        // Cargar personaje principal
        personajePrincipal = CargaPersonajePrincipal::cargarPersonaje(rutaPersonajePrincipal);
        // Cargar enemigos
        enemigosFacil = FactoryEnemigos::crearEnemigo(rutaEnemigos, "Facil"); // Cargar enemigos de dificultad fácil
        enemigosMedia = FactoryEnemigos::crearEnemigo(rutaEnemigos, "Media"); // Cargar enemigos de dificultad media
        enemigosDificil = FactoryEnemigos::crearEnemigo(rutaEnemigos, "Dificil"); // Cargar enemigos de dificultad difícil



    } catch (const exception& e) {
        cout<<"Error al cargar los archivos, verifique que los archivos existan y tengan el formato correcto: "<<e.what()<<endl;
        exit(1); // Salir del programa si hay un error al cargar los archivos
    }
    enemigoActual = nullptr;
}

void Simulacion::ejecutarSimulacion() {
    int round = 1;


    while (personajePrincipal->isVivo() && round<=5) {
        cout<<"Round "<<round<<endl;
        char dificultad = round<3 ? 'f' : round <5 ? 'm' : 'd'; // Asignar dificultad según el round
        cout<<"Dificultad: "<<(dificultad == 'f' ? "Facil" : dificultad == 'm' ? "Media" : "Dificil")<<endl;
        zonaPelea(dificultad);
        round++;
    }

}

void Simulacion::zonaPelea(char tipo) {
    // elegir un personaje enemigo al azar de la dificultad correspondiente

    random_device rd;
    mt19937 motor(rd());
    uniform_int_distribution<int> distribucion(0,tipo == 'f' ? (enemigosFacil.size()-1 ): tipo == 'm' ? (enemigosMedia.size()-1) : (enemigosDificil.size()-1));

    enemigoActual = nullptr;
    int cantidad = 0;
    int seleccion = 0;

    vector<Personaje*> enemigos = tipo == 'f' ? enemigosFacil : tipo == 'm' ? enemigosMedia : enemigosDificil;

    while (!enemigoActual) {
        seleccion = distribucion(motor);
        if (enemigos[seleccion]->isVivo()) {
            enemigoActual = enemigos[seleccion];
            break;
        }
        cantidad++;
        if (cantidad>enemigos.size()*2) {
            throw runtime_error("No hay enemigos vivos en esta dificultad");
        }
    }

    cout<<"Acaba de iniciar una pelea contra "<<enemigoActual->getNombre()<<endl;

    while (personajePrincipal->isVivo() && enemigoActual->isVivo()) {
        Movimiento* mov = menuPersonajePrincipal();
        if (!mov) {
            cout<<"Has decidido curarte en este turno"<<endl;
        }
        else {
            cout<<Pelea::pelear(personajePrincipal, mov, enemigoActual);
            if (enemigoActual->isVivo()) {
                // El enemigo ataca de vuelta con un movimiento aleatorio
                if (enemigoActual->getCantidadMovimientos() > 0) {
                    uniform_int_distribution<int> ataque(1, enemigoActual->getCantidadMovimientos());
                    Movimiento* movEnemigo = enemigoActual->getMovimientoIndice(ataque(motor));
                    cout << Pelea::pelear(enemigoActual, movEnemigo, personajePrincipal);
                }
            }
        }
    }
    if (personajePrincipal->isVivo()) {
        cout<<"Has ganado la pelea contra "<<enemigoActual->getNombre()<<endl;
    } else {
        cout<<"Has perdido la pelea contra "<<enemigoActual->getNombre()<<endl;
    }

}

Movimiento* Simulacion::menuPersonajePrincipal() {
    cout<<personajePrincipal->getNombre()<<", Vida: "<<personajePrincipal->getVida()<<endl;

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
                cout<<personajePrincipal->getMovimientos()<<endl;
                int opcionMovimiento = -1;
                while (opcionMovimiento < 1 || opcionMovimiento > personajePrincipal->getCantidadMovimientos()) {
                    cout<<"Opcion: ";
                    cin>>opcionMovimiento;
                    // Validar que la opción sea un número válido
                    if (cin.fail() || opcionMovimiento < 1 || opcionMovimiento > personajePrincipal->getMovimientos().size()) {
                        cout << "Opción inválida. Por favor, ingrese un número entre 1 y " << personajePrincipal->getMovimientos().size() << "." << endl;
                        cin.clear(); // Limpiar el estado de error
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar la entrada inválida
                    }
                }
                return personajePrincipal->getMovimientoIndice(opcionMovimiento);
            }
            case 2: {
                cout<<"Informacion del rival: "<<endl;
                cout<<enemigoActual->mostrar()<<endl;
            }
            case 3: {

                PersonajePrincipal* pp = dynamic_cast<PersonajePrincipal*>(personajePrincipal);
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
