#include "Bus.h"

using namespace std;

namespace viajefeliz {
    Bus::Bus(const string& codbus, int codLinea) : codbus(codbus), codLinea(codLinea), conductor(nullptr) {
        if (codbus.empty() || codLinea < 0) {
            throw TransporteException("Código de bus inválido o código de línea negativo");
        }
    }

    void Bus::setMatricula(const string& matricula) {
        this->matricula = matricula;
    }

    void Bus::setConductor(Conductor* conductor) {
        this->conductor = conductor;
    }

    const string& Bus::getCodbus() const { return codbus; }
    int Bus::getCodLinea() const { return codLinea; }
    const string& Bus::getMatricula() const { return matricula; }
    const Conductor* Bus::getConductor() const { return conductor; }

    bool Bus::operator==(const Bus& other) const {
        return codbus == other.codbus && matricula == other.matricula;
    }

    ostream& operator<<(ostream& os, const Bus& bus) {
        os << "Bus(" << bus.codbus << ", " << bus.codLinea << ", " << bus.matricula << ")";
        return os;
    }
}