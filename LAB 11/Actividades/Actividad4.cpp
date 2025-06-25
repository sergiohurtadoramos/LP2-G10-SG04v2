#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept> 
using namespace std;
struct Producto {
    string nombre;
    float precio;
    int cantidad;
};
Producto inventario[100];
int total = 0;
void cargar() {
    ifstream archivo("inventario.csv");
    if (!archivo) {
        cout << "No se encontró archivo, se creará uno nuevo.\n";
        return;
    }
    try {
        string nombre;
        float precio;
        int cantidad;
        while (archivo >> nombre >> precio >> cantidad) {
            inventario[total].nombre = nombre;
            inventario[total].precio = precio;
            inventario[total].cantidad = cantidad;
            total++;
        }
        archivo.close();
    } catch (...) {
        cout << "Error al cargar archivo.\n";
    }
}
void guardar() {
    try {
        ofstream archivo("inventario.csv");
        for (int i = 0; i < total; i++) {
            archivo << inventario[i].nombre << " "
                    << inventario[i].precio << " "
                    << inventario[i].cantidad << endl;
        }
        archivo.close();
    } catch (...) {
        cout << "Error al guardar archivo.\n";
    }
}
void registrar() {
    try {
        cout << "Nombre: ";
        cin >> inventario[total].nombre;
        cout << "Precio: ";
        if (!(cin >> inventario[total].precio)) throw runtime_error("Precio inválido");
        cout << "Cantidad: ";
        if (!(cin >> inventario[total].cantidad)) throw runtime_error("Cantidad inválida");
        total++;
        guardar();
        cout << "Producto agregado\n";
    } catch (const exception& e) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error: " << e.what() << endl;
    }
}
void mostrar() {
    for (int i = 0; i < total; i++) {
        cout << inventario[i].nombre << " - "
             << inventario[i].precio << " - "
             << inventario[i].cantidad << endl;
    }

void buscar() {
    string nombre;
    cout << "Buscar producto: ";
    cin >> nombre;
    for (int i = 0; i < total; i++) {
        if (inventario[i].nombre == nombre) {
            cout << "Precio: " << inventario[i].precio
                 << " | Cantidad: " << inventario[i].cantidad << endl;
            return;
        }
    }
    cout << "Producto no encontrado\n";
}
void vender() {
    string nombre;
    int cant;

    try {
        cout << "Producto a vender: ";
        cin >> nombre;
        cout << "Cantidad: ";
        if (!(cin >> cant)) throw runtime_error("Cantidad inválida");
        for (int i = 0; i < total; i++) {
            if (inventario[i].nombre == nombre) {
                if (inventario[i].cantidad >= cant) {
                    inventario[i].cantidad -= cant;
                    guardar();
                    cout << "Venta realizada\n";
                } else {
                    throw runtime_error("Stock insuficiente");
                }
                return;
            }
        }
        cout << "Producto no encontrado\n";
    } catch (const exception& e) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error: " << e.what() << endl;
    }
}
int main() {
    cargar();
    int op;
    do {
        cout << "\n1. Registrar\n2. Mostrar\n3. Buscar\n4. Vender\n5. Salir\nOpción: ";
        cin >> op;

        switch (op) {
            case 1: registrar(); break;
            case 2: mostrar(); break;
            case 3: buscar(); break;
            case 4: vender(); break;
            case 5: cout << "Saliendo...\n"; break;
            default: cout << "Opción inválida\n";
        }
    } while (op != 5);

    return 0;
}
