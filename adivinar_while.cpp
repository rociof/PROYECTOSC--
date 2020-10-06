/*El ordenador generará un número aleatorio entre 0 y 10 
Hay un máximo de intentos de 10.
Se dirá al usuario si el número es mayor o menor que el aleatorio y */
#include <iostream>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num;
    int intentos = 0;
    //utilizamos la función rand para crear un número aleatorio
    srand(time(NULL));
    int secreto = rand() % 10;
    //con la función de la hora del sistema se consigue que cada vez que se ejecute el número será aleatorio
    std::cout << "Adivina el número secreto (entre 1 y 10). Tienes 5 intentos" << std::endl;

    //En un while si la condición la primera vez es falsa no entrará ya en el bucle while
    //en este caso la condición pasa a ser falsa cuando el número de intentos llega a 10

    while (intentos < 5 && num != secreto)
    {
        std::cout << "Introduce un número:" << std::endl;
        std::cin >> num;
        intentos++;
        if (num == secreto)
        {
            std::cout << "¡Enhorabuena, has acertado!" << std::endl;
        }
        else if (num > secreto)
        {
            std::cout << "El número es mayor:" << std::endl;
        }

        else if (num < secreto)
        {
            std::cout << "El número es menor:" << std::endl;
        }
    }

    std::cout << "El número era: " << secreto << std::endl;

    if (intentos < 6 && num != secreto)
    {
        std::cout << "Lo siento, has llegado al  número máximo de intentos" << std::endl;
        std::cout << "El número era: " << secreto << std::endl;
    }
#ifdef _WIN32
    system("pause");
#elif
    system("read -r");
#endif
    return 0;
}
