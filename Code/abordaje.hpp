//funcion de abordaje
#pragma once
#include <iostream>
#include <list>
#include <queue>

using namespace std;

//informacion de cada pasajero 
struct Cliente{
    string nombre;
    int edad;
    char discapsitado;
    string destino;

};
typedef struct Cliente cliente;

//Enumerar los destinos posibles 
enum destino{EEUU, Canada, Colombia};

//Una cola de de pasajeros corrientes y una de pasajeros prioritarios 
queue <cliente> normal;
queue <cliente> prioritario;

void menu (list <cliente>,list <cliente>);
void Elegir_destino(list <cliente>, list <cliente>);
void Abordar_pasajeros();
void Abordaje_destino(destino, list <cliente>, list <cliente>);

void menu(list <cliente> pasajeros, list <cliente> pasajerosDiscapacitados){
    bool s=true;
    int opcion;
    //Menu de opciones principales
    do{
        cout<<endl<<"********** MENU DE OPCIONES **********"<<endl;
        cout<<"1.Elegir destino\n"<<"2.Abordar a los pasajeros\n"<<"3.salir\n";
        cout<<endl<<"Ingrese su opcion:"<<endl;
        cin>>opcion;cin.ignore();
        switch (opcion){
            case 1: Elegir_destino(pasajeros, pasajerosDiscapacitados); break;
            case 2: Abordar_pasajeros(); break;
            case 3: s = false; break;
            default: cout<<"\nLa opcion ingresada no es valida\n";
        }       
    } while (s);
}
