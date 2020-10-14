#include <iostream>

/**
 * Array para contener el estado del tablero.
 */
int tablero[3][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}};

/**
 * Turno del jugador actual.
 */
int jugador = 1;

/**
 * Visualiza el estado del tablero.
 */
void mostrar_tablero()
{
    system("cls");
    std::cout << "\t JUEGO TRES EN RAYA \n\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
           std::cout << "\t | " << tablero[i][j] << " | ";
            //std::cout << tablero[i][j];
        }
        std::cout << std::endl;
    }
}

/**
 * Pide por teclado dos valores entre 1 y 3, entregándolos en
 * las variables fila y columna (pasadas por referencia).
 * Si el usuario introduce valores fuera de rango, vuelve a pedirselo.
 * Al final, los valores son corregidos: el valor final de ambos estará
 * entre 0 y 2.
 */

/*paso de variable por referencia, no se hace una copia se le da la referencia
de la dirección de memoria de la variable original
Se hace porque cuando termine esa función se siguen manteniendo esos valores*/
void solicitar_posicion(int &fila, int &columna)
{
    do
    {
        std::cout << "Introduzca fila: " << std::endl;
        std::cin >> fila;
    } while (fila < 1 || fila > 3);
    fila--;

    do
    {
        std::cout << "Introduzca columna: " << std::endl;
        std::cin >> columna;
    } while (columna < 1 || columna > 3);
    columna--;
}

bool casilla_ocupada(int fila, int columna)
{
    return tablero[fila][columna] != 0;
}

int ganador()
{ /*la función tiene que hacer un return si encuentra ganador;
    Devuelve 1 o 2 en ese caso; 0 si no gana nadie*/
    for (int k = 0; k < 3; k++)
    {
        // comprobación de fila
        //la primera casilla tiene que ser igual a la segunda y la tercera tiene que ser igual a la primera
        if (tablero[0][0]!=0 && tablero[0][1] == tablero[0][0] && tablero[0][2]==tablero[0][0])
            return tablero[0][0];
        if (tablero[1][0]!=0 && tablero[1][1] == tablero[1][0] && tablero[1][2]==tablero[1][0])
            return tablero[1][0];
        if (tablero[2][0]!=0 && tablero[2][1] == tablero[2][0] && tablero[2][2]==tablero[2][0])
            return tablero[2][0];
        //if (tablero[k][0] && tablero[k][0]==tablero[k][1] && tablero[k][0]==tablero[k][2]) return tablero[k][0];

        // comprobación de columna
        if (tablero[0][0]!=0 && tablero[1][0] == tablero[0][0] && tablero[2][0] == tablero[0][0])
          return tablero[0][0];
        if (tablero[0][1]!=0 && tablero[1][1] == tablero[0][1] && tablero[2][1] == tablero[0][1])
          return tablero[0][1];
        if (tablero[0][2]!=0 && tablero[1][2] == tablero[0][2] && tablero[2][2] == tablero[0][2])
          return tablero[0][2];


        // if (tablero[0][0]!=0 && tablero[0][k] == tablero[1][k] && tablero[0][k] == tablero[2][k])
        //     return tablero[0][k];
        
    }

    // comprobación de diagonal directa
    if (tablero[0][0]!=0 && tablero[1][1] == tablero[0][0] && tablero[2][2] == tablero[0][0])
          return tablero[0][0];


    // if (tablero[0][0] && tablero[0][0] == tablero[1][1] && tablero[0][0] == tablero[2][2])
    //     return tablero[0][0];

    // comprobación de diagonal inversa
    if (tablero[2][0]!=0 && tablero[1][1] == tablero[2][0] && tablero[0][2] == tablero[2][0])
          return tablero[2][0];


    // if (tablero[2][0] && tablero[2][0] == tablero[1][1] && tablero[2][0] == tablero[0][2])
    //     return tablero[2][0];

    // en caso contrario, no hay ganador
    return 0;
}

/*Función para alternar el turno del jugador
Se pasa por referencia para que cambie el valor de la función
void cambiar_turno(int& turno) {
            if(turno == 1){
                turno = 2;
            } else {
                turno = 1;
            }
    // se podría poner también como turno = 3 - turno;
}


 */

int main()
{
    /* Habría dos opciones, hacerlo con un while o un for
    int contador = 0;
    int ganador = 0;
    int turno = 1; //empieza jugador 1
    //invocamos a la función ganador en el while y lo va a comparar con 0.
    //Si hay ganador va a salir del bucle
    while (ganador() ==0 && contador < 9){
        mostrar_tablero();
        solicitar_posicion(fila, columna);
        //comprobar si la casilla no está ocupada
        if (tablero[fila][columna] == 0) {
            //poner ficha e incrementar contador
            tablero[fila][columna] = turno;
            contador++;  
            // llamamos a la función cambiar turno para cambiar de jugador
            cambiar_turno(turno);
        } else {
            std::cout << "Casilla ocupada" << std:: endl;
           
        }
        
    */
    for (int jugadas = 0; jugadas < 9 && !ganador(); jugadas++)
    {
        mostrar_tablero();
        std::cout << "Turno del jugador " << jugador << std::endl;
        while (true)
        {
            int fila, columna;
            solicitar_posicion(fila, columna);
            if (casilla_ocupada(fila, columna))
            {
                std::cout << "Esa casilla ya está ocupada." << std::endl;
            }
            else
            {
                tablero[fila][columna] = jugador;
                break;
            }
        }
        //jugador = 3 - jugador;
        //Otra forma sería:
        if (jugador == 1)
            jugador = 2;
        else
            jugador = 1;
    }
    //Al terminar, mostramos tablero por última vez y el ganador que es
    mostrar_tablero();
    if (ganador())
    {
        std::cout << "Gana el jugador " << ganador() << std::endl;
    }
    else
    {
        std::cout << "No hay ganador." << std::endl;
    }

    system("pause");
    return 0;
}