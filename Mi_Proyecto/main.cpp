#include <iostream>
#include <stdio.h>
using namespace std;
#define NUM_VUELTAS 20

#pragma region FirmaFunciones
void bienvenida();
void leer(string mensaje, int &valor);
void cargarVueltas(int &vueltasCargadas);
void cargarDatosVueltas(int duracionVuelta[], int vueltasCargadas);
void calcularVueltaRapida(int duracionVuelta[], int vueltasCargadas, int &tiempoVueltaRapida);
void calcularVueltaLenta(int duracionVuelta[], int vueltasCargadas, int &tiempoVueltaLenta);
void menu(int &vueltasCargadas, int duracionVuelta[], int &tiempoVueltaRapida, int &tiempoVueltaLenta);
#pragma endregion

int main()
{
    int vueltasCargadas = 0;
    int duracionVuelta[NUM_VUELTAS] = {0};
    int tiempoVueltaRapida = 0;
    int tiempoVueltaLenta = 0;

    menu(vueltasCargadas, duracionVuelta, tiempoVueltaRapida, tiempoVueltaLenta);

    cout << vueltasCargadas << endl;

    for (int i = 0; i < vueltasCargadas; i++)
    {
        cout << duracionVuelta[i] << endl;
    }

    cout << "Vuelta rapida: " << tiempoVueltaRapida << endl;

    return 0;
}

#pragma region Funciones
void leer(string mensaje, int &valor)
{
    cout << mensaje;
    cin >> valor;
}

void cargarVueltas(int &vueltasCargadas)
{
    cout << endl;
    leer("Ingrese el numero de vueltas: ", vueltasCargadas);
}

void cargarDatosVueltas(int duracionVuelta[], int vueltasCargadas)
{
    if (vueltasCargadas > 0)
    {
        cout << endl;
        for (int i = 0; i < vueltasCargadas; i++)
        {
            cout << "Ingrese la duracion de la vuelta numero " << i + 1 << ": ";
            cin >> duracionVuelta[i];
        }
    }
    else
    {
        cout << endl;
        cout << "No hay vueltas para cargar" << endl;
    }
}

void calcularVueltaRapida(int duracionVuelta[], int vueltasCargadas, int &tiempoVueltaRapida)
{
    int nroVueltaRapida = 0;

    if (vueltasCargadas > 0)
    {
        tiempoVueltaRapida = duracionVuelta[0];
        for (int i = 0; i < vueltasCargadas; i++)
        {
            if (duracionVuelta[i] > tiempoVueltaRapida)
            {
                tiempoVueltaRapida = duracionVuelta[i];
                nroVueltaRapida = i + 1;
            }
        }
        cout << "La vuelta mas rapida fue la Nro " << nroVueltaRapida << " con un tiempo de " << tiempoVueltaRapida << endl;
    }
    else
    {
        cout << endl;
        cout << "No hay vueltas ingresadas" << endl;
    }
}

void calcularVueltaLenta(int duracionVuelta[], int vueltasCargadas, int &tiempoVueltaLenta)
{
    int nroVueltaLenta = 0;

    if (vueltasCargadas > 0)
    {
        tiempoVueltaLenta = duracionVuelta[0];
        for (int i = 0; i < vueltasCargadas; i++)
        {
            if (duracionVuelta[i] < tiempoVueltaLenta)
            {
                tiempoVueltaLenta = duracionVuelta[i];
                nroVueltaLenta = i + 1;
            }
        }
        cout << "La vuelta mas lenta fue la Nro " << nroVueltaLenta << " con un tiempo de " << tiempoVueltaLenta << endl;
    }
    else
    {
        cout << endl;
        cout << "No hay vueltas ingresadas" << endl;
    }
}

void bienvenida()
{
    cout << endl;
    cout << "******************************************************************************************************" << endl;
    cout << "*******                                                                                        *******" << endl;
    cout << "**** TSS - Laboratorio de Programacion I                                                          ****" << endl;
    cout << "**** Trabajo Practico - Ciclista                                                                  ****" << endl;
    cout << "****                               Karen Kunz, Nahuel Medici, Facundo Minicucci, Alejandro Sacchi ****" << endl;
    cout << "*******                                                                                        *******" << endl;
    cout << "******************************************************************************************************" << endl;
    cout << endl;
}

void menu(int &vueltasCargadas, int duracionVuelta[], int &tiempoVueltaRapida, int &tiempoVueltaLenta)
{
    int opcion;

    bienvenida();

    do
    {
        do
        {
            cout << endl;
            cout << "/------------ MENU -------------\\" << endl;
            cout << "| 1. Cargar vueltas             |" << endl;
            cout << "| 2. Ingresar datos de vueltas  |" << endl;
            cout << "| 3. Calcular vuelta mas rapida |" << endl;
            cout << "| 4. Calcular vuelta mas leta   |" << endl;
            cout << "| 5. Salir                      |" << endl;
            cout << "\\-------------------------------/" << endl;
            cout << "Ingrese la opcion: ";
            cin >> opcion;
        } while (opcion > 5 || opcion < 0);

        switch (opcion)
        {
        case 1:
            cargarVueltas(vueltasCargadas);
            break;
        case 2:
            cargarDatosVueltas(duracionVuelta, vueltasCargadas);
            break;
        case 3:
            calcularVueltaRapida(duracionVuelta, vueltasCargadas, tiempoVueltaRapida);
            break;
        case 4:
            calcularVueltaLenta(duracionVuelta, vueltasCargadas, tiempoVueltaLenta);
            break;
        case 5:
            cout << endl;
            cout << "Que tenga un buen dia!" << endl;
            system("PAUSE");
            break;
        }
    } while (opcion != 5);
}
#pragma endregion