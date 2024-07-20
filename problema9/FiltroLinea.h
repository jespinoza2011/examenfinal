#ifndef FILTRO_LINEA_H
#define FILTRO_LINEA_H

#include "Criterio.h"
#include "TransporteException.h"

using namespace std;

namespace viajefeliz {
    class FiltroLinea : public Criterio {
    private:
        int codLinea;

    public:
        FiltroLinea(int codLinea);
        bool busEsSeleccionable(const Bus& bus) const override;
        friend ostream& operator<<(ostream& os, const FiltroLinea& filtro);
    };
}

#endif