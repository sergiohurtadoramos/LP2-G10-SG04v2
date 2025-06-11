#include <iostream>
using namespace std;
class Animal {
public:
    virtual void hacerSonido() {
        cout << "El animal hace un sonido genérico." << endl;
    }
};
class Perro : public Animal {
public:
    void hacerSonido() override {
        cout << "El perro dice: ¡Guau!" << endl;
    }
};
class Gato : public Animal {
public:
    void hacerSonido() override {
        cout << "El gato dice: ¡Miau!" << endl;
    }
};
class Vaca : public Animal {
public:
    void hacerSonido() override {
        cout << "La vaca dice: ¡Muuu!" << endl;
    }
};
int main() {
    Animal* animales[3];
    animales[0] = new Perro();
    animales[1] = new Gato();
    animales[2] = new Vaca();
    for (int i = 0; i < 3; ++i) {
        animales[i]->hacerSonido();
    }
    for (int i = 0; i < 3; ++i) {
        delete animales[i];
    }
    return 0;
}

