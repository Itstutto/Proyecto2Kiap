//
// Created by cesar on 4/6/2026.
//

#include "Simulation.h"

#include "LoadPlayer.h"
#include "EnemyCombat.h"
#include "PlayerCombat.h"
#include "EnemyFactory.h"
#include "MovementsFactory.h"
#include "ZonesFactory.h"
#include "LowerMovList.h"
#include "Fight.h"
#include "LowerZone.h"

Simulation::Simulation() {
    // Initialize file paths
    player1Path = "personaje_principal.txt";
    enemiesPath = "enemies.txt";
    movementsPath = "movimientos_inferiores.txt";
    upperZonePath = "zona_superior.txt";
    lowerZonePath = "zona_inferior.txt";
    try {
        LowerMovList::getInstance()->addElement(MovementsFactory::createMovements(movementsPath)); //Load lower file movements
        UpperZone::getInstance()->addElement(ZonesFactory::createZones(upperZonePath)); // Load upper zones
        LowerZone::getInstance()->addElement(ZonesFactory::createZones(lowerZonePath)); // Load lower zones
        // Cargar personaje principal
        player1 = LoadPlayer::loadPlayer(player1Path);
        // Cargar enemies
        easyEnemies = EnemyFactory::createEnemy(enemiesPath, "Facil"); // Load enemies of easy difficulty
        mediumEnemies = EnemyFactory::createEnemy(enemiesPath, "Media"); // Load medium difficulty enemies
        hardEnemies = EnemyFactory::createEnemy(enemiesPath, "Dificil"); // Load enemies of hard difficulty



    } catch (const exception& e) {
        cout<<"Error al cargar los archivos, verifique que los archivos existan y tengan el formato correcto: "<<e.what()<<endl;
        exit(1); // Exit the program if there is an error loading the files.
    }
    actualEnemy = nullptr;
}

Simulation::~Simulation() {
    delete player1;
    for (auto enemy : easyEnemies) {
        delete enemy;
    }
    for (auto enemy : mediumEnemies) {
        delete enemy;
    }
    for (auto enemy : hardEnemies) {
        delete enemy;
    }

}


void Simulation::execSimulation() {
    starMenu();
    int round = 1;


    while (player1->isAlive() && round<=5) {
        cout<<"Round "<<round<<endl;
        char difficulty = round<3 ? 'f' : round <5 ? 'm' : 'd'; // Assign difficulty according to the round
        cout<<"Dificultad: "<<(difficulty == 'f' ? "Facil" : difficulty == 'm' ? "Media" : "Dificil")<<endl;
        fightZone(difficulty);
        Save::logBattle("battle_log.txt", player1, actualEnemy, round);
        round++;
        if (player1->isAlive()) {
            betweenFightsMenu();
        }
    }

    if (player1->isAlive()) {
        cout<<"Felicidades, has ganado la simulacion!"<<endl;
    } else {
        cout<<"Lo siento, has perdido la simulacion :c"<<endl;
    }
    Save::savePlayer(player1, player1Path);
    Save::saveEnemies(easyEnemies, enemiesPath);
    Save::saveEnemies(mediumEnemies, enemiesPath);
    Save::saveEnemies(hardEnemies, enemiesPath);


}

void Simulation::starMenu() {
    cout<<"Bienvenido a Kiap"<<endl;
    int option = 0;
    do {
        cout<<"Datos del personaje principal:"<<endl;
        cout<<player1->show() << endl;
        cout<<"1. Iniciar Combate"<<endl;
        cout<<"2. Cambiar Nombre"<<endl;
        cout<<"3. Cambiar Genero"<<endl;
        cout<<"4. Reiniciar estadisticas"<<endl;
        cin>>option;
        if (cin.fail()) {
            cout << "Entrada inválida. Por favor, ingrese un número entre 1 y 4." << endl;
            cin.clear(); // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Ignorar la entrada inválida
            continue;
        }
        switch (option) {
            case 1: {
                cout<<"Iniciando combate..."<<endl;
                break;
            }
            case 2: {
                string newName;
                cout<<"Ingrese el nuevo nombre: ";
                cin>>newName;
                try{
                    player1->setName(newName);
                    cout<<"Nombre cambiado exitosamente"<<endl;
                }catch (const invalid_argument& e) {
                    cout<<"Error al cambiar el nombre: "<<e.what()<<endl;
                    continue;
                }
                option = 0; // Reset option to show the menu again
                break;
            }
            case 3: {
                char newGender;
                cout<<"Ingrese el nuevo genero (M/F/O): ";
                cin>>newGender;
                try {
                    player1->setGender(newGender);
                    cout<<"Genero cambiado exitosamente"<<endl;
                }catch (const invalid_argument& e) {
                    cout<<"Error al cambiar el genero: "<<e.what()<<endl;
                    continue;
                }
                option = 0; // Reset option to show the menu again
                break;
            }
            case 4: {
                player1->resetStats();
                for (auto enemy : easyEnemies) {
                    enemy->resetStats();
                }
                for (auto enemy : mediumEnemies) {
                    enemy->resetStats();
                }
                for (auto enemy : hardEnemies) {
                    enemy->resetStats();
                }
                cout<<"Estadisticas reiniciadas exitosamente"<<endl;
                option = 0; // Reset option to show the menu again
                break;
            }
            default: {
                cout << "Opción no válida. Por favor, ingrese un número entre 1 y 4." << endl;
                break;
            }
        }

    }while (option < 1 || option > 4);
}

void Simulation::betweenFightsMenu() {
    int option = 0;
    while (option < 1 || option > 2) {
        cout<<"Elija una option: "<<endl;
        cout<<"1. Ir a la tienda"<<endl;
        cout<<"2. Continuar a la siguiente pelea"<<endl;
        cin>>option;
        if (cin.fail()) {
            cout << "Entrada inválida. Por favor, ingrese un número entre 1 y 2." << endl;
            cin.clear(); // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            continue;
        }
        switch (option) {
            case 1: {
                store();
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

void Simulation::store() {
    Player* pp = dynamic_cast<Player*>(player1);
    if (!pp) {
        cout<<"Hey! La tienda solo es para el personaje principal, intruso >:c"<<endl;
        return;
    }
    vector<Movement*> availableMovements = LowerMovList::getInstance()->getElements();
    int option = 0;
    cout<<"Bienvenido a la tienda, elija que movimiento desea comprar"<<endl;
    while (option < 1 || option > availableMovements.size()) {
        Player* pp = dynamic_cast<Player*>(player1);
        if (!pp) {
            cout<<"Usted no es un personaje principal, jale de aqui"<<endl;
            break;
        }
        cout<<"Tienes "<<pp->getExpPoints()<<" puntos de experiencia"<<endl;
        int index = 1;
        for (auto x : availableMovements) {
            cout<<index++<<") "<<x->show()<<(player1->canMakeMove(x) ? " (Ya lo tienes)" : "")<<endl;
        }
        cout<<index<<") Salir de la tienda"<<endl;
        cout<<"Opcion: ";
        cin>>option;
        if (cin.fail() || option < 1 || option > availableMovements.size()+1) {
            cout << "Opción inválida. Por favor, ingrese un número entre 1 y " << availableMovements.size()+1 << "." << endl;
            cin.clear(); // Limpiar el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar la entrada inválida
            continue;
        }
        if (option == availableMovements.size()+1) {
            cout<<"Saliendo de la tienda..."<<endl;
            break;
        }
        if (player1->canMakeMove(availableMovements[option-1])) {
            cout<<"Ya tienes ese movimiento, elige otro"<<endl;
            option = 0;
            continue;
        }
        if (pp->getExpPoints() < availableMovements[option-1]->getCost()) {
            cout<<"No tienes suficientes puntos de experiencia para comprar este movimiento, sigue peleando para ganar mas puntos"<<endl;
            option = 0;
            continue;
        }

        player1->addMovement(availableMovements[option-1]->getName(), availableMovements[option-1]->getLimb());
        pp->buy(availableMovements[option-1]->getCost());
        cout<<"Has comprado el movimiento "<<availableMovements[option-1]->getName()<<", te quedan "<<pp->getExpPoints()<<" puntos de experiencia"<<endl;
    }
}


void Simulation::fightZone(char type) {
    // elegir un personaje enemy al azar de la difficulty correspondiente

    random_device rd;
    mt19937 engine(rd());
    uniform_int_distribution<int> distribution(0,type == 'f' ? (easyEnemies.size()-1 ): type == 'm' ? (mediumEnemies.size()-1) : (hardEnemies.size()-1));
    uniform_int_distribution<int> expPoints(20,35);
    actualEnemy = nullptr;
    int amount = 0;
    int selection = 0;

    vector<Character*> enemies = type == 'f' ? easyEnemies : type == 'm' ? mediumEnemies : hardEnemies;

    while (!actualEnemy) {
        selection = distribution(engine);
        if (enemies[selection]->isAlive()) {
            actualEnemy = enemies[selection];
            break;
        }
        amount++;
        if (amount>enemies.size()*2) {
            throw runtime_error("No hay enemigos vivos en esta difficulty");
        }
    }

    cout<<"Acaba de iniciar una pelea contra "<<actualEnemy->getName()<<endl;

    while (player1->isAlive() && actualEnemy->isAlive()) {
        combatManager.setStrategy(new PlayerCombat());
        Movement* mov = combatManager.executeStrategy(player1, actualEnemy);
        if (!mov) {
            cout<<"Has decidido curarte en este turno"<<endl;
        }
        else {
            cout<<Fight::fight(player1, mov, actualEnemy);
        }
        if (!actualEnemy->isAlive()) {
            cout<<"Has derrotado a "<<actualEnemy->getName()<<", ganando 20 puntos de experiencia"<<endl;
            break;
        }
        combatManager.setStrategy(new EnemyCombat());
        mov = combatManager.executeStrategy(actualEnemy, player1);
        if (!mov) {
            cout<<actualEnemy->getName()<<" ha decidido curarse en este turno"<<endl;
        }
        else {
            cout << Fight::fight(actualEnemy, mov, player1);
        }

    }
    if (player1->isAlive()) {
        cout<<"Has ganado la pelea contra "<<actualEnemy->getName()<<endl;
        Player* pp = dynamic_cast<Player*>(player1);
        if (!pp) {
            cout<<"Error al otorgar experiencia, usted no es personaje principal tramposo"<<endl;
            return;
        }
        int experienciaGanada = expPoints(engine);
        pp->gainExp(experienciaGanada);
        cout<<"Has ganado "<<experienciaGanada<<" puntos de experiencia"<<endl;
        experienciaGanada = expPoints(engine);
        pp->gainHealP(experienciaGanada);
        cout<<"Has ganado"<<experienciaGanada<<" puntos de curacion"<<endl;
    } else {
        cout<<"Has perdido la pelea contra "<<actualEnemy->getName()<<endl;
    }

}


