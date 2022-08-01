#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

struct opcion{
    int num{};
    string texto;
    void (*funcion)(){};
};
typedef struct opcion Opcion;