#include <stdio.h>

int par(int x){
    if(x % 2 == 0){
        printf("O número %d é par! ", x);
    }
    else{
        printf("O número %d não é par! ", x);
    }
}

int main()
{
    int a;
    
    printf("Digite um número: ");
    scanf("%d", &a);
    
    par(a);
    return 0;
}
