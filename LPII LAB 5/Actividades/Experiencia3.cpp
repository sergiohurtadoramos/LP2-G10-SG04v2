#include <iostream>
using namespace std;

class Fecha {
private:
    int dia, mes, anio;

public:
    Fecha(int d = 1, int m = 1, int a = 2000) : dia(d), mes(m), anio(a) {}

    void mostrar() const {
        cout << dia << "/" << mes << "/" << anio;
    }
};
class Contrato {
private:
    string codigo;
    string descripcion;
    Fecha fechaInicio;

public:
    Contrato(string c, string d, Fecha f) : codigo(c), descripcion(d), fechaInicio(f) {}

    void mostrar() const {
        cout << "Código: " << codigo << endl;
        cout << "Descripción: " << descripcion << endl;
        cout << "Fecha de inicio: ";
        fechaInicio.mostrar();
        cout << endl;
    }
};
class Empleado {
private:
    string nombre;
    Contrato contrato;

public:
    Empleado(string nom, Contrato cont) : nombre(nom), contrato(cont) {}

    void mostrar() const {
        cout << "Empleado: " << nombre << endl;
        contrato.mostrar();
    }
};
int main() {
    Fecha f(15, 4, 2025);
    Contrato c("C001", "Contrato a plazo fijo", f);
    Empleado e("Luis Torres", c);

    e.mostrar();

    return 0;
}