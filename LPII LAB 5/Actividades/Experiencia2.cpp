#include <iostream>
using namespace std;

class Dispositivo {
private:
    string marca;
    string modelo;
    int anioFabricacion;

public:
    Dispositivo() {
        marca = "Sin marca";
        modelo = "Sin modelo";
        anioFabricacion = 0;
        cout << "[Constructor por defecto] Dispositivo creado: " << modelo << endl;
    }
    Dispositivo(string m, string mod, int anio) {
        marca = m;
        modelo = mod;
        anioFabricacion = anio;
        cout << "[Constructor parametrizado] Dispositivo creado: " << modelo << endl;
    }
    Dispositivo(const Dispositivo& otro) {
        marca = otro.marca;
        modelo = otro.modelo;
        anioFabricacion = otro.anioFabricacion;
        cout << "[Constructor de copia] Copia de dispositivo creada: " << modelo << endl;
    }
    ~Dispositivo() {
        cout << "[Destructor] Dispositivo destruido: " << modelo << endl;
    }
};

int main() {
    Dispositivo dispositivos[3] = {
        Dispositivo("Samsung", "Galaxy S21", 2021),
        Dispositivo("Apple", "iPhone 13", 2021),
        Dispositivo("Xiaomi", "Redmi Note 11", 2022)
    };

    return 0;
}
