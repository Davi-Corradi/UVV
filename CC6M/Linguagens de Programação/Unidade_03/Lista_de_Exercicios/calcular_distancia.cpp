#include <iostream>
#include <cmath>

int main()
{
    double x1, y1, x2, y2;

    std::cout << "Digite o primeiro par ordenado (x1, y1) (Nao use virgula): ";
    std::cin >> x1 >> y1;
    
    std::cout << "Digite o segundo par ordenado (x2, y2) (Nao use virgula): ";
    std::cin >> x2 >> y2;

    double distancia = std::hypot(x2 - x1, y2 - y1);

    std::cout << "\nA distancia euclidiana entre os dois pontos eh de: " << distancia << " metros";
    std::cout << "\nValor arredondado para cima: " << std::ceil(distancia); 
    std::cout << "\nValor arredondado para baixo: " << std::floor(distancia); 

    return 0;
}