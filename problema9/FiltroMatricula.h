#ifndef FILTRO_MATRICULA_H
#define FILTRO_MATRICULA_H

#include "Criterio.h"
#include "TransporteException.h"
#include <string>


namespace viajefeliz {
    class FiltroMatricula : public Criterio {
    private:
        string cadenaBuscar;

    public:
        FiltroMatricula(const string& cadenaBuscar);
        bool busEsSeleccionable(const Bus& bus) const override;
        friend ostream& operator<<(ostream& os, const FiltroMatricula& filtro);
    };
}

#endif