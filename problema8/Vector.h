#ifndef VECTOR_H
#define VECTOR_H

#include "ExcepcionVectorRango.h"

template <typename T, long tam=10>
class Vector {
private:
    T array[tam];
    int nelem;

public:
    Vector();
    ~Vector();
    bool addElement(const T& elem);
    T operator[](int n) const;
    int getNumElementos() const;
    int getCapacidad() const;
    bool buscar(const T& elemento) const;
};

template <typename T, long tam>
bool buscar(const Vector<T, tam>& vector, const T& elemento);

#include "Vector.cpp"

#endif