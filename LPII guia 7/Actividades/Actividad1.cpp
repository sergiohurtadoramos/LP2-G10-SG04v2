#include <iostream>
#include <string>
using namespace std;

class Cliente {
protected:
    string nombre;
    string correo;
    string tarjeta;
    string contrasena;

public:
    Cliente(string _nombre, string _correo, string _tarjeta, string _contrasena)
        : nombre(_nombre), correo(_correo), tarjeta(_tarjeta), contrasena(_contrasena) {}

    void mostrarDatos() {
        cout << "Nombre: " << nombre << endl;
        cout << "Correo: " << correo << endl;
        cout << "Tarjeta (oculta): " << string(tarjeta.size(), '*') << endl;
    }
};

class ClienteSeguro : public Cliente {
public:
    ClienteSeguro(string _nombre, string _correo, string _tarjeta, string _contrasena)
        : Cliente(_nombre, _correo, _tarjeta, _contrasena) {}
};
