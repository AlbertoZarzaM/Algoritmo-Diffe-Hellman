#include <iostream>

int exponenciacionRapida(int a, int b, int n) {
    int x = 1;
    int y = a % n;
    while (b > 0) {
        if (b % 2 == 1) {
            x = (x * y) % n;
        }
        y = (y * y) % n;
        b = b / 2;
    }
    return x % n;
}

bool isPrime(int n) {

    if (n == 1) {
        return false;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int diffieHellman(int g, int p, int a, int b,  int c) {
    int YA = exponenciacionRapida(g, a, p);
    int YB = exponenciacionRapida(g, b, p);
    int YC = exponenciacionRapida(g, c, p);
    
    

    std::cout << "El valor de Ya es: " << YA << std::endl;
    std::cout << "El valor de Yb es: " << YB << std::endl;
    std::cout << "El valor de Yc es: " << YC << std::endl;

    int s1 = exponenciacionRapida(YB, a, p);
    int s2 = exponenciacionRapida(YC, b, p);
    int s3 = exponenciacionRapida(YA, c, p);

    int Ka = exponenciacionRapida(s2, a, p);
    int Kb = exponenciacionRapida(s3, b, p);
    int Kc = exponenciacionRapida(s1, c, p);

    std::cout << "El valor de la llave compartida es: " << Ka << std::endl;
    std::cout << "El valor de la llave compartida es: " << Kb << std::endl;
    std::cout << "El valor de la llave compartida es: " << Kc << std::endl;

    if (Ka == Kb && Kb == Kc) {
        std::cout << "Las llaves son iguales" << std::endl;
    } else {
        std::cout << "Las llaves son diferentes" << std::endl;
    }
    return Ka;
}

int main() {
  std::cout << "Bienvenido al programa de Diffie-Hellman" << std::endl;

  int p, a, b, c, g;
  std::cout << "Ingrese el valor del primo p: " << std::endl;
  std::cin >> p;
  
  if (!isPrime(p)) {
      std::cout << "El valor ingresado no es primo" << std::endl;
      return 0;
  }
  

  std::cout << "Ingrese el valor del alfa: " << std::endl;
  std::cin >> g;
  std::cout << "Ingrese el valor del secreto a: " << std::endl;
  std::cin >> a;
  std::cout << "Ingrese el valor del secreto b: " << std::endl;
  std::cin >> b;
  std::cout << "Ingrese el valor del secreto c: " << std::endl;
  std::cin >> c;
  std::cout << "El valor de la llave compartida es:\n " << diffieHellman(g, p, a, b, c) << std::endl;
}