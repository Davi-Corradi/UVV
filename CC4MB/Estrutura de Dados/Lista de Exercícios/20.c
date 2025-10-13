#include <stdio.h>

int main() {
    int n;

    printf("Digite o numero de linhas do Triangulo de Pascal: ");
    scanf("%d", &n);

    // matriz para armazenar os valores
    int pascal[n][n];

    // construir o triângulo
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            // bordas do triângulo sempre têm valor 1
            if (j == 0 || j == i) {
                pascal[i][j] = 1;
            } else {
                // valor é a soma dos dois acima
                pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }

            printf("%d ", pascal[i][j]);
        }
        printf("\n");
    }

    return 0;
}