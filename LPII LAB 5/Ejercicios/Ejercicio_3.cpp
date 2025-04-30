#include <iostream>
using namespace std;

class Habitacion {
private:
    int numero;
    string tipo;
    float precioPorNoche;
public:
    Habitacion() {}
    Habitacion(int n, string t, float p) {
        numero = n;
        tipo = t;
        precioPorNoche = p;
    }
    float getPrecioPorNoche() {
        return precioPorNoche;
    }
    void mostrar() {
        cout << "Habitación " << numero << ", Tipo: " << tipo << ", Precio por noche: " << precioPorNoche << endl;
    }
};

class ReservaHotel {
private:
    Habitacion* habitaciones;
    int cantidad;
public:
    ReservaHotel(int c) {
        cantidad = c;
        habitaciones = new Habitacion[cantidad];
        for (int i = 0; i < cantidad; i++) {
            int num;
            string tipo;
            float precio;
            cout << "Habitación " << i + 1 << " - Número: ";
            cin >> num;
            cin.ignore();
            cout << "Tipo: ";
            getline(cin, tipo);
            cout << "Precio por noche: ";
            cin >> precio;
            habitaciones[i] = Habitacion(num, tipo, precio);
        }
    }

    ~ReservaHotel() {
        delete[] habitaciones;
    }

    float calcularTotalPorNoche() {
        float total = 0;
        for (int i = 0; i < cantidad; i++) {
            total += habitaciones[i].getPrecioPorNoche();
        }
        return total;
    }

    void mostrarHabitaciones() {
        for (int i = 0; i < cantidad; i++) {
            habitaciones[i].mostrar();
        }
    }
};

int main() {
    int n;
    cout << "Ingrese la cantidad de habitaciones: ";
    cin >> n;
    ReservaHotel reserva(n);
    cout << "\n--- Detalle de habitaciones ---\n";
    reserva.mostrarHabitaciones();
    cout << "\nTotal por noche de todas las habitaciones: " << reserva.calcularTotalPorNoche() << endl;
    return 0;
}

