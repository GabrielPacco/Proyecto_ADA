# PROYECTO FINAL - ANALISIS Y DISEÑO DE ALGORITMOS - UNSA TRAVEL

![image](https://user-images.githubusercontent.com/78099176/182054996-f4ea91e8-59e3-4cd6-b154-839c4ac45ee5.png)


## Descripción del Proyecto

### Enlace al video de la exposición:
    
[![Alt text](https://img.youtube.com/vi/QQqT5w-uCPk/0.jpg)](https://youtu.be/QQqT5w-uCPk)

### UNSA TRAVEL

Se ha creado un sistema de boletería simplificado para una aerolínea llamada UNSA TRAVEL que ayudara a los estudiantes universitarios de nuestra universidad a movilizarse e impulsar sus viajes durante su proceso academico el cual tiene nexos con 60 ciudades alrededor del mundo, las cuales se pueden visualizar en este mapa: 
El sistema posee las siguientes funcionalidades:

- Calcula la mejor ruta desde Perú, Lima hacia la ciudad que el pasajero desee viajar. Las rutas se calculan en base a los vuelos específicos que la aerolinea ofrece. Así mismo, se calcula la mejor ruta de regreso.

- En caso que la aerolínea no ofrezca vuelos directos hacia esa localización, se toman en cuentas todas las escalas necesarias para llegar al destino. Al cliente se le carga monetariamente el costo total de cada boleto, incluyendo todas las escalas de sus viajes de ida y vuelta.

 - Se le da al cliente la opción de registrar cuantas maletas desee con su respectivo peso.
 
- Se encolan a los pasajeros para el ingreso a las respectivas puestas de sus primeros destinos, teniendo prioridad con los que tengan algún tipo de discapacidad o que se encuentren en el grupo de la tercera edad.

- Se calcula el total vendido por boletos.


## Tipos de estructuras utilizadas

Las principales estructuras de datos que se han utilizado son: 

#### Grafo

Se creó [este grafo](http://graphonline.ru/en/?graph=NPvTxAfWDBTwNwpb) ponderado y direccionado que conecta a todas las ciudades con las que la aerolínea tiene nexo. Cada vértice es una ciudad y cada arco es el vuelo que las conecta, el peso de cada arco es la cantidad promedio de minutos que tarda dicho viaje. Dicho peso se utiliza para calcular el costo de viaje. Se usó la matriz de adyacencia para obtener la lista de adyacencia y poder implementar el grafo en el sistema (desde cero) que calcula la mejor ruta en función del tiempo.

#### Arreglos Dinámicos

Se crean arreglos dinamicos usando la libreria `<vector>` para almacenar diferentes tipos de datos como por ejemplo para guardar los clientesy verificar si tienen alguna discapacidad o no, para registrar las maletas de los clientes y para iniciar el abordaje de los pasajeros. 

#### Pilas 

Si el cliente ingresa los datos de su equipaje estos se llevan en una pila haciendo uso de la librería `<stack>` para ser procesados posteriormente. El procesamiento del equipaje posterior a esto está fuera del enfoque del sistema, lo único de lo que guarda es una lista de las pilas que contienen el equipaje que se ha registrado.

#### Colas

Por medio de la librería `<queue>` se crean colas que almacenan todas las posibles rutas que hay disponibles desde un destino a otro. Posteriormente se comparan para sacar la más óptima tanto de ida como de vuelta y se almacenan en el registro del cliente.


### Pre-requisitos 📋

### Hardware
Recomendado:
● CPU: Intel Core i3 ó AMD Athlon II (K10) 2.8 GHz
● RAM: 4GB
● Disco duro: 1GB
● Visual Studio Code
● Extension Code Runner - VSCode
● C++: En su última versión

Mínimo:
● CPU: Intel Pentium D ó AMD Athlon 64 (K8) 2.6 GHz
● RAM: 2GB
● Disco Duro: Al menos 200 MB libres
● Visual Studio Code
● Extension Code Runner - VSCode
● C++: En su última versión

### Software
● Versión de C++: 14 en adelante
● Tener instalado el compilador de C++ MinGW
● Tener instalado VSCode

### Instalación 🔧

1. Realiza uan clonación del repositorio en el sitio local de su preferencia con
    ```
    git clone https://github.com/GabrielPacco/Proyecto_ADA
    ```
2. Abre el archivo desde la terminal de comandos con Visual Studio Code
     ```
    cd Proyecto_ADA
    ```
3. Ingresar a la ubicación del código.
    ```
    cd Code
    ```
4. Ingresar el siguiente comando para compilar:
    ```
    g++ -o main.exe main.cpp
    ```
5. Ejecutar el archivo .exe:
    ```
    main.exe
    ```
## Ejecutando las pruebas ⚙️

1. Abrir la carpeta en la que se encuentra el código del programa en Visual Studio Code.
2. Inicializar el código.
3. No utilizar el código en la terminal de Visual Studio Code .
4. Utilizar el ejecutable creado.
5. Maximizar la ventana emergente.
6. Pantalla de inicio del programa.
7. Menú principal del programa
8. Toma de datos del cliente
9. Destino a dónde desea viajar
10. Redirección al sistema de maletas.
11. Mostrar ganancias.
12. Iniciar abordaje.



## Autores ✒️

_En este proyecto todos los integrantes han panticipado activamente:_

* **Miguel Angel Deza Cuela** - *Programador* - [Miguel-Deza](https://github.com/Miguel-Deza)
* **Marko Marcelo Ituccayasi Umeres** - *Programador* - [Marko-Marcelo](https://github.com/MarkoMarcelo)
* **Gabriel Pacco Huaraca** - *Programador* - [GabrielPacco](https://github.com/GabrielPacco)
* **Gleddynuri Marbel Picha Chañi** - *Programador* - [Gleddynuri-Marbel](https://github.com/Gleddynuri-Marbel)
* **Erick Torres Quispe** - *Programador* - [ericktq](https://github.com/ericktq)

![image](https://user-images.githubusercontent.com/78099176/182055449-775ba12b-68ab-4f00-8b3c-ca2281404fbf.png)



## Licencia 📄
Este proyecto está bajo la Licencia BSD 3-Clause License - mira el archivo LICENSE.md para detalles
## Expresiones de Gratitud 🎁

* Agradecemos a todos nuestros profesores universitarios por inculcarnos todos sus conocimientos 📢
* Damos las gracias a todos nuestros seguidores futuros del repositorio 🤓.




---
