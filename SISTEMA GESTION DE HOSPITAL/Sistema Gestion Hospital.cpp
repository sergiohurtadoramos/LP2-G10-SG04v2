#include <iostream>
#include <vector>
using namespace std;

class Persona {
protected:
    string nombre;
    string dni;
    int edad;
    string celular;
public:
    Persona(string _nombre, string _dni, int _edad, string _celular) {
        nombre = _nombre;
        dni = _dni;
        edad = _edad;
        celular = _celular;
    }
    void mostrarInformacion() {
        cout << "Nombre: " << nombre << ", DNI: " << dni << ", Edad: " << edad << ", Celular: " << celular << endl;
    }
    string getNombre() { return nombre; }
};

class Doctor : public Persona {
    string especialidad;
    string horario;
public:
    Doctor(string _nombre, string _dni, int _edad, string _celular, string _especialidad, string _horario)
        : Persona(_nombre, _dni, _edad, _celular) {
        especialidad = _especialidad;
        horario = _horario;
    }
    void atenderPaciente() {
        cout << "Atendiendo paciente..." << endl;
    }
    void generarInforme() {
        cout << "Generando informe médico..." << endl;
    }
};

class Cita;

class Paciente : public Persona {
    string historialMedico;
    string seguroSocial;
public:
    Paciente(string _nombre, string _dni, int _edad, string _celular, string _historialMedico, string _seguroSocial)
        : Persona(_nombre, _dni, _edad, _celular) {
        historialMedico = _historialMedico;
        seguroSocial = _seguroSocial;
    }
    void pagarCita() {
        cout << "Cita pagada." << endl;
    }
    void ingresarReclamo() {
        cout << "Reclamo ingresado." << endl;
    }
};

class Cita {
    string fecha;
    string hora;
    float costo;
    Paciente* paciente;
    Doctor* doctor;
public:
    Cita(string _fecha, string _hora, float _costo, Paciente* _paciente, Doctor* _doctor) {
        fecha = _fecha;
        hora = _hora;
        costo = _costo;
        paciente = _paciente;
        doctor = _doctor;
    }
    void validarCita() {
        cout << "Cita validada para " << paciente->getNombre() << " con el Dr. " << doctor->getNombre() << " el " << fecha << " a las " << hora << "." << endl;
    }
    void mostrarCita() {
        cout << "Cita: " << fecha << " - " << hora << ", Paciente: " << paciente->getNombre()
             << ", Doctor: " << doctor->getNombre() << ", Costo: S/." << costo << endl;
    }
    float getCosto() { return costo; }
    string getFecha() { return fecha; }
    Doctor* getDoctor() { return doctor; }
};

class Reclamo {
    string descripcion;
    string fecha;
    Cita* cita;
public:
    Reclamo(string _descripcion, string _fecha, Cita* _cita) {
        descripcion = _descripcion;
        fecha = _fecha;
        cita = _cita;
        cout << "Reclamo registrado: " << descripcion << " en fecha " << fecha << endl;
    }
    void mostrarReclamo() {
        cout << "Reclamo del " << fecha << ": " << descripcion << " - Cita con " << cita->getDoctor()->getNombre() << endl;
    }
};

class Administrador {
    vector<Doctor*> listaDoctores;
    vector<Cita*> listaCitas;
public:
    void agregarDoctor(Doctor* doctor) {
        listaDoctores.push_back(doctor);
    }
    void actualizarDoctor() {
        cout << "Actualizar doctor..." << endl;
    }
    void mostrarListaCitas() {
        for (auto c : listaCitas) {
            c->mostrarCita();
        }
    }
    void mostrarListaDoctores() {
        for (auto d : listaDoctores) {
            d->mostrarInformacion();
        }
    }
    void registrarCita(Cita* cita) {
        listaCitas.push_back(cita);
    }
    void reporteVentas() {
        float total = 0;
        for (auto c : listaCitas) total += c->getCosto();
        cout << "Ingresos totales por citas: S/." << total << endl;
    }
};

int main() {
    Paciente* paciente1 = new Paciente("Lucía Pérez", "11223344", 30, "987654321", "Historial1", "SeguroX");
    Doctor* doctor1 = new Doctor("Juan Ramos", "12345678", 45, "912345678", "Pediatría", "8am - 4pm");
    Administrador admin;
    admin.agregarDoctor(doctor1);

    Cita* cita1 = new Cita("2025-04-20", "10:30", 150.0, paciente1, doctor1);
    cita1->validarCita();
    admin.registrarCita(cita1);

    Reclamo* reclamo1 = new Reclamo("Demora en la atención", "2025-04-21", cita1);
    reclamo1->mostrarReclamo();

    doctor1->mostrarInformacion();
    admin.mostrarListaCitas();
    admin.reporteVentas();

    delete paciente1;
    delete doctor1;
    delete cita1;
    delete reclamo1;
    return 0;
}