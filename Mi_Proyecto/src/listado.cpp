#include "../include/vuelta.h"
#include "../include/calculos.h"
#include "../include/listado.h"

#include <iostream>

using namespace std;

void informarVueltaRapida(Vuelta vueltas[], int cantVueltas)
{
    if (cantVueltas > 0)
    {
        Vuelta vuelta = obtenerVueltaRapida(vueltas, cantVueltas);
        int min = vuelta.tiempo / 100;
        int seg = vuelta.tiempo - (min * 100);
        int mes = vuelta.fecha / 100;
        int dia = vuelta.fecha - (mes * 100);

        cout << endl;
        cout << "\t\t\t--- Vuelta Mas Rapida ---" << endl;
        cout << endl;
        cout << "\t\tFecha\tMinutos\tSegundos\tVelocidad" << endl;
        cout << "\t\t" << dia << "/" << mes << "\t" << min << "\t" << seg << "\t\t" << vuelta.velocidad << "km/m" << endl;
    }
    else
    {
        cout << "No hay datos cargados." << endl;
    }

    cout << endl;
    system("PAUSE");
}

void informarVueltaLenta(Vuelta vueltas[], int cantVueltas)
{
    if (cantVueltas > 0)
    {
        Vuelta vuelta = obtenerVueltaLenta(vueltas, cantVueltas);
        int min = vuelta.tiempo / 100;
        int seg = vuelta.tiempo - (min * 100);
        int mes = vuelta.fecha / 100;
        int dia = vuelta.fecha - (mes * 100);

        cout << endl;
        cout << "\t\t\t--- Vuelta Mas Lenta ---" << endl;
        cout << endl;
        cout << "\t\tFecha\tMinutos\tSegundos\tVelocidad" << endl;
        cout << "\t\t" << dia << "/" << mes << "\t" << min << "\t" << seg << "\t\t" << vuelta.velocidad << "km/m" << endl;
    }
    else
    {
        cout << "No hay datos cargados." << endl;
    }

    cout << endl;
    system("PAUSE");
}

void listadoVueltasCargadas(Vuelta vueltas[], int cantVueltas)
{
    if (cantVueltas > 0)
    {
        cout << endl;
        cout << "\t\t\t--- Listado de Vueltas Cargadas ---" << endl;
        cout << endl;
        cout << "\t\tFecha\tMinutos\tSegundos\tVelocidad" << endl;

        for (int i = 0; i < cantVueltas; i++)
        {
            int min = vueltas[i].tiempo / 100;
            int seg = vueltas[i].tiempo - (min * 100);
            int mes = vueltas[i].fecha / 100;
            int dia = vueltas[i].fecha - (mes * 100);

            cout << "\t\t" << dia << "/" << mes << "\t" << min << "\t" << seg << "\t\t" << vueltas[i].velocidad << " km/m" << endl;
        }
    }
    else
    {
        cout << "No es posible generar el listado. No hay datos cargados." << endl;
    }

    cout << endl;
    system("PAUSE");
}

void informarReduccionEntrePeorYMejorTiempo(Vuelta vueltas[], int cantVueltas, bool hayDatos)
{
    cout << endl;

    if (!hayDatos)
    {
        cout << "No hay datos cargados." << endl;
    }
    else if (cantVueltas == 1)
    {
        cout << "Solo se cargo una vuelta. No es posible calcular la reduccion de tiempo entre el peor y mejor tiempo." << endl;
    }
    else
    {
        float porcentaje = 100 - ((obtenerVueltaRapida(vueltas, cantVueltas).tiempo / obtenerVueltaLenta(vueltas, cantVueltas).tiempo) * 100);
        cout << "Porcentaje de reduccion de tiempo entre el peor y mejor tiempo: " << porcentaje << "%" << endl;
    }

    cout << endl;
    system("PAUSE");
}

void listadoVueltasSuperiorAVelocidadMedia(Vuelta vueltas[], int cantVueltas, bool hayDatos)
{
    int dia, mes;
    float velMediaGeneral = obtenerVelocidadMediaGeneral(vueltas, cantVueltas);

    cout << endl;

    if (!hayDatos)
    {
        cout << "No es posible generar el listado. No hay datos cargados." << endl;
        return;
    }

    cout << "\t\t\t--- Listado de vueltas que superan la velocidad media (" << velMediaGeneral << "km/m) ---" << endl;
    cout << endl;
    cout << "\t\tFecha\tVelocidad" << endl;

    for (int i = 0; i < cantVueltas; i++)
    {
        if (vueltas[i].velocidad > velMediaGeneral)
        {
            mes = vueltas[i].fecha / 100;
            dia = vueltas[i].fecha - (mes * 100);
            cout << "\t\t" << dia << "\\" << mes << "\t" << vueltas[i].velocidad << " km/m" << endl;
        }
    }

    cout << endl;
    system("PAUSE");
}