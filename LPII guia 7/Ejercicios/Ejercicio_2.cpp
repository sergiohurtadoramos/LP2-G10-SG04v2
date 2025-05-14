#include <iostream>
#include <string>
using namespace std;
class Persona {
protected:
    string nombre;
    int edad;
    double salario;
    string correoElectronico;  

public:
    Persona(string n, int e, double s, string correo) : nombre(n), edad(e), salario(s), correoElectronico(correo) {}
    void mostrarInfo() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Salario: " << salario << endl;
    }
    void mostrarCorreo() {
        cout << "Correo Electrónico: " << correoElectronico << endl;
    }
};
class Empleado : public Persona {
public:
    Empleado(string n, int e, double s, string correo) : Persona(n, e, s, correo) {}
    void mostrarEmpleadoInfo() {
        mostrarInfo();  
        mostrarCorreo(); 
    }
};
class Cliente : public Persona {
public:
    Cliente(string n, int e, double s, string correo) : Persona(n, e, s, correo) {}
    void mostrarClienteInfo() {
        mostrarInfo();  
        mostrarCorreo();
    }
};

int main() {
    string nombre, correo;
    int edad;
    double salario;
    cout << "Ingrese los datos del Empleado:" << endl;
    cout << "Nombre: ";
    getline(cin, nombre);
    cout << "Edad: ";
    cin >> edad;
    cout << "Salario: ";
    cin >> salario;
    cin.ignore();  
    cout << "Correo Electrónico: ";
    getline(cin, correo);
    Empleado emp(nombre, edad, salario, correo);
    cout << "\nInformación del Empleado:" << endl;
    emp.mostrarEmpleadoInfo();
    cout << "\nIngrese los datos del Cliente:" << endl;
    cout << "Nombre: ";
    getline(cin, nombre);
    cout << "Edad: ";
    cin >> edad;
    cout << "Salario: ";
    cin >> salario;
    cin.ignore();  
    cout << "Correo Electrónico: ";
    getline(cin, correo);
    Cliente cli(nombre, edad, salario, correo);
    cout << "\nInformación del Cliente:" << endl;
    cli.mostrarClienteInfo();

    return 0;
}




