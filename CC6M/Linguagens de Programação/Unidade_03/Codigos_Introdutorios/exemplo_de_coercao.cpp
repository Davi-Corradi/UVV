#include <iostream>
#include <cmath>

int main()
{
    int x = 5;

    // O argumento 'x' (int) sofre coercao para 'double' (4.0) antes da chamada
    double raiz = std::sqrt(x);

    std::cout << "Raiz: " << raiz; // Exibe 2.23607 e não somente 2

    return 0;
}