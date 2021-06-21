#include "../include/pedirInput.h"
#include <iostream>

using namespace std;

void leer(string mensaje, int &valor)
{
    cout << mensaje;
    cin >> valor;
}

void leer(string mensaje, float &valor)
{
    cout << mensaje;
    cin >> valor;
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