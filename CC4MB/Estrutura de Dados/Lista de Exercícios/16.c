#include <stdio.h>

int main()
{
    int vetor[6] = {1, 0 , 5, -2, -5, 7};
    
    for(int i = 0; i < 6; i++){
        printf("Vetor[%d] = %d\n",i ,vetor[i]);
    }
    
    vetor[4] = 100;
    
    printf("\n");
    
    printf("Vetor Atualizado: \n\n");
    
    for(int i = 0; i < 6; i++){
        printf("Vetor[%d] = %d\n",i ,vetor[i]);
    }
    return 0;
}