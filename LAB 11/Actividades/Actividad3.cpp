#include <iostream>
#include <fstream>
#include <string>
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
}
void guardar() {
    ofstream archivo("inventario.csv");
    for (int i = 0; i < total; i++) {
        archivo << inventario[i].nombre << " "
                << inventario[i].precio << " "
                << inventario[i].cantidad << endl;
    }
    archivo.close();
}
void registrar() {
    cout << "Nombre: ";
    cin >> inventario[total].nombre;
    cout << "Precio: ";
    cin >> inventario[total].precio;
    cout << "Cantidad: ";
    cin >> inventario[total].cantidad;
    total++;
    guardar();
    cout << "Producto agregado\n";
}
void mostrar() {
    for (int i = 0; i < total; i++) {
        cout << inventario[i].nombre << " - "
             << inventario[i].precio << " - "
             << inventario[i].cantidad << endl;
    }
}
void buscar() {
    string nombre;
    cout << "Buscar: ";
    cin >> nombre;
    for (int i = 0; i < total; i++) {
        if (inventario[i].nombre == nombre) {
            cout << "Precio: " << inventario[i].precio
                 << " | Cantidad: " << inventario[i].cantidad << endl;
            return;
        }
    }
    cout << "No encontrado\n";
}
void vender() {
    string nombre;
    int cant;
    cout << "Producto a vender: ";
    cin >> nombre;
    cout << "Cantidad: ";
    cin >> cant;
    for (int i = 0; i < total; i++) {
        if (inventario[i].nombre == nombre) {
            if (inventario[i].cantidad >= cant) {
                inventario[i].cantidad -= cant;
                guardar();
                cout << "Venta realizada\n";
            } else {
                cout << "Stock insuficiente\n";
            }
            return;
        }
    }
    cout << "Producto no encontrado\n";
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
        }
    } while (op != 5);
    return 0;
}

