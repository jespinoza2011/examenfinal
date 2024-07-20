#include "Vector.h"

template <typename T, long tam>
Vector<T, tam>::Vector() : nelem(0) {}

template <typename T, long tam>
Vector<T, tam>::~Vector() { nelem=0; }

template <typename T, long tam>
bool Vector<T, tam>::addElement(const T& elem) {
    if (nelem<tam) {
        array[nelem++]=elem;
        return true;
    } else return false;
}

template <typename T, long tam>
T Vector<T, tam>::operator[](int n) const {
    if (n<nelem) return array[n];
    else throw ExcepcionVectorRango(n, nelem);
}

template <typename T, long tam>
int Vector<T, tam>::getNumElementos() const { return nelem; }

template <typename T, long tam>
int Vector<T, tam>::getCapacidad() const { return tam; }

template <typename T, long tam>
bool Vector<T, tam>::buscar(const T& elemento) const {
    for (int i = 0; i < nelem; ++i) {
        if (array[i] == elemento) return true;
    }
    return false;
}

template <typename T, long tam>
bool buscar(const Vector<T, tam>& vector, const T& elemento) {
    for (int i = 0; i < vector.getNumElementos(); ++i) {
        if (vector[i] == elemento) return true;
    }
    return false;
}