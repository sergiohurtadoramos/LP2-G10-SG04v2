#include <iostream>
#include <cmath>
using namespace std;
class Forma {
public:
    virtual double calcularPerimetro() = 0; 
    virtual ~Forma() {} 
};
class Circulo : public Forma {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}
    double calcularPerimetro() override {
        return 2 * M_PI * radio;
    }
};
class Rectangulo : public Forma {
private:
    double largo, ancho;
public:
    Rectangulo(double l, double a) : largo(l), ancho(a) {}
    double calcularPerimetro() override {
        return 2 * (largo + ancho);
    }
};
class Triangulo : public Forma {
private:
    double lado1, lado2, lado3;
public:
    Triangulo(double l1, double l2, double l3) : lado1(l1), lado2(l2), lado3(l3) {}
    double calcularPerimetro() override {
        return lado1 + lado2 + lado3;
    }
};
int main() {
    Forma* forma = nullptr;
    int opcion;

    cout << "Seleccione una forma para calcular su perímetro:\n";
    cout << "1. Círculo\n2. Rectángulo\n3. Triángulo\nOpción: ";
    cin >> opcion;
    switch(opcion) {
        case 1: {
            double radio;
            cout << "Ingrese el radio del círculo: ";
            cin >> radio;
            forma = new Circulo(radio);
            break;
        }
        case 2: {
            double largo, ancho;
            cout << "Ingrese el largo del rectángulo: ";
            cin >> largo;
            cout << "Ingrese el ancho del rectángulo: ";
            cin >> ancho;
            forma = new Rectangulo(largo, ancho);
            break;
        }
        case 3: {
            double l1, l2, l3;
            cout << "Ingrese el lado 1 del triángulo: ";
            cin >> l1;
            cout << "Ingrese el lado 2 del triángulo: ";
            cin >> l2;
            cout << "Ingrese el lado 3 del triángulo: ";
            cin >> l3;
            forma = new Triangulo(l1, l2, l3);
            break;
        }
        default:
            cout << "Opción no válida.\n";
            return 1;
    }
    if (forma != nullptr) {
        double perimetro = forma->calcularPerimetro();
        cout << "El perímetro de la forma seleccionada es: " << perimetro << endl;
        delete forma; 
    }

    return 0;
}

