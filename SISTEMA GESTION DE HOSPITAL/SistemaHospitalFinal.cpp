#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

void limpiarEntrada() {
    cin.clear();
    while (cin.get() != '\n');
}

class Persona {
protected:
    string nombre, dni, celular;
    int edad;
public:
    Persona(string _nombre, string _dni, int _edad, string _celular)
        : nombre(_nombre), dni(_dni), edad(_edad), celular(_celular) {}
    void mostrarInformacion() {
        cout << "Nombre: " << nombre << ", DNI: " << dni << ", Edad: " << edad << ", Celular: " << celular << endl;
    }
    string getNombre() { return nombre; }
    string getDNI() { return dni; }
    void actualizarDatos(string _nombre, string _dni, int _edad, string _celular) {
        nombre = _nombre; dni = _dni; edad = _edad; celular = _celular;
    }
};

class Doctor : public Persona {
    string especialidad;
    int horaEntrada, horaSalida;
    float costoConsulta;
public:
    Doctor(string _nombre, string _dni, int _edad, string _celular, string _especialidad, int _horaEntrada, int _horaSalida, float _costo)
        : Persona(_nombre, _dni, _edad, _celular), especialidad(_especialidad), horaEntrada(_horaEntrada), horaSalida(_horaSalida), costoConsulta(_costo) {}
    void mostrarDoctor() {
        mostrarInformacion();
        cout << "Especialidad: " << especialidad << ", Horario: " << horaEntrada << ":00 - " << horaSalida << ":00, Costo: S/." << costoConsulta << endl;
    }
    string getEspecialidad() { return especialidad; }
    string getHorario() { return to_string(horaEntrada) + ":00 - " + to_string(horaSalida) + ":00"; }
    int getHoraEntrada() { return horaEntrada; }
    int getHoraSalida() { return horaSalida; }
    float getCosto() { return costoConsulta; }
};

class Paciente : public Persona {
    string historialMedico, seguroSocial;
public:
    Paciente(string _nombre, string _dni, int _edad, string _celular, string _historialMedico, string _seguroSocial)
        : Persona(_nombre, _dni, _edad, _celular), historialMedico(_historialMedico), seguroSocial(_seguroSocial) {}
};

class Cita {
    string hora;
    float costo;
    Paciente* paciente;
    Doctor* doctor;
public:
    Cita(string _hora, float _costo, Paciente* _paciente, Doctor* _doctor)
        : hora(_hora), costo(_costo), paciente(_paciente), doctor(_doctor) {}
    void mostrarCita() {
        cout << "Cita: " << hora << ", Paciente: " << paciente->getNombre()
             << ", Doctor: " << doctor->getNombre() << ", Costo: S/." << costo << endl;
    }
    float getCosto() { return costo; }
    string getHora() { return hora; }
    string getEspecialidad() { return doctor->getEspecialidad(); }
    string getDoctorNombre() { return doctor->getNombre(); }
    string getPacienteNombre() { return paciente->getNombre(); }
};

class Reclamo {
    string descripcion, fecha;
    Cita* cita;
public:
    Reclamo(string _descripcion, string _fecha, Cita* _cita)
        : descripcion(_descripcion), fecha(_fecha), cita(_cita) {}
    void mostrarReclamo() {
        cout << "Reclamo del " << fecha << ": " << descripcion << " - Cita con " << cita->getDoctorNombre() << endl;
    }
};

class Administrador {
    vector<Doctor*> listaDoctores;
    vector<Cita*> listaCitas;
    vector<Reclamo*> listaReclamos;
public:
    void agregarDoctor(Doctor* doctor) { listaDoctores.push_back(doctor); }
    void registrarCita(Cita* cita) { listaCitas.push_back(cita); }
    void registrarReclamo(Reclamo* reclamo) { listaReclamos.push_back(reclamo); }
    void mostrarListaCitas() { for (auto c : listaCitas) c->mostrarCita(); }
    void mostrarListaDoctores() { for (auto d : listaDoctores) d->mostrarDoctor(); }
    void mostrarReclamos() { for (auto r : listaReclamos) r->mostrarReclamo(); }
    vector<Doctor*>& getListaDoctores() { return listaDoctores; }
    vector<Cita*>& getListaCitas() { return listaCitas; }
    void reporteVentas() {
        float total = 0;
        for (auto c : listaCitas) total += c->getCosto();
        cout << "Ventas totales: S/." << total << endl;
    }
};

bool iniciarSesion(vector<Paciente*>& pacientes, Paciente*& pacienteActivo) {
    string dni;
    cout << "DNI: "; getline(cin, dni);
    for (auto p : pacientes) {
        if (p->getDNI() == dni) {
            pacienteActivo = p;
            return true;
        }
    }
    cout << "Usuario no encontrado. Registrando nuevo paciente.\n";
    string nombre, celular, historial, seguro;
    int edad;
    cout << "Nombre: "; getline(cin, nombre);
    cout << "Edad: "; while (!(cin >> edad)) { cout << "Edad inválida. Intente de nuevo: "; limpiarEntrada(); }
    limpiarEntrada();
    cout << "Celular: "; getline(cin, celular);
    cout << "Historial Medico: "; getline(cin, historial);
    cout << "Seguro Social: "; getline(cin, seguro);
    pacienteActivo = new Paciente(nombre, dni, edad, celular, historial, seguro);
    pacientes.push_back(pacienteActivo);
    return true;
}

int main() {
    Administrador admin;
    vector<Paciente*> pacientes;
    Paciente* pacienteActivo = nullptr;

    admin.agregarDoctor(new Doctor("Dra. Ana Torres", "12345678", 45, "987654321", "Cardiología", 8, 16, 150.0));
    admin.agregarDoctor(new Doctor("Dr. Luis Gómez", "87654321", 50, "912345678", "Pediatría", 9, 17, 120.0));
    admin.agregarDoctor(new Doctor("Dra. Carla Pérez", "11223344", 38, "923456789", "Dermatología", 10, 18, 100.0));

    while (true) {
        string user, password;
        cout << "\n¿Eres administrador o paciente? (admin/paciente/salir): ";
        getline(cin, user);

        if (user == "admin") {
            cout << "Ingrese contraseña de administrador: ";
            getline(cin, password);
            if (password != "admin123") {
                cout << "Contraseña incorrecta.\n";
                continue;
            }
            int opcion;
            do {
                cout << "\n--- MENU ADMIN ---\n1. Registrar Doctor\n2. Mostrar Doctores\n3. Mostrar Citas\n4. Registrar Reclamo\n5. Mostrar Reclamos\n6. Reporte de Ventas\n0. Salir al menú principal\nOpcion: ";
                while (!(cin >> opcion)) { cout << "Opción inválida. Intente de nuevo: "; limpiarEntrada(); }
                limpiarEntrada();
                if (opcion == 1) {
                    string nombre, dni, celular, especialidad;
                    int edad, entrada, salida;
                    float costo;
                    cout << "Nombre: "; getline(cin, nombre);
                    cout << "DNI: "; getline(cin, dni);
                    cout << "Edad: "; while (!(cin >> edad)) { cout << "Edad inválida: "; limpiarEntrada(); }
                    limpiarEntrada();
                    cout << "Celular: "; getline(cin, celular);
                    cout << "Especialidad: "; getline(cin, especialidad);
                    cout << "Hora de entrada (6-15): ";
                    while (!(cin >> entrada) || entrada < 6 || entrada > 15) {
                        cout << "Hora de entrada inválida (debe ser entre 6 y 15): "; limpiarEntrada();
                    }
                    cout << "Hora de salida (mayor que entrada hasta máx 23): ";
                    while (!(cin >> salida) || salida <= entrada || salida > 23) {
                        cout << "Hora de salida inválida (mayor que entrada y hasta las 23): "; limpiarEntrada();
                    }
                    cout << "Costo por consulta: "; while (!(cin >> costo) || costo < 0) { cout << "Costo inválido: "; limpiarEntrada(); }
                    limpiarEntrada();
                    admin.agregarDoctor(new Doctor(nombre, dni, edad, celular, especialidad, entrada, salida, costo));
                } else if (opcion == 2) admin.mostrarListaDoctores();
                else if (opcion == 3) admin.mostrarListaCitas();
                else if (opcion == 4) {
                    if (admin.getListaCitas().empty()) { cout << "No hay citas registradas." << endl; continue; }
                    string descripcion, fecha;
                    cout << "Descripcion: "; getline(cin, descripcion);
                    cout << "Fecha: "; getline(cin, fecha);
                    admin.registrarReclamo(new Reclamo(descripcion, fecha, admin.getListaCitas()[0]));
                } else if (opcion == 5) admin.mostrarReclamos();
                else if (opcion == 6) admin.reporteVentas();
            } while (opcion != 0);

        } else if (user == "paciente") {
            if (!iniciarSesion(pacientes, pacienteActivo)) continue;
            int opcion;
            do {
                cout << "\n--- MENU PACIENTE ---\n1. Ver Doctores\n2. Agendar Cita\n3. Ver Citas\n4. Ingresar Reclamo\n0. Salir al menú principal\nOpcion: ";
                while (!(cin >> opcion)) { cout << "Opción inválida. Intente de nuevo: "; limpiarEntrada(); }
                limpiarEntrada();
                if (opcion == 1) admin.mostrarListaDoctores();
                else if (opcion == 2) {
                    if (admin.getListaDoctores().empty()) {
                        cout << "No hay doctores disponibles." << endl; continue;
                    }
                    for (size_t i = 0; i < admin.getListaDoctores().size(); ++i) {
                        cout << i << ". "; admin.getListaDoctores()[i]->mostrarDoctor();
                    }
                    int idxD;
                    cout << "Indice del Doctor: ";
                    while (!(cin >> idxD) || idxD < 0 || idxD >= admin.getListaDoctores().size()) {
                        cout << "Índice inválido. Intente de nuevo: "; limpiarEntrada();
                    }
                    limpiarEntrada();
                    string hora;
                    cout << "Hora de la cita (HH:MM): "; getline(cin, hora);

                    try {
                        Doctor* doc = admin.getListaDoctores()[idxD];

                        int horaCita, minutoCita;
                        stringstream ss(hora);
                        string hStr, mStr;
                        getline(ss, hStr, ':');
                        getline(ss, mStr);

                        horaCita = stoi(hStr);
                        minutoCita = stoi(mStr);

                        if (horaCita < doc->getHoraEntrada() || horaCita >= doc->getHoraSalida()) {
                            cout << "Hora fuera del horario del doctor." << endl;
                            continue;
                        }

                        int nuevaHoraMin = horaCita * 60 + minutoCita;

                        bool conflicto = false;
                        for (Cita* c : admin.getListaCitas()) {
                            if (c->getDoctorNombre() == doc->getNombre()) {
                                stringstream ssExistente(c->getHora());
                                string hE, mE;
                                getline(ssExistente, hE, ':');
                                getline(ssExistente, mE);
                                int minExistente = stoi(hE) * 60 + stoi(mE);
                                if (abs(minExistente - nuevaHoraMin) < 30) {
                                    conflicto = true;
                                    break;
                                }
                            }
                        }

                        if (conflicto) {
                            cout << "Conflicto de horario: ya existe una cita para ese doctor dentro de los 30 minutos." << endl;
                            continue;
                        }

                        admin.registrarCita(new Cita(hora, doc->getCosto(), pacienteActivo, doc));
                        cout << "Cita registrada correctamente." << endl;
                    } catch (...) {
                        cout << "Formato de hora inválido." << endl;
                    }

                } else if (opcion == 3) admin.mostrarListaCitas();
                else if (opcion == 4) {
                    if (admin.getListaCitas().empty()) { cout << "No hay citas registradas." << endl; continue; }
                    string descripcion, fecha;
                    cout << "Descripcion: "; getline(cin, descripcion);
                    cout << "Fecha: "; getline(cin, fecha);
                    admin.registrarReclamo(new Reclamo(descripcion, fecha, admin.getListaCitas()[0]));
                }
            } while (opcion != 0);
        } else if (user == "salir") break;
        else cout << "Opcion invalida." << endl;
    }
    return 0;
}

