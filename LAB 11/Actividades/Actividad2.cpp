#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Producto {
public:
    string nombre;
    float precio;
    int cantidad;
    void mostrar() {
        cout << "Nombre: " << nombre
             << ", Precio: " << precio
             << ", Cantidad: " << cantidad << endl;
    }
};
void guardarInventario(Producto inv[], int n) {
    ofstream archivo("inventario.txt");
    for (int i = 0; i < n; i++) {
        archivo << inv[i].nombre << " "
                << inv[i].precio << " "
                << inv[i].cantidad << "\n";
    }
    archivo.close();
}
void cargarInventario(Producto inv[], int &n) {
    ifstream archivo("inventario.txt");
    while (archivo >> inv[n].nombre >> inv[n].precio >> inv[n].cantidad) {
        n++;
    }
    archivo.close();
}
void registrar(Producto inv[], int &n) {
    cout << "Nombre: "; cin >> inv[n].nombre;
    cout << "Precio: "; cin >> inv[n].precio;
    cout << "Cantidad: "; cin >> inv[n].cantidad;
    n++;
    guardarInventario(inv, n);
    cout << "Producto agregado\n";
}
void actualizar(Producto inv[], int n) {
    string nombre;
    cout << "Producto a actualizar: "; cin >> nombre;
    for (int i = 0; i < n; i++) {
        if (inv[i].nombre == nombre) {
            cout << "Nuevo precio: "; cin >> inv[i].precio;
            cout << "Nueva cantidad: "; cin >> inv[i].cantidad;
            guardarInventario(inv, n);
            cout << "Producto actualizado\n";
            return;
        }
    }
    cout << "Producto no encontrado\n";
}
void vender(Producto inv[], int n) {
    string nombre;
    int cantidad;
    cout << "Producto a vender: "; cin >> nombre;
    cout << "Cantidad: "; cin >> cantidad;
    for (int i = 0; i < n; i++) {
        if (inv[i].nombre == nombre) {
            if (inv[i].cantidad >= cantidad) {
                inv[i].cantidad -= cantidad;
                guardarInventario(inv, n);
                cout << "Venta realizada\n";
            } else {
                cout << "Stock insuficiente\n";
            }
            return;
        }
    }
    cout << "Producto no encontrado\n";
}
void informe(Producto inv[], int n) {
    cout << "\nINVENTARIO:\n";
    for (int i = 0; i < n; i++) inv[i].mostrar();
}
int main() {
    Producto inventario[100];
    int total = 0, op;
    cargarInventario(inventario, total);
    do {
        cout << "\n--- MENÚ ---\n";
        cout << "1. Registrar\n2. Actualizar\n3. Vender\n4. Ver informe\n5. Salir\nOpción: ";
        cin >> op;

        switch (op) {
            case 1: registrar(inventario, total); break;
            case 2: actualizar(inventario, total); break;
            case 3: vender(inventario, total); break;
            case 4: informe(inventario, total); break;
            case 5: cout << "Saliendo\n"; break;
            default: cout << "Opción inválida\n";
        }
    } while (op != 5);

    return 0;
}



