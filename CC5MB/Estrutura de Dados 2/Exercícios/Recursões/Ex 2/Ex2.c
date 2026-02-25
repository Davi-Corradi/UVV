#include <stdio.h>

int max_aux(int v[], int n, int maior_atual){
    if(n == 0){
        return maior_atual;
    }
    
    if(v[n - 1] > maior_atual){
        return max_aux(v, n - 1, v[n - 1]);
    }
    
    else{
        return max_aux(v, n - 1, maior_atual);
    }
}

int max(int v[], int n){
    return max_aux(v, n, v[0]);
}

int main()
{
    int vetor[5] = {1, 3, 2, 7, 0}; 
    printf("%d", max(vetor, 5));

    return 0;
}