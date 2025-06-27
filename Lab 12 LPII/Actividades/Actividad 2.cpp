#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <cctype> // Para toupper
#include <iterator> // Para iteradores

using namespace std;

// Función para convertir una palabra a mayúsculas
string aMayusculas(string palabra) {
    transform(palabra.begin(), palabra.end(), palabra.begin(), ::toupper);
    return palabra;
}

int main() {
    list<string> palabras;
    int cantidad;
    string palabra, buscar;

    cout << "¿Cuántas palabras deseas ingresar?: ";
    cin >> cantidad;
    cin.ignore(); // Limpiar el buffer

    // a) Leer palabras del usuario
    for (int i = 0; i < cantidad; ++i) {
        cout << "Ingresa la palabra " << i + 1 << ": ";
        getline(cin, palabra);
        palabras.push_back(palabra);
    }

    // b) Ordenar las palabras alfabéticamente
    palabras.sort();

    // Mostrar lista ordenada
    cout << "\nPalabras ordenadas alfabéticamente:\n";
    for (const auto& p : palabras)
        cout << p << endl;

    // c) Contar apariciones de una palabra
    cout << "\n¿Palabra a buscar y contar?: ";
    getline(cin, buscar);

    int ocurrencias = count(palabras.begin(), palabras.end(), buscar);
    cout << "La palabra '" << buscar << "' aparece " << ocurrencias << " veces.\n";

    // d) Convertir todas las palabras a mayúsculas
    for (auto& p : palabras)
        p = aMayusculas(p);

    // e) Mostrar lista transformada
    cout << "\nLista en MAYÚSCULAS:\n";
    for (const auto& p : palabras)
        cout << p << endl;

    return 0;
}
