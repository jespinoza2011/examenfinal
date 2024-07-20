#include "FiltroMatricula.h"
#include <algorithm>

using namespace std;

namespace viajefeliz {
    FiltroMatricula::FiltroMatricula(const string& cadenaBuscar) : cadenaBuscar(cadenaBuscar) {
        if (cadenaBuscar.empty()) {
            throw TransporteException("Cadena de búsqueda vacía");
        }
    }

    bool FiltroMatricula::busEsSeleccionable(const Bus& bus) const {
        return bus.getMatricula().find(cadenaBuscar) != string::npos;
    }

    ostream& operator<<(ostream& os, const FiltroMatricula& filtro) {
        os << "Autobuses cuya matricula contiene [" << filtro.cadenaBuscar << "]";
        return os;
    }
}