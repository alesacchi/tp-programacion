#include "../include/vuelta.h"
#include "../include/pedirInput.h"

struct Vuelta vuelta;

void cargarVueltas(Vuelta vueltas[], int &cantVueltas, int cantMaxVueltas, float &km, bool &hayDatos)
{
    Vuelta vuelta;
    int dia, mes;

    cout << endl;

    km = ingresarKm();
    mes = ingresarMes();

    cout << endl;
    cout << "Cargando datos de vuelta..." << endl;
    dia = ingresarDia();

    while (cantVueltas < cantMaxVueltas && dia != 0)
    {
        vuelta.fecha = (mes * 100) + dia;

        vuelta.tiempo = ingresarTiempo();
        vuelta.velocidad = km / (vuelta.tiempo / 100);

        vueltas[cantVueltas] = vuelta;

        cout << endl;
        cout << "Cargando datos de vuelta..." << endl;
        dia = ingresarDia();

        cantVueltas++;
    }

    hayDatos = cantVueltas > 0;
}

void ordenarVueltas(Vuelta vueltas[], int cantVueltas)
{
    int i = 0, j, aux;
    bool ordenado = false;

    while (i < cantVueltas && !ordenado)
    {
        ordenado = true;
        for (j = 0; j < cantVueltas - i - 1; j++)
        {
            if (vueltas[j].fecha > vueltas[j + 1].fecha)
            {
                aux = vueltas[j].fecha;
                vueltas[j].fecha = vueltas[j + 1].fecha;
                vueltas[j + 1].fecha = aux;
                ordenado = false;
            }
        }
        i++;
    }
}