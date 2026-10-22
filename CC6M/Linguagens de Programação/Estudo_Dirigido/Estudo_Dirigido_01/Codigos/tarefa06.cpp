#include <iostream>

int main(){

    int numero1{0}, numero2{0}, divisao_inteira{0}, resto_divisao{0}; 
    double acumulador{0};

    std::cout << "Digite o primeiro numero: ";
    std::cin >> numero1;

    while (numero2 == 0) { 
        std::cout << "Digite o segundo numero (sem ser 0): ";
        std::cin >> numero2;
    }

    divisao_inteira = numero1 / numero2;
    resto_divisao = numero1 % numero2;

    double divisao_real = static_cast<double>(numero1) / numero2;

    std::cout << "Divisao inteira: " << divisao_inteira;
    std::cout << "\nResto da divisao: " << resto_divisao;
    std::cout << "\nDivisao real: " << divisao_real << "\n";

    for (int i = 1; i <= 4; i++) {
        acumulador += numero1;
        acumulador -= numero2;
        acumulador *= numero1;
        acumulador /= numero2;

        std::cout << "Iteracao " << i << " - Acumulador: " << acumulador << "\n";
    }

    return 0;
}