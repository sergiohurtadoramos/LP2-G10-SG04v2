#include <iostream>
#include <string>
using namespace std;

class FechaRegistro {
private:
    int dia, mes, año;
public:
    FechaRegistro(int d, int m, int a) : dia(d), mes(m), año(a) {}
    void mostrarFecha() const {
        cout << dia << "/" << mes << "/" << año;
    }
};
class Direccion {
private:
    string calle, ciudad, codigoPostal;
public:
    Direccion(string c, string ci, string cp) : calle(c), ciudad(ci), codigoPostal(cp) {}
    void mostrarDireccion() const {
        cout << "Calle: " << calle << ", Ciudad: " << ciudad << ", Codigo Postal: " << codigoPostal;
    }
};
class Cliente {
private:
    string nombre;
    FechaRegistro fechaRegistro;
    Direccion direccion;
public:
    Cliente(string nom, int d, int m, int a, string c, string ci, string cp) : nombre(nom), fechaRegistro(d, m, a), direccion(c, ci, cp) {}
    void mostrarCliente() const {
        cout << "Cliente: " << nombre << endl;
        cout << "Fecha de Registro: ";
        fechaRegistro.mostrarFecha();
        cout << endl;
        cout << "Direccion: ";
        direccion.mostrarDireccion();
        cout << endl;
    }
};

int main() {
    string nombre, calle, ciudad, codigoPostal;
    int dia, mes, año;

    cout << "Ingrese el nombre del cliente: ";
    getline(cin, nombre);

    cout << "Ingrese el dia de registro (1-31): ";
    cin >> dia;
    cout << "Ingrese el mes de registro (1-12): ";
    cin >> mes;
    cout << "Ingrese el año de registro: ";
    cin >> año;
    cin.ignore(); 
    cout << "Ingrese la calle de la direccion: ";
    getline(cin, calle);
    cout << "Ingrese la ciudad de la direccion: ";
    getline(cin, ciudad);
    cout << "Ingrese el codigo postal de la direccion: ";
    getline(cin, codigoPostal);
    Cliente cliente(nombre, dia, mes, año, calle, ciudad, codigoPostal);
    cliente.mostrarCliente();

    return 0;
}

