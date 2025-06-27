#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct Producto {
    string codigo;
    string descripcion;
    int cantidad;
};
vector<Producto> inventario;
void agregarProducto() {
    Producto p;
    cout << "Código del producto: ";
    cin.ignore();
    getline(cin, p.codigo);
    for (int i = 0; i < inventario.size(); i++) {
        if (inventario[i].codigo == p.codigo) {
            cout << "Ya existe un producto con ese código.";
            return;
        }
    }
    cout << "Descripción: ";
    getline(cin, p.descripcion);
    cout << "Cantidad disponible: ";
    cin >> p.cantidad;
    inventario.push_back(p);
    cout << "Producto agregado.";
}
void actualizarCantidad() {
    string codigo;
    cout << "Código del producto: ";
    cin.ignore();
    getline(cin, codigo);
    for (int i = 0; i < inventario.size(); i++) {
        if (inventario[i].codigo == codigo) {
            cout << "Cantidad actual: " << inventario[i].cantidad << endl;
            cout << "Nueva cantidad: ";
            cin >> inventario[i].cantidad;
            cout << "Cantidad actualizada.";
            return;
        }
    }
    cout << "Producto no encontrado.";
}
void buscarProducto() {
    string codigo;
    cout << "Código del producto: ";
    cin.ignore();
    getline(cin, codigo);
    for (int i = 0; i < inventario.size(); i++) {
        if (inventario[i].codigo == codigo) {
            cout << "Código: " << inventario[i].codigo << endl;
            cout << "Descripción: " << inventario[i].descripcion << endl;
            cout << "Cantidad: " << inventario[i].cantidad << endl;
            return;
        }
    }
    cout << "Producto no encontrado.";
}
void mostrarProductosOrdenados() {
    if (inventario.empty()) {
        cout << "No hay productos en el inventario.";
        return;
    }
    vector<Producto> lista = inventario;
    sort(lista.begin(), lista.end(), [](Producto a, Producto b) {
        return a.descripcion < b.descripcion;
    });
    cout << "Lista de productos ordenados por descripción:";
    for (int i = 0; i < lista.size(); i++) {
        cout << "Código: " << lista[i].codigo << endl;
        cout << "Descripción: " << lista[i].descripcion << endl;
        cout << "Cantidad: " << lista[i].cantidad << endl;
    }
}
int main() {
    int opcion;
    do {
        cout << "\n1. Agregar producto\n";
        cout << "2. Actualizar cantidad\n";
        cout << "3. Buscar producto por código\n";
        cout << "4. Mostrar productos ordenados por descripción\n";
        cout << "5. Salir\n";
        cout << "Opción: ";
        cin >> opcion;
        if (opcion == 1) agregarProducto();
        else if (opcion == 2) actualizarCantidad();
        else if (opcion == 3) buscarProducto();
        else if (opcion == 4) mostrarProductosOrdenados();
        else if (opcion == 5) cout << "Fin del programa.\n";
        else cout << "Opción inválida.\n";
    } while (opcion != 5);
    return 0;
}
