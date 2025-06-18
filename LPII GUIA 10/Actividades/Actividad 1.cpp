#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Template para calcular distancia entre dos puntos (2D o 3D si se extiende)
template <typename T>
T calcularDistancia(T x1, T y1, T x2, T y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// Template para estimar tiempo de entrega en función de la distancia y velocidad
template <typename T>
T estimarTiempoEntrega(T distancia, T velocidad) {
    if (velocidad == 0) {
        cerr << "Error: la velocidad no puede ser cero." << endl;
        return -1;
    }
    return distancia / velocidad;
}

// Template para generar informe de entrega
template <typename T>
void generarInforme(string destino, T distancia, T tiempo) {
    cout << "---- INFORME DE ENTREGA ----" << endl;
    cout << "Destino: " << destino << endl;
    cout << "Distancia estimada: " << distancia << " km" << endl;
    cout << "Tiempo estimado: " << tiempo << " horas" << endl;
    cout << "-----------------------------" << endl;
}

int main() {
    // Datos de ejemplo
    double x1 = 0.0, y1 = 0.0;
    double x2 = 3.0, y2 = 4.0;
    double velocidad = 60.0; // km/h

    // Cálculo usando templates
    double distancia = calcularDistancia(x1, y1, x2, y2);
    double tiempo = estimarTiempoEntrega(distancia, velocidad);
    generarInforme("Sucursal Norte", distancia, tiempo);

    return 0;
}
