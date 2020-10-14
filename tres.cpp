#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int tablero[3][3] = {
	{0, 0, 0},
	{0, 0, 0},
	{0, 0, 0}
};
int i,j;
int fila=0, col=0;
int jugador=1;
int movj1=0, movj2=0;
bool final = false;
int error=0;


void dibujar(){
	// Borramos y mostramos en pantalla el tablero
    system("cls");
	cout << "\t JUEGO TRES EN RAYA \n\n";
    for( i = 0; i < 3; i++ ) {
        for( j = 0; j < 3; j++ ) {
			cout << "\t | " << tablero[i][j] << " | ";
		}
        cout << endl;
    }
	cout << "\n";
}

void comprobar() {
	int pieza;
	int contador;
	int ganador = 0;
	int movimientos = 0;
	// Comprobar horizontales (fichas del mismo jugador con la misma coordenada 'x')
	for( i=0; i<3; i++ )
	{
		contador=0;
		pieza = tablero[i][0];
		if( pieza == jugador )
		{
			contador++;
			for( j=1; j<3; j++ )
			{
				if( tablero[i][j] != pieza )
					break;
				else
					contador++;
				if( contador == 3 ) // Si hay 3 fichas iguales el jugador gana
					ganador = jugador;
			}
		}
	}
	// Comprobar verticales (fichas del mismo jugador con la misma coordenada 'y')
	for( i=0; i<3; i++ )
	{
		contador=0;
		pieza = tablero[0][i];
		if( pieza == jugador )
		{
			contador++;
			for( j=1; j<3; j++ )
			{
				if( tablero[j][i] != pieza )
					break;
				else
					contador++;
				if( contador == 3 ) // Si hay 3 fichas iguales en línea el jugador gana
					ganador = jugador;
			}
		}
	}

    // Comprobar diagonal izq a dcha. (fichas del mismo jugador con coordenada 'x' = coordenada 'y')
	contador = 0;
	pieza = tablero[0][0];
	if( pieza == jugador )
	{
		contador++;
		for( i=1; i<3; i++ )
		{
			if( tablero[i][i] != pieza )
				break;
			else
				contador++;
			if( contador == 3 ) // Si hay 3 fichas iguales el jugador gana
				ganador = jugador;
		}
	}

    // Comprobar diagonal dcha a izq. (fichas del mismo jugador con coordenada 'x' desde 0 a length-1 y coordenada 'y' desde length-1 a 0
	contador = 0;
	pieza = tablero[0][2];
	if( pieza == jugador )
	{
		contador++;
		for( i=1; i<3; i++ )
		{
			if( tablero[i][2-i] != pieza )
				break;
			else
				contador++;
			if( contador == 3 ) // Si hay 3 fichas iguales el jugador gana
				ganador = jugador;
		}
	}
	// Si hay ganador, el final cambia a true, se muestra en pantalla y  se llega al final partida
	if( ganador != 0 ) {
		movimientos = (jugador == 1) ? movj1 : movj2; 
		cout << "\n Jugador " << ganador << " HA GANADO después de " << movimientos << " movimientos."  << endl;
		final = true;
	}
	
}

void coordenadas(){
	//podría ser un if(tablero[fila-1][columna-1] !=0)
	if( error == 1 ) { // error=1 si no seleccionaron unas coordenadas vacías
		cout << "Jugador " << jugador << " Elija coordenadas vacías " << endl;
	}
	// Pedimos la coordenada de la fila mientras no teclee entre 1 y 3
	do{
		cout << "Jugador " << jugador << " Introduzca la Fila entre 1 y 3 " << endl;
		cin >> fila;
		if (cin.fail())
        {
            cout << "Eso no es un numero" << endl;
            cin.clear();
            cin.ignore();
        }
	}
	while( fila<1 || fila>3 );
	
	// Pedimos la coordenada de la columna mientras no teclee entre 1 y 3
	do{
		cout << "Jugador " << jugador << " Introduzca la Columna entre 1 y 3 " << endl;
		cin >> col;
		if (cin.fail())
        {
            cout << "Eso no es un numero" << endl;
            cin.clear();
            cin.ignore();
        }
	}
	while( col<1 || col>3 );


	// Comprobamos que las coordenadas corresponden a un lugar vacío y modificamos el array. Si no está vacío error=1
	if(	tablero[fila-1][col-1] == 0 ) {
		error = 0;
		tablero[fila-1][col-1] = jugador;
		dibujar();
		if( jugador == 1 )
			movj1 ++;
		else
			movj2 ++;

		// Si se han movido al menos 3 fichas comprobamos si hay ganador con tres en raya. También podría ser 
		//if( movj1 + movj2 >= 5 )
		if( movj1>=3 || movj2>=3 )
			comprobar();
		// Cambiamos el jugador
		//jugador = (jugador == 1) ? 2 : 1; 
		if(jugador == 1)
		jugador = 2;
		else 
		jugador =1;
	}
	else error = 1; // Las coordenadas no son correctas, volverá a pedirlas

	// Si se ha llegado a 9 movimientos y no hay ganador, fin de la partida
	if( movj1 + movj2 == 9  && final == false ) {
		cout << "Final de partida. No hay ganador" << endl;
		final = true;
	}
}


int main()
{
	dibujar(); // Dibujamos el tablero vacío.
	while(!final){  // Mientras no acabe la partida (por ganador o movimientos) pedimos las coordenadas al jugador
		coordenadas();
	}
	//return 0;
	 system("pause");
    return 0;
}