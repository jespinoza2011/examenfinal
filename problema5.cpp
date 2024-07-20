#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

bool tienePropiedadVentana(const string &secuencia, int &posicionInfractor) {
    int n = secuencia.size();

    for (int k = 1; k <= n; ++k) {
        unordered_set<string> patrones;
        for (int i = 0; i <= n - k; ++i) {
            string ventana = secuencia.substr(i, k);
            patrones.insert(ventana);
            if (patrones.size() > k + 1) {
                // La posición del infractor es i + k - 1 porque el infractor es el símbolo que causa la violación
                posicionInfractor = i + k;
                return false;
            }
        }
    }
    return true;
}

int main() {
    string secuencia;
    cout << "Introduce la secuencia: ";
    cin >> secuencia;

    int posicionInfractor = -1;
    if (tienePropiedadVentana(secuencia, posicionInfractor)) {
        cout << "SI" << endl;
    } else {
        cout << "NO:" << posicionInfractor << endl;
    }

    return 0;
}