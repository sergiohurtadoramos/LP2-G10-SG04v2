#include <iostream>
using namespace std;
class Animal {
public:
    virtual void hacerSonido() {
        cout << "El animal hace un sonido" << endl;
    }
    virtual ~Animal() {} 
};
class Perro : public Animal {
public:
    void hacerSonido() override {
        cout << "Guau guau" << endl;
    }
};
class Gato : public Animal {
public:
    void hacerSonido() override {
        cout << "Miau" << endl;
    }
};
class Vaca : public Animal {
public:
    void hacerSonido() override {
        cout << "Muu" << endl;
    }
};
int main() {
    Animal* animal1 = new Perro();
    Animal* animal2 = new Gato();
    Animal* animal3 = new Vaca();
    cout << "Perro dice: ";
    animal1->hacerSonido();
    cout << "Gato dice: ";
    animal2->hacerSonido();
    cout << "Vaca dice: ";
    animal3->hacerSonido();
    delete animal1;
    delete animal2;
    delete animal3;

    return 0;
}


