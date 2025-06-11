#include <iostream>
#include <vector>
using namespace std;

// Clase base abstracta
class Producto {
public:
    virtual double calcularValorTotal() const = 0;
    virtual void aplicarDescuento(double porcentaje) = 0;
    virtual void mostrarInfo() const = 0;
    virtual ~Producto() {}
};

// Electrónico
class Electronico : public Producto {
private:
    string nombre;
    double precioUnitario;
    int cantidad;
public:
    Electronico(string n, double p, int c) : nombre(n), precioUnitario(p), cantidad(c) {}
    double calcularValorTotal() const override {
        return precioUnitario * cantidad;
    }
    void aplicarDescuento(double porcentaje) override {
        precioUnitario -= precioUnitario * (porcentaje / 100);
    }
    void mostrarInfo() const override {
        cout << "Producto: Electrónico | Nombre: " << nombre
             << " | Precio: S/ " << precioUnitario
             << " | Cantidad: " << cantidad << endl;
    }
};

// Ropa
class Ropa : public Producto {
private:
    string tipo;
    double precio;
    int unidades;
public:
    Ropa(string t, double p, int u) : tipo(t), precio(p), unidades(u) {}
    double calcularValorTotal() const override {
        return precio * unidades;
    }
    void aplicarDescuento(double porcentaje) override {
        precio -= precio * (porcentaje / 100);
    }
    void mostrarInfo() const override {
        cout << "Producto: Ropa | Tipo: " << tipo
             << " | Precio: S/ " << precio
             << " | Unidades: " << unidades << endl;
    }
};

// Alimento
class Alimento : public Producto {
private:
    string nombre;
    double precioPorKg;
    double kilos;
public:
    Alimento(string n, double p, double k) : nombre(n), precioPorKg(p), kilos(k) {}
    double calcularValorTotal() const override {
        return precioPorKg * kilos;
    }
    void aplicarDescuento(double porcentaje) override {
        precioPorKg -= precioPorKg * (porcentaje / 100);
    }
    void mostrarInfo() const override {
        cout << "Producto: Alimento | Nombre: " << nombre
             << " | Precio/kg: S/ " << precioPorKg
             << " | Kilos: " << kilos << endl;
    }
};

// Main con menú
int main() {
    vector<Producto*> inventario;
    int opcion;

    do {
        cout << "\n--- GESTIÓN DE INVENTARIO ---\n";
        cout << "1. Agregar producto\n";
        cout << "2. Ver productos y valores\n";
        cout << "3. Aplicar descuento a todos\n";
        cout << "4. Calcular valor total del inventario\n";
        cout << "5. Salir\n";
        cout << "Opción: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "\nTipos de producto:\n";
            cout << "1. Electrónico\n";
            cout << "2. Ropa\n";
            cout << "3. Alimento\n";
            int tipo;
            cin >> tipo;

            switch (tipo) {
                case 1: {
                    string nombre;
                    double precio;
                    int cantidad;
                    cout << "Nombre del producto: ";
                    cin >> nombre;
                    cout << "Precio unitario: ";
                    cin >> precio;
                    cout << "Cantidad: ";
                    cin >> cantidad;
                    inventario.push_back(new Electronico(nombre, precio, cantidad));
                    break;
                }
                case 2: {
                    string tipo;
                    double precio;
                    int unidades;
                    cout << "Tipo de ropa: ";
                    cin >> tipo;
                    cout << "Precio por unidad: ";
                    cin >> precio;
                    cout << "Cantidad: ";
                    cin >> unidades;
                    inventario.push_back(new Ropa(tipo, precio, unidades));
                    break;
                }
                case 3: {
                    string nombre;
                    double precio, kilos;
                    cout << "Nombre del alimento: ";
                    cin >> nombre;
                    cout << "Precio por kilo: ";
                    cin >> precio;
                    cout << "Kilos: ";
                    cin >> kilos;
                    inventario.push_back(new Alimento(nombre, precio, kilos));
                    break;
                }
                default:
                    cout << "Opción inválida.\n";
            }

        } else if (opcion == 2) {
            if (inventario.empty()) {
                cout << "Inventario vacío.\n";
            } else {
                for (size_t i = 0; i < inventario.size(); ++i) {
                    cout << "\nProducto #" << i + 1 << ":\n";
                    inventario[i]->mostrarInfo();
                    cout << "Valor total: S/ " << inventario[i]->calcularValorTotal() << endl;
                }
            }

        } else if (opcion == 3) {
            double porcentaje;
            cout << "Ingrese porcentaje de descuento: ";
            cin >> porcentaje;
            for (Producto* p : inventario)
                p->aplicarDescuento(porcentaje);
            cout << "Descuento aplicado.\n";

        } else if (opcion == 4) {
            double total = 0;
            for (Producto* p : inventario)
                total += p->calcularValorTotal();
            cout << "Valor total del inventario: S/ " << total << endl;

        } else if (opcion != 5) {
            cout << "Opción inválida.\n";
        }

    } while (opcion != 5);

    for (Producto* p : inventario) delete p;

    return 0;
}
