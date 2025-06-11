#include <iostream>
#include <cmath>
using namespace std;
class FiguraGeometrica {
public:
    virtual double calcularArea() = 0;
    virtual double calcularPerimetro() = 0;
    virtual ~FiguraGeometrica() {}
};
class Circulo : public FiguraGeometrica {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}
    double calcularArea() override {
        return M_PI * radio * radio;
    }
    double calcularPerimetro() override {
        return 2 * M_PI * radio;
    }
};
class Rectangulo : public FiguraGeometrica {
private:
    double largo, ancho;
public:
    Rectangulo(double l, double a) : largo(l), ancho(a) {}
    double calcularArea() override {
        return largo * ancho;
    }
    double calcularPerimetro() override {
        return 2 * (largo + ancho);
    }
};
class Triangulo : public FiguraGeometrica {
private:
    double lado;
public:
    Triangulo(double l) : lado(l) {}
    double calcularArea() override {
        return (sqrt(3) / 4) * lado * lado;
    }
    double calcularPerimetro() override {
        return 3 * lado;
    }
};
int main() {
    FiguraGeometrica* figuras[3];
    figuras[0] = new Circulo(5);
    figuras[1] = new Rectangulo(4, 6);
    figuras[2] = new Triangulo(3);
    for (int i = 0; i < 3; i++) {
        cout << "Figura " << i + 1 << ":\n";
        cout << "Área: " << figuras[i]->calcularArea() << endl;
        cout << "Perímetro: " << figuras[i]->calcularPerimetro() << endl << endl;
    }
    for (int i = 0; i < 3; i++) {
        delete figuras[i];
    }

    return 0;
}


