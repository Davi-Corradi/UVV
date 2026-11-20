#include "ContaBanco.hpp"
#include <iostream>
#include <limits>

int main()
{

    std::string nomeLido;
    double quantiaLida{0.0};

    std::cout << "\n ==== SISTEMA DE CONTA BANCARIA ==== \n\n";

    ContaBanco conta;
    ContaBanco conta2("Davi Corradi", 1000.75);

    std::cout << "Digite o nome do titular: ";
    std::getline(std::cin, nomeLido);

    std::cout << "\nDigite a quantia a ser depositada: " << "\n";

    while (!(std::cin >> quantiaLida))
    {
        std::cout << "Entrada invalida. Digite apenas valores numericos: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Estudar essas funcoes
    }

    conta.setTitular(nomeLido);
    conta.depositar(quantiaLida);

    std::cout << "\n==== DADOS DO CLIENTE 1 ==== \n";
    std::cout << "\n";
    conta.exibirDados();

    std::cout << "\n==== DADOS DO CLIENTE 2 ==== \n";
    std::cout << "\n";
    conta2.exibirDados();

    return 0;
}