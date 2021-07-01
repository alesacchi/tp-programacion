#include <iostream>
#include <stdio.h>
#include "include/vuelta.h"
#include "include/info.h"
#include "include/pedirInput.h"
#include "include/listado.h"
#include "include/calculos.h"

using namespace std;

#define CANT_MAX_VUELTAS 30 // 1 mes

#pragma region FirmaFunciones
void cargarVueltas(Vuelta vueltas[], int &cantVueltas, float &kilometrosVuelta, bool &datosCargados);
void ordenarVueltas(Vuelta vueltas[], int cantVueltas);
#pragma endregion

int main()
{
    int vueltasCargadas = 0, opcion;
    float kilometrosVuelta = 0;
    Vuelta vueltas[CANT_MAX_VUELTAS];
    bool datosCargados = false;

    imprimirBienvenida();

    do
    {
        opcion = menu();

        switch (opcion)
        {
        case 1:
            cargarVueltas(vueltas, vueltasCargadas, CANT_MAX_VUELTAS, kilometrosVuelta, datosCargados);
            if (vueltasCargadas > 0)
            {
                ordenarVueltas(vueltas, vueltasCargadas);
            }
            break;
        case 2:
            listadoVueltasCargadas(vueltas, vueltasCargadas);
            break;
        case 3:
            informarVueltaRapida(vueltas, vueltasCargadas);
            break;
        case 4:
            informarVueltaLenta(vueltas, vueltasCargadas);
            break;
        case 5:
            informarReduccionEntrePeorYMejorTiempo(vueltas, vueltasCargadas, datosCargados);
            break;
        case 6:
            listadoVueltasSuperiorAVelocidadMedia(vueltas, vueltasCargadas, datosCargados);
            break;
        case 0:
            imprimirFinDelPrograma();
            break;
        default:
            cout << "Opcion incorrecta. Ingrese una opcion valida." << endl;
            break;
        }
    } while (opcion != 0);

    return 0;
}