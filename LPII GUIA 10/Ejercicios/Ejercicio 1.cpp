#include <iostream>
using namespace std;
template <typename T>
void ordenarRutas(T rutas[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = i + 1; j < tam; j++) {
            if (rutas[i] > rutas[j]) {
                T aux = rutas[i];
                rutas[i] = rutas[j];
                rutas[j] = aux;
            }
        }
    }

    cout << "Rutas ordenadas con plantillas de función: ";
    for (int i = 0; i < tam; i++) {
        cout << rutas[i] << " ";
    }
    cout << endl;
}

int main() {
    float tiempos[] = {3.5, 2.1, 4.0, 1.8};
    int tam = 4;

    ordenarRutas(tiempos, tam); 

    return 0;
}


