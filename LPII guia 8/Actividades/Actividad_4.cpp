#include <iostream>
using namespace std;
class Vehiculo {
public:
    virtual void acelerar() {
        cout << "Acelerando el vehiculo" << endl;
    }

    virtual ~Vehiculo() {} 
};
class Coche : public Vehiculo {
public:
    void acelerar() override {
        cout << "Acelerando el coche" << endl;
    }

    void encenderLuces() {
        cout << "Luces del coche encendidas" << endl;
    }
};
class Motocicleta : public Vehiculo {
public:
    void acelerar() override {
        cout << "Acelerando la motocicleta" << endl;
    }
};
int main() {
    Coche miCoche;
    cout << "Coche:" << endl;
    miCoche.acelerar();         
    miCoche.encenderLuces();      
    Motocicleta miMoto;
    cout << "\nMotocicleta:" << endl;
    miMoto.acelerar();       
    Vehiculo* vehiculo;
    vehiculo = &miCoche;
    cout << "\nUsando puntero Vehiculo* con Coche:" << endl;
    vehiculo->acelerar();       

    vehiculo = &miMoto;
    cout << "\nUsando puntero Vehiculo* con Motocicleta:" << endl;
    vehiculo->acelerar();        

    return 0;
}

