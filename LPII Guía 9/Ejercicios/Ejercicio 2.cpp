#include <iostream>
#include <vector>
using namespace std;

// Clase base abstracta
class Animal {
public:
    virtual void comer() const = 0;
    virtual void dormir() const = 0;
    virtual void moverse() const = 0;
    virtual void mostrarInfo() const = 0;
    virtual ~Animal() {}
};

// Mamífero
class Mamifero : public Animal {
public:
    void comer() const override {
        cout << "El mamífero está comiendo hierba o carne" << endl;
    }
    void dormir() const override {
        cout << "El mamífero duerme por la noche" << endl;
    }
    void moverse() const override {
        cout << "El mamífero camina sobre patas" << endl;
    }
    void mostrarInfo() const override {
        cout << "Tipo: Mamífero" << endl;
    }
};

// Ave
class Ave : public Animal {
public:
    void comer() const override {
        cout << "El ave picotea semillas o insectos" << endl;
    }
    void dormir() const override {
        cout << "El ave duerme en su nido" << endl;
    }
    void moverse() const override {
        cout << "El ave vuela por los cielos" << endl;
    }
    void mostrarInfo() const override {
        cout << "Tipo: Ave" << endl;
    }
};

// Reptil
class Reptil : public Animal {
public:
    void comer() const override {
        cout << "El reptil devora insectos o pequeños animales" << endl;
    }
    void dormir() const override {
        cout << "El reptil duerme durante el día" << endl;
    }
    void moverse() const override {
        cout << "El reptil se arrastra lentamente" << endl;
    }
    void mostrarInfo() const override {
        cout << "Tipo: Reptil" << endl;
    }
};

// Menú principal
int main() {
    vector<Animal*> animales;
    int opcion;

    do {
        cout << "\n--- SIMULADOR DE ANIMALES ---\n";
        cout << "1. Crear animal\n";
        cout << "2. Ver acciones de animales\n";
        cout << "3. Salir\n";
        cout << "Opción: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "\nSeleccione la especie:\n";
            cout << "1. Mamífero\n";
            cout << "2. Ave\n";
            cout << "3. Reptil\n";
            int tipo;
            cin >> tipo;

            switch (tipo) {
                case 1:
                    animales.push_back(new Mamifero());
                    break;
                case 2:
                    animales.push_back(new Ave());
                    break;
                case 3:
                    animales.push_back(new Reptil());
                    break;
                default:
                    cout << "Tipo inválido.\n";
            }

        } else if (opcion == 2) {
            if (animales.empty()) {
                cout << "No hay animales aún.\n";
            } else {
                for (size_t i = 0; i < animales.size(); ++i) {
                    cout << "\nAnimal #" << i + 1 << ":\n";
                    animales[i]->mostrarInfo();
                    animales[i]->comer();
                    animales[i]->dormir();
                    animales[i]->moverse();
                }
            }

        } else if (opcion == 3) {
            cout << "Cerrando simulador...\n";
        } else {
            cout << "Opción inválida.\n";
        }

    } while (opcion != 3);

    for (Animal* a : animales) delete a;

    return 0;
}
