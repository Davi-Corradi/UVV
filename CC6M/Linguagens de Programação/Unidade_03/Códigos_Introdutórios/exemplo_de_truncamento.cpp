#include <iostream>

// Prototipo
void exibirInteiro(int numero);

int main() {
    double pi = 3.14159;
    
    // Coercao com estreitamento (narrowing): pi eh truncado para 3
    exibirInteiro(pi);

    return 0;
}

void exibirInteiro(int numero) {
    std::cout << "Valor truncado: " << numero << std::endl; // Exibe 3
}