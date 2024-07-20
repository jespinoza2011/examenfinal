#include <iostream>
#include <string>
#include "Vector.h"

using namespace std;

int main() {
    Vector<string> vs;
    while (vs.addElement("HOLA"));

    try {
        for (int i = vs.getNumElementos(); i >= 0; i--)
            cout << vs[i] << endl;
    } catch (ExcepcionVectorRango &ex) {
        cerr << ex.what() << "posicion: " << ex.getPos()
                  << ", num. elementos: " << ex.getNumElem() << endl;
    }

    Vector<double> vd;
    vd.addElement(3.14);
    vd.addElement(2.71);
    cout << "Buscando 3.14: " << (vd.buscar(3.14) ? "Encontrado" : "No encontrado") << endl;
    cout << "Buscando 1.41: " << (buscar(vd, 1.41) ? "Encontrado" : "No encontrado") << endl;

    return 0;
}