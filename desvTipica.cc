/*
A partir de un fichero de texto que contiene números (con decimales), calcular la media, el número de muestras y la desviación típica (opcional). El programa debe leer los datos del fichero y mostrar los resultados por pantalla.
*/

#include <iostream>
#include <cmath>   // sqrt
#include <iomanip> // std::setprecision
#include <windows.h>
#include <fstream>

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    // Proceso de lectura de archivo

    double cadena, media, total;
    int cant = 0;

    // std::ifstream fe("numero.txt");
     std::ifstream fe("datos.csv");

    if (!fe) // consulto si se puede encontrar o leer el archivo
    {
        std::cout << "No se puede abrir el fichero\n\n";
        system("pause");
        return 0;
    }

    std::cout << "Imprimo los valores del Archivo\n";
    
    while (!fe.eof())
    {
        fe >> cadena;
        cant++;
        printf("valores [%d] ==>  %.8f\n",cant, cadena);       
        total += (cadena);
        
    }
    printf("Total ==>  %.8f\n", total);
    std::cout<<"====================================\n";


    fe.close();

    // *********   

    // formula desviación
    float desviacion = sqrt(total / (cant - 1));    
    std::cout << "Cantidad: " << cant << std::endl;

    // std::cout << std::setprecision(5);
    //  std::cout << "la Desviacion : " << desviacion << std::endl;
    std::printf("Desviación STD : %.4f\n", desviacion);

    system("pause");

    return 0;
}