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

}

void Simulacion::zonaPelea(char tipo) {
    // elegir un personaje enemigo al azar de la dificultad correspondiente

    random_device rd;
    mt19937 motor(rd());
    uniform_int_distribution<int> distribucion(0,tipo == 'f' ? enemigosFacil.size()-1 : tipo == 'm' ? enemigosMedia.size()-1 : enemigosDificil.size()-1);

    enemigoActual == nullptr;
    int cantidad = 0;
    int seleccion;

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
            continue; // Si el movimiento es nulo, volver a mostrar el menú
        }
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

Movimiento* Simulacion::menuPersonajePrincipal() {
    cout<<personajePrincipal->getNombre()<<", Vida: "<<personajePrincipal->getVida()<<endl;

    cout<<"Elija una accion: "<<endl;
    cout<<"1. Atacar"<<endl;
    cout<<"2. Ver informacion del rival"<<endl;
    cout<<"Opcion: ";
    int opcion;
    cin>>opcion;
    switch (opcion) {
        case 1: {
            cout<<"Elija un movimiento: "<<endl;
            cout<<personajePrincipal->getMovimientos()<<endl;
            cout<<"Opcion: ";
            int opcionMovimiento;
            cin>>opcionMovimiento;
            // Validar que la opción sea un número válido
            if (cin.fail() || opcionMovimiento < 1 || opcionMovimiento > personajePrincipal->getMovimientos().size()) {
                cout << "Opción inválida. Por favor, ingrese un número entre 1 y " << personajePrincipal->getMovimientos().size() << "." << endl;
                cin.clear(); // Limpiar el estado de error
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar la entrada inválida
                return nullptr; // Salir del método para que el usuario pueda intentar de nuevo
            }

            return personajePrincipal->getMovimientoIndice(opcionMovimiento);
        }
        case 2: {
            cout<<"Informacion del rival: "<<endl;
            cout<<enemigoActual->mostrar()<<endl;
            return nullptr; // Volver al menú principal después de mostrar la información del rival
        }
        default:
            cout<<"Opcion no valida"<<endl;
            return nullptr;
    }

}
