#include <stdio.h>

float lerNum(float x){
    return x/5;
}

int main()
{
    float a;
    
    printf("Digite um número: ");
    scanf("%f", &a);
    
    
    printf("Resultado: %.2f", lerNum(a));
    
    return 0;
}


