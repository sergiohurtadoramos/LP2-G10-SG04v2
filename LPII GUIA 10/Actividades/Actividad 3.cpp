#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Template de clase que representa una Ruta genérica
template <typename T>
class Ruta {
private:
    string codigoRuta;
    vector<T> puntos; // Puntos de entrega, coordenadas, clientes, etc.

public:
    Ruta(string cod) : codigoRuta(cod) {}

    void agregarPunto(const T& punto) {
        puntos.push_back(punto);
    }

    void mostrarRuta() {
        cout << "Ruta: " << codigoRuta << endl;
        cout << "Puntos registrados:" << endl;
        for (const auto& p : puntos) {
            cout << " - " << p << endl;
        }
    }

    int cantidadPuntos() const {
        return puntos.size();
    }
};

// Clase principal que representa el sistema logístico
class SistemaLogistico {
public:
    void mostrarResumenRuta() {
        cout << "Resumen del sistema de rutas cargadas en el día." << endl;
    }

    template <typename T>
    void generarInformeRuta(Ruta<T>& ruta) {
        cout << "\n[INFORME]" << endl;
        ruta.mostrarRuta();
        cout << "Total de puntos: " << ruta.cantidadPuntos() << endl;
    }
};

int main() {
    // Ruta de tipo string (direcciones)
    Ruta<string> rutaA("R-101");
    rutaA.agregarPunto("Av. Los Olivos 123");
    rutaA.agregarPunto("Jr. Independencia 456");

    // Ruta de tipo float (coordenadas)
    Ruta<float> rutaB("R-202");
    rutaB.agregarPunto(12.345);
    rutaB.agregarPunto(13.789);

    // Sistema logístico principal
    SistemaLogistico sistema;
    sistema.mostrarResumenRuta();
    sistema.generarInformeRuta(rutaA);
    sistema.generarInformeRuta(rutaB);

    return 0;
}
