
// Visualizar los números del 1 al 10

#include <iostream>
#include <Windows.h>

int main()

{
    std::cout << "Los primeros diez números son " << std::endl;

    for (int k = 0; k < 10; k++)
    {
        std::cout << k << std::endl;
    }
#ifdef _WIN32
    system("pause");
#elif
    system("read -r");
#endif
    return 0;
}
