#include <iostream>
#include <vector>
using namespace std;

// STRATEGY
class Ordenamiento {
public:
    virtual void ordenar(vector<int>& datos) = 0;
};

class Burbuja : public Ordenamiento {
public:

    void ordenar(vector<int>& datos) override {
        int n = datos.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (datos[j] > datos[j + 1]) {
                    int temp = datos[j];
                    datos[j] = datos[j + 1];
                    datos[j + 1] = temp;
                }
            }
        }
        cout << "Ordenado con Burbuja" << endl;
    }
};

class QuickSort : public Ordenamiento {
private:

    void quicksort(vector<int>& datos, int inicio, int fin) {

        if (inicio >= fin) {
            return;
        }
        int pivote = datos[fin];
        int i = inicio - 1;

        for (int j = inicio; j < fin; j++) {
            if (datos[j] < pivote) {
                i++;
                int temp = datos[i];
                datos[i] = datos[j];
                datos[j] = temp;
            }
        }

        int temp = datos[i + 1];
        datos[i + 1] = datos[fin];
        datos[fin] = temp;

        int posicion = i + 1;

        quicksort(datos, inicio, posicion - 1);
        quicksort(datos, posicion + 1, fin);
    }

public:

    void ordenar(vector<int>& datos) override {

        quicksort(datos, 0, datos.size() - 1);
        cout << "Ordenado con QuickSort" << endl;
    }
};

class SistemaOrdenamiento {
private:
    Ordenamiento* estrategia;
public:

    SistemaOrdenamiento(Ordenamiento* e) {
        estrategia = e;
    }
    void setEstrategia(Ordenamiento* e) {
        estrategia = e;
    }
    void ordenarDatos(vector<int>& datos) {
        estrategia->ordenar(datos);
    }
};

void mostrar(vector<int> datos) {
    for (int i = 0; i < datos.size(); i++) {
        cout << datos[i] << " ";
    }
    cout << endl;
}

int main() {

    vector<int> numeros = {5, 2, 9, 1, 7};

    // Estrategia Burbuja
    Burbuja b;

    SistemaOrdenamiento sistema(&b);
    sistema.ordenarDatos(numeros);
    mostrar(numeros);
    cout << endl;

    // Nuevos datos
    vector<int> numeros2 = {8, 4, 6, 3, 1};

    // Cambiar estrategia a QuickSort
    QuickSort q;
    sistema.setEstrategia(&q);
    sistema.ordenarDatos(numeros2);
    mostrar(numeros2);

    return 0;
}
