#include "../include/vuelta.h"
#include "../include/calculos.h"

Vuelta obtenerVueltaRapida(Vuelta vueltas[], int cantVueltas)
{
    Vuelta vueltaRapida;

    vueltaRapida = vueltas[0];

    for (int i = 0; i < cantVueltas; i++)
    {
        if (vueltas[i].velocidad > vueltaRapida.velocidad)
        {
            vueltaRapida = vueltas[i];
        }
    }

    return vueltaRapida;
}

Vuelta obtenerVueltaLenta(Vuelta vueltas[], int cantVueltas)
{
    Vuelta vueltaLenta;

    vueltaLenta = vueltas[0];

    for (int i = 0; i < cantVueltas; i++)
    {
        if (vueltas[i].velocidad < vueltaLenta.velocidad)
        {
            vueltaLenta = vueltas[i];
        }
    }

    return vueltaLenta;
}

float obtenerVelocidadMediaGeneral(Vuelta vueltas[], int cantVueltas)
{
    float velSum = 0;

    for (int i = 0; i < cantVueltas; i++)
    {
        velSum += vueltas[i].velocidad;
    }

    return velSum / cantVueltas;
}