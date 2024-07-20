#include "FiltroExpManejo.h"

namespace viajefeliz {
    FiltroExpManejo::FiltroExpManejo(int minAnhios) : minAnhios(minAnhios) {
        if (minAnhios < 0) {
            throw TransporteException("Mínimo de años negativo");
        }
    }

    bool FiltroExpManejo::busEsSeleccionable(const Bus& bus) const {
        const Conductor* conductor = bus.getConductor();
        if (!conductor) return false;

        int anhiosExperiencia = conductor->getAnhiosManejo();
        int anhiosFaltantes = minAnhios - anhiosExperiencia;

        if (anhiosExperiencia >= minAnhios) return true;
        return anhiosFaltantes < static_cast<int>(conductor->getCapacitaciones().size());
    }

    ostream& operator<<(ostream& os, const FiltroExpManejo& filtro) {
        os << "Conductores con al menos [" << filtro.minAnhios << "] años de experiencia";
        return os;
    }
}