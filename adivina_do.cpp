/*El ordenador generará un número aleatorio entre 0 y 999 
Hay un máximo de intentos de 10.
Se dirá al usuario si el número es mayor o menor que el aleatorio y */
#include <iostream>
#include <stdlib.h>
#include <time.h> //hora del sistema
#include <Windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int num;
    int intentos = 0;
    //utilizamos la función rand para crear un número aleatorio
    srand(time(NULL));
    int secreto = rand() % 1000;
    //con la función de la hora del sistema se consigue que cada vez que se ejecute el número será aleatorio
    std::cout << "Tienes 5 intentos para adivinar un número entre 0 y 999" << std::endl;
    do
    {

        std::cout << "Introduce un número entre 0 y 999" << std::endl;
        std::cin >> num;
        //En un while si la condición la primera vez es falsa no entrará ya en el bucle
        //en este caso la condición pasa a ser falsa cuando el número de intentos llega a 10

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

    } while (intentos < 10 && secreto != num);

    if (intentos < 11)
    {
        std::cout << "Lo siento, has llegado al  número máximo de intentos," << std::endl;
        std::cout << "El número era: " << secreto << std::endl;
    }

#ifdef _WIN32
    system("pause");
#elif
    system("read -r");
#endif
    return 0;
}