#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct Contacto {
    string nombre;
    string telefono;
    string correo;
};
vector<Contacto> contactos;
void agregarContacto() {
    Contacto c;
    cout << "Nombre: ";
    cin.ignore();
    getline(cin, c.nombre);
    cout << "Teléfono: ";
    getline(cin, c.telefono);
    cout << "Correo: ";
    getline(cin, c.correo);
    contactos.push_back(c);
    cout << "Contacto agregado.";
}
void buscarContacto() {
    string nombre;
    cout << "Nombre del contacto a buscar: ";
    cin.ignore();
    getline(cin, nombre);
    for (int i = 0; i < contactos.size(); i++) {
        if (contactos[i].nombre == nombre) {
            cout << "Nombre: " << contactos[i].nombre << endl;
            cout << "Teléfono: " << contactos[i].telefono << endl;
            cout << "Correo: " << contactos[i].correo << endl;
            return;
        }
    }
    cout << "Contacto no encontrado.";
}
void actualizarContacto() {
    string nombre;
    cout << "Nombre del contacto a actualizar: ";
    cin.ignore();
    getline(cin, nombre);
    for (int i = 0; i < contactos.size(); i++) {
        if (contactos[i].nombre == nombre) {
            cout << "Nuevo teléfono: ";
            getline(cin, contactos[i].telefono);
            cout << "Nuevo correo: ";
            getline(cin, contactos[i].correo);
            cout << "Contacto actualizado.";
            return;
        }
    }
    cout << "Contacto no encontrado.";
}
void mostrarContactosOrdenados() {
    if (contactos.empty()) {
        cout << "No hay contactos registrados.";
        return;
    }
    vector<Contacto> lista = contactos;
    sort(lista.begin(), lista.end(), [](Contacto a, Contacto b) {
        return a.nombre < b.nombre;
    });
    cout << "Lista de contactos ordenada:\n";
    for (int i = 0; i < lista.size(); i++) {
        cout << "Nombre: " << lista[i].nombre << endl;
        cout << "Teléfono: " << lista[i].telefono << endl;
        cout << "Correo: " << lista[i].correo << endl;
        cout << "-------------------\n";
    }
}
int main() {
    int opcion;
    do {
        cout << "\n1. Agregar contacto\n";
        cout << "2. Buscar contacto\n";
        cout << "3. Actualizar contacto\n";
        cout << "4. Ver contactos ordenados\n";
        cout << "5. Salir\n";
        cout << "Opción: ";
        cin >> opcion;
        if (opcion == 1) agregarContacto();
        else if (opcion == 2) buscarContacto();
        else if (opcion == 3) actualizarContacto();
        else if (opcion == 4) mostrarContactosOrdenados();
        else if (opcion == 5) cout << "Fin del programa.\n";
        else cout << "Opción incorrecta.\n";
    } while (opcion != 5);
    return 0;
}


