#include <stdio.h>

/* int busca(int lista[], int numeroBuscado){
    
    for(int i = 0; i < 7; i++){
        if(lista[i] == numeroBuscado){
            return i;
        }
    }
    
    return - 1;
    
}  */

void imprimir(int *v, int n){
    printf("\t\t VETOR: \n");
    printf("| ");
    for(int i = 0; i < n; i++){
        printf("%d | ", v[i]);
    }
}

int buscaOrdenada(int lista[], int numeroBuscado){
    
    for(int i = 0; i < 7; i++){
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

int buscaBinaria(int lista[], int numeroBuscado){
    for(int i = 0; i < 7; i++){
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


int main(){

    // int vetor[7] = {23, 4, 67, -8, 54, 90, 21};
    // int vetorOrdenado[7] = {-8, 4, 21, 23, 54, 67, 90};
    int novoVetor[10] = {-8, -5, 1, 4, 14, 21, 23, 54, 67, 90};
    
/*  for(int i = 0; i < 7; i++){
        printf("%d\n",vetor[i]);
    }   */
    
    int numeroBuscado;
    
    imprimir(novoVetor, 10);
    
    printf("\nDigite o número desejado: ");
    scanf("%d", &numeroBuscado);
    
    // int posicao = busca(vetor, numeroBuscado);
    
    // int posicao = buscaOrdenada(vetorOrdenado, numeroBuscado);
    
    
    /* if(posicao != -1){
        printf("O número está na posicão: %d",buscaOrdenada(vetorOrdenado, numeroBuscado));
    }
    else{
        printf("O número não está no vetor! ");
    } */
    
    int posicao = buscaBinaria(novoVetor, numeroBuscado);
    
    if(posicao != -1){
        printf("O número está na posicão: %d",buscaBinaria(novoVetor, numeroBuscado));
    }
    else{
        printf("O número não está no vetor! ");
    } 
    return 0;
}