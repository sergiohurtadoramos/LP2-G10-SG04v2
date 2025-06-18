#include <iostream>
#include <string>
using namespace std;

// Clase que representa una entrega
class Entrega {
private:
    string codigo;
    string destino;
    string vehiculoAsignado;

public:
    Entrega(string c, string d) : codigo(c), destino(d), vehiculoAsignado("No asignado") {}

    // Método genérico para asignar cualquier tipo de vehículo
    template <typename T>
    void asignarVehiculo(T vehiculo) {
        // Conversión simple a string (puede mejorarse con std::to_string o template specialization)
        vehiculoAsignado = vehiculo;
    }

    // Método genérico para registrar datos adicionales (pueden ser horarios, prioridad, etc.)
    template <typename T>
    void registrarDato(string nombreCampo, T valor) {
        cout << "Dato registrado [" << nombreCampo << "]: " << valor << endl;
    }

    void mostrarEntrega() {
        cout << "Entrega: " << codigo << endl;
        cout << "Destino: " << destino << endl;
        cout << "Vehículo asignado: " << vehiculoAsignado << endl;
    }
};

int main() {
    // Crear entrega
    Entrega e1("E-001", "Av. Central 123");

    // Asignar vehículo usando template (tipo string)
    e1.asignarVehiculo<string>("Camión Furgón 4x4");

    // Registrar diferentes tipos de datos usando métodos genéricos
    e1.registrarDato("Hora programada", "14:30");
    e1.registrarDato("Prioridad", 1);
    e1.registrarDato("Distancia estimada (km)", 12.7);

    // Mostrar datos
    e1.mostrarEntrega();

    return 0;
}
