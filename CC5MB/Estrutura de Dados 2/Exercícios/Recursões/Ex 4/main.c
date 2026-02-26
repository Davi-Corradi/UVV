#include <stdio.h>

int eh_primo_aux(int n, int divisor){
    if (divisor * divisor > n){
        return 1;
    }
    
    if (n % divisor == 0){
        return 0;
    }
    
    else{
        return eh_primo_aux(n, divisor + 1);
    }
}

int eh_primo(int n){
    if (n <= 1){
        return 0;
    }
    
    return eh_primo_aux(n, 2);
}

int main()
{
    int numero = 2;
    
    if (eh_primo(numero)){
        printf("O número %d é primo! ", numero);
    }
    else{
        printf("O número %d não é primo! ", numero);
    }
    
    return 0;
}