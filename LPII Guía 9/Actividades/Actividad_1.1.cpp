#include <iostream>
using namespace std;
class Animal {
public:
    void hacerSonido() {
        cout << "El animal hace un sonido genérico." << endl;
    }
};

class Perro : public Animal {
public:
    void hacerSonido() {
        cout << "El perro ladra: ¡Guau guau!" << endl;
    }
};
int main() {
    Animal* a;
    Perro p;
    a = &p;
    a->hacerSonido(); 
    return 0;
}
