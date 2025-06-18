#include <iostream>
using namespace std;
template <class T>
class RutaRecipiente {
private:
    T rutas[100];
    int tam;
public:
    RutaRecipiente(T datos[], int t) {
        tam = t;
        for (int i = 0; i < tam; i++) {
            rutas[i] = datos[i];
        }
    }
    void ordenar() {
        for (int i = 0; i < tam - 1; i++) {
            for (int j = i + 1; j < tam; j++) {
                if (rutas[i] > rutas[j]) {
                    T aux = rutas[i];
                    rutas[i] = rutas[j];
                    rutas[j] = aux;
                }
            }
        }
    }
    void mostrar() {
        cout << "Rutas ordenadas con clase recipiente: ";
        for (int i = 0; i < tam; i++) {
            cout << rutas[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    string zonas[] = {"Zona C", "Zona A", "Zona B"};
    int tam = 3;
    RutaRecipiente<string> rutas(zonas, tam);
    rutas.ordenar();
    rutas.mostrar();

    return 0;
}

