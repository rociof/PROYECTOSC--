/*Programa para mostrar los primeros 20 números de la secuencia de Fibonacci */
#include <iostream>
int main()
{
    int a = 0;
    int b = 1;
    int suma = 1;

    std::cout << "Los veinte primeros números de la secuencia de Fibonacci son: " << std::endl;
    //0 , 1 , 1 , 2 , 3 , 5 , 8 , 13 , 21 , 34 , 55 , 89 , 144 , 233 ...
    //fórmula --> suma = a + b
    //for (inicial; condición; actualizar)
    
    for (int i = 0; i < 20; i++)
    {
        std::cout << a << " ";
        suma = a + b;
        a = b; //hay que ir desplazando un lugar los valores
        b = suma;
    }

#ifdef _WIN32
    system("pause");
#elif
    system("read -r");
#endif
    return 0;
}