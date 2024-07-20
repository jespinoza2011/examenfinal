#include "Servicio.h"
#include <algorithm>

using namespace std;

namespace viajefeliz {
    Servicio::Servicio(const string& ciudad, const vector<Bus>& buses)
        : ciudad(ciudad), busesDisponibles(buses) {
        if (ciudad.empty()) {
            throw TransporteException("Nombre de ciudad vacío");
        }
    }

    vector<Bus> Servicio::filtra(const Criterio& criterio) {
        busesFiltrados.clear();
        for (const auto& bus : busesDisponibles) {
            if (criterio.busEsSeleccionable(bus)) {
                busesFiltrados.push_back(bus);
            }
        }
        return busesFiltrados;
    }

    vector<Bus> Servicio::filtra(const Criterio& criterio, const vector<Bus>& busesAFiltrar) {
        if (busesAFiltrar.empty()) {
            throw TransporteException("Lista de buses a filtrar vacía");
        }
        vector<Bus> resultado;
        for (const auto& bus : busesAFiltrar) {
            if (criterio.busEsSeleccionable(bus)) {
                resultado.push_back(bus);
            }
        }
        return resultado;
    }

    const string& Servicio::getCiudad() const { return ciudad; }
    const vector<Bus>& Servicio::getBusesDisponibles() const { return busesDisponibles; }
    const vector<Bus>& Servicio::getBusesFiltrados() const { return busesFiltrados; }

    ostream& operator<<(ostream& os, const Servicio& servicio) {
        os << "Servicio{ciudad='" << servicio.ciudad << "', buses=[";
        for (size_t i = 0; i < servicio.busesDisponibles.size(); ++i) {
            if (i > 0) os << ", ";
            os << servicio.busesDisponibles[i];
        }
        os << "]}";
        return os;
    }
}