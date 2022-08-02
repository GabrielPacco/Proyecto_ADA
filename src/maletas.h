#include <iostream>
#include <stack>
#include <vector>

using namespace std;
struct maleta
{
    int cantidad;
    vector<float> peso;
};
int MenuMaletas();
void mostraPila(stack<maleta>);
void agregaMaletas();
int opcion;
stack<maleta> maletaPila;

int MenuMaletas()
{
    cout << endl;
    cout << "Bienvenido al sistema de registro de maletas" << endl;
    cout << endl;
    bool seguir = true;
    do
    {
        cout << "Ingrese el numero de la accion que desea realizar \n";
        cout << endl;
        cout << "------------      MENU       ------------" << endl
             << endl;
        cout << "________________________________________" << endl;
        cout << "1. Agregar Maletas   " << endl;
        cout << "2. Ver Maletas       " << endl;
        cout << "3. Salir             " << endl;
        cout << "________________________________________" << endl;
        cout << "-----------------------------------------" << endl;
        cout << endl;
        cout << " Opción : ";
        cin >> opcion;
        if (opcion == 1)
        {
            agregaMaletas();
        }
        else if (opcion == 2)
        {
            mostraPila(maletaPila);
        }
        else if (opcion == 3)
        {
            seguir = false;
        }
        else
        {
            cout << "Opción Inválida\n\n";
        }
    } while (seguir);
    return 0;
}