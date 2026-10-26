
#include <iostream>
#include <cmath>

long long fibonacciBinet(int n);
long long fibonacciIterativo(int m);

int main()
{
    int n = 80;

    std::cout << "--- Metodo de Binet ---\n";
    fibonacciBinet(n);

    std::cout << "\n--- Metodo Iterativo ---\n";
    fibonacciIterativo(n);

    return 0;
}

long long fibonacciBinet(int n)
{
    double phi = (1 + std::sqrt(5.0)) / 2.0;
    double psi = (1 - std::sqrt(5.0)) / 2.0;
    long long resultado{0};

    for (int i = 0; i <= n; i++)
    {
        resultado = std::round((std::pow(phi, i) - std::pow(psi, i)) / std::sqrt(5.0));

        std::cout << "Fibonacci de " << i << " = " << resultado << "\n";
    }

    return resultado;
}

long long fibonacciIterativo(int m)
{
    long long anterior = 0;
    long long atual = 1;
    long long resultado{0};

    for (int i = 0; i <= m; i++)
    {
        if (i == 0)
        {
            resultado = 0;
        }
        else if (i == 1)
        {
            resultado = 1;
        }
        else
        {
            resultado = anterior + atual;
            anterior = atual;
            atual = resultado;
        }

        std::cout << "Fibonacci de " << i << " = " << resultado << "\n";
    }

    return resultado;
}

/* Explicacao: Os erros de precisao do metodo de Binet, referentes a funcao round(), podem serem notados a partir do Fibonacci de 72, cujo
o ultimo digito signifiaivo passa a ser arrendondado para 5, sendo que no metodo iterativo ele e 4. A partir dai, os erros de precisao de
arredondamento sao cada vez maiores, demonstrando o perigo computacional dessa abordagem.

*/