
/*El ordenador generará un número aleatorio entre 0 y 10 
Hay un máximo de intentos de 10.
Se dirá al usuario si el número es mayor o menor que el aleatorio y */

#include <iostream>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int secreto = rand() % 10;
    int num;
    int intentos = 0;

    std::cout << "Adivina un número entre 0 y 10 " << std::endl;
    //for (inicial; condición; actualizar)
    for (int i = 0; i < 10; i++)
    {
        std::cout << "Introduce un número entre 0 y 10: " << std::endl;
        std::cin >> num;
        if (num == secreto)
        {
            std::cout << "Acertaste" << std::endl;
            break;
        }

        if (num > secreto)
        {
            std::cout << "El número es mayor" << std::endl;
        }
        else
        {
            std::cout << "El número es menor" << std::endl;
        }
    }
    if (intentos < 11 && num != secreto)

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
