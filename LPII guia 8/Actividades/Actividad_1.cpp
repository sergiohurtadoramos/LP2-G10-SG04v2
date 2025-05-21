#include <iostream>
#include <cmath> 
using namespace std;
class Figura {
public:
    virtual double calcularArea() = 0; 
    virtual ~Figura() {}
};
class Circulo : public Figura {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}
    double calcularArea() override {
        return M_PI * pow(radio, 2);
    }
};
class Rectangulo : public Figura {
private:
    double base, altura;
public:
    Rectangulo(double b, double a) : base(b), altura(a) {}
    double calcularArea() override {
        return base * altura;
    }
};
class Triangulo : public Figura {
private:
    double base, altura;
public:
    Triangulo(double b, double a) : base(b), altura(a) {}
    double calcularArea() override {
        return (base * altura) / 2;
    }
};
class Cuadrado : public Figura {
private:
    double lado;
public:
    Cuadrado(double l) : lado(l) {}
    double calcularArea() override {
        return lado * lado;
    }
};
class Pentagono : public Figura {
private:
    double lado;
    double apotema;
public:
    Pentagono(double l, double a) : lado(l), apotema(a) {}
    double calcularArea() override {
        return (5 * lado * apotema) / 2;
    }
};

int main() {
    Figura* figura = nullptr;
    int opcion;
    cout << "Selecciona una figura para calcular su area:\n";
    cout << "1. Circulo\n2. Rectangulo\n3. Triangulo\n4. Cuadrado\n5. Pentagono\n";
    cout << "Opcion: ";
    cin >> opcion;

    switch(opcion) {
        case 1: {
            double radio;
            cout << "Introduce el radio del circulo: ";
            cin >> radio;
            figura = new Circulo(radio);
            break;
        }
        case 2: {
            double base, altura;
            cout << "Introduce la base del rectangulo: ";
            cin >> base;
            cout << "Introduce la altura del rectangulo: ";
            cin >> altura;
            figura = new Rectangulo(base, altura);
            break;
        }
        case 3: {
            double base, altura;
            cout << "Introduce la base del triangulo: ";
            cin >> base;
            cout << "Introduce la altura del triangulo: ";
            cin >> altura;
            figura = new Triangulo(base, altura);
            break;
        }
        case 4: {
            double lado;
            cout << "Introduce el lado del cuadrado: ";
            cin >> lado;
            figura = new Cuadrado(lado);
            break;
        }
        case 5: {
            double lado, apotema;
            cout << "Introduce el lado del pentagono: ";
            cin >> lado;
            cout << "Introduce la apotema del pentagono: ";
            cin >> apotema;
            figura = new Pentagono(lado, apotema);
            break;
        }
        default:
            cout << "Opcion no valida" << endl;
            return 1;
    }

    cout << "El area de la figura es: " << figura->calcularArea() << endl;
    delete figura;
    return 0;
}



