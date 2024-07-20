#ifndef CONDUCTOR_H
#define CONDUCTOR_H

#include <string>
#include <vector>
#include <iostream>
#include "TransporteException.h"

using namespace std;

namespace viajefeliz {
    class Conductor {
    private:
        string codigo;
        string dni;
        string nombre;
        int anhiosManejo;
        vector<string> capacitaciones;

    public:
        Conductor(const string& codigo, const string& dni, const string& nombre);

        void setAnhiosManejo(int anhios);
        void addCapacitacion(const string& capacitacion);

        const string& getCodigo() const;
        const string& getDni() const;
        const string& getNombre() const;
        int getAnhiosManejo() const;
        const vector<string>& getCapacitaciones() const;

        bool operator==(const Conductor& other) const;
        friend ostream& operator<<(ostream& os, const Conductor& conductor);
    };
}

#endif