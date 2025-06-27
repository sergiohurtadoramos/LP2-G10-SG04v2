#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

// Función para verificar si un carácter es vocal (mayúscula o minúscula)
bool esVocal(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    string entrada;
    deque<char> caracteres;

    // Ingreso de cadena
    cout << "Ingresa una cadena de texto: ";
    getline(cin, entrada);

    // Almacenar en deque
    for (char c : entrada)
        caracteres.push_back(c);

    // a) Mostrar caracteres uno por uno con iterador
    cout << "\nCaracteres uno por uno:\n";
    for (deque<char>::iterator it = caracteres.begin(); it != caracteres.end(); ++it)
        cout << *it << " ";
    cout << endl;

    // b) Reemplazar vocales con '*'
    for (auto it = caracteres.begin(); it != caracteres.end(); ++it) {
        if (esVocal(*it))
            *it = '*';
    }

    // Mostrar cadena modificada
    cout << "\nCadena con vocales reemplazadas por '*': ";
    for (char c : caracteres)
        cout << c;
    cout << endl;

    // c) Mostrar en orden inverso usando iterador inverso
    cout << "\nCadena en orden inverso:\n";
    for (deque<char>::reverse_iterator rit = caracteres.rbegin(); rit != caracteres.rend(); ++rit)
        cout << *rit;
    cout << endl;

    return 0;
}
