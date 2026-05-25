#include <iostream>
#include <vector>
using namespace std;

class EditorTexto {
private:
	string texto;
public:
	void escribir(string nuevoTexto) {
		texto += nuevoTexto;
	}
	void guardar() {
		cout << "Texto guardado: " << texto << endl;
	}
	void deshacer() {
		if (texto.length() > 0) {
			texto.pop_back();
			cout << "Ultimo caracter eliminado" << endl;
		}
		else {
			cout << "No hay texto para deshacer" << endl;
		}
	}
	void mostrar() {
		cout << "Texto actual: " << texto << endl;
	}
};

class Comando {
public:
	virtual void ejecutar() = 0;
};

class ComandoGuardar : public Comando {
private:
	EditorTexto* editor;

public:
	ComandoGuardar(EditorTexto* e) {
		editor = e;
	}
	void ejecutar() override {
		editor->guardar();
	}
};

class ComandoDeshacer : public Comando {
private:
	EditorTexto* editor;
public:
	ComandoDeshacer(EditorTexto* e) {
		editor = e;
	}
	void ejecutar() override {
		editor->deshacer();
	}
};

class Boton {
private:
	Comando* comando;
public:
	Boton(Comando* c) {
		comando = c;
	}
	void presionar() {
		comando->ejecutar();
	}
};

int main() {

	// Receiver
	EditorTexto editor;
	editor.escribir("Hola Mundo");
	editor.mostrar();
	cout << endl;

	// Commands
	ComandoGuardar guardar(&editor);
	ComandoDeshacer deshacer(&editor);

	// Invokers
	Boton botonGuardar(&guardar);
	Boton botonDeshacer(&deshacer);

	// Ejecutar comandos
	botonGuardar.presionar();
	cout << endl;
	botonDeshacer.presionar();
	editor.mostrar();

	return 0;
}
