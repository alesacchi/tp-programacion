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