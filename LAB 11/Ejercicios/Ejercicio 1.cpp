#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string nombreArchivo;
    cout << "Ingrese el nombre del archivo de texto: ";
    getline(cin, nombreArchivo); 

    ifstream archivo(nombreArchivo); 

    if (!archivo) {
        cerr << "Error: no se pudo abrir el archivo \"" << nombreArchivo << "\"." << endl;
        return 1;
    }

    string linea;
    cout << "\nContenido del archivo:\n" << endl;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    archivo.close();
    return 0;
}
