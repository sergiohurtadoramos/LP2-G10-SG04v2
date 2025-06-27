#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct Evento {
    string nombre;
    string fecha;
    vector<string> asistentes;
};
vector<Evento> eventos;
void agregarEvento() {
    Evento e;
    cout << "Nombre del evento: ";
    cin.ignore();
    getline(cin, e.nombre);
    cout << "Fecha del evento: ";
    getline(cin, e.fecha);
    eventos.push_back(e);
    cout << "Evento agregado.";
}
void agregarAsistente() {
    string nombre;
    cout << "Nombre del evento: ";
    cin.ignore();
    getline(cin, nombre);
    for (int i = 0; i < eventos.size(); i++) {
        if (eventos[i].nombre == nombre) {
            string asistente;
            cout << "Nombre del asistente: ";
            getline(cin, asistente);
            eventos[i].asistentes.push_back(asistente);
            cout << "Asistente agregado.";
            return;
        }
    }
    cout << "Evento no encontrado.";
}
void verAsistentesOrdenados() {
    string nombre;
    cout << "Nombre del evento: ";
    cin.ignore();
    getline(cin, nombre);
    for (int i = 0; i < eventos.size(); i++) {
        if (eventos[i].nombre == nombre) {
            vector<string> lista = eventos[i].asistentes;
            sort(lista.begin(), lista.end());
            cout << "Asistentes:";
            for (int j = 0; j < lista.size(); j++) {
                cout << lista[j] << endl;
            }
            return;
        }
    }
    cout << "Evento no encontrado.";
}
void buscarPorFecha() {
    string fecha;
    cout << "Ingrese la fecha: ";
    cin.ignore();
    getline(cin, fecha);
    for (int i = 0; i < eventos.size(); i++) {
        if (eventos[i].fecha == fecha) {
            cout << "- " << eventos[i].nombre << endl;
        }
    }
}
int main() {
    int opcion;
    do {
        cout << "\n1. Agregar evento\n";
        cout << "2. Agregar asistente\n";
        cout << "3. Ver asistentes ordenados\n";
        cout << "4. Buscar eventos por fecha\n";
        cout << "5. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        if (opcion == 1) agregarEvento();
        else if (opcion == 2) agregarAsistente();
        else if (opcion == 3) verAsistentesOrdenados();
        else if (opcion == 4) buscarPorFecha();
        else if (opcion == 5) cout << "Fin del programa.\n";
        else cout << "Opcion incorrecta.\n";

    } while (opcion != 5);

    return 0;
}


