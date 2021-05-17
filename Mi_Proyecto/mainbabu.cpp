#include <iostream>
#include <stdio.h>
using namespace std;
#define NUM_VUELTAS 20

void leer(string mensaje, int &valor){
    cout << mensaje << endl;
    cin >> valor;
}
void leer(string mensaje, float &valor){
    cout << mensaje << endl;
    cin >> valor;
}

void convertirTiempo(int minSegVuelta[][2], int vueltasCargadas, int duracionVuelta[]){
    int minutos = 0;
    int segundos = 0;

    //En la columna 0 guardo los minutos y en la columna 1 guardo los segundos
    for (int i = 0; i < vueltasCargadas; i++)
    {
        minutos = duracionVuelta[i] / 100;
        segundos = duracionVuelta[i] % 100;
        minSegVuelta[i][0] = minutos;
        minSegVuelta[i][1] = segundos;
    }
    
    
}

string obtenerPosicion(int vuelta){
    string posicionVuelta[20];
    posicionVuelta[0] = "primera vuelta";
    posicionVuelta[1] = "segunda vuelta";
    posicionVuelta[2] = "tercer vuelta";
    posicionVuelta[3] = "cuarta vuelta";
    posicionVuelta[4] = "quinta vuelta";
    posicionVuelta[5] = "sexta vuelta";
    posicionVuelta[6] = "septima vuelta";
    posicionVuelta[7] = "octava vuelta";
    posicionVuelta[8] = "novena vuelta";
    posicionVuelta[9] = "decima vuelta";
    posicionVuelta[10] = "undecima vuelta";
    posicionVuelta[11] = "duodecima vuelta";
    posicionVuelta[12] = "decimotercer vuelta";
    posicionVuelta[13] = "decimocuarta vuelta";
    posicionVuelta[14] = "decimoquinta vuelta";
    posicionVuelta[15] = "decimosexta vuelta";
    posicionVuelta[16] = "decimoseptima vuelta";
    posicionVuelta[17] = "decimoctava vuelta";
    posicionVuelta[18] = "decimonovena vuelta";
    posicionVuelta[19] = "vigesima vuelta";

    return posicionVuelta[vuelta];
}

void cargarVueltas(int &vueltasCargadas, float &kilometrosVuelta){
    cout << endl;
    leer("Ingrese el numero de vueltas", vueltasCargadas);
    leer("Ingrese los kilometros de la vuelta", kilometrosVuelta);
    cout << "Se han cargado " << vueltasCargadas << " vueltas de " << kilometrosVuelta << "km." << endl;
}

void cargarDatosVueltas(int duracionVuelta[], int vueltasCargadas, int minSegVueltas[][2]){
    if(vueltasCargadas > 0){
        cout << endl;
        for (int i = 0; i < vueltasCargadas; i++)
        {
            cout << "Ingrese la duracion de la " << obtenerPosicion(i) << " (MMSS)" << endl;
            cin >> duracionVuelta[i];
        }

        cout << "Se han cargado todas las vueltas" << endl;
    }
    else{
        cout << endl;
        cout << "No hay vueltas para cargar" << endl;
    }

    convertirTiempo(minSegVueltas, vueltasCargadas, duracionVuelta);
}

void calcularVueltaRapida(int duracionVuelta[], int vueltasCargadas, int &vueltaRapida, int minSegVueltas[][2]){
    int posicionVueltaRapida = 0;

    if(vueltasCargadas > 0){
        vueltaRapida = duracionVuelta[0];

        for (int i = 0; i < vueltasCargadas; i++)
        {
            if (duracionVuelta[i] > vueltaRapida)
            {
                vueltaRapida = duracionVuelta[i];
                posicionVueltaRapida = i;
            }
        }
        cout << "La vuelta mas rapida fue la " << obtenerPosicion(posicionVueltaRapida) << " y tuvo una duracion de " << minSegVueltas[posicionVueltaRapida][0] << ":" << minSegVueltas[posicionVueltaRapida][1] << endl;
    }
    else{
        cout << endl;
        cout << "No hay vueltas ingresadas" << endl;
    }
}

void calcularVueltaLenta(int duracionVuelta[], int vueltasCargadas, int minSegVueltas[][2], int &vueltaLenta){
    int posicionVueltaLenta = 0;

    if(vueltasCargadas > 0){
        vueltaLenta = duracionVuelta[0];

        for (int i = 0; i < vueltasCargadas; i++)
        {
            if (duracionVuelta[i] < vueltaLenta)
            {
                vueltaLenta = duracionVuelta[i];
                posicionVueltaLenta = i;
            }
        }
        cout << "La vuelta mas lenta fue la " << obtenerPosicion(posicionVueltaLenta) << " y tuvo una duracion de " << minSegVueltas[posicionVueltaLenta][0] << ":" << minSegVueltas[posicionVueltaLenta][1] << endl;
    }
    else{
        cout << endl;
        cout << "No hay vueltas ingresadas" << endl;
    }
}

void calcularVelocidadMedia(int vueltaRapida, int vueltaLenta, float kilometrosVuelta){
    int minutosRapida = vueltaRapida / 100;
    int segundosRapida = vueltaRapida % 100;
    int minutosLenta = vueltaRapida / 100;
    int segundosLenta = vueltaRapida % 100;

    int tiempoRapida = (minutosRapida * 60) + segundosRapida;
    int tiempoLenta = (minutosLenta * 60) + segundosLenta;

    float velocidadMedia = kilometrosVuelta / (tiempoRapida - tiempoLenta);

    cout << "La velocidad media fue de " << velocidadMedia << "m/s" << endl;
}

void menu(int &vueltasCargadas, int duracionVuelta[], int &vueltaRapida, float &kilometrosVuelta, int minSegVueltas[][2], int &vueltaLenta){
    int opcion;

    do
    {
        do
        {
            cout << endl;
            cout << "Menu" << endl;
            cout << "1- Cargar vueltas y kilometraje" << endl;
            cout << "2- Ingresar datos de vueltas" << endl;
            cout << "3- Calcular vuelta mas rapida" << endl;
            cout << "4- Calcular vuelta mas lenta" << endl;
            cout << "5- Calcular velocidad media" << endl;
            cout << "6- Salir" << endl;
            cout << "Ingrese la opcion: ";
            cin >> opcion;
        }while (opcion > 6 || opcion < 0);
        
        switch (opcion)
        {
        case 1:
            cargarVueltas(vueltasCargadas, kilometrosVuelta);
            break;
        case 2:
            cargarDatosVueltas(duracionVuelta, vueltasCargadas, minSegVueltas);
            break;
        case 3:
            calcularVueltaRapida(duracionVuelta, vueltasCargadas, vueltaRapida, minSegVueltas);
            break;
        case 4:
            calcularVueltaLenta(duracionVuelta, vueltasCargadas, minSegVueltas, vueltaLenta);
            break;
        case 5:
            calcularVelocidadMedia(vueltaRapida, vueltaLenta, kilometrosVuelta);
            break;
        case 6:
            cout << "Que tenga un buen dia" << endl;
            break;
        }
    } while (opcion != 6);
}

int main(){
    int vueltasCargadas = 0;
    float kilometrosVuelta = 0;
    int duracionVuelta[NUM_VUELTAS] = {0};
    int vueltaRapida = 0;
    int vueltaLenta = 0;
    int minSegVuelta[][2] = {0};

    menu(vueltasCargadas, duracionVuelta, vueltaRapida, kilometrosVuelta, minSegVuelta, vueltaLenta);
    
    return 0;
}