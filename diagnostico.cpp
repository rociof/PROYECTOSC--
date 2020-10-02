
#include <iostream>

float temperatura;
char tos, aire, contacto;
int contador = 0;
/*Si el paciente presenta más o dos síntomas 
habrá que preguntar si tuvo contacto con infectados
Si hubo contacto habrá que mostrar mensaje de posible contagio.
Si no hubo contacto se mostrará un mensaje para que vigile los síntomas.
Si no presenta ningún síntoma se mostrará el mensaje de que no hay riesgo*/
int main()
{

    std::cout << "Introduzca la temperatura corporal en ºC:" << std::endl;
    std::cin >> temperatura;
    if (temperatura > 37)
    {
        contador++;
    }

    //std::cout << "¿Tiene tos seca (s/n)?\n"; Es recomendable usar en endl en lugar de salto de línea
    std::cout << "¿Tiene tos seca (s/n)?" << std::endl;
    std::cin >> tos;
    if (tos == 's' || tos == 'S')
    {
        contador++;
    }

    std::cout << "Presenta sensación de falta de aire (s/n) " << std::endl;
    std::cin >> aire;
    if (aire == 's' || aire == 'S')
    {
        contador++;
    }
    if (contador < 2)
    {
        std::cout << "Está usted bien" << std::endl;
    }

    if (contador >= 2)
    {
        std::cout << "¿Ha tenido usted contacto con algún posible contagiado (s/n) ? " << std::endl;
        std::cin >> contacto;
        if (contacto == 's' || contacto == 'S')
        {
            std::cout << "Puede estar usted contagiado" << std::endl;
        }
        else if (contacto == 'n' || contacto == 'N')
        {
            std::cout << "Vigile los síntomas " << std::endl;
        }
    }

#ifdef _WIN32
    system("pause");
#elif
    system("read -r");
#endif
}
