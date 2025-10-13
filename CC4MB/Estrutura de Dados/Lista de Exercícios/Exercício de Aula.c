#include <stdio.h>

void imprime(int *m, int n){
    int i;
    for (i=0; i<n; i++){
        printf("%d \n", m[i]);
    }
}

void mult(int vet[],int num, int n){
    int i;
    for(i=0; i<n; i++){
        vet[i] = vet[i] * num;
    }
    
}

int main(){
    
    int x;
    
    int vet[5] = {1,2,3,4,5};
    printf("\tVETOR: \n");
    imprime(vet,5);
    
    printf("\nDigite um número: ");
    scanf("%d", &x);
    
    mult(vet, x, 5);
    printf("\nResultado do vetor multiplicado: \n");
    imprime(vet, 5);
    return 0;
}