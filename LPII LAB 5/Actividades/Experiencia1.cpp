#include <iostream>
using namespace std;

class CuentaBancaria {
private:
    string numero;
    string titular;
    double saldo;

public:
    CuentaBancaria(string numero, string titular, double saldo = 0) {
        this->numero = numero;
        this->titular = titular;
        this->saldo = saldo;
    }
    CuentaBancaria& depositar(double monto) {
        if (monto > 0) {
            saldo += monto;
        }
        return *this;
    }
    CuentaBancaria& retirar(double monto) {
        if (monto > 0 && monto <= saldo) {
            saldo -= monto;
        }
        return *this;
    }
    CuentaBancaria& mostrarSaldo() {
        cout << "Saldo actual de " << titular << ": S/ " << saldo << endl;
        return *this;
    }
};
int main() {
    CuentaBancaria cuenta("123456789", "Juan Pérez");
    cuenta.depositar(1000).retirar(200).mostrarSaldo();

    return 0;
}
