#include <iostream>
#include <string>

// #ifdef _WIN32
//     #include <windows.h>
// #endif

void limpiar_pantalla()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    std::cout << "\t\tJUEGO TRES EN RAYAS\n\n";
    std::cout << "\t\t# | 1 | 2 | 3 |\n";
    std::cout << "\t\t  ------------\n";
}

int main()
{
    // inicializo las variables
    int jugadas = 1, jugador = 1, suma;
    int tablero[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};

    int cordx, cordy, fin = 0;

    // inicio bucle juego
    while (jugadas < 10)
    {
        limpiar_pantalla();
        // std::cout << "\t\tJUEGO TRES EN RAYAS\n\n";
        // std::cout << "\t\t  | 1 | 2 | 3\n";
        // std::cout << "\t\t  ------------\n";

        for (int i = 0; i < 3; i++)
        {
            std::cout << "\t\t" << i + 1 << " | ";
            for (int j = 0; j < 3; j++)
            {
                std::cout << tablero[i][j] << " | ";
            }
            std::cout << std::endl;
        }

        // hacer bucle de movimiento
        std::cout << "Mueve el jugador: " << jugador << std::endl;

        // verifico movimiento
        do
        {
            int movi = 0; // para verificar movimiento
            // ---------------------------
            std::cout << "Ingresar numero de linea: ";
            std::cin >> cordx;
            std::cout << "Ingresar numero de Columna: ";
            std::cin >> cordy;

            // verifico las coordenadas
            if (cordx < 1 || cordx > 3 || cordy < 1 || cordy > 3 ) 
            {
                std::cout << "Ingresar bien las coordenadas\n";
                
                std::cin.get(); 
                // limpiar_pantalla();
            }
            // -------------------------------
            else
            {             
                // Actualizo el tablero
                if (tablero[cordx - 1][cordy - 1] == 0)
                {
                    // actualizo dato
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

                if (movi == 1)  // confirmo dato actualizado
                    break;
            }

        } while (true);

        // ------------------------------------------
        // verificar partida
        // ------------------------------------------

        // verifico lineas
        for (int i = 0; i < 3; i++)
        {
            suma = tablero[i][0] + tablero[i][1] + tablero[i][2];

            if ((tablero[i][0] == tablero[i][1]) && (tablero[i][0] == tablero[i][2]) && (suma == 6 || suma == 3))
            {
                fin = 1; // final partida con ganador
                break;
            };
        };

        // verifico columnas
        for (int i = 0; i < 3; i++)
        {
            suma = tablero[0][i] + tablero[1][i] + tablero[2][i];            

            if ((tablero[0][i] == tablero[1][i]) && (tablero[0][i] == tablero[2][i]) && (suma == 6 || suma == 3))
            {
                fin = 1;  // final partida con ganador
                break;
            };
        };

        // verifico diagonal 1
        suma = tablero[0][0] + tablero[1][1] + tablero[2][2];

        if ((tablero[0][0] == tablero[1][1]) && (tablero[0][0] == tablero[2][2]) && (suma == 6 || suma == 3))
        {
            fin = 1;  // final partida con ganador
        };

        // verifico diagonal 2
        suma = tablero[0][2] + tablero[1][1] + tablero[2][0];

        if ((tablero[0][2] == tablero[1][1]) && (tablero[0][2] == tablero[2][0]) && (suma == 6 || suma == 3))
        {
            fin = 1;  // final partida con ganador
        };        

        // Partida finalizada con ganador
        if (fin == 1)
        {
            limpiar_pantalla();
            for (int i = 0; i < 3; i++)
            {
                std::cout << "\t\t" << i + 1 << " | ";
                for (int j = 0; j < 3; j++)
                {
                    std::cout << tablero[i][j] << " | ";
                }
                std::cout << std::endl;
            }
            std::cout << "El ganador es el jugador: " << jugador << std::endl;
            break;
        }

        jugadas++; // incremento jugada

        // cambio el jugador    
        jugador = (jugador == 1) ? 2 : 1; 
      
    }
     if(fin==0){
         std::cout << "\n\nNo hubo ganadores ...\n\n";
         std::cin.get();
     }

    return 0;
}