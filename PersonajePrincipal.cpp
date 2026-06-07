//
// Created by cesar on 1/6/2026.
//

#include "PersonajePrincipal.h"

#include "ListMovInferiores.h"

PersonajePrincipal::PersonajePrincipal(const string &nombre, char genero, double vida, int puntosCuracion, int puntosExperiencia) : Personaje(nombre, genero, vida) {

    if (nombre.empty()) {
        throw invalid_argument("El nombre del personaje principal no puede estar vacío");
    }
    if (genero != 'M' && genero != 'F' && genero != 'O') {
        throw invalid_argument("Género inválido: '" + string(1, genero) + "'. Debe ser M, F u O");
    }
    if (vida <= 0) {
        throw invalid_argument("La vida del personaje principal debe ser mayor a 0, recibido: " + to_string(vida));
    }
    this->puntosCuracion = puntosCuracion;
    this->puntosExperiencia = puntosExperiencia;
}

string PersonajePrincipal::getNombre() {
    return nombre;
}

int PersonajePrincipal::getPuntosCuracion() {
        return puntosCuracion;
}

int PersonajePrincipal::getPuntosExperiencia() {
    return puntosExperiencia;
}

void PersonajePrincipal::ganarExperiencia(int cantidad) {
    if (cantidad < 0) {
        throw invalid_argument("La cantidad de experiencia ganada no puede ser negativa: " + to_string(cantidad));
    }
    puntosExperiencia += cantidad;
}

void PersonajePrincipal::comprar(int cantidad) {
    if (cantidad < 0) {
        throw invalid_argument("La cantidad a comprar no puede ser negativa: " + to_string(cantidad));
    }
    if (cantidad>puntosExperiencia) {
        throw invalid_argument("No tienes suficientes puntos de experiencia para comprar esta cantidad de puntos de curación, te faltan " + to_string(cantidad-puntosExperiencia) + " puntos");
    }
    puntosExperiencia -= cantidad;
}

std::string PersonajePrincipal::mostrar(){
    stringstream s;
    s<<"---------Personaje Principal--------"<<endl
    <<"Nombre: "<<nombre<<endl
    <<"Genero: "<<(genero == 'M' ? "masculino" : genero == 'F' ? "Femenino" : "otro")<<endl
    <<"Vida: "<<vida<<endl
    <<nombre<<(vivo ? " sigue con vida" : " ya no sigue con vida :c")<<endl;
    return s.str();
}

bool PersonajePrincipal::sanar(int cantidad) {
    if (cantidad < 0) {
        throw invalid_argument("La cantidad de curación no puede ser negativa: " + to_string(cantidad));
    }

    if (puntosCuracion <= cantidad || cantidad <= 0) {
        return false; // No hay suficientes puntos de curación
    }
    vida+=cantidad;
    if (vida>100) {
        vida = 100;
    }
    puntosCuracion-=cantidad;
    return true;


}

void PersonajePrincipal::reiniciarEstadisticas() {
    Personaje::reiniciarEstadisticas();
    puntosCuracion = 0;
    puntosExperiencia = 0;
    movimientos.agregarElemento(ListMovInferiores::getInstancia()->getMovimiento("Ap Chagui", "Pie derecho"));
    movimientos.agregarElemento(ListMovInferiores::getInstancia()->getMovimiento("Ap Chagui", "Pie izquierdo"));
}

string PersonajePrincipal::serializar() {
    stringstream ss;
    ss<<nombre<<","<<genero<<","<<vida<<","<<puntosCuracion<<","<<puntosExperiencia<<endl;
    for (const auto& mov : movimientos.getElementos()) {
        ss << mov->getNombre() << "," << mov->getExtremidad()<<endl;
    }

    return ss.str();
}
