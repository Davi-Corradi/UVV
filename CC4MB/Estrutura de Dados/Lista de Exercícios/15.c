#include <stdio.h>

int main()
{

    int maior = 0;
    int menor;
    int num;
    
    do{
        printf("Digite um número. (negativo para parar): ");
        scanf("%d", &num);
        if(num >= 0){
            if(num > maior){
                maior = num;
        
            }
        } else{
            menor = num;
        }
    
    } while(num >= 0);
    
    printf("Maior número: %d", maior);
    printf("\nMenor número: %d", menor);
    
    
    return 0;
}