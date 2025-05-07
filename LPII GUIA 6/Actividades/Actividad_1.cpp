#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Estudiante {
public:
    string nombre;
    float promedio;
    Estudiante(string nom, float prom) : nombre(nom), promedio(prom) {}
    void imprimir() {
        cout << nombre << " - Promedio: " << promedio << endl;
    }
};
bool comparar(Estudiante e1, Estudiante e2) {
    return e1.promedio > e2.promedio;  
}
int main() {
    int n;
    cout << "Cuántos estudiantes quieres ingresar? ";
    cin >> n;
    vector<Estudiante> estudiantes;
    string nombre;
    float promedio;
    for (int i = 0; i < n; i++) {
        cout << "Nombre del estudiante: ";
        cin >> nombre;
        cout << "Promedio: ";
        cin >> promedio;
        estudiantes.push_back(Estudiante(nombre, promedio));
    }
    sort(estudiantes.begin(), estudiantes.end(), comparar);
    cout << "\nEstudiantes ordenados por promedio: \n";
    for (int i = 0; i < estudiantes.size(); i++) {
        estudiantes[i].imprimir();
    }
    cout << "\nEstudiantes con promedio mayor a 14: \n";
    for (int i = 0; i < estudiantes.size(); i++) {
        if (estudiantes[i].promedio > 14) {
            estudiantes[i].imprimir();
        }
    }
    return 0;
}



