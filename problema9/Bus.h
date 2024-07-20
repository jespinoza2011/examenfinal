#ifndef BUS_H
#define BUS_H

#include <string>
#include <iostream>
#include "Conductor.h"
#include "TransporteException.h"

using namespace std;

namespace viajefeliz {
    class Bus {
    private:
        string codbus;
        int codLinea;
        string matricula;
        Conductor* conductor;

    public:
        Bus(const string& codbus, int codLinea);

        void setMatricula(const string& matricula);
        void setConductor(Conductor* conductor);

        const string& getCodbus() const;
        int getCodLinea() const;
        const string& getMatricula() const;
        const Conductor* getConductor() const;

        bool operator==(const Bus& other) const;
        friend ostream& operator<<(ostream& os, const Bus& bus);
    };
}

#endif