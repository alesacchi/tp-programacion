#pragma once

struct Vuelta
{
    int fecha;    // MMDD
    float tiempo; // MMSS
    float velocidad;
};

void cargarVueltas(Vuelta vueltas[], int &cantVueltas, int cantMaxVueltas, float &km, bool &hayDatos);
void ordenarVueltas(Vuelta vueltas[], int cantVueltas);