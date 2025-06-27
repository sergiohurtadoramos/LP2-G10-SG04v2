#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // Para accumulate

using namespace std;

bool esPar(int n) {
    return n % 2 == 0;
}

int main() {
    vector<int> numeros;
    int cantidad, valor;

    cout << "¿Cuántos números deseas ingresar? ";
    cin >> cantidad;

    // Ingreso de números
    for (int i = 0; i < cantidad; i++) {
        cout << "Ingresa el número " << i + 1 << ": ";
        cin >> valor;
        numeros.push_back(valor);
    }

    // Mostrar lista original
    cout << "\nLista original: ";
    for (int n : numeros)
        cout << n << " ";
    cout << endl;

    // a) Calcular la suma
    int suma = accumulate(numeros.begin(), numeros.end(), 0);
    cout << "Suma de los números: " << suma << endl;

    // b) Encontrar el máximo y mínimo
    int minimo = *min_element(numeros.begin(), numeros.end());
    int maximo = *max_element(numeros.begin(), numeros.end());
    cout << "Mínimo: " << minimo << ", Máximo: " << maximo << endl;

    // c) Ordenar ascendentemente
    sort(numeros.begin(), numeros.end());
    cout << "Lista ordenada: ";
    for (int n : numeros)
        cout << n << " ";
    cout << endl;

    // d) Eliminar los números pares
    numeros.erase(remove_if(numeros.begin(), numeros.end(), esPar), numeros.end());
    cout << "Lista final (sin pares): ";
    for (int n : numeros)
        cout << n << " ";
    cout << endl;

    return 0;
}
