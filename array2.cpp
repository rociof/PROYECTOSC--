
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cmath>

using namespace std;

//Histograma: El programa va a recorrer todos los elementos de un archivo de datos. Este array empieza con todos los elementos a 0;
/*Si está entre 0-0.5 se le suma 1
0.5-1-- +1
1.5-2 -- +1
2-2.5 -- +1
2.5-3 -- +1
3.5-4 -- +1
4.5-5 -- +1
La idea es contar todos los números que hay entre ese intervalo
*/

int main()
{
    ifstream datos("datos.csv"); //lo utilizamos para abrir un fichero de datos
    if (!datos)                  // consulto si se puede encontrar o leer el archivo
    {
        std::cout << "El archivo no existe" << endl;
        system("pause");
        return 0;
    }
    //Lo primero que hay que hacer es inicializar el array en 0;
    double r[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int contador = 0; //contador
    double x = 0.0;
    while (!datos.eof())
    {
        //Hay que identificar el intervalo al que pertenece
        //Una vez identificado el elemento se incrementa el contador

       datos >> x;
        

        for (int i = 0; i < 10; i++)
        {
            if (x >= 0.5*i && x <= 0.5*(i + 1))
            {
                r[i]++;
                break;
            }
        }
    }
    //cerramos el archivo
    
    datos.close();

    // Al acabar el fichero leer contadores
    for (int i = 0; i < 10; i++)
    {
        cout << "El numero de elementos del intervalo  son: " << r[i] << endl;
        contador += r[i];
    }
    cout << "El número de total de registros es: " << contador << endl;

#ifdef _WIN32
    system("pause");
#elif
    system("read -r");
#endif
    return 0;
}