#include <iostream>
#include <stack>
#include <vector>

using namespace std;
struct maleta{
  int cantidad;
  vector<float> peso;
};
int MenuMaletas();
void mostrarPila (stack<maleta>);
void agregaMaleta();
int opcion;
stack <maleta> maletaPila;
