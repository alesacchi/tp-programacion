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

int menu()
{
    int opcion;

    cout << endl;
    cout << "\t\t/--------------------------------- MENU ---------------------------------\\" << endl;
    cout << "\t\t|                                                                        |" << endl;
    cout << "\t\t| 1. Cargar vueltas y kilometraje                                        |" << endl;
    cout << "\t\t| 2. Listado de vueltas cargadas                                         |" << endl;
    cout << "\t\t| 3. Informar vuelta mas rapida                                          |" << endl;
    cout << "\t\t| 4. Informar vuelta mas lenta                                           |" << endl;
    cout << "\t\t| 5. Informar porcentaje de reduccion entre peor y mejor tiempo          |" << endl;
    cout << "\t\t| 6. Listado de vueltas que superan la velocidad media del entrenamiento |" << endl;
    cout << "\t\t| 0. Salir                                                               |" << endl;
    cout << "\t\t|                                                                        |" << endl;
    cout << "\t\t\\------------------------------------------------------------------------/" << endl;
    cout << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    return opcion;
}

int ingresarDia()
{
    int dia;
    do
    {
        leer("\tIngresar el dia de la vuelta (0 para salir): ", dia);
    } while (dia < 0 || dia > 31);
    return dia;
}

int ingresarMes()
{
    int mes;
    do
    {
        leer("Ingresar el mes en el que se realiza el entrenamiento: ", mes);
    } while (mes < 1 || mes > 12);
    return mes;
}

float ingresarTiempo()
{
    float tiempo;
    leer("\tIngresar el tiempo de la vuelta (MMSS): ", tiempo);
    while (tiempo < 0001 || tiempo > 6060)
    {
        cout << "Tanto los minutos como los segundos deben estar en el rango de 0 a 60." << endl;
        leer("\tIngresar el tiempo de la vuelta (MMSS): ", tiempo);
    }

    return tiempo;
}

float ingresarKm()
{
    float km;

    leer("Ingresar los km recorridos: ", km);
    while (km <= 0)
    {
        cout << "Los km deben ser mayores a 0." << endl;
        leer("Ingresar los km recorridos: ", km);
    }

    return km;
}