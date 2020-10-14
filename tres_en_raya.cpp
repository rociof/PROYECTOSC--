
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

/*función para controlar que las posiciones que indica el jugador están dentro
 de los posibles valores del array. Se le pasa el parámetro nombre para
 que la función sirva para pedirle al usuario fila y columna */

int introducir_numero(int desde, int hasta, string nombre)
{
    int numero;

    do
    {
        cout << "Introduzca la " << nombre << " entre " << desde << " y " << hasta << endl;
        cin >> numero;
        if (cin.fail())
        {
            cout << "Eso no es un numero" << endl;
            cin.clear();
            cin.ignore();
        }

    } while (numero < desde || numero > hasta);
    return numero;
}

//hay que crear un array bidimensional de 3x3
int i, j;
int tablero[3][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}};

// Se hace un bucle for anidado para mostrar filas y columnas
void mostrar_tablero()
{
    cout << "\t JUEGO TRES EN RAYA \n\n";
    for (i = 0; i < 3; i++)
    {

        for (j = 0; j < 3; j++)
        {
            cout << "\t | " << tablero[i][j] << " | ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{

    int jugador = 1;
    int fila, col;
    int mov = 0;
    int jugada = 0;
    int i, j;
    /* Esta función solicita un número por entrada estándar de teclado  dentro del intervalo delimitado por "desde" y "hasta"
     La función trabaja con números enteros*/

    mostrar_tablero();

    cout << "Comenzamos el juego" << endl;

    do
    {
        fila = introducir_numero(1, 3, "fila");
        col = introducir_numero(1, 3, "columna");
    }

    while (jugada < 10);
    {
        //llamamos a la función introducir_numero

       

        if (tablero[fila][col] != 0)
        {
            cout << "La casilla está ocupada, elige otra posición " << endl ;
        }
        else {
            tablero[fila][col] = jugador;
             mov++;
             mostrar_tablero();
             jugador = 2;
        }
    }
    /*Mientras no haya ganador, comprobar que la casilla esté vacía y colocar ficha del jugador al que le toque.
    Si no está vacía, lanzamos una alerta de casilla ocupada y  volvemos al inicio
    Si está vacía se coloca la ficha de ese jugador y se cambia de turno (del 1 al 2 y del 2 al 1) */

    //Si hay ganador y el tablero está lleno

#ifdef _WIN32
system("pause");
#elif
system("read -r");
#endif
return 0;
}