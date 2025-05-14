#include <iostream>
using namespace std;
class Vehiculo {
protected:
    string marca;
    string modelo;
    string año;
    double precio;
public:
    void ingresarDatosBase() {
        cout << "Marca: ";
        cin >> marca;
        cout << "Modelo: ";
        cin >> modelo;
        cout << "Año: ";
        cin >> año;
        cout << "Precio: $";
        cin >> precio;
    }
    void mostrarInfo() {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Año: " << año << endl;
        cout << "Precio: $" << precio << endl;
    }
};
class Automovil : public Vehiculo {
private:
    int puertas;
    string combustible;

public:
    void ingresarDatosAutomovil() {
        ingresarDatosBase();
        cout << "Número de puertas: ";
        cin >> puertas;
        cout << "Tipo de combustible: ";
        cin >> combustible;
    }

    void mostrarAutomovil() {
        mostrarInfo();
        cout << "Puertas: " << puertas << endl;
        cout << "Combustible: " << combustible << endl;
    }
};
class Motocicleta : public Vehiculo {
private:
    int cilindrada;
public:
    void ingresarDatosMotocicleta() {
        ingresarDatosBase();
        cout << "Cilindrada: ";
        cin >> cilindrada;
    }
    void mostrarMotocicleta() {
        mostrarInfo();
        cout << "Cilindrada: " << cilindrada << " cc" << endl;
    }
};
int main() {
    Automovil auto1;
    Motocicleta moto1;
    cout << "=== Ingresar datos del Automóvil ===" << endl;
    auto1.ingresarDatosAutomovil();
    cout << "\n=== Ingresar datos de la Motocicleta ===" << endl;
    moto1.ingresarDatosMotocicleta();
    cout << "\n=== Datos del Automóvil ===" << endl;
    auto1.mostrarAutomovil();
    cout << "\n=== Datos de la Motocicleta ===" << endl;
    moto1.mostrarMotocicleta();

    return 0;
}


