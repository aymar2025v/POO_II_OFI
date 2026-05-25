
#ifndef FECHA_H
#define FECHA_H

#include <iostream>

class Fecha {
public:
    // Constructor con valores por defecto
    Fecha(int dia = 1, int mes = 1, int anio = 2000);
    
    // Destructor (para observar el orden)
    ~Fecha();
    
    void mostrar() const;
    
private:
    int dia, mes, anio;
};

#endif
