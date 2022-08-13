#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include "dstns.hpp"
#include "validaciones.hpp"
#include "logo.hpp"
#include "maletas.hpp"
#include "abordaje.hpp"

using namespace std;

bool compNombres(string a, string b) {return a < b;};
void clientes();
void ganancias();
int despliegueDestinos();
void verNums(int);

vector <cliente> listaPasajeros;
vector<cliente> pasajerosDiscapacitados;
set<string> destinos;


string continentes[5] = {
    "America", "Africa", "Asia", "Europa", "Oceania" 
};

ruta rutaCliente;

int main()
{
    comenzarBusqueda(0,10);
    mostrarLogo();
    bool stop=true;
    int opt = 0;
    cout<<"Bienvenido"<<endl;

    do
    {
        cout<<"===================== M E N U ====================="; cout<<endl;
        cout<<"               1. Ingresar clientes."<<endl;
        cout<<"               2. Mostrar Ganancias."<<endl;
        cout<<"               3. Iniciar abordaje."<<endl;
        cout<<"               4. Salir. "<<endl;
        cout<<"Opcion: ";
        opt = validarRango(to_string(opt), 1, 4);
        cout<<"===================================================="<<endl;

        switch (opt)
        {
            case 1:
                clientes();
            break;
            case 2:
                ganancias();
            break;
            case 3:
                Crear_puerta(listaPasajeros, pasajerosDiscapacitados);
            break;
            case 4:
                stop=false;
            break;

            default:
                cout<<"Opcion no valida. Intente de nuevo."<<endl;
            break;
        }

    } while (stop);
    return 0;


}

void clientes()
{
    cliente unPasajero; //declaracion de objeto para acceder a la estructura.

    //inicio de recoleccion de datos.
    bool error = true;

    int num=0;
    int cont=0;

    cout<<"Bienvenido. "<<endl;
//cout<<"Numero de pasajeros a ingresar: ";
//cin>>num;
    cin.ignore();

    string auxString = " ";
    
    cout<<"-Ingrese el nombre del pasajero: ";       
    unPasajero.nombre = validarString();
//while (cont<num)

    do
    {
        /*cout<<"Ingrese el nombre del pasajero "<<cont+1<<": "<<endl;
        getline(cin, unPasajero.nombre);*/
        cout<<"Ingrese la edad del pasajero "<<cont+1<<": "<<endl;
        cin>>unPasajero.edad;

        if (cin.fail() || unPasajero.edad < 1){
            cin.clear();
            cin.ignore();
            cout << endl;
            cout << "Por favor ingresa un numero entero positivo, intentalo otra vez." << endl;
            cout << "----------------------------------------------------------------" << endl;
            cout << endl;
        } 

         else {
            error = false;
        }
    } while (error);

    cout<<"¿Tiene alguna discapacidad? ";
    bool opt2=true;

    while(opt2) //validacion de dato
    {
            cout<<"(s/n): ";
            cin>>unPasajero.discapacidad;

            if (unPasajero.discapacidad!='n' && unPasajero.discapacidad!='s')
            {
                cout<<"Opcion invalida, intentelo de nuevo"<<endl;
            }
            else 
            {
                opt2=false;
            } 

    }

    cout<<"Destinos posibles: "<<endl;
    //Retorna la ruta con todos sus datos
    rutaCliente = comenzarBusqueda(0, despliegueDestinos());
    unPasajero.rutaVuelo=rutaCliente;
    unPasajero.costoTotal = costoTotalFinal;

    string destinoData = ciudades[unPasajero.rutaVuelo.pares.front().destino].ciudad;
    cout << endl << "Costo total por ida y vuelta: $" << unPasajero.costoTotal << endl << endl;
    destinos.insert(destinoData);
        
        //cout << "Primer destino: " << ciudades[rutaCliente.pares.front().destino].ciudad << endl;
        /*bool opt3=true;
        while(opt3) //validacion de dato
        {
            cout<<"Elija su opcion: ";
            cin>>unPasajero.destino;
            if (unPasajero.destino>8)
            {
                cout<<"Opcion no valida. Intentelo de nuevo. "<<endl;
                opt3=true;
            }else opt3=false;   
        }*/

        cout<<"Redirigiendo al sistema de registro de maletas..."<<endl;
        MenuMaletas();
        cin.ignore();

        if (unPasajero.discapacidad=='s' || unPasajero.edad>65) //validacion de lista de pertenencia
        {
            pasajerosDiscapacitados.push_back(unPasajero); //cola pasajeros discapacitados y adultos mayores
        } else listaPasajeros.push_back(unPasajero); //cola pasajeros 
    }


int despliegueDestinos(){
    int opt = 0;
    vector<string> paises, ciudadesDisponibles;
    int counter = 0, optPais = 0, optFinal = 0, numDestino = 0;
    string pais, ciudad;

    for(int i = 0; i < 5; i++) cout << i+1 << "] " << continentes[i] << endl;

    cout << endl << "Ingrese el numero del continente al que desea visitar: ";
    opt = validarRango(to_string(opt), 1, 5);
    string continente = continentes[opt-1];
    cout << endl << "Paises disponibles en " << continente << ": " << endl << endl;
    //paises de continentes disponibles
    for(int i = 1; i < 60; i++){
        if(ciudades[i].continente == continente)paises.push_back(ciudades[i].pais);
    }
    
    //eliminacion de copias
    sort(paises.begin(), paises.end(), compNombres);
    paises.erase(unique(paises.begin(), paises.end()), paises.end());

    for(vector<string>::iterator it=paises.begin(); it!=paises.end(); it++){
        counter++;
        cout << counter << "] " << *it << endl;
    }

    cout << endl;
    cout << "Ingrese el numero del pais al que desea visitar: ";
    optPais = validarRango(to_string(optPais), 1, paises.size());
    cout << endl;

    //almacena pais
    counter = 0;
    for(vector<string>::iterator it=paises.begin(); it!=paises.end(); it++){
        counter++;
        if(counter == optPais) pais = *it;
    }

    //lista de ciudades
    counter = 0;
    for(int i = 1; i < 60; i++){
        if(ciudades[i].pais == pais) ciudadesDisponibles.push_back(ciudades[i].ciudad);
    }

    sort(ciudadesDisponibles.begin(), ciudadesDisponibles.end(), compNombres);
    ciudadesDisponibles.erase(unique(ciudadesDisponibles.begin(), ciudadesDisponibles.end()), ciudadesDisponibles.end());

    //listar en pantalla
    counter = 0;
    for(vector<string>::iterator it=ciudadesDisponibles.begin(); it!=ciudadesDisponibles.end(); it++){
        counter++;
        cout << counter << "] " << *it << endl;
    }

    cout << endl;
    cout << "Ciudades disponibles en " << pais << ": " << endl;
    cout << "Ingrese el numero de la ciudad que desea visitar: ";
    optFinal = validarRango(to_string(optFinal), 1, ciudadesDisponibles.size());

    //almacena ciudad
    counter = 0;
    for(vector<string>::iterator it=ciudadesDisponibles.begin(); it!=ciudadesDisponibles.end(); it++){
        counter++;
        if(counter == optFinal) ciudad = *it;
    }

    //busqueda de ciudades y su relacion
    for(int i = 1; i < 60; i++){
        if(ciudades[i].ciudad == ciudad) numDestino = i;
    }

    return numDestino;

}

void ganancias(){

    float ganancia1=0, ganancia2=0, gananciaTotal=0;

    for (int i = 0; i < listaPasajeros.size(); i++)
    {
        ganancia1+=(listaPasajeros[i].costoTotal);
    }

    for (int i = 0; i < pasajerosDiscapacitados.size(); i++)
    {
        ganancia2+=(pasajerosDiscapacitados[i].costoTotal);
    }

    gananciaTotal+=ganancia1+ganancia2;

    cout<<"\nGanancias por boletos: $"<<gananciaTotal<<endl<<endl;
}

void verNums(int opt)
{
    if (cin.fail())
    {
        cout<<"Por favor, ingrese solo numeros. "<<endl;
        cin.clear();
        cin.ignore();
    } 
}
