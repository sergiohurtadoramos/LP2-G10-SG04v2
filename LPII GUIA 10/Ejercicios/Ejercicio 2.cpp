#include <iostream>
using namespace std;

class Logistica {
public:
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
        cout << "Rutas ordenadas plantillas de método: ";
        for (int i = 0; i < tam; i++) {
            cout << rutas[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    int distancias[] = {12, 7, 20, 4};
    int tam = 4;
    Logistica empresa;
    empresa.ordenarRutas(distancias, tam);  

    return 0;
}


