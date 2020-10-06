

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cmath>

using namespace std; //se incluye la librería estándar del sistema
/*A partir de un fichero de texto que contiene números (con decimales), calcular la media,
 el número de muestras y la desviación típica (opcional).
 El programa debe leer los datos del fichero y mostrar los resultados por pantalla.*/

int main()
{
    double media, suma= 0;
    int cantidad =0; //contador de registros
    double desviacion;
    
    //la variable que va a contener los datos
    double x;
    //Para extraer uno o más datos del fichero (leerlo) y meterlo en "x" usaremos "datos >> x;"
    ifstream datos("datos.csv"); //ofstream sería fichero abierto para escritura;
    if (!datos) // consulto si se puede encontrar o leer el archivo
    {
        std::cout << "El archivo no existe" << endl;
        system("pause");
        return 0;
    }

    
    //la función eof cuando llegue al final del fichero va a cambiar su condición de falso a verdadero
    //Los que nos interesa en este caso es que siga interando MIENTRAS NO estemos en el final del fichero de datos
    cout << "Los datos que tenemos en el archivo son: " << endl;
    while (!datos.eof())
    {
        //la variable double x;, se puede declarar fuera del bucle para todo el programa
        datos >> x;
        cantidad++;
        suma = suma +x; // suma+=x; Suma de los valores
        
        cout << x <<endl;
    }
      //Para cerrar el fichero "datos.close()". Se ponen paréntesis porque es una llamada
    datos.close();
    //media
    media = suma/ cantidad;
    cout << "La media de los datos es: "  << media << endl;
    cout << "La suma de los registros es: " << suma << endl;
    // formula desviación
    desviacion = sqrt(suma / (cantidad - 1));    
    cout << "Cantidad: " << cantidad << std::endl;
    cout << "El valor de la desviación típica es: "<<desviacion <<endl;

    system("pause");



  


#ifdef _WIN32
    system("pause");
#elif
    system("read -r");
#endif
    return 0;
}