#include <stdio.h>

float maior(float x, float y){
    if(x > y){
        printf("O número %.2f é maior que %.2f", x,y);
        return x;
    }
    
    else{
        printf("O número %.2f é maior que %.2f", y,x);
        return y;
    }
}

float menor(float x, float y){
    if(x < y){
        printf("\nO número %.2f é menor que %.2f", x,y);
        return x;
    }
     else{
        printf("O número %.2f é menor que %.2f", y,x);
        return y;
     }
}

float diferenca(float maior, float menor){
    return maior - menor;
}


int main(){
    float a, b, valMaior, valMenor;
    printf("Digite os valores: ");
    scanf("%f %f", &a, &b);
    
    valMaior = maior(a, b);
    valMenor = menor(a, b);
    
    
    printf("\nA diferença entre os valores é de: %.2f", diferenca(valMaior, valMenor));
    return 0;
}
