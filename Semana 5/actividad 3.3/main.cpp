


#include <iostream>

class Contador {
	// Declaración de función amiga (friend)
	friend void modificarX(Contador& c, int nuevoValor);

public:
	Contador() : x(0) {}

	void mostrar() const {
		std::cout << "Valor de x: " << x << std::endl;
	}

private:
	int x;  // variable privada
};

// Definición de la función amiga
// Puede acceder directamente a x (privado) porque es friend
void modificarX(Contador& c, int nuevoValor) {
	c.x = nuevoValor;   // Acceso directo a miembro privado
}

int main() {
	Contador cont;
	cont.mostrar();          // Valor de x: 0
	modificarX(cont, 42);    // Modificación mediante friend
	cont.mostrar();          // Valor de x: 42

	// No se puede acceder a cont.x directamente desde main (error de compilación)
	// cont.x = 10;   // ERROR: 'int Contador::x' is private within this context

	return 0;
}
