#include <iostream>
using namespace std;

// Interfaz
class Reproductor {
public:
    virtual void reproducir() = 0;
    virtual void pausar() = 0;
    virtual void detener() = 0;
    virtual ~Reproductor() {}
};

// Clase Reproductor
class ReproductorMP3 : public Reproductor {
public:
    void reproducir() override {
        cout << "Reproduciendo archivo MP3..." << endl;
    }
    void pausar() override {
        cout << "Pausando reproducción." << endl;
    }
    void detener() override {
        cout << "Deteniendo reproducción." << endl;
    }
};

int main() {
    ReproductorMP3 mp3;

    mp3.reproducir();
    mp3.pausar();
    mp3.detener();

    return 0;
}
