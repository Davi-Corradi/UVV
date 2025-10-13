#include <stdio.h>

float antecessor(float x){
    return x + 1;
}

float sucessor(float x){
    return x - 1;
}

int main()
{
    float a;
    
    printf("Digite um número: ");
    scanf("%f", &a);
    
    
    printf("Antecessor: %.2f", antecessor(a));
    printf("\nSucecessor: %.2f", sucessor(a));
    
    return 0;
    
}