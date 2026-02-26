#include <stdio.h>

int busca_aux(int v[], int n, int a){
    if(n == 0){
        return -1;
    }
    
    if(v[n - 1] == a){
        return n - 1;
    }
    
    else{
        return busca_aux(v, n - 1, a);
    }
}

int busca(int v[], int n, int a){
    return busca_aux(v, n, a);
}

void imprimir(int v[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main()
{
    int vetor[5] = {1, 3, 2, 7, 0}; 
    int posicao = busca(vetor, 5, 3);
    
    printf("Vetor: ");
    imprimir(vetor, 5);
    
    if(posicao != -1){
        printf("\nO número foi encontrado na posição %d do vetor! ", posicao);
        
    }
    else{
        printf("\nO número não foi encontrado no vetor! ");
    }

    return 0;
}