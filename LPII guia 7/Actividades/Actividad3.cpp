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
    bool autenticado;

public:
    ClienteSeguro(string _nombre, string _correo, string _tarjeta, string _contrasena)
        : Cliente(_nombre, _correo, _tarjeta, _contrasena) {
        tarjetaEncriptada = encriptar(tarjeta);
        autenticado = false;
        cout << "ClienteSeguro creado.\n";
    }

    void autenticar(string contrasenaIngresada) {
        if (contrasenaIngresada == contrasena) {
            autenticado = true;
            cout << "Autenticación exitosa.\n";
        } else {
            cout << "Autenticación fallida.\n";
        }
    }

    void mostrarTarjetaSegura() {
        if (autenticado)
            cout << "Tarjeta encriptada: " << tarjetaEncriptada << endl;
        else
            cout << "Debe autenticarse para ver la tarjeta.\n";
    }

    ~ClienteSeguro() {
        cout << "Destructor de ClienteSeguro ejecutado.\n";
    }
};
