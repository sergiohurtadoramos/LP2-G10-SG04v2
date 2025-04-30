#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Producto {
private:
    string nombre;
    double precio;
    double descuento;
public:
    Producto() {
        nombre = "";
        precio = 0;
        descuento = 0;
    }
    Producto& setNombre(string n) {
        nombre = n;
        return *this;
    }
    Producto& setPrecio(double p) {
        precio = p;
        return *this;
    }
    Producto& setDescuento(double d) {
        descuento = d;
        return *this;
    }
    double calcularPrecioFinal() {
        return precio - (precio * descuento / 100);
    }
    void mostrarProducto() {
        cout << "Nombre: " << nombre << endl;
        cout << "Precio: S/ " << precio << endl;
        cout << "Descuento: " << descuento << "%" << endl;
        cout << "Precio final: S/ " << calcularPrecioFinal() << endl;
        cout << "-----------------------------" << endl;
    }
};
int main() {
    int cantidad;
    cout << "¿Cuántos productos vas a registrar?: ";
    cin >> cantidad;
    vector<Producto> productos;
    for (int i = 0; i < cantidad; i++) {
        cout << "\nProducto #" << (i + 1) << endl;
        string nombre;
        double precio, descuento;
        cout << "Ingresa el nombre del producto: ";
        cin.ignore(); 
        getline(cin, nombre);
        cout << "Ingresa el precio del producto: S/ ";
        cin >> precio;
        cout << "Ingresa el descuento (%): ";
        cin >> descuento;
        cin.ignore();
        Producto p;
        p.setNombre(nombre).setPrecio(precio).setDescuento(descuento);
        productos.push_back(p);
    }
    double total = 0;
    cout << "\n===== Lista de productos registrados =====\n";
    for (int i = 0; i < productos.size(); i++) {
        productos[i].mostrarProducto();
        total += productos[i].calcularPrecioFinal();
    }
    cout << "Total acumulado a pagar: S/ " << total << endl;

    return 0;
}
