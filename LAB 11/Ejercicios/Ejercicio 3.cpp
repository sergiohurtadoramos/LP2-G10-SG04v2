#include <iostream>
#include <fstream>
#include <string>
#include <cereal/archives/binary.hpp>
#include <cereal/types/string.hpp>

using namespace std;

class Persona {
private:
    string nombre;
    int edad;
    string direccion;

public:
    Persona() = default; 

    Persona(string nom, int ed, string dir)
        : nombre(nom), edad(ed), direccion(dir) {}

    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }
    string getDireccion() const { return direccion; }

    void setNombre(const string& nom) { nombre = nom; }
    void setEdad(int ed) { edad = ed; }
    void setDireccion(const string& dir) { direccion = dir; }

    template<class Archive>
    void serialize(Archive& ar) {
        ar(nombre, edad, direccion);
    }
};

int main() {
    Persona p1("Juan Juan", 5, "Av. Estados Unidos 123");

    {
        ofstream archivo("persona.bin", ios::binary);
        cereal::BinaryOutputArchive salida(archivo);
        salida(p1);
    }

    Persona p2;
    {
        ifstream archivo("persona.bin", ios::binary);
        cereal::BinaryInputArchive entrada(archivo);
        entrada(p2);
    }

    cout << "Datos de la persona deserializada:" << endl;
    cout << "Nombre: " << p2.getNombre() << endl;
    cout << "Edad: " << p2.getEdad() << endl;
    cout << "Direccion: " << p2.getDireccion() << endl;

    return 0;
}
