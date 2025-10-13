#include <stdio.h>

void imprimirVetor(int *v, int n){
    printf("Vetor: |");
    for(int i = 0; i<n; i++ ){
        printf(" %d |", v[i]);
    }
}

int buscaBinariaIterativa(int *v, int n, int elem){
    int inicio, meio, final;
    inicio = 0;
    final= n-1;
    while(inicio <= final){
        meio = (inicio + final)/2;
        if(v[meio] == elem){
            return meio;
        }else{
            if(v[meio] < elem){
                inicio = meio+1;
            }else{
                final = meio-1;
            }
        }
    }
    return -1;
}

int buscaBinariaRecursiva(int *v, int inicio, int final, int x){
    if(inicio<=final){
        int meio = (inicio + final)/2;
        if(v[meio] == x){
            return meio;
        }
        else{
            if(v[meio] > x){
                return buscaBinariaRecursiva(v, inicio, meio-1,x);
            }else{
                return buscaBinariaRecursiva(v, meio+1, final, x);
            }
        }
    }
    return -1;
}

int main(){

    int vetor[7] = {23, 4, 67, -8, 54, 90, 21};
    int novoVetor[10] = {-8, -5, 1, 4, 14, 21, 23, 54, 67, 90};
    
    int numeroBuscado;
    
    printf("=== Busca Binária Iterativa ===");
    printf("\nDigite o número desejado: ");
    scanf("%d", &numeroBuscado); 
    
    imprimirVetor(novoVetor, 10);
    
    int posicao = buscaBinariaIterativa(novoVetor, 10, numeroBuscado);
    
    if(posicao != -1){
        printf("\nO número está na posicão: %d",buscaBinariaIterativa(novoVetor, 10, numeroBuscado));
    }
    else{
        printf("\nO número não está no vetor! ");
    } 
    

    printf("\n\n=== Busca Binária Recursiva ===");
    printf("\nDigite o número desejado: ");
    scanf("%d", &numeroBuscado);
    
    imprimirVetor(novoVetor, 10);
    
    int posicao2 = buscaBinariaRecursiva(novoVetor, 0, 9, numeroBuscado);
    
    if(posicao2 != -1){
        printf("\nO número está na posicão: %d",buscaBinariaRecursiva(novoVetor, 0, 9, numeroBuscado));
    }
    else{
        printf("\nO número não está no vetor! ");
    } 
    
    return 0;
}

