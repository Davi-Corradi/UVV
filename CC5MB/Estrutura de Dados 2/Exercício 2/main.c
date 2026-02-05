#include <stdio.h>
#include <math.h>

struct Ponto {
    int x;
    int y;
};

struct Circunferencia {
    struct Ponto centro;
    float raio;
};

void verificarPonto(struct Ponto p, struct Circunferencia c, char* nome) {
    double dist = sqrt(pow((p.x - c.centro.x), 2) + pow((p.y - c.centro.y), 2));
    
    printf("%s: ", nome);
    if (dist < c.raio) {
        printf("Está dentro!\n");
    } else if (dist == c.raio) {
        printf("Está sobreposto (na borda)!\n");
    } else {
        printf("Está fora!\n");
    }
}

int main() {
    struct Ponto p1 = {2, 3};
    struct Ponto p2 = {4, 5};
    
    struct Circunferencia circ;
    circ.centro.x = 1;
    circ.centro.y = 2;
    circ.raio = 5;

    verificarPonto(p1, circ, "Ponto 1");
    verificarPonto(p2, circ, "Ponto 2");

    return 0;
}