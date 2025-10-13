#include <stdio.h>

int main()
{

    int par; 
    
    do{ 
    printf("Digite um número inteiro par: ");
    scanf("%d" , &par);
    
    if(par % 2 != 0){
        printf("O número nãó é par! Tente Novamente.\n");
        }
    } while(par % 2 != 0);
    
    
    while(par >= 0){
        printf("%d ", par);
        par-= 2;
    }
    
    return 0;
}
