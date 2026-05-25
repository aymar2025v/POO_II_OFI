
#include "Empleado.h"
#include <iostream>

// Observa la lista de inicialización: primero se construyen los miembros (fechaNacimiento, fechaContratacion)
// en el orden en que se declaran en la clase (no en el orden de la lista).

Empleado::Empleado(const std::string& nom, const Fecha& nac, const Fecha& cont)
	: nombre(nom), fechaNacimiento(nac), fechaContratacion(cont) {
	std::cout << "Constructor de Empleado: " << nombre << std::endl;
}

Empleado::~Empleado() {
	std::cout << "Destructor de Empleado: " << nombre << std::endl;
}

void Empleado::mostrar() const {
	std::cout << "Empleado: " << nombre << "\n";
	std::cout << "  Fecha nacimiento: ";
	fechaNacimiento.mostrar();
	std::cout << "\n  Fecha contratacion: ";
	fechaContratacion.mostrar();
	std::cout << std::endl;
}
