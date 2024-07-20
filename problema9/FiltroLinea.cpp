#include "FiltroLinea.h"

using namespace std;

namespace viajefeliz {
    FiltroLinea::FiltroLinea(int codLinea) : codLinea(codLinea) {
        if (codLinea < 0) {
            throw TransporteException("Código de línea negativo");
        }
    }

    bool FiltroLinea::busEsSeleccionable(const Bus& bus) const {
        return bus.getCodLinea() == codLinea;
    }

    ostream& operator<<(ostream& os, const FiltroLinea& filtro) {
        os << "Autobuses de la línea [" << filtro.codLinea << "]";
        return os;
    }
}