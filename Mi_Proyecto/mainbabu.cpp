#include <iostream>
#include <stdio.h>
using namespace std;
#define NUM_VUELTAS 20

void leer(string mensaje, int &valor){
    cout << mensaje << endl;
    cin >> valor;
}

void cargarVueltas(int &vueltasCargadas){
    cout << endl;
    leer("Ingrese el numero de vueltas", vueltasCargadas);
}

void cargarDatosVueltas(int duracionVuelta[], int vueltasCargadas){
    if(vueltasCargadas > 0){
        cout << endl;
        for (int i = 0; i < vueltasCargadas; i++)
        {
            cout << "Ingrese la duracion de la vuelta numero " << i+1 << endl;
            cin >> duracionVuelta[i];
        }
    }
    else{
        cout << endl;
        cout << "No hay vueltas para cargar" << endl;
    }
}

void calcularVueltaRapida(int duracionVuelta[], int vueltasCargadas, int &vueltaRapida){
    if(vueltasCargadas > 0){
        vueltaRapida = duracionVuelta[0];
        for (int i = 0; i < vueltasCargadas; i++)
        {
            if (duracionVuelta[i] > vueltaRapida)
            {
                vueltaRapida = duracionVuelta[i];
            }
        }
        cout << "La vuelta mas rapida fue de " << vueltaRapida << endl;
    }
    else{
        cout << endl;
        cout << "No hay vueltas ingresadas" << endl;
    }
}

void menu(int &vueltasCargadas, int duracionVuelta[], int &vueltaRapida){
    int opcion;

    do
    {
        do
        {
            cout << endl;
            cout << "Menu" << endl;
            cout << "1- Cargar vueltas" << endl;
            cout << "2- Ingresar datos de vueltas" << endl;
            cout << "3- Calcular vuelta mas rapida" << endl;
            cout << "4- Salir" << endl;
            cout << "Ingrese la opcion: ";
            cin >> opcion;
        }while (opcion > 5 || opcion < 0);
        
        switch (opcion)
        {
        case 1:
            cargarVueltas(vueltasCargadas);
            break;
        case 2:
            cargarDatosVueltas(duracionVuelta, vueltasCargadas);
            break;
        case 3:
            calcularVueltaRapida(duracionVuelta, vueltasCargadas, vueltaRapida);
            break;
        case 4:
            cout << "Que tenga un buen dia" << endl;
            break;
        }
    } while (opcion != 4);
}

int main(){
    int vueltasCargadas = 0;
    int duracionVuelta[NUM_VUELTAS] = {0};
    int vueltaRapida = 0;

    menu(vueltasCargadas, duracionVuelta, vueltaRapida);

    cout << vueltasCargadas << endl;

    for (int i = 0; i < vueltasCargadas; i++)
    {
        cout << duracionVuelta[i] << endl;
    }

    cout << "Vuelta rapida: " << vueltaRapida << endl;
    
    return 0;
}