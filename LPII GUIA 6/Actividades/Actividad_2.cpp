#include <iostream>
using namespace std;

class Circulo {
private:
    float radio;
public:
    Circulo(float r) : radio(r) {}
    float getRadio() const {
        return radio;
    }
    friend float calcularArea(Circulo c);
};
float calcularArea(Circulo c) {
    return 3.14159 * c.getRadio() * c.getRadio();  
}
int main() {
    float radio;
    cout << "Ingresa el radio del círculo: ";
    cin >> radio;
    Circulo c1(radio);
    cout << "Área del círculo con radio " << c1.getRadio() << " es: " << calcularArea(c1) << endl;

    return 0;
}





