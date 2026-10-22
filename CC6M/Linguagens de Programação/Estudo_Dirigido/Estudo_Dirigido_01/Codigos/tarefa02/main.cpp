#include <iostream>
#include "math_utils.hpp"

int main(void) {

    float raioLido;
    std::cout << "Digite o valor do raio: ";
    std::cin >> raioLido;
    
    MathUtils mathutils(raioLido);
    mathutils.exibir();

    return 0;
}