#include <iostream>
using namespace std;

class Empleado {
public:
    virtual double calcularSalario() = 0; 
    virtual ~Empleado() {}
};

class EmpleadoTiempoCompleto : public Empleado {
private:
    double salarioMensual;
public:
    EmpleadoTiempoCompleto(double salario) : salarioMensual(salario) {}
    double calcularSalario() override {
        return salarioMensual;
    }
};

class EmpleadoMedioTiempo : public Empleado {
private:
    double pagoPorHora;
    int horasTrabajadas;
public:
    EmpleadoMedioTiempo(double pago, int horas) : pagoPorHora(pago), horasTrabajadas(horas) {}
    double calcularSalario() override {
        return pagoPorHora * horasTrabajadas;
    }
};

int main() {
    EmpleadoTiempoCompleto emp1(2500);
    EmpleadoMedioTiempo emp2(20, 80);

    cout << "Salario empleado tiempo completo: s/." << emp1.calcularSalario() << endl;
    cout << "Salario empleado medio tiempo: s/." << emp2.calcularSalario() << endl;

    return 0;
}
