#include <iostream>
using namespace std;
float b, h, s;

int main()
{

  cout << "Introduzca la base del triángulo:\n";
  cin >> b;
  cout << "Introduzca la altura del triángulo:\n";
  cin >> h;
  s = (b * h) / 2;
  cout << "La superficie del triángulo es: " << s << " m2" << endl;

#ifdef _WIN32
  system("pause");
#elif
  system("read -r");
#endif
}