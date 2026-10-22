#include <iostream>

int main()
{
    int idade{15};
    double altura{1.75};
//  int peso{70.95}; Declaracao de variavel com tipo errado, pois o valor atribuido é do tipo double.
    auto nome = "Daniel";
    auto contador = 10;

    contador = 5.99;

    std::cout << "Nome: " << nome;
    std::cout << "\nIdade: " << idade;
    std::cout << "\nAltura: " << altura;
    std::cout << "\nContador apos reatribuicao: " << contador;

    return 0;
}