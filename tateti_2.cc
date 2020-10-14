/********************************************************* 
 * Programa: Juego Tradicional de Ta-Te-Ti / tres en raya
 * Nombre: Hugo Rodriguez
 * DNI 32.720.186-H
**********************************************************/

// Includes
#include <iostream>
#include <string>
#include <locale.h> // caracteres especiales
 #include <windows.h>
// #pragma setlocale("spanish")
using namespace std;

// declaración de funciones
void verificoPartida(int[][3], int, int, int &);
void limpiarPantalla(int[][3]);
void introducirCoordenada(string, int &);

// Principal
int main()
{
    // config caracteres especiales
     SetConsoleOutputCP(CP_UTF8);
    // setlocale( LC_ALL, "es-ES" );
    // setlocale(LC_ALL,"");
    // setlocale( LC_ALL, "es_ES.UTF-8" );
    // std::locale::global(std::locale("spanish")); //C++

    // inicializo las variables
    int jugadas = 1, jugador = 1, suma;
    int tablero[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};

    int cordx = 0;
    int cordy = 0;
    int fin = 0;

    // inicio bucle juego
    while (jugadas < 10)
    {
        limpiarPantalla(tablero);

        // hacer bucle de movimiento
        std::cout << "\nMueve el Jugador Nº: " << jugador << std::endl;

        // verifico movimiento
        do
        {
            int movi = 0; // para verificar movimiento

            // Ingreso Coordenadas
            introducirCoordenada("fila", cordx);
            introducirCoordenada("Columna", cordy);

            // Actualizo el tablero
            if (tablero[cordx - 1][cordy - 1] == 0)
            {
                tablero[cordx - 1][cordy - 1] = jugador;
                movi = 1;
            }
            else
            {
                // vuelvo a pedir movimiento
                if (tablero[cordx - 1][cordy - 1] > 0)
                {
                    std::cout << "Posicion ya ocupada\n";
                    std::cin.get();
                }
            }

            if (movi == 1) // confirmo dato actualizado
                break;

        } while (true);

        // ------------------------------------------
        // verificar partida
        // ------------------------------------------
        verificoPartida(tablero, cordx, cordy, fin);

        // Partida finalizada con ganador
        if (fin == 1)
        {
            limpiarPantalla(tablero);
            std::cout << "\nEl ganador es el Jugador N: " << jugador << std::endl;
            break;
        }

        jugadas++; // incremento jugada

        // cambio el jugador
        jugador = (jugador == 1) ? 2 : 1;
    }
    if (fin == 0)
    {
        std::cout << "\nE M P A T E !!!\nNo hubo ganadores ...\n\n";
        std::cin.get();
    }
    return 0;
} // fin de main

//verificacion de Partida
void verificoPartida(int tablero[][3], int cordx, int cordy, int &finalizado)
{

    int suma = 0;
    // verifico lineas
    suma = tablero[cordx - 1][0] + tablero[cordx - 1][1] + tablero[cordx - 1][2];

    if (suma > 0 && (tablero[cordx - 1][0] == tablero[cordx - 1][1]) && (tablero[cordx - 1][0] == tablero[cordx - 1][2]))
    {
        finalizado = 1; // final partida con ganador
    }

    // verifico columnas
    suma = tablero[0][cordy - 1] + tablero[1][cordy - 1] + tablero[2][cordy - 1];

    if ((tablero[0][cordy - 1] == tablero[1][cordy - 1]) && (tablero[0][cordy - 1] == tablero[2][cordy - 1]) && (suma > 0))
    {
        finalizado = 1; // final partida con ganador
    };

    // verifico diagonal 1
    suma = tablero[0][0] + tablero[1][1] + tablero[2][2];

    if ((tablero[0][0] == tablero[1][1]) && (tablero[0][0] == tablero[2][2]) && (suma > 0))
    {
        finalizado = 1; // final partida con ganador
    };

    // verifico diagonal 2
    suma = tablero[0][2] + tablero[1][1] + tablero[2][0];

    if ((tablero[0][2] == tablero[1][1]) && (tablero[0][2] == tablero[2][0]) && (suma > 0))
    {
        finalizado = 1; // final partida con ganador
    };
} // fin función

// Limpieza y redibujo pantalla
void limpiarPantalla(int tab[][3])
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    cout << "\tJUEGO TRES EN RAYAS - TA-TE-TI\n\n";
    cout << "\t\t# | 1 | 2 | 3 |\n";
    cout << "\t\t  ------------\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "\t\t" << i + 1 << " | ";
        for (int j = 0; j < 3; j++)
        {
            if( tab[i][j] > 0){
            cout << tab[i][j] << " | ";
            }else
            {
                cout << "." << " | ";
            }
            
        }
        cout << endl;
    }
} // fin función

// Entrada de datos de FILA / COLUMNA
void introducirCoordenada(string cadena, int &numero)
{
    // int numero;
    do
    {
        cout << "\tIngresar numero de " << cadena << ": ";
        cin >> numero;
        if (cin.fail())
        {
            cout << "Eso no es un numero" << endl;
            cin.clear();
            cin.ignore();
            cin.get();
        }

    } while (numero < 1 || numero > 3);
    //  return numero;
} // fin función