#include <iostream>
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
void registrar(Producto inv[], int &n) {
    cout << "Nombre: "; cin >> inv[n].nombre;
    cout << "Precio: "; cin >> inv[n].precio;
    cout << "Cantidad: "; cin >> inv[n].cantidad;
    n++;
    cout << "Poducto agregado";
}
void actualizar(Producto inv[], int n) {
    string nombre;
    cout << "Producto a actualizar: "; cin >> nombre;
    for (int i = 0; i < n; i++) {
        if (inv[i].nombre == nombre) {
            cout << "Nuevo precio: "; cin >> inv[i].precio;
            cout << "Nueva cantidad: "; cin >> inv[i].cantidad;
            cout << "Producto actualizado";
            return;
        }
    }
    cout << "Producto no encontrado";
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
                cout << "Venta realizada";
            } else {
                cout << "Stock insuficiente";
            }
            return;
        }
    }
    cout << " Producto no encontrado\n";
}

void informe(Producto inv[], int n) {
    cout << "\n INVENTARIO\n";
    for (int i = 0; i < n; i++) inv[i].mostrar();
}

int main() {
    Producto inventario[100];
    int total = 0, op;

    do {
        cout << "\n--- MENÚ ---\n";
        cout << "1. Registrar\n2. Actualizar\n3. Vender\n4. Ver informe\n5. Salir\nOpción: ";
        cin >> op;

        switch (op) {
            case 1: registrar(inventario, total); break;
            case 2: actualizar(inventario, total); break;
            case 3: vender(inventario, total); break;
            case 4: informe(inventario, total); break;
            case 5: cout << " Saliendo...\n"; break;
            default: cout << "Opción inválida\n";
        }
    } while (op != 5);

    return 0;
}
