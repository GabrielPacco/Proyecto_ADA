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

void Elegir_destino(list <cliente> pasajeros , list <cliente> pasajerosDiscapacitados){
    destino vuelo;
    bool s=true;
    int pais;
    do{ //desplegamos otro menu para que el usuario escoja el destino del vuelo
        cout<<endl<<"++++++++++ CODIGOS DE PAISES +++++++++"<<endl;
        cout<<"1.EEUU\n"<<"2.Canada\n"<<"3.Colombia\n"<<"4.Salir\n";
        cout<<endl<<"Ingrese el destino del vuelo:"<<endl;
        cin>>pais;cin.ignore();

        switch (pais){
            case 1: vuelo = EEUU; break;
            case 2: vuelo = Canada; break;
            case 3: vuelo = Colombia; break;
            case 4: s = false; break;
            default:
                cout<<"Opcion no valida. Intente nuevamente.";
            break;
        }
        Abordaje_destino(vuelo, pasajeros, pasajerosDiscapacitados);
        s = false;
    } while (s);
}

void Abordar_pasajeros(){
    if (normal.empty() || prioritario.empty()){ //las colas no deben estar vacias
    cout<<"\nNo hay pasajeros para este destino\n\n";
    }
    //Se muestra la cola de pasajeros con prioridad
    if (!prioritario.empty()){
        cout<<"========== Pasajeros prioritarios =========="<<endl<<endl;
        while (!prioritario.empty()){
            cliente siguiente_abordar = prioritario.front();
            //se muestran los datos en consola
            cout<<"Nombre: "<<siguiente_abordar.nombre<<endl;
            cout<<"Edad: "<<siguiente_abordar.edad<<endl;
            cout<<"Destino: "<<siguiente_abordar.destino<<endl<<endl;
            //Procedemos a abordarlos despejando la cola
            prioritario.pop();
        }
    }
    //Repetimos el proceso anterios pero ahora con la cola de no prioritarios
    if (!normal.empty()){
        cout<<"========== Pasajeros corrientes =========="<<endl<<endl;
        while (!normal.empty()){
            cliente siguiente_abordar = normal.front();

            cout<<"Nombre: "<<siguiente_abordar.nombre<<endl;
            cout<<"Edad: "<<siguiente_abordar.edad<<endl;
            cout<<"Destino: "<<siguiente_abordar.destino<<endl<<endl;

            normal.pop();
        }
    }
}

