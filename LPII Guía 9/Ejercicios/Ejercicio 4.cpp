#include <iostream>
#include <vector>
using namespace std;

// Clase base
class Personaje {
public:
    virtual void atacar() const = 0;
    virtual void defender() const = 0;
    virtual void habilidadEspecial() const = 0;
    virtual void mostrarInfo() const = 0;
    virtual ~Personaje() {}
};

// Guerrero
class Guerrero : public Personaje {
private:
    int vida = 150, fuerza = 30;
public:
    void atacar() const override {
        cout << "Guerrero ataca con su espada. Daño: " << fuerza << endl;
    }
    void defender() const override {
        cout << "Guerrero se cubre con su escudo. Defensa +10\n";
    }
    void habilidadEspecial() const override {
        cout << "¡Golpe Brutal! Daño doble: " << fuerza * 2 << endl;
    }
    void mostrarInfo() const override {
        cout << "Clase: Guerrero | Vida: " << vida << " | Fuerza: " << fuerza << endl;
    }
};

// Mago
class Mago : public Personaje {
private:
    int vida = 100, mana = 80;
public:
    void atacar() const override {
        cout << "Mago lanza una bola de fuego. Daño mágico: 25\n";
    }
    void defender() const override {
        cout << "Mago crea un escudo mágico. Defensa +15\n";
    }
    void habilidadEspecial() const override {
        cout << "¡Tormenta Arcana! Daño mágico masivo\n";
    }
    void mostrarInfo() const override {
        cout << "Clase: Mago | Vida: " << vida << " | Maná: " << mana << endl;
    }
};

// Arquero
class Arquero : public Personaje {
private:
    int vida = 120, precision = 35;
public:
    void atacar() const override {
        cout << "Arquero dispara una flecha certera. Daño: " << precision << endl;
    }
    void defender() const override {
        cout << "Arquero esquiva el ataque. Defensa +5\n";
    }
    void habilidadEspecial() const override {
        cout << "¡Lluvia de Flechas! Ataque múltiple\n";
    }
    void mostrarInfo() const override {
        cout << "Clase: Arquero | Vida: " << vida << " | Precisión: " << precision << endl;
    }
};

int main() {
    vector<Personaje*> personajes;
    int opcion;

    do {
        cout << "\n--- JUEGO DE ROL ---\n";
        cout << "1. Crear personaje\n";
        cout << "2. Ver personajes y acciones\n";
        cout << "3. Salir\n";
        cout << "Opción: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "\nClases disponibles:\n";
            cout << "1. Guerrero\n";
            cout << "2. Mago\n";
            cout << "3. Arquero\n";
            int tipo;
            cin >> tipo;

            switch (tipo) {
                case 1: personajes.push_back(new Guerrero()); break;
                case 2: personajes.push_back(new Mago()); break;
                case 3: personajes.push_back(new Arquero()); break;
                default: cout << "Clase inválida.\n";
            }

        } else if (opcion == 2) {
            if (personajes.empty()) {
                cout << "No hay personajes creados.\n";
            } else {
                for (size_t i = 0; i < personajes.size(); ++i) {
                    cout << "\nPersonaje #" << i + 1 << ":\n";
                    personajes[i]->mostrarInfo();
                    personajes[i]->atacar();
                    personajes[i]->defender();
                    personajes[i]->habilidadEspecial();
                }
            }
        } else if (opcion != 3) {
            cout << "Opción inválida.\n";
        }

    } while (opcion != 3);

    for (Personaje* p : personajes) delete p;

    return 0;
}
