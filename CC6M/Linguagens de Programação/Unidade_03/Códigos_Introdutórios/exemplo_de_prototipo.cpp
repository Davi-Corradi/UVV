#include <iostream>

// Prototipo da funcao (declaracao)

int obterMaior(int a, int b);

int main()
{
    int x = 15;
    int y = 20;

    // Chamada valida: o compilador ja conhece o prototipo de obterMaior

    int maior = obterMaior(x, y);

    std::cout << "O maior valor eh: " << maior;

    return 0;
}

// Definicao da funcao (implementacao)

int obterMaior(int a, int b)
{
    return (a > b) ? a : b;
}