
#include <iostream>

class Tiempo {
private:
    int hora, minuto, segundo;

public:
    Tiempo(int h = 0, int m = 0, int s = 0) : hora(h), minuto(m), segundo(s) {}

    // Cada método set retorna una referencia al objeto actual (*this)
    Tiempo& setHora(int h) {
        if (h >= 0 && h < 24)
            hora = h;
        else
            hora = 0;
        return *this;   // Devuelve el objeto actual por referencia
    }

    Tiempo& setMinuto(int m) {
        if (m >= 0 && m < 60)
            minuto = m;
        else
            minuto = 0;
        return *this;
    }

    Tiempo& setSegundo(int s) {
        if (s >= 0 && s < 60)
            segundo = s;
        else
            segundo = 0;
        return *this;
    }

    void mostrar() const {
        std::cout << hora << ":" << minuto << ":" << segundo << std::endl;
    }
};

int main() {
    Tiempo t;

    // Encadenamiento de llamadas
    t.setHora(10).setMinuto(30).setSegundo(15);
    t.mostrar();   // 10:30:15

    // También se puede encadenar la propia muestra si mostrar retornara *this,
    // pero no es necesario.

    return 0;
}
