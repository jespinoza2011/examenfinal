#include "ExcepcionVectorRango.h"

ExcepcionVectorRango::ExcepcionVectorRango(int pos, int numElem)
    : posicion(pos), numElementos(numElem) {}

const char* ExcepcionVectorRango::what() const {
    return "Error de rango en Vector: ";
}

int ExcepcionVectorRango::getPos() const {
    return posicion;
}

int ExcepcionVectorRango::getNumElem() const {
    return numElementos;
}