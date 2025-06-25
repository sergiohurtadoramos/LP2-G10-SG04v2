#include <iostream>

using namespace std;

int divide(int a, int b) {
    if (b == 0) {
        throw runtime_error("Error: no se puede dividir por cero.");
    }
    return a / b;
}

int main() {
    int x, y;

    cout << "Ingrese dos numeros (dividendo y divisor): ";
    cin >> x >> y;

    try {
        int resultado = divide(x, y);
        cout << "Resultado: " << resultado << endl;
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }

    
    try {
        cout << "\nDividiendo 20 entre 4: ";
        cout << divide(20, 4) << endl;
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }

    try {
        cout << "Dividiendo 9 entre 0: ";
        cout << divide(9, 0) << endl;
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
