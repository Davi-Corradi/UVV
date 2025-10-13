
#include <stdio.h>


void imprimirVetor(int *v, int n){
    printf("Vetor: |");
    for(int i = 0; i<n; i++ ){
        printf(" %d |", v[i]);
    }
}

int busca(int lista[], int numeroBuscado){
    
    for(int i = 0; i < 7; i++){
        if(lista[i] == numeroBuscado){
            return i;
        }
    }
    
    return - 1;
    
}  


int buscaLinearOrdenada(int lista[],int n, int numeroBuscado){
    for(int i = 0; i < n; i++){
        if(lista[i] == numeroBuscado){
            return i;
        }
        else{
            if(numeroBuscado < lista[i]){
                return - 1;
            }
        }
    }
    
    return - 1;
}

int main()
{
    
    int vetor[7] = {23, 4, 67, -8, 54, 90, 21};
    int novoVetor[10] = {-8, -5, 1, 4, 14, 21, 23, 54, 67, 90};
    
    int numeroBuscado;
    
    printf("\t=== Busca ===\n");
    printf("\n");
    
    imprimirVetor(vetor, 7);
    
    printf("\nDigite o número desejado: ");
    scanf("%d", &numeroBuscado);
    
    
    int posicao2 = busca(vetor, numeroBuscado);
    
    if(posicao2 != -1){
        printf("\nO número está na posicão: %d",busca(vetor, numeroBuscado));
    }
    else{
        printf("\nO número não está no vetor! \n\n");
        printf("\n");
    } 
    
    printf("\t=== Busca Linear Ordenada ===\n");
    printf("\n");
    
    imprimirVetor(novoVetor, 10);
    
    printf("\nDigite o número desejado: ");
    scanf("%d", &numeroBuscado);
    
    int posicao = buscaLinearOrdenada(novoVetor, 10, numeroBuscado);
    
    if(posicao != -1){
        printf("\nO número está na posicão: %d\n",buscaLinearOrdenada(novoVetor, 10, numeroBuscado));
    }
    else{
        printf("\nO número não está no vetor! \n");
    } 
    return 0;
}

