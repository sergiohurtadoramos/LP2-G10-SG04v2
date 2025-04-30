#include <iostream>
#include <string>
using namespace std;

class Gerente {
public:
    Gerente(string nombre) {
        cout << "Constructor de Gerente: " << nombre << endl;
    }
    ~Gerente() {
        cout << "Destructor de Gerente" << endl;
    }
};

class Direccion {
public:
    Direccion(string ubicacion) {
        cout << "Constructor de Direccion: " << ubicacion << endl;
    }
    ~Direccion() {
        cout << "Destructor de Direccion" << endl;
    }
};

class Empresa {
private:
    Gerente gerente;
    Direccion direccion;
public:
    Empresa(string nomGerente, string dirEmpresa) 
        : gerente(nomGerente), direccion(dirEmpresa) {
        cout << "Constructor de Empresa" << endl;
    }
    ~Empresa() {
        cout << "Destructor de Empresa" << endl;
    }
};

int main() {
    string nombreGerente, ubicacionEmpresa;
    cout << "Ingrese nombre del gerente: ";
    getline(cin, nombreGerente);
    cout << "Ingrese direccion de la empresa: ";
    getline(cin, ubicacionEmpresa);

    Empresa miEmpresa(nombreGerente, ubicacionEmpresa);
    return 0;
}


