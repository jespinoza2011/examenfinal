#include "Conductor.h"
#include <algorithm>

using namespace std;

namespace viajefeliz {
    Conductor::Conductor(const string& codigo, const string& dni, const string& nombre)
        : codigo(codigo), dni(dni), nombre(nombre), anhiosManejo(0) {
        if (codigo.empty() || dni.empty() || nombre.empty()) {
            throw TransporteException("Los datos del conductor no pueden ser nulos");
        }
    }

    void Conductor::setAnhiosManejo(int anhios) {
        anhiosManejo = anhios;
    }

    void Conductor::addCapacitacion(const string& capacitacion) {
        capacitaciones.push_back(capacitacion);
    }

    const string& Conductor::getCodigo() const { return codigo; }
    const string& Conductor::getDni() const { return dni; }
    const string& Conductor::getNombre() const { return nombre; }
    int Conductor::getAnhiosManejo() const { return anhiosManejo; }
    const vector<string>& Conductor::getCapacitaciones() const { return capacitaciones; }

    bool Conductor::operator==(const Conductor& other) const {
        return codigo == other.codigo && dni == other.dni;
    }

    ostream& operator<<(ostream& os, const Conductor& conductor) {
        os << "Conductor(" << conductor.codigo << ", " << conductor.dni << ", " << conductor.nombre << ")";
        return os;
    }
}