#include <iostream>
using namespace std;
class Vector2D {
private:
    float x, y;
public:
    Vector2D() {
        x = 0;
        y = 0;
    }
    void leer() {
        cout << "Ingrese componente X: ";
        cin >> x;
        cout << "Ingrese componente Y: ";
        cin >> y;
    }
    void mostrar() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
    Vector2D operator+(Vector2D otro) {
        Vector2D resultado;
        resultado.x = x + otro.x;
        resultado.y = y + otro.y;
        return resultado;
    }
    Vector2D operator-(Vector2D otro) {
        Vector2D resultado;
        resultado.x = x - otro.x;
        resultado.y = y - otro.y;
        return resultado;
    }
};

int main() {
    Vector2D v1, v2, suma, resta;
    cout << "Ingrese el primer vector:" << endl;
    v1.leer();
    cout << "Ingrese el segundo vector:" << endl;
    v2.leer();
    suma = v1 + v2;
    resta = v1 - v2;
    cout << "Suma de vectores: ";
    suma.mostrar();
    cout << "Resta de vectores: ";
    resta.mostrar();

    return 0;
}






