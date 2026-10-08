#include <iostream>
#include <cmath>

const double PI = 3.141592653589793;
const int DISTANCIA = 50;
const double ANGULO = 30.00;

double grausParaRadianos(double graus)
{
    return graus * (PI / 180);
}

int main()
{
    double anguloRadianos = grausParaRadianos(ANGULO);
    double altura = DISTANCIA * std::tan(anguloRadianos);

    std::cout << "A altura eh de: " << altura << " metros\n";
    return 0;
}