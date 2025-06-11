#include <iostream>
#include <vector>
using namespace std;

// Clase base abstracta
class Empleado {
public:
    virtual double calcularSalario() const = 0;
    virtual void mostrarInfo() const = 0;
    virtual ~Empleado() {}
};

// Asalariado
class Asalariado : public Empleado {
private:
    double sueldoMensual;
public:
    Asalariado(double sueldo) : sueldoMensual(sueldo) {}
    double calcularSalario() const override {
        return sueldoMensual;
    }
    void mostrarInfo() const override {
        cout << "Empleado Asalariado - Sueldo mensual: S/ " << sueldoMensual << endl;
    }
};

// Por hora
class PorHora : public Empleado {
private:
    double horas, tarifa;
public:
    PorHora(double h, double t) : horas(h), tarifa(t) {}
    double calcularSalario() const override {
        return horas * tarifa;
    }
    void mostrarInfo() const override {
        cout << "Empleado por Hora - Horas: " << horas << ", Tarifa: S/ " << tarifa << endl;
    }
};

// Comisionista
class Comisionista : public Empleado {
private:
    double sueldoBase, ventas, porcentajeComision;
public:
    Comisionista(double base, double v, double pc)
        : sueldoBase(base), ventas(v), porcentajeComision(pc) {}
    double calcularSalario() const override {
        return sueldoBase + (ventas * porcentajeComision / 100);
    }
    void mostrarInfo() const override {
        cout << "Empleado Comisionista - Base: S/ " << sueldoBase
             << ", Ventas: S/ " << ventas
             << ", Comisión: " << porcentajeComision << "%" << endl;
    }
};

// Menú
int main() {
    vector<Empleado*> empleados;
    int opcion;

    do {
        cout << "\n--- SISTEMA DE NÓMINA ---\n";
        cout << "1. Registrar empleado\n";
        cout << "2. Mostrar nómina\n";
        cout << "3. Salir\n";
        cout << "Opción: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "\nTipos de empleado:\n";
            cout << "1. Asalariado\n";
            cout << "2. Por hora\n";
            cout << "3. Comisionista\n";
            int tipo;
            cin >> tipo;

            switch (tipo) {
                case 1: {
                    double sueldo;
                    cout << "Ingrese sueldo mensual: ";
                    cin >> sueldo;
                    empleados.push_back(new Asalariado(sueldo));
                    break;
                }
                case 2: {
                    double horas, tarifa;
                    cout << "Ingrese horas trabajadas: ";
                    cin >> horas;
                    cout << "Ingrese tarifa por hora: ";
                    cin >> tarifa;
                    empleados.push_back(new PorHora(horas, tarifa));
                    break;
                }
                case 3: {
                    double base, ventas, comision;
                    cout << "Ingrese sueldo base: ";
                    cin >> base;
                    cout << "Ingrese monto de ventas: ";
                    cin >> ventas;
                    cout << "Ingrese porcentaje de comisión: ";
                    cin >> comision;
                    empleados.push_back(new Comisionista(base, ventas, comision));
                    break;
                }
                default:
                    cout << "Tipo de empleado inválido.\n";
            }

        } else if (opcion == 2) {
            if (empleados.empty()) {
                cout << "No hay empleados registrados.\n";
            } else {
                double total = 0;
                for (size_t i = 0; i < empleados.size(); ++i) {
                    cout << "\nEmpleado #" << i + 1 << ":\n";
                    empleados[i]->mostrarInfo();
                    double salario = empleados[i]->calcularSalario();
                    cout << "Salario calculado: S/ " << salario << endl;
                    total += salario;
                }
                cout << "\nTotal a pagar en nómina: S/ " << total << endl;
            }

        } else if (opcion == 3) {
            cout << "Saliendo del sistema de nómina...\n";
        } else {
            cout << "Opción inválida.\n";
        }

    } while (opcion != 3);

    for (Empleado* e : empleados) delete e;

    return 0;
}
