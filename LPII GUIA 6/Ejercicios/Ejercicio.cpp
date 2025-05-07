#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Alumno {
private:
    string nombre;
    int edad;
    float promedio;

public:
    Alumno(string n, int e, float p) : nombre(n), edad(e), promedio(p) {}

    friend class Grupo;

    friend bool esMejorQue(const Alumno& a, const Alumno& b);

    bool operator<(const Alumno& otro) const {
        return promedio < otro.promedio;
    }

    friend ostream& operator<<(ostream& os, const Alumno& a) {
        os << "Nombre: " << a.nombre << ", Edad: " << a.edad << ", Promedio: " << a.promedio;
        return os;
    }
};

bool esMejorQue(const Alumno& a, const Alumno& b) {
    return a.promedio > b.promedio;
}

class Grupo {
private:
    vector<Alumno> alumnos;
    int cantidad;

public:
    Grupo(int c) : cantidad(c) {}

    void mostrarGrupo() {
        cout << "Grupo de " << alumnos.size() << " alumnos:" << endl << endl;
        for (const Alumno& a : alumnos)
            cout << a << endl;
    }

    void agregarAlumno(string nombre, int edad, float promedio) {
        if (alumnos.size() < cantidad) {
            alumnos.emplace_back(nombre, edad, promedio);
        } else {
            cout << "No se puede agregar más alumnos. Capacidad llena." << endl;
        }
    }

    void ordenarPorPromedio() {
        sort(alumnos.begin(), alumnos.end());
    }

    float promedioGeneral() {
        float suma = 0;
        int total = 0;
    
        for (int i = 0; i < alumnos.size(); i++) {
            suma += alumnos[i].promedio;
            total++;
        }
    
        if (total == 0)
            return 0;
        else
            return suma / total;
    }

   Alumno mejorAlumno() {
        if (alumnos.size() == 0) {
            Alumno vacio("", 0, 0);  
            return vacio;
        }
    
        Alumno mejor = alumnos[0];
    
        for (int i = 1; i < alumnos.size(); i++) {
            if (alumnos[i].promedio > mejor.promedio) {
                mejor = alumnos[i];
            }
        }
    
        return mejor;
    }
};

int main() {
    Grupo grupo(5);

    grupo.agregarAlumno("Pablo", 17, 18.5);
    grupo.agregarAlumno("Ana", 18, 16.7);
    grupo.agregarAlumno("Luis", 17, 19.1);
    grupo.agregarAlumno("Valeria", 16, 17.8);
    grupo.agregarAlumno("Carlos", 18, 15.5);

    grupo.mostrarGrupo();

    cout << endl << "Promedio general del grupo: " << grupo.promedioGeneral() << endl;

    Alumno mejor = grupo.mejorAlumno();
    cout << "Mejor alumno: " << mejor << endl;

    return 0;
}