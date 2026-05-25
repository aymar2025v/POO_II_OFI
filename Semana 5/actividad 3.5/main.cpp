

#include "Empleado.h"
#include <iostream>

int main() {
    // Crear objetos Fecha en el stack (locales)
    Fecha nacimiento(15, 5, 1990);
    Fecha contratacion(1, 10, 2020);

    std::cout << "\n--- Creando empleado dinámicamente con new ---\n";
    // Asigna memoria en el heap para un objeto Empleado
    Empleado* empPtr = new Empleado("Carlos Lopez", nacimiento, contratacion);

    std::cout << "\n--- Mostrando empleado desde el puntero ---\n";
    empPtr->mostrar();

    std::cout << "\n--- Liberando memoria con delete ---\n";
    delete empPtr;   // Llama al destructor de Empleado y libera la memoria

    std::cout << "\n--- Fin del programa ---\n";
    return 0;
}
