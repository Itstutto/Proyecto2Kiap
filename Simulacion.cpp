//
// Created by cesar on 4/6/2026.
//

#include "Simulacion.h"

#include "CargaPersonajePrincipal.h"
#include "CombateEnemigo.h"
#include "CombatePrincipal.h"
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
        menuEntrePeleas();
    }

}

void Simulacion::menuEntrePeleas() {
    int opcion = 0;
    while (opcion < 1 || opcion > 2) {
        cout<<"Elija una opcion: "<<endl;
        cout<<"1. Ir a la tienda"<<endl;
        cout<<"2. Continuar a la siguiente pelea"<<endl;
        cin>>opcion;
        if (cin.fail()) {
            cout << "Entrada inválida. Por favor, ingrese un número entre 1 y 2." << endl;
            cin.clear(); // Limpiar el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar la entrada inválida
            continue;
        }
        switch (opcion) {
            case 1: {
                tienda();
                break;
            }
            case 2: {
                cout<<"Continuando a la siguiente pelea..."<<endl;
                break;
            }
            default: {
                cout << "Opción no válida. Por favor, ingrese un número entre 1 y 2." << endl;
                break;
            }
        }
    }

}

void Simulacion::tienda() {
    PersonajePrincipal* pp = dynamic_cast<PersonajePrincipal*>(personajePrincipal);
    if (!pp) {
        cout<<"Hey! La tienda solo es para el personaje principal, intruso >:c"<<endl;
        return;
    }
    vector<Movimiento*> movimientosDisponibles = ListMovInferiores::getInstancia()->getElementos();
    int opcion = 0;
    cout<<"Bienvenido a la tienda, elija que movimiento desea comprar"<<endl;
    while (opcion < 1 || opcion > movimientosDisponibles.size()) {
        PersonajePrincipal* pp = dynamic_cast<PersonajePrincipal*>(personajePrincipal);
        if (!pp) {
            cout<<"Usted no es un personaje principal, jale de aqui"<<endl;
            break;
        }
        cout<<"Tienes "<<pp->getPuntosExperiencia()<<" puntos de experiencia"<<endl;
        int indice = 1;
        for (auto x : movimientosDisponibles) {
            cout<<indice++<<") "<<x->mostrar()<<(personajePrincipal->puedeRealizarMovimiento(x) ? " (Ya lo tienes)" : "")<<endl;
        }
        cout<<indice<<") Salir de la tienda"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;
        if (cin.fail() || opcion < 1 || opcion > movimientosDisponibles.size()+1) {
            cout << "Opción inválida. Por favor, ingrese un número entre 1 y " << movimientosDisponibles.size()+1 << "." << endl;
            cin.clear(); // Limpiar el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar la entrada inválida
            continue;
        }
        if (opcion == movimientosDisponibles.size()+1) {
            cout<<"Saliendo de la tienda..."<<endl;
            break;
        }
        if (personajePrincipal->puedeRealizarMovimiento(movimientosDisponibles[opcion-1])) {
            cout<<"Ya tienes ese movimiento, elige otro"<<endl;
            opcion = 0;
            continue;
        }
        if (pp->getPuntosExperiencia() < movimientosDisponibles[opcion-1]->getCosto()) {
            cout<<"No tienes suficientes puntos de experiencia para comprar este movimiento, sigue peleando para ganar mas puntos"<<endl;
            opcion = 0;
            continue;
        }

        personajePrincipal->agregarMovimiento(movimientosDisponibles[opcion-1]->getNombre(), movimientosDisponibles[opcion-1]->getExtremidad());
        pp->comprar(movimientosDisponibles[opcion-1]->getCosto());
        cout<<"Has comprado el movimiento "<<movimientosDisponibles[opcion-1]->getNombre()<<", te quedan "<<pp->getPuntosExperiencia()<<" puntos de experiencia"<<endl;
    }
}


void Simulacion::zonaPelea(char tipo) {
    // elegir un personaje enemigo al azar de la dificultad correspondiente

    random_device rd;
    mt19937 motor(rd());
    uniform_int_distribution<int> distribucion(0,tipo == 'f' ? (enemigosFacil.size()-1 ): tipo == 'm' ? (enemigosMedia.size()-1) : (enemigosDificil.size()-1));
    uniform_int_distribution<int> puntosExperiencia(20,35);
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
        gestorCombates.setEstrategia(new CombatePrincipal());
        Movimiento* mov = gestorCombates.ejecutarEstrategia(personajePrincipal, enemigoActual);
        if (!mov) {
            cout<<"Has decidido curarte en este turno"<<endl;
        }
        else {
            cout<<Pelea::pelear(personajePrincipal, mov, enemigoActual);
        }
        if (!enemigoActual->isVivo()) {
            cout<<"Has derrotado a "<<enemigoActual->getNombre()<<", ganando 20 puntos de experiencia"<<endl;
            break;
        }
        gestorCombates.setEstrategia(new CombateEnemigo());
        mov = gestorCombates.ejecutarEstrategia(enemigoActual, personajePrincipal);
        if (!mov) {
            cout<<enemigoActual->getNombre()<<" ha decidido curarse en este turno"<<endl;
        }
        else {
            cout << Pelea::pelear(enemigoActual, mov, personajePrincipal);
        }

    }
    if (personajePrincipal->isVivo()) {
        cout<<"Has ganado la pelea contra "<<enemigoActual->getNombre()<<endl;
        PersonajePrincipal* pp = dynamic_cast<PersonajePrincipal*>(personajePrincipal);
        if (!pp) {
            cout<<"Error al otorgar experiencia, usted no es personaje principal tramposo"<<endl;
            return;
        }
        int experienciaGanada = puntosExperiencia(motor);
        pp->ganarExperiencia(experienciaGanada);
        cout<<"Has ganado "<<experienciaGanada<<" puntos de experiencia"<<endl;
    } else {
        cout<<"Has perdido la pelea contra "<<enemigoActual->getNombre()<<endl;
    }

}


