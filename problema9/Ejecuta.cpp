#include <iostream>
#include <vector>
#include <algorithm>
#include "Servicio.h"
#include "FiltroLinea.h"
#include "FiltroMatricula.h"
#include "FiltroExpManejo.h"

using namespace std;
using namespace viajefeliz;

int main() {
    try {
        // Crear conductores
        vector<Conductor> conductores = {
            Conductor("con121", "45444721", "Julio Perez"),
            Conductor("con122", "45444722", "Maria Garcia"),
            Conductor("con123", "45444723", "Pedro Lopez"),
            Conductor("con124", "45444724", "Ana Martinez"),
            Conductor("con125", "45444725", "Luis Rodriguez"),
            Conductor("con126", "45444726", "Carlos Carlin")
        };

        // Configurar años de manejo y capacitaciones
        conductores[0].setAnhiosManejo(5);
        conductores[0].addCapacitacion("Actualizacion de Reglas");
        conductores[0].addCapacitacion("Concientizacion");

        conductores[5].setAnhiosManejo(10);
        conductores[5].addCapacitacion("Actualizacion de Reglas");
        conductores[5].addCapacitacion("Civismo");
        conductores[5].addCapacitacion("Concientizacion");
        conductores[5].addCapacitacion("Manejo de ira");
        conductores[5].addCapacitacion("Mecanica basica");
        conductores[5].addCapacitacion("Respeto de normas");

        // Crear buses
        vector<Bus> buses = {
            Bus("bus121", 25), Bus("bus122", 25), Bus("bus123", 25),
            Bus("bus124", 27), Bus("bus125", 25), Bus("bus126", 25)
        };

        // Configurar matrículas y conductores
        buses[0].setMatricula("LIAQP121");
        buses[0].setConductor(&conductores[0]);
        buses[1].setMatricula("MOBPJ122");
        buses[1].setConductor(&conductores[1]);
        buses[2].setMatricula("DHLIQ123");
        buses[2].setConductor(&conductores[2]);
        buses[3].setMatricula("DHQLI124");
        buses[3].setConductor(&conductores[3]);
        buses[4].setMatricula("DHEAQ123");
        buses[4].setConductor(&conductores[4]);
        buses[5].setMatricula("DHLIQ126");
        buses[5].setConductor(&conductores[5]);

        // Crear servicio
        Servicio servicio("Lima", buses);

        // Imprimir datos del servicio
        cout << "##### imprimiendo los datos del servicio #####" << endl;
        cout << servicio << endl;

        // Aplicar filtros
        FiltroLinea filtroLinea(25);
        FiltroMatricula filtroMatricula("LI");
        FiltroExpManejo filtroExpManejo(4);

        vector<Bus> busesFiltrados = servicio.filtra(filtroLinea);
        busesFiltrados = servicio.filtra(filtroMatricula, busesFiltrados);
        busesFiltrados = servicio.filtra(filtroExpManejo, busesFiltrados);

        // Imprimir buses filtrados
        cout << "##### imprimiendo los buses filtrados, sus conductores y sus capacitaciones #####" << endl;
        for (const auto& bus : busesFiltrados) {
            cout << "### Bus ###" << endl;
            cout << bus << endl;
            cout << "### Conductor ###" << endl;
            cout << *bus.getConductor() << endl;
            cout << "### capacitaciones ###" << endl;
            vector<string> capacitaciones = bus.getConductor()->getCapacitaciones();
            sort(capacitaciones.begin(), capacitaciones.end());
            cout << "[";
            for (size_t i = 0; i < capacitaciones.size(); ++i) {
                if (i > 0) cout << ", ";
                cout << capacitaciones[i];
            }
            cout << "]" << endl << endl;
        }
    } catch (const TransporteException& e) {
        cerr << "Error: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "Error inesperado: " << e.what() << endl;
    }

    return 0;
}