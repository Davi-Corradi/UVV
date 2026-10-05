#include <iostream>
#include <cmath> // Necessario para std::sqrt e std::pow

int main() {
    double x1 = 1.0, y1 = 2.0;
    double x2 = 4.0, y2 = 6.0;

    // Calculao da distancia euclidiana usando std::sqrt e std::pow
    double distancia = std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));

    // Forma alternativa otimizada usando std::hypot
    double distanciaAlternativa = std::hypot(x2 - x1, y2 - y1);

    std::cout << "Distancia calculada: " << distancia;
    std::cout << "\nDistancia calculada via funcao hypot: " << distanciaAlternativa;

    return 0;
}