

#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
#include "Fecha.h"

class Empleado {
public:

	// Constructor: recibe nombre y dos fechas (por copia o const&)
	Empleado(const std::string& nombre, const Fecha& fechaNac, const Fecha& fechaCont);

	// Destructor
	~Empleado();

	void mostrar() const;

private:

	std::string nombre;
	Fecha fechaNacimiento;
	Fecha fechaContratacion;
};

#endif
