#include "../include/info.h"
#include <iostream>

using namespace std;

void imprimirBienvenida()
{
    cout << endl;
    cout << "******************************************************************************************************" << endl;
    cout << "*******                                                                                        *******" << endl;
    cout << "**** TSS - Laboratorio de Programacion I                                                          ****" << endl;
    cout << "**** Trabajo Practico - Ciclista                                                                  ****" << endl;
    cout << "****                               Karen Kunz, Nahuel Medice, Facundo Minicucci, Alejandro Sacchi ****" << endl;
    cout << "*******                                                                                        *******" << endl;
    cout << "******************************************************************************************************" << endl;
    cout << endl;
}

int imprimirMenu()
{
    int opcion;

    cout << endl;
    cout << "/------------ MENU ---------------\\" << endl;
    cout << "|                                 |" << endl;
    cout << "| 1. Cargar vueltas y kilometraje |" << endl;
    cout << "| 2. Ingresar datos de vueltas    |" << endl;
    cout << "| 3. Calcular vuelta mas rapida   |" << endl;
    cout << "| 4. Calcular vuelta mas lenta    |" << endl;
    cout << "| 5. Calcular velocidad media     |" << endl;
    cout << "| 0. Salir                        |" << endl;
    cout << "|                                 |" << endl;
    cout << "\\---------------------------------/" << endl;
    cout << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    return opcion;
}

void imprimirFinDelPrograma()
{
    cout << endl;
    cout << "Que tenga un buen dia!" << endl;
    cout << endl;
    system("PAUSE");
    cout << endl;
}