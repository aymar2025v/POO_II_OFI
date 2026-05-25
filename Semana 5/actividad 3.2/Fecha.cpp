#include "Fecha.h"
#include <iostream>

Fecha::Fecha(int d, int m, int a) 
    : dia(d), mes(m), anio(a) {
    std::cout << "Constructor de Fecha: " << dia << "/" << mes << "/" << anio << std::endl;
}

Fecha::~Fecha() {
    std::cout << "Destructor de Fecha: " << dia << "/" << mes << "/" << anio << std::endl;
}

void Fecha::mostrar() const {
    std::cout << dia << "/" << mes << "/" << anio;
}
