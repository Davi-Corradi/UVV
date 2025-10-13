#include <stdio.h>

float maior(float x, float y){
    if(x > y){
        printf("O número %.2f é maior que %.2f", x,y);
    }
    return x;
}

float menor(float x, float y){
    if(x < y){
        printf("O número %.2f é menor que %.2f", x,y);
    }
    return y;
}

int main(){
    float a, b;
    printf("Digite os valores: ");
    scanf("%f %f", &a, &b);
    
    maior(a, b);
    menor(a, b);
    
    return 0;
}