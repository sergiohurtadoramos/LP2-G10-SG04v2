#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class FiguraGeometrica {
public:
    virtual double calcularArea() const = 0;
    virtual double calcularPerimetro() const = 0;
    virtual void mostrarInformacion() const = 0;
    virtual ~FiguraGeometrica() {}
};

class Circulo : public FiguraGeometrica {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}
    double calcularArea() const override { return 3.1416 * radio * radio; }
    double calcularPerimetro() const override { return 2 * 3.1416 * radio; }
    void mostrarInformacion() const override {
        cout << "Círculo - Radio: " << radio << endl;
    }
};

class Rectangulo : public FiguraGeometrica {
private:
    double base, altura;
public:
    Rectangulo(double b, double h) : base(b), altura(h) {}
    double calcularArea() const override { return base * altura; }
    double calcularPerimetro() const override { return 2 * (base + altura); }
    void mostrarInformacion() const override {
        cout << "Rectángulo - Base: " << base << ", Altura: " << altura << endl;
    }
};

class TrianguloRectangulo : public FiguraGeometrica {
private:
    double base, altura;
public:
    TrianguloRectangulo(double b, double h) : base(b), altura(h) {}
    double calcularArea() const override { return (base * altura) / 2; }
    double calcularPerimetro() const override {
        return base + altura + sqrt(base * base + altura * altura);
    }
    void mostrarInformacion() const override {
        cout << "Triángulo Rectángulo - Base: " << base << ", Altura: " << altura << endl;
    }
};

int main() {
    vector<FiguraGeometrica*> figuras;
    int opcion;

    do {
        cout << "\n--- MENÚ ---\n";
        cout << "1. Agregar figura\n";
        cout << "2. Ver figuras registradas\n";
        cout << "3. Salir\n";
        cout << "Opción: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "\nSeleccione el tipo de figura:\n";
            cout << "1. Círculo\n";
            cout << "2. Rectángulo\n";
            cout << "3. Triángulo rectángulo\n";
            int tipo;
            cin >> tipo;

            switch (tipo) {
                case 1: {
                    double r;
                    cout << "Ingrese radio: ";
                    cin >> r;
                    figuras.push_back(new Circulo(r));
                    break;
                }
                case 2: {
                    double b, h;
                    cout << "Ingrese base: ";
                    cin >> b;
                    cout << "Ingrese altura: ";
                    cin >> h;
                    figuras.push_back(new Rectangulo(b, h));
                    break;
                }
                case 3: {
                    double b, h;
                    cout << "Ingrese base: ";
                    cin >> b;
                    cout << "Ingrese altura: ";
                    cin >> h;
                    figuras.push_back(new TrianguloRectangulo(b, h));
                    break;
                }
                default:
                    cout << "Tipo de figura inválido.\n";
            }

        } else if (opcion == 2) {
            if (figuras.empty()) {
                cout << "No hay figuras registradas.\n";
            } else {
                for (size_t i = 0; i < figuras.size(); ++i) {
                    cout << "\nFigura #" << i + 1 << ":\n";
                    figuras[i]->mostrarInformacion();
                    cout << "Área: " << figuras[i]->calcularArea() << endl;
                    cout << "Perímetro: " << figuras[i]->calcularPerimetro() << endl;
                }
            }
        } else if (opcion != 3) {
            cout << "Opción no válida.\n";
        }

    } while (opcion != 3);

    for (FiguraGeometrica* f : figuras) delete f;

    return 0;
}
