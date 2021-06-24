#include <iostream>
#include <stdio.h>
#include "include/info.h"
#include "include/pedirInput.h"

using namespace std;

#define NUM_VUELTAS 20

struct Vuelta
{
    int orden;
    int tiempo;
    int fecha;
    float velocidadMedia;
};

#pragma region FirmaFunciones
void convertirTiempo(int minSegVuelta[][2], int vueltasCargadas, int duracionVuelta[]);
void cargarVueltas(int &vueltasCargadas, float &kilometrosVuelta);
void cargarDatosVueltas(int duracionVuelta[], int vueltasCargadas, int minSegVueltas[][2], bool &datosCargados);
float obtenerTiempoVueltaRapida(int duracionVuelta[], int vueltasCargadas);
float obtenerTiempoVueltaLenta(int duracionVuelta[], int vueltasCargadas);
void calcularVueltaRapida(int duracionVuelta[], int vueltasCargadas, int minSegVueltas[][2], bool datosCargados);
void calcularVueltaLenta(int duracionVuelta[], int vueltasCargadas, int minSegVueltas[][2], bool datosCargados);
void calcularVelocidadMedia(int vueltaRapida, int vueltaLenta, float kilometrosVuelta);
void informarReduccionEntrePeorYMejorTiempo(int duracionVuelta[], int vueltasCargadas, bool datosCargados);
#pragma endregion

int main()
{
    int vueltasCargadas = 0;
    float kilometrosVuelta = 0;
    int duracionVuelta[NUM_VUELTAS] = {0};
    int minSegVuelta[NUM_VUELTAS][2] = {0};
    int opcion;
    bool datosCargados = false;

    imprimirBienvenida();

    do
    {
        opcion = imprimirMenu();

        switch (opcion)
        {
        case 1:
            cargarVueltas(vueltasCargadas, kilometrosVuelta);
            break;
        case 2:
            cargarDatosVueltas(duracionVuelta, vueltasCargadas, minSegVuelta, datosCargados);
            break;
        case 3:
            calcularVueltaRapida(duracionVuelta, vueltasCargadas, minSegVuelta, datosCargados);
            break;
        case 4:
            calcularVueltaLenta(duracionVuelta, vueltasCargadas, minSegVuelta, datosCargados);
            break;
        case 5:
            informarReduccionEntrePeorYMejorTiempo(duracionVuelta, vueltasCargadas, datosCargados);
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

#pragma region Funciones
void convertirTiempo(int minSegVuelta[][2], int vueltasCargadas, int duracionVuelta[])
{
    //En la columna 0 guardo los minutos y en la columna 1 guardo los segundos
    for (int i = 0; i < vueltasCargadas; i++)
    {
        minSegVuelta[i][0] = duracionVuelta[i] / 100;
        minSegVuelta[i][1] = duracionVuelta[i] % 100;
    }
}

void cargarVueltas(int &vueltasCargadas, float &kilometrosVuelta)
{
    cout << endl;
    do
    {
        leer("Ingrese el numero de vueltas: ", vueltasCargadas);
    } while (vueltasCargadas < 1 || vueltasCargadas > NUM_VUELTAS);

    do
    {
        leer("Ingrese los kilometros de la vuelta: ", kilometrosVuelta);
    } while (kilometrosVuelta < 1);

    cout << endl;
    cout << "Se han cargado " << vueltasCargadas << " vueltas de " << kilometrosVuelta << "km." << endl;
}

void cargarDatosVueltas(int duracionVuelta[], int vueltasCargadas, int minSegVueltas[][2], bool &datosCargados)
{
    if (vueltasCargadas > 0)
    {
        cout << endl;
        for (int i = 0; i < vueltasCargadas; i++)
        {
            // TODO: no deberia permitir cargar horas > 23 y minutos > 59
            // mod: cout << "Ingrese la duracion de la vuelta numero " << i << " (MMSS):"
            cout << "Ingrese la duracion de la vuelta nro " << i + 1 << " (MMSS): ";
            cin >> duracionVuelta[i];
        }

        cout << "Se han cargado todas las vueltas." << endl;
        datosCargados = true;
    }
    else
    {
        cout << endl;
        cout << "No hay vueltas para cargar" << endl;
    }

    convertirTiempo(minSegVueltas, vueltasCargadas, duracionVuelta);
}

void calcularVueltaRapida(int duracionVuelta[], int vueltasCargadas, int minSegVueltas[][2], bool datosCargados)
{
    int vueltaRapida, posicionVueltaRapida = 0;

    if (datosCargados)
    {
        vueltaRapida = duracionVuelta[0];

        for (int i = 0; i < vueltasCargadas; i++)
        {
            if (duracionVuelta[i] < vueltaRapida)
            {
                vueltaRapida = duracionVuelta[i];
                posicionVueltaRapida = i;
            }
        }
        cout << "La vuelta mas rapida fue la nro " << posicionVueltaRapida + 1 << " y tuvo una duracion de " << minSegVueltas[posicionVueltaRapida][0] << " minutos y " << minSegVueltas[posicionVueltaRapida][1] << " segundos." << endl;
    }
    else
    {
        cout << endl;
        cout << "No hay vueltas ingresadas" << endl;
    }
}

void calcularVueltaLenta(int duracionVuelta[], int vueltasCargadas, int minSegVueltas[][2], bool datosCargados)
{
    int vueltaLenta, posicionVueltaLenta = 0;

    if (datosCargados)
    {
        vueltaLenta = duracionVuelta[0];

        for (int i = 0; i < vueltasCargadas; i++)
        {
            if (duracionVuelta[i] > vueltaLenta)
            {
                vueltaLenta = duracionVuelta[i];
                posicionVueltaLenta = i;
            }
        }
        cout << "La vuelta mas lenta fue la nro " << posicionVueltaLenta + 1 << " y tuvo una duracion de " << minSegVueltas[posicionVueltaLenta][0] << " minutos y " << minSegVueltas[posicionVueltaLenta][1] << " segundos." << endl;
    }
    else
    {
        cout << endl;
        cout << "No hay vueltas ingresadas" << endl;
    }
}

void calcularVelocidadMedia(int vueltaRapida, int vueltaLenta, float kilometrosVuelta)
{
    if (vueltaRapida != 0 && vueltaLenta != 0)
    {
        int minutosRapida = vueltaRapida / 100;
        int segundosRapida = vueltaRapida % 100;
        int minutosLenta = vueltaLenta / 100;
        int segundosLenta = vueltaLenta % 100;

        float tiempoRapida = (minutosRapida * 60) + segundosRapida;
        float tiempoLenta = (minutosLenta * 60) + segundosLenta;
        float metros = kilometrosVuelta * 1000;

        //TODO: si solo se carga 1 vuelta o los tiempos tiempoLenta y tiempoRapida son iguales,
        // queda división por 0. Agregar validación.
        float velocidadMedia = metros / (tiempoLenta - tiempoRapida);

        cout << "La velocidad media fue de " << velocidadMedia << " m/s." << endl;
    }
    else
    {
        cout << endl;
        cout << "No has calculado las vueltas rapida y lenta" << endl;
    }
}

float obtenerTiempoVueltaRapida(int duracionVuelta[], int vueltasCargadas)
{
    float tiempoVueltaRapida;

    tiempoVueltaRapida = duracionVuelta[0];

    for (int i = 0; i < vueltasCargadas; i++)
    {
        if (duracionVuelta[i] < tiempoVueltaRapida)
        {
            tiempoVueltaRapida = duracionVuelta[i];
        }
    }

    return tiempoVueltaRapida;
}

float obtenerTiempoVueltaLenta(int duracionVuelta[], int vueltasCargadas)
{
    float tiempoVueltaLenta;

    tiempoVueltaLenta = duracionVuelta[0];

    for (int i = 0; i < vueltasCargadas; i++)
    {
        if (duracionVuelta[i] > tiempoVueltaLenta)
        {
            tiempoVueltaLenta = duracionVuelta[i];
        }
    }

    return tiempoVueltaLenta;
}

void informarReduccionEntrePeorYMejorTiempo(int duracionVuelta[], int vueltasCargadas, bool hayDatos)
{
    cout << endl;

    if (!hayDatos)
    {
        cout << "No hay datos cargados." << endl;
    }
    else if (vueltasCargadas == 1)
    {
        cout << "Solo se cargo una vuelta. No es posible calcular la reduccion de tiempo entre el peor y mejor tiempo." << endl;
    }
    else
    {
        float porcentaje = 100 - ((obtenerTiempoVueltaRapida(duracionVuelta, vueltasCargadas) / obtenerTiempoVueltaLenta(duracionVuelta, vueltasCargadas)) * 100);
        cout << "Porcentaje de reduccion de tiempo entre el peor y mejor tiempo: " << porcentaje << "%" << endl;
    }
}
#pragma endregion