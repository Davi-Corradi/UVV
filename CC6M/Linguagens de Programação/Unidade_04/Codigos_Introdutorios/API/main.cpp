#include <iostream>
#include "soma_api.h"

int main() {
    int x = 10;
    int y = 20;

    int resultado = soma(x, y);

    std::cout << "O resultado da soma via API eh: "
              << resultado << std::endl;

    return 0;
}