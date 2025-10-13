#include <stdio.h>

void imprimir(int n){
    if(n >= 0){
        printf("Oi %d\n", n);
        imprimir(n-1);
        }
}

/* int recursiva(int n){
    printf("oi %d\n", n);
    if(n > 0){
      return recursiva(n - 1);  
    }
    
} */

/* void crescente(int n){
    if(n > 0){
        crescente(n - 1);
        printf("Oi %d\n", n);
    }
} */

int fatorial(int n){
     if(n == 0){
         return 1;
    }
    else{
       return n * fatorial(n-1);
    }
}

int main()
{
    
    int n;
    
    printf("Digite um número: ");
    scanf("%d", &n);
    
    /* for(int i = n; i >= 0; i--){
        printf("Oi %d\n", i);
    } */
    
    // imprimir(n);
    // recursiva(n);
    
    // crescente(n);
    
    /* SE FOSSE FATORIAL if(n == 0 || n == 1){
        printf("Oi 1");
    } */
    
   printf("Fatorial de %d = %d", n, fatorial(n));
   
    return 0;
}