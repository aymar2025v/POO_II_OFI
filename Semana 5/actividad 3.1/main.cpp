
#include "Time.h"
#include <iostream>
using namespace std;

int main() {
    
    // Objeto no constante
    Time t1(10, 30, 45);
    cout << "t1 (no const): ";
    t1.printMilitary();
    cout << endl;

    t1.setHour(14);
    t1.printMilitary();
    cout << endl;

    // Objeto constante 
    const Time t2(23, 59, 58);
    
    cout << "\nt2 hora (getHour): " << t2.getHour() << endl;
    
    cout << "t2 (const): ";
    t2.printMilitary();
    cout << endl;

    // Esto NO compila: setHour no es const
    // t2.setHour(22);   // ERROR: passing 'const Time' as 'this' argument discards qualifiers

    // Esto NO compila: setMinute no es const
    // t2.setMinute(0);   // ERROR similar

    // Podemos leer todos los getters
    cout << "t2 minutos: " << t2.getMinute() << endl;
    cout << "t2 segundos: " << t2.getSecond() << endl;

    return 0;
}
