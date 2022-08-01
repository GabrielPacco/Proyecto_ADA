#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include "rutas.hpp"

using namespace std;

bool compNombres(string a, string b) { return a < b; };

void clientes();
void ganancias();
int despliegueDestinos();
void verNums(int);

vector<cliente> listaPasajeros;
vector<cliente> pasajerosDiscapacitados;
set<string> destinos;

string continentes[5] = {
    "America", "Africa", "Asia", "Europa", "Oceania"};

ruta rutaCliente;

int main()
{
    mostrarLogo();

    bool stop = true;
    int opt = 0;
    cout << "Bienvenido" << endl;

    do
    {
        cout << "===================== M E N U =====================";
        cout << endl;
        cout << "               1. Ingresar clientes." << endl;
        cout << "               2. Mostrar Ganancias." << endl;
        cout << "               3. Iniciar abordaje." << endl;
        cout << "               4. Salir. " << endl;
        cout << "Opcion: ";
        opt = validarRango(to_string(opt), 1, 4);
        cout << "====================================================" << endl;

        switch (opt)
        {
        case 1:
            clientes();
            break;
        case 2:
            ganancias();
            break;
        case 3:
            // crearPuertas(destinos, listaPasajeros, pasajerosDiscapacitados);
            Crear_puerta(listaPasajeros, pasajerosDiscapacitados);
            break;
        case 4:
            stop = false;
            break;

        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
            break;
        }

    } while (stop);

    return 0;
}