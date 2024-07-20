#ifndef FILTRO_EXP_MANEJO_H
#define FILTRO_EXP_MANEJO_H

#include "Criterio.h"
#include "TransporteException.h"

using namespace std;

namespace viajefeliz {
    class FiltroExpManejo : public Criterio {
    private:
        int minAnhios;

    public:
        FiltroExpManejo(int minAnhios);
        bool busEsSeleccionable(const Bus& bus) const override;
        friend ostream& operator<<(ostream& os, const FiltroExpManejo& filtro);
    };
}

#endif