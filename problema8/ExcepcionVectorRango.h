#ifndef EXCEPCION_VECTOR_RANGO_H
#define EXCEPCION_VECTOR_RANGO_H

class ExcepcionVectorRango {
    private:
        int posicion;
        int numElementos;

    public:
        ExcepcionVectorRango(int pos, int numElem);
        const char* what() const;
        int getPos() const;
        int getNumElem() const;
};

#endif