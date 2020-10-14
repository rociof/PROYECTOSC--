
#include <iostream>
#include <stdlib.h>

//función para calcular media entre dos números
//admitirá dos parámetros de entrada
double media(double a, double b) {
    return (a+b)/2;
}

using namespace std;


int main() {

cout <<" La media de 5 y 7 es: " << media(5,7) << endl; 



#ifdef _WIN32
    system("pause");
#elif
    system("read -r");
#endif
    return 0;


}