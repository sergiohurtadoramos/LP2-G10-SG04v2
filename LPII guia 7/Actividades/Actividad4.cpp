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

// Herencia PUBLIC
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

// Herencia PROTECTED
class ClienteProtected : protected Cliente {
public:
    ClienteProtected(string _nombre, string _correo, string _tarjeta, string _contrasena)
        : Cliente(_nombre, _correo, _tarjeta, _contrasena) {}

    void mostrarCorreo() {
        cout << "Correo (herencia protected): " << correo << endl;
    }
};

// Herencia PRIVATE
class ClientePrivado : private Cliente {
public:
    ClientePrivado(string _nombre, string _correo, string _tarjeta, string _contrasena)
        : Cliente(_nombre, _correo, _tarjeta, _contrasena) {}

    void mostrarInfo() {
        cout << "Cliente con herencia privada:\n";
        mostrarDatos();
    }
};

// MAIN
int main() {
    ClienteSeguro c1("Sergio", "sergio@mail.com", "1234567890123456", "abc123");
    c1.mostrarDatos();
    c1.autenticar("abc123");
    c1.mostrarTarjetaSegura();

    ClienteProtected c2("Lucía", "lucia@mail.com", "4444555566667777", "pass456");
    c2.mostrarCorreo();

    ClientePrivado c3("Ana", "ana@mail.com", "8888999900001111", "clave999");
    c3.mostrarInfo();

    return 0;
}
