#ifndef CRITERIO_H
#define CRITERIO_H

#include "Bus.h"

namespace viajefeliz {
    class Criterio {
    public:
        virtual bool busEsSeleccionable(const Bus& bus) const = 0;
        virtual ~Criterio() = default;
    };
}

#endif