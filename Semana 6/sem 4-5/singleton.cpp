

#include <iostream>
using namespace std;

class Config {

private:

    static Config* instance;

    string idioma;

    Config() {
        idioma = "Español";
    }

public:

    static Config* getInstance() {

        if (!instance)
            instance = new Config();

        return instance;
    }

    void setIdioma(string nuevoIdioma) {
        idioma = nuevoIdioma;
    }

    void mostrarIdioma() {
        cout << "Idioma: " << idioma << endl;
    }

    void showMessage() {
        cout << "Configuración global cargada.\n";
    }
};

Config* Config::instance = nullptr;

int main() {

    Config* obj1 = Config::getInstance();
    Config* obj2 = Config::getInstance();

    obj1->showMessage();

    // Comparar direcciones
    cout << "\nDirección obj1: " << obj1 << endl;
    cout << "Dirección obj2: " << obj2 << endl;

    // Verificar si son iguales
    cout << "\n¿Son iguales?: "
         << (obj1 == obj2) << endl;

    // Mostrar valor inicial
    cout << "\nValor inicial:\n";
    obj1->mostrarIdioma();

    // Cambiar desde obj1
    obj1->setIdioma("Inglés");

    // Ver desde obj2
    cout << "\nDespués del cambio:\n";
    obj2->mostrarIdioma();

    return 0;
}
