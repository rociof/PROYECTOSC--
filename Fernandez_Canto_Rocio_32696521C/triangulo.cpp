#include <iostream>
float b, h, s;

int main()
{

  std::cout << "Introduzca la base del triángulo:\n";
  std::cin >> b;
  std::cout << "Introduzca la altura del triángulo:\n";
  std::cin >> h;
  s = (b * h) / 2;
  std::cout << "La superficie del triángulo es: " << s << " m2";

#ifdef _WIN32
  system("pause");
#elif
  system("read -r");
#endif
}