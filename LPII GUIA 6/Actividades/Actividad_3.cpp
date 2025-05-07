#include <iostream>
using namespace std;

class Banco {
private:
    static float tasaInteres;  
public:
    static void cambiarTasa(float nuevaTasa) {
        tasaInteres = nuevaTasa;
    }
    static float obtenerTasa() {
        return tasaInteres;
    }
};
float Banco::tasaInteres = 0.05; 
class CuentaBancaria {
private:
    float saldo;

public:
    CuentaBancaria(float saldoInicial) : saldo(saldoInicial) {}
    void depositar(float monto) {
        saldo += monto;
    }
    void retirar(float monto) {
        if (monto <= saldo) {
            saldo -= monto;
        } else {
            cout << "Saldo insuficiente!" << endl;
        }
    }
    float calcularInteres() {
        return saldo * Banco::obtenerTasa();  
    }
    void mostrarSaldo() {
        cout << "Saldo actual: " << saldo << endl;
    }
};

int main() {
    float nuevaTasa, saldoInicial, deposito, retiro;
    cout << "Ingrese la nueva tasa de interes (por ejemplo, 0.07 para 7%): ";
    cin >> nuevaTasa;
    Banco::cambiarTasa(nuevaTasa); 
    cout << "Ingrese el saldo inicial de la cuenta: ";
    cin >> saldoInicial;
    CuentaBancaria cuenta1(saldoInicial);
    cout << "Ingrese el monto a depositar: ";
    cin >> deposito;
    cuenta1.depositar(deposito); 
    cout << "Ingrese el monto a retirar: ";
    cin >> retiro;
    cuenta1.retirar(retiro);  
    cuenta1.mostrarSaldo();
    float interes = cuenta1.calcularInteres();
    cout << "Interes ganado: " << interes << endl;

    return 0;
}





