#include <iostream>
#include <string>
using namespace std;
class Movil {
protected:
    string marca;
    string modelo;
    string sistemaOperativo;

public:
    Movil(string m, string mod, string so) : marca(m), modelo(mod), sistemaOperativo(so) {}
    virtual ~Movil() {}
    void mostrarInfo() {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Sistema Operativo: " << sistemaOperativo << endl;
    }
};
class Telefono : public Movil {
public:
    Telefono(string m, string mod, string so) : Movil(m, mod, so) {}
    ~Telefono() {}
};
class Tablet : public Movil {
public:
    Tablet(string m, string mod, string so) : Movil(m, mod, so) {}
    ~Tablet() {}
};

int main() {
    string marca, modelo, sistemaOperativo;
    cout << "Ingrese los datos del Teléfono:" << endl;
    cout << "Marca: ";
    getline(cin, marca);
    cout << "Modelo: ";
    getline(cin, modelo);
    cout << "Sistema Operativo: ";
    getline(cin, sistemaOperativo);

    Telefono t1(marca, modelo, sistemaOperativo);
    cout << "\nInformación del Teléfono:" << endl;
    t1.mostrarInfo();
    cout << "\nIngrese los datos de la Tablet:" << endl;
    cout << "Marca: ";
    getline(cin, marca);
    cout << "Modelo: ";
    getline(cin, modelo);
    cout << "Sistema Operativo: ";
    getline(cin, sistemaOperativo);

    Tablet tab1(marca, modelo, sistemaOperativo);
    cout << "\nInformación de la Tablet:" << endl;
    tab1.mostrarInfo();

    return 0;
}



