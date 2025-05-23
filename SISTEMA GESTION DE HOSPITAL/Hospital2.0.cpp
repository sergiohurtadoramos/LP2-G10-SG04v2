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
    void mostrarDoctor() {
        mostrarInformacion();
        cout << "Especialidad: " << especialidad << ", Horario: " << horario << endl;
    }
    string getEspecialidad() { return especialidad; }
};

class Paciente : public Persona {
    string historialMedico;
    string seguroSocial;
public:
    Paciente(string _nombre, string _dni, int _edad, string _celular, string _historialMedico, string _seguroSocial)
        : Persona(_nombre, _dni, _edad, _celular) {
        historialMedico = _historialMedico;
        seguroSocial = _seguroSocial;
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
    void mostrarCita() {
        cout << "Cita: " << fecha << " - " << hora << ", Paciente: " << paciente->getNombre()
             << ", Doctor: " << doctor->getNombre() << ", Costo: S/." << costo << endl;
    }
    float getCosto() { return costo; }
    string getEspecialidad() { return doctor->getEspecialidad(); }
    string getDoctorNombre() { return doctor->getNombre(); }
    string getPacienteNombre() { return paciente->getNombre(); }
};

class Administrador {
    vector<Doctor*> listaDoctores;
    vector<Cita*> listaCitas;
public:
    void agregarDoctor(Doctor* doctor) {
        listaDoctores.push_back(doctor);
    }
    void registrarCita(Cita* cita) {
        listaCitas.push_back(cita);
    }
    void mostrarListaCitas() {
        for (auto c : listaCitas) {
            c->mostrarCita();
        }
    }
    vector<Doctor*>& getListaDoctores() {
        return listaDoctores;
    }
    void reporteVentas() {
        float total = 0;
        cout << "--- Reporte de Ventas ---" << endl;
        for (auto c : listaCitas) total += c->getCosto();
        cout << "Total general: S/." << total << endl;
    }
};

int main() {
    Administrador admin;
    vector<Paciente*> pacientes;

    int opcion;
    do {
        cout << "\n--- MENU PRINCIPAL ---" << endl;
        cout << "1. Registrar Doctor" << endl;
        cout << "2. Registrar Paciente" << endl;
        cout << "3. Agendar Cita" << endl;
        cout << "4. Mostrar Citas" << endl;
        cout << "5. Reporte de Ventas" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            string nombre, dni, celular, especialidad, horario;
            int edad;
            cout << "Nombre del doctor: "; getline(cin, nombre);
            cout << "DNI: "; getline(cin, dni);
            cout << "Edad: "; cin >> edad; cin.ignore();
            cout << "Celular: "; getline(cin, celular);
            cout << "Especialidad: "; getline(cin, especialidad);
            cout << "Horario: "; getline(cin, horario);
            admin.agregarDoctor(new Doctor(nombre, dni, edad, celular, especialidad, horario));

        } else if (opcion == 2) {
            string nombre, dni, celular, historial, seguro;
            int edad;
            cout << "Nombre del paciente: "; getline(cin, nombre);
            cout << "DNI: "; getline(cin, dni);
            cout << "Edad: "; cin >> edad; cin.ignore();
            cout << "Celular: "; getline(cin, celular);
            cout << "Historial Medico: "; getline(cin, historial);
            cout << "Seguro Social: "; getline(cin, seguro);
            pacientes.push_back(new Paciente(nombre, dni, edad, celular, historial, seguro));

        } else if (opcion == 3) {
            if (pacientes.empty() || admin.getListaDoctores().empty()) {
                cout << "Debe haber al menos un paciente y un doctor registrado." << endl;
                continue;
            }
            string fecha, hora;
            float costo;
            cout << "Fecha (YYYY-MM-DD): "; getline(cin, fecha);
            cout << "Hora: "; getline(cin, hora);
            cout << "Costo: "; cin >> costo; cin.ignore();

            cout << "Seleccione Doctor:" << endl;
            for (size_t i = 0; i < admin.getListaDoctores().size(); ++i) {
                cout << i << ". ";
                admin.getListaDoctores()[i]->mostrarDoctor();
            }
            int doctorIndex;
            cout << "Indice: "; cin >> doctorIndex; cin.ignore();

            admin.registrarCita(new Cita(fecha, hora, costo, pacientes[0], admin.getListaDoctores()[doctorIndex]));

        } else if (opcion == 4) {
            admin.mostrarListaCitas();

        } else if (opcion == 5) {
            admin.reporteVentas();
        }

    } while (opcion != 0);

    return 0;
}
