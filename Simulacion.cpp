//
// Created by cesar on 4/6/2026.
//

#include "Simulacion.h"

#include "LoadPlayer.h"
#include "EnemyCombat.h"
#include "PlayerCombat.h"
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
        ListMovInferiores::getInstancia()->agregarElemento(FactoryMovimientos::crearMovimientos(rutaMovimientosInferiores)); // Cargar movements inferiores
        ZonaSuperior::getInstancia()->agregarElemento(FactoryZonas::crearZonas(rutaZonaSuperior)); // Cargar zonas superiores
        ZonaInferior::getInstancia()->agregarElemento(FactoryZonas::crearZonas(rutaZonaInferior)); // Cargar zonas inferiores
        // Cargar personaje principal
        personajePrincipal = LoadPlayer::loadPlayer(rutaPersonajePrincipal);
        // Cargar enemigos
        enemigosFacil = FactoryEnemigos::crearEnemigo(rutaEnemigos, "Facil"); // Cargar enemigos de difficulty fácil
        enemigosMedia = FactoryEnemigos::crearEnemigo(rutaEnemigos, "Media"); // Cargar enemigos de difficulty media
        enemigosDificil = FactoryEnemigos::crearEnemigo(rutaEnemigos, "Dificil"); // Cargar enemigos de difficulty difícil



    } catch (const exception& e) {
        cout<<"Error al cargar los archivos, verifique que los archivos existan y tengan el formato correcto: "<<e.what()<<endl;
        exit(1); // Salir del programa si hay un error al cargar los archivos
    }
    enemigoActual = nullptr;
}



void Simulacion::ejecutarSimulacion() {
    menuInicial();
    int round = 1;


    while (personajePrincipal->isAlive() && round<=5) {
        cout<<"Round "<<round<<endl;
        char difficulty = round<3 ? 'f' : round <5 ? 'm' : 'd'; // Asignar difficulty según el round
        cout<<"Dificultad: "<<(difficulty == 'f' ? "Facil" : difficulty == 'm' ? "Media" : "Dificil")<<endl;
        zonaPelea(difficulty);
        round++;
        menuEntrePeleas();
    }

    if (personajePrincipal->isAlive()) {
        cout<<"Felicidades, has ganado la simulacion!"<<endl;
    } else {
        cout<<"Lo siento, has perdido la simulacion :c"<<endl;
    }
    Guardar::guardarPersonajePrincipal(personajePrincipal, rutaPersonajePrincipal);
    Guardar::guardarEnemigos(enemigosFacil, rutaEnemigos);
    Guardar::guardarEnemigos(enemigosMedia, rutaEnemigos);
    Guardar::guardarEnemigos(enemigosDificil, rutaEnemigos);


}

void Simulacion::menuInicial() {
    cout<<"Bienvenido a Kiap"<<endl;
    int option = 0;
    do {
        cout<<"Datos del personaje principal:"<<endl;
        cout<<personajePrincipal->mostrar() << endl;
        cout<<"1. Iniciar Combate"<<endl;
        cout<<"2. Cambiar Nombre"<<endl;
        cout<<"3. Cambiar Genero"<<endl;
        cout<<"4. Reiniciar estadisticas"<<endl;
        cin>>option;
        if (cin.fail()) {
            cout << "Entrada inválida. Por favor, ingrese un número entre 1 y 4." << endl;
            cin.clear(); // Limpiar el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar la entrada inválida
            continue;
        }
        switch (option) {
            case 1: {
                cout<<"Iniciando combate..."<<endl;
                break;
            }
            case 2: {
                string nuevoNombre;
                cout<<"Ingrese el nuevo name: ";
                cin>>nuevoNombre;
                try{
                    personajePrincipal->setName(nuevoNombre);
                    cout<<"Nombre cambiado exitosamente"<<endl;
                }catch (const invalid_argument& e) {
                    cout<<"Error al cambiar el name: "<<e.what()<<endl;
                    continue;
                }
                option = 0; // Reiniciar opción para mostrar el menú nuevamente
                break;
            }
            case 3: {
                char nuevoGenero;
                cout<<"Ingrese el nuevo gender (M/F/O): ";
                cin>>nuevoGenero;
                try {
                    personajePrincipal->setGender(nuevoGenero);
                    cout<<"Genero cambiado exitosamente"<<endl;
                }catch (const invalid_argument& e) {
                    cout<<"Error al cambiar el gender: "<<e.what()<<endl;
                    continue;
                }
                option = 0; // Reiniciar opción para mostrar el menú nuevamente
                break;
            }
            case 4: {
                personajePrincipal->resetStats();
                for (auto enemy : enemigosFacil) {
                    enemy->resetStats();
                }
                for (auto enemy : enemigosMedia) {
                    enemy->resetStats();
                }
                for (auto enemy : enemigosDificil) {
                    enemy->resetStats();
                }
                cout<<"Estadisticas reiniciadas exitosamente"<<endl;
                option = 0; // Reiniciar opción para mostrar el menú nuevamente
                break;
            }
            default: {
                cout << "Opción no válida. Por favor, ingrese un número entre 1 y 4." << endl;
                break;
            }
        }

    }while (option < 1 || option > 4);
}

void Simulacion::menuEntrePeleas() {
    int option = 0;
    while (option < 1 || option > 2) {
        cout<<"Elija una option: "<<endl;
        cout<<"1. Ir a la tienda"<<endl;
        cout<<"2. Continuar a la siguiente pelea"<<endl;
        cin>>option;
        if (cin.fail()) {
            cout << "Entrada inválida. Por favor, ingrese un número entre 1 y 2." << endl;
            cin.clear(); // Limpiar el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar la entrada inválida
            continue;
        }
        switch (option) {
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
    Player* pp = dynamic_cast<Player*>(personajePrincipal);
    if (!pp) {
        cout<<"Hey! La tienda solo es para el personaje principal, intruso >:c"<<endl;
        return;
    }
    vector<Movimiento*> movimientosDisponibles = ListMovInferiores::getInstancia()->getElementos();
    int option = 0;
    cout<<"Bienvenido a la tienda, elija que movimiento desea buy"<<endl;
    while (option < 1 || option > movimientosDisponibles.size()) {
        Player* pp = dynamic_cast<Player*>(personajePrincipal);
        if (!pp) {
            cout<<"Usted no es un personaje principal, jale de aqui"<<endl;
            break;
        }
        cout<<"Tienes "<<pp->getExpPoints()<<" puntos de experiencia"<<endl;
        int index = 1;
        for (auto x : movimientosDisponibles) {
            cout<<index++<<") "<<x->mostrar()<<(personajePrincipal->canMakeMove(x) ? " (Ya lo tienes)" : "")<<endl;
        }
        cout<<index<<") Salir de la tienda"<<endl;
        cout<<"Opcion: ";
        cin>>option;
        if (cin.fail() || option < 1 || option > movimientosDisponibles.size()+1) {
            cout << "Opción inválida. Por favor, ingrese un número entre 1 y " << movimientosDisponibles.size()+1 << "." << endl;
            cin.clear(); // Limpiar el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar la entrada inválida
            continue;
        }
        if (option == movimientosDisponibles.size()+1) {
            cout<<"Saliendo de la tienda..."<<endl;
            break;
        }
        if (personajePrincipal->canMakeMove(movimientosDisponibles[option-1])) {
            cout<<"Ya tienes ese movimiento, elige other"<<endl;
            option = 0;
            continue;
        }
        if (pp->getExpPoints() < movimientosDisponibles[option-1]->getCosto()) {
            cout<<"No tienes suficientes puntos de experiencia para buy este movimiento, sigue peleando para ganar mas puntos"<<endl;
            option = 0;
            continue;
        }

        personajePrincipal->addMovement(movimientosDisponibles[option-1]->getName(), movimientosDisponibles[option-1]->getExtremidad());
        pp->buy(movimientosDisponibles[option-1]->getCosto());
        cout<<"Has comprado el movimiento "<<movimientosDisponibles[option-1]->getName()<<", te quedan "<<pp->getExpPoints()<<" puntos de experiencia"<<endl;
    }
}


void Simulacion::zonaPelea(char tipo) {
    // elegir un personaje enemy al azar de la difficulty correspondiente

    random_device rd;
    mt19937 engine(rd());
    uniform_int_distribution<int> distribucion(0,tipo == 'f' ? (enemigosFacil.size()-1 ): tipo == 'm' ? (enemigosMedia.size()-1) : (enemigosDificil.size()-1));
    uniform_int_distribution<int> expPoints(20,35);
    enemigoActual = nullptr;
    int amount = 0;
    int seleccion = 0;

    vector<Character*> enemigos = tipo == 'f' ? enemigosFacil : tipo == 'm' ? enemigosMedia : enemigosDificil;

    while (!enemigoActual) {
        seleccion = distribucion(engine);
        if (enemigos[seleccion]->isAlive()) {
            enemigoActual = enemigos[seleccion];
            break;
        }
        amount++;
        if (amount>enemigos.size()*2) {
            throw runtime_error("No hay enemigos vivos en esta difficulty");
        }
    }

    cout<<"Acaba de iniciar una pelea contra "<<enemigoActual->getName()<<endl;

    while (personajePrincipal->isAlive() && enemigoActual->isAlive()) {
        gestorCombates.setEstrategia(new PlayerCombat());
        Movimiento* mov = gestorCombates.executeStrategy(personajePrincipal, enemigoActual);
        if (!mov) {
            cout<<"Has decidido curarte en este turno"<<endl;
        }
        else {
            cout<<Pelea::pelear(personajePrincipal, mov, enemigoActual);
        }
        if (!enemigoActual->isAlive()) {
            cout<<"Has derrotado a "<<enemigoActual->getName()<<", ganando 20 puntos de experiencia"<<endl;
            break;
        }
        gestorCombates.setEstrategia(new EnemyCombat());
        mov = gestorCombates.executeStrategy(enemigoActual, personajePrincipal);
        if (!mov) {
            cout<<enemigoActual->getName()<<" ha decidido curarse en este turno"<<endl;
        }
        else {
            cout << Pelea::pelear(enemigoActual, mov, personajePrincipal);
        }

    }
    if (personajePrincipal->isAlive()) {
        cout<<"Has ganado la pelea contra "<<enemigoActual->getName()<<endl;
        Player* pp = dynamic_cast<Player*>(personajePrincipal);
        if (!pp) {
            cout<<"Error al otorgar experiencia, usted no es personaje principal tramposo"<<endl;
            return;
        }
        int experienciaGanada = expPoints(engine);
        pp->gainExp(experienciaGanada);
        cout<<"Has ganado "<<experienciaGanada<<" puntos de experiencia"<<endl;
    } else {
        cout<<"Has perdido la pelea contra "<<enemigoActual->getName()<<endl;
    }

}


