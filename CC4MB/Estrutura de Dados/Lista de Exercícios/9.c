#include <stdio.h>

void menu() {
    printf("Soma - 1");
    printf("\nSubtração - 2");
    printf("\nMultiplicação - 3");
    printf("\nDivisão - 4");
}

void somar(float x, float y) {
    printf("Resultado: %.2f\n", x + y);
}

void subtrair(float x, float y) {
    printf("Resultado: %.2f\n", x - y);
}

void mult(float x, float y) {
    printf("Resultado: %.2f\n", x * y);
}

void dividir(float x, float y) {
    if (y == 0) {
        printf("Erro: divisão por zero!\n");
    } else {
        printf("Resultado: %.2f\n", x / y);
    }
}

int main() {
    int op;
    float a, b;

    while (1) {
        menu();
        printf("\nSelecione a operação desejada: ");
        scanf("%d", &op);

        if (op < 1 || op > 4) {
            printf("Opção inválida! Tente novamente.\n\n");
            continue; 
        }

        printf("Digite os números: ");
        scanf("%f %f", &a, &b);

        if (op == 1) {
            somar(a, b);
        } 
        
        else if (op == 2) {
            subtrair(a, b);
        } 
        
        else if (op == 3) {
            mult(a, b);
        } 
        
        else if (op == 4) {
            dividir(a, b);
        }

        break;
    }

    return 0;
}