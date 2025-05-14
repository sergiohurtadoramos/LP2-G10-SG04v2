#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Cliente {
protected:
    string nombre;
    string correo;
    string tarjeta;
    string contrasena;

protected:
    string encriptar(string dato) {
        reverse(dato.begin(), dato.end());
        return dato;
    }

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
protected:
    string tarjetaEncriptada;

public:
    ClienteSeguro(string _nombre, string _correo, string _tarjeta, string _contrasena)
        : Cliente(_nombre, _correo, _tarjeta, _contrasena) {
        tarjetaEncriptada = encriptar(tarjeta);
    }

    void mostrarTarjetaSegura() {
        cout << "Tarjeta encriptada: " << tarjetaEncriptada << endl;
    }
};
