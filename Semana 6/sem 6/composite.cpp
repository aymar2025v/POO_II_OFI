
#include <iostream>
#include <vector>
using namespace std;

// COMPONENT
class Elemento {
public:
	virtual void mostrar() = 0;
};

// LEAF -> Archivo
class Archivo : public Elemento {
private:
	string nombre;

public:
	Archivo(string n) {
		nombre = n;
	}

	void mostrar() override {
		cout << "Archivo: " << nombre << endl;
	}
};

// COMPOSITE -> Carpeta
class Carpeta : public Elemento {
private:
	string nombre;
	vector<Elemento*> elementos;

public:
	Carpeta(string n) {
		nombre = n;
	}

	// Agregar archivos o carpetas
	void agregar(Elemento* elemento) {
		elementos.push_back(elemento);
	}

	void mostrar() override {
		cout << "Carpeta: " << nombre << endl;

		// Mostrar todo lo que contiene
		for (int i = 0; i < elementos.size(); i++) {
			elementos[i]->mostrar();
		}
	}
};

int main() {

	// Archivos
	Archivo* archivo1 = new Archivo("foto.png");
	Archivo* archivo2 = new Archivo("documento.pdf");
	Archivo* archivo3 = new Archivo("tarea.docx");

	// Carpetas
	Carpeta* carpeta1 = new Carpeta("Mis Archivos");
	Carpeta* carpeta2 = new Carpeta("Tareas");

	// Agregar archivos a carpeta2
	carpeta2->agregar(archivo3);

	// Agregar elementos a carpeta1
	carpeta1->agregar(archivo1);
	carpeta1->agregar(archivo2);
	carpeta1->agregar(carpeta2);

	// Mostrar estructura completa
	carpeta1->mostrar();

	return 0;
}
