
#include <stdio.h>

int main()
{
    int vetor[6];
    // int *p = vetor
    
    for(int a = 0; a < 6; a++){
        printf("Digite o %dº  número inteiro: ",a+ 1);
        scanf("%d", &vetor[a]); // ou scanf("%d", p + a);
    }
    
    printf("\nValores do Vetor: \n\n");
    
    for(int i = 0; i < 6; i++){
        printf("Vetor[%d] = %d\n",i ,vetor[i]); // printf("Vetor[%d] = %d\n",i ,*(p + i));
    }
    
    
    return 0;
}