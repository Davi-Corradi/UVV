#include "math_utils.hpp"
#include  <iostream>

MathUtils::MathUtils() : pi(3.14159f), raio(0.0f) {}
MathUtils::MathUtils(float raio) : pi(3.14159f), raio(raio) {}

float MathUtils::getPi() const {
    return pi;
}

float MathUtils::getRaio() const{
    return raio;
}

void MathUtils::setPi(float pi) {
    this->pi = pi;
}

void MathUtils::setRaio(float raio) {
    this->raio = raio;
}

void MathUtils::exibir() const {
    std::cout << "Valor de pi: " << pi;
    std::cout << "\nValor do raio: " << raio;
    std::cout << "\nValor da área do círculo: " << pi * raio * raio;
}