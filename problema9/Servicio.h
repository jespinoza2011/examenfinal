#ifndef SERVICIO_H
#define SERVICIO_H

#include <string>
#include <vector>
#include "Bus.h"
#include "Criterio.h"
#include "TransporteException.h"

using namespace std;

namespace viajefeliz {
    class Servicio {
    private:
        string ciudad;
        vector<Bus> busesDisponibles;
        vector<Bus> busesFiltrados;

    public:
        Servicio(const string& ciudad, const vector<Bus>& buses);

        vector<Bus> filtra(const Criterio& criterio);
        vector<Bus> filtra(const Criterio& criterio, const vector<Bus>& busesAFiltrar);

        const string& getCiudad() const;
        const vector<Bus>& getBusesDisponibles() const;
        const vector<Bus>& getBusesFiltrados() const;

        friend ostream& operator<<(ostream& os, const Servicio& servicio);
    };
}

#endif