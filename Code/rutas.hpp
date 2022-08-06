//Las rutas para los vuelos

#pragma once
#include <iostream>
#include <list>
#include <queue>
#include <string>
using namespace std;

struct Nodo{
    int inicio;
    int fin;
    int peso;
};
//Prototipo de funciones
int comenzarBusqueda(int s, int d);
