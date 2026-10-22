#include <iostream>
#include <limits>
#include <string>

int main()
{
    int idade;
    std::string nome_completo;
    
    std::cout<<"Digite sua idade: ";
    std::cin >> idade;
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    
    
    std::cout<< "Digite seu nome completo: ";
    std::getline(std::cin, nome_completo);
    
    std::cout<<"Idade: " << idade;
    std::cout<<"\nNome completo: " << nome_completo;

    return 0;
}