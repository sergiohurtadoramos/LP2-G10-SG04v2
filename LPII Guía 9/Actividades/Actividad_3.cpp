#include <iostream>
#include <cmath>
using namespace std;
class Figura {
public:
    virtual double calcularArea() = 0; 
};
class Circulo : public Figura {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}
    double calcularArea() override {
        return 3.1416 * radio * radio;
    }
};
class Rectangulo : public Figura {
private:
    double base, altura;
public:
    Rectangulo(double b, double h) : base(b), altura(h) {}
    double calcularArea() override {
        return base * altura;
    }
};
class Triangulo : public Figura {
private:
    double base, altura;
public:
    Triangulo(double b, double h) : base(b), altura(h) {}
    double calcularArea() override {
        return (base * altura) / 2;
    }
};
int main() {
    Figura* figuras[3];
    figuras[0] = new Circulo(5);
    figuras[1] = new Rectangulo(4, 6);
    figuras[2] = new Triangulo(3, 7);
    for (int i = 0; i < 3; i++) {
        cout << "Área de la figura " << i + 1 << ": " << figuras[i]->calcularArea() << endl;
    }
    for (int i = 0; i < 3; i++) {
        delete figuras[i];
    }
    return 0;
}

