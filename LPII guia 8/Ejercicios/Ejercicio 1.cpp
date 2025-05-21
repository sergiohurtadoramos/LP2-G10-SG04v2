#include <iostream>
using namespace std;

// Clase abstracta
class Figura {
public:
    virtual void dibujar() = 0;
    virtual double calcularArea() = 0;
    virtual ~Figura() {}
};
// Figuras 
class Circulo : public Figura {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}
    void dibujar() override {
        cout << "Dibujando un círculo" << endl;
    }
    double calcularArea() override {
        const double PI = 3.1416;
        return PI * radio * radio;
    }
};

class Rectangulo : public Figura {
private:
    double ancho, alto;
public:
    Rectangulo(double a, double b) : ancho(a), alto(b) {}
    void dibujar() override {
        cout << "Dibujando un rectángulo" << endl;
    }
    double calcularArea() override {
        return ancho * alto;
    }
};

class Triangulo : public Figura {
private:
    double base, altura;
public:
    Triangulo(double b, double h) : base(b), altura(h) {}
    void dibujar() override {
        cout << "Dibujando un triángulo" << endl;
    }
    double calcularArea() override {
        return 0.5 * base * altura;
    }
};

int main() {
    Circulo c(5);
    Rectangulo r(4, 6);
    Triangulo t(3, 7);

    c.dibujar();
    cout << "Área del círculo: " << c.calcularArea() << endl;

    r.dibujar();
    cout << "Área del rectángulo: " << r.calcularArea() << endl;

    t.dibujar();
    cout << "Área del triángulo: " << t.calcularArea() << endl;

    return 0;
}
