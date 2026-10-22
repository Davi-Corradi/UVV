#include <iostream>

int main()
{
    int cout = 10;
    
    std::cout<<"O valor da variavel eh: " << cout;

    // 'cout' e 'cin' não fazem parte da sintaxe central, são somente objetos comuns definidos dentro do namespace.
    // Por isso é possível reutilizar esses objetos no escopo local.
    
    return 0;
}