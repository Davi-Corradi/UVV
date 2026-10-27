#include <iostream>
#include <cmath>
#include <iomanip>
#include <chrono>

long long fibonacciBinet(int n);
long long fibonacciIterativo(int m);

int main()
{
    int n = 80;
    int testes[] = {10, 20, 40, 60, 70};

    std::cout << "\n"
              << std::right << std::setw(50) << "TABELA COMPARATIVA DE VALORES\n\n";

    std::cout << std::left
              << std::setw(5) << "\nn"
              << std::setw(22) << "Iterativo"
              << std::setw(22) << "Binet"
              << std::setw(15) << "Diferenca Absoluta\n";
    std::cout << "------------------------------------------------------------------\n";

    for (int i = 0; i <= n; i++)
    {
        long long iterativo = fibonacciIterativo(i);
        long long binet = fibonacciBinet(i);
        long long diferenca = std::abs(iterativo - binet);

        std::cout << std::left
                  << std::setw(5) << i
                  << std::setw(22) << iterativo
                  << std::setw(22) << binet
                  << std::setw(15) << diferenca << "\n";
    }
    std::cout << "------------------------------------------------------------------\n";

    std::cout << "\n\n"
              << std::right << std::setw(65) << "TABELA COMPARATIVA DE VALORES E EXECUCAO\n\n";

    std::cout << std::left
              << std::setw(5) << "\nn"
              << std::setw(22) << "Iterativo"
              << std::setw(22) << "Binet"
              << std::setw(32) << "Tempo de execucao (Iterativo)"
              << std::setw(30) << "Tempo de execucao (Binet)\n";
    std::cout << "---------------------------------------------------------------------------------------------------\n";

    for (int t : testes)
    {
        auto inicio_iterativo = std::chrono::high_resolution_clock::now();
        long long resultado_iterativo = fibonacciIterativo(t);
        auto fim_iterativo = std::chrono::high_resolution_clock::now();

        auto duracao_iterativa = std::chrono::duration_cast<std::chrono::nanoseconds>(fim_iterativo - inicio_iterativo).count();
        auto inicio_binet = std::chrono::high_resolution_clock::now();
        long long resultado_binet = fibonacciBinet(t);

        auto fim_binet = std::chrono::high_resolution_clock::now();
        auto duracao_binet = std::chrono::duration_cast<std::chrono::nanoseconds>(fim_binet - inicio_binet).count();

        std::cout << std::left
                  << std::setw(5) << t
                  << std::setw(22) << resultado_iterativo
                  << std::setw(30) << resultado_binet
                  << std::setw(32) << duracao_iterativa
                  << std::setw(30) << duracao_binet << "\n";
    }
    std::cout << "-------------------------------------------------------------------------------------------------------\n";

    return 0;
}

long long fibonacciBinet(int n)
{
    double phi = (1 + std::sqrt(5.0)) / 2.0;
    double psi = (1 - std::sqrt(5.0)) / 2.0;

    return std::round((std::pow(phi, n) - std::pow(psi, n)) / std::sqrt(5));
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
    }

    return resultado;
}

/* 4.2

Explicacao: Os erros de precisao do metodo de Binet, referentes a funcao round(), podem ser notados a partir do Fibonacci de 72, cujo
o ultimo digito significativo passa a ser arrendondado para 5, sendo que no metodo iterativo ele e 4. A partir dai, os erros de precisao de
arredondamento sao cada vez maiores, provenientes da precisao numerica limitada da mantissa de 53 bits, que sao os bits reservados para os
digitos significativos de um numero. O valor 2^53, abrange um pouco mais de 9 quatrilhoes de valores, e como o valor √5 é irracional, gerando
uma dizima infinita, consequentemente, os valores destinados a mantissa passam a ser insuficientes para representar o maximo de precisao numerica
dos valores conforme n cresce, sendo que por causa da extrapolacao da mantissa, os valores ja chegam incorretos na funcao round, causando erros
de arredondamentos cada vez maiores.


4.3

Calculo interno de ϕ^n: O computador utiliza a FPU (Unidade de Ponto Flutuante) que converte a base e o expoente utilizando
logaritmos naturais e a constante de Euler (e), baseando-se na identidade matematica: x^n = e^{n ln(x)}. Para processar a
constande de Euler e o ln, o hardware utiliza aproximacoes numericas via polinomios (geralmente series de Taylor ou
Algoritmos CORDIC). Portanto, o calculo exige diversos ciclos de clock, que variam de acordo com o tamanho do numero e a
arquitetura do chip.

Custo real: O custo teorico tende a ser O(1), ou seja, constante, pois matematicamente uma variavel exponencial, como x^n, 
e calculada diretamente. No entanto, computacionalmente, o computador nao processa polinomios e equacoes diretamente ele 
depende de processamentos pesados em nivel de hardware (geralmente calculados por serie de Taylor ou aproximacoes de 
logaritmos naturais), sendo assim, na pratica essa matematica exige diversos ciclos de clock para o processamento e nao 
apenas um. Sendo assim, o custo real depende mais do harware do que da arquitetura e da precisao.

4.4

Recorrencia Linear: Uma relaca\o de recorrencia e classificada como linear quando todos os termos dependentes estao na
primeira potencia.O conceito de homogeneidade significa que todos os termos da equacao dependem exclusivamente de elementos
anteriores da sequencia, portanto, ela e homogenea porque nao possui nenhum termo avulso ou constante adicionada ao final da
equacao. A estrutura F_n - F_{n-1} - F{n-2} = 0, mostra que ela e linear e homogenea.

Equacao derivada: A formula geral de Fibonacci e F(n) = F(n-1) + F(n - 2), assumindo que a sequencia cresce como uma PG, temos
Fn = r^n, e substituindo isso na formula temos, r^n = r^(n-1) + r^(n - 2). Dividindo ambos os lados por r^(n - 2), temos,
(r^n / r^(n-2)) = (r^(n-1) / r^(n-2)) + (r^(n-2) / r^(n-2)), ou seja, r² = r¹ + 1, que pode ser reescrito como r² - r - 1 = 0,
portanto, a primeira derivacao esta completa.

Raizes ϕ e ψ e diagonalizacao: Como foi assumido anteriormente que a sequencia e a recorrencia se comportam como um PG,
ou seja, um progressao geometrica do tipo F^n = r^n, chegamos na deducao da formula r² - r - 1 = 0, que e justamente uma
equacao do 2º grau. Por isso, o surgimento das raizes advem do processo de utilizar a formula de Bhaskara, chegando 
exatamente em ((1 + √5) / 2) e ((1 - √5) / 2).

*/
