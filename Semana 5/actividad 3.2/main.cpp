#include "Empleado.h"

int main() {
    
    Fecha nacimiento(15, 5, 1990);
    Fecha contratacion(1, 10, 2020);
    
    std::cout << "\n--- Creando empleado ---\n";
    Empleado emp("Ana Garcia", nacimiento, contratacion);
    
    std::cout << "\n--- Mostrando datos ---\n";
    emp.mostrar();
    
    std::cout << "\n--- Fin del programa (se destruirá emp) ---\n";
    
    return 0;
}
