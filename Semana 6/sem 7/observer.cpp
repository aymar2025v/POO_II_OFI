#include <iostream>
#include <vector>
using namespace std;

// OBSERVER
class Usuario {
private:
    string nombre;
public:
    Usuario(string n) {
        nombre = n;
    }

    // Recibir notificación
    void actualizar(string mensaje) {
        cout << nombre << " recibio el mensaje: "
             << mensaje << endl;
    }
};

// SUBJECT
class Chat {
private:
    vector<Usuario*> usuarios;

public:

    // Agregar usuarios al chat
    void agregarUsuario(Usuario* usuario) {
        usuarios.push_back(usuario);
    }

    // Enviar mensaje a todos
    void enviarMensaje(string mensaje) {
        cout << "\nNuevo mensaje en el chat\n" << endl;
        for (int i = 0; i < usuarios.size(); i++) {
            usuarios[i]->actualizar(mensaje);
        }
    }
};

int main() {

    // Crear usuarios
    Usuario* u1 = new Usuario("Aldo");
    Usuario* u2 = new Usuario("Maria");
    Usuario* u3 = new Usuario("Carlos");

    // Crear chat
    Chat chat;

    // Agregar usuarios
    chat.agregarUsuario(u1);
    chat.agregarUsuario(u2);
    chat.agregarUsuario(u3);

    // Enviar mensajes
    chat.enviarMensaje("Hola a todos");
    chat.enviarMensaje("La reunion empieza a las 8 PM");

    return 0;
}
