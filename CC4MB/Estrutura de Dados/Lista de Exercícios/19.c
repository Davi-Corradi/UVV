#include <stdio.h>

int main()

{

	int vetor1[10], vetor2[10], intersecao[10];
    int i, k = 0;
    
	for(i = 0; i < 10; i++) {
        printf("Digite o %dº valor: ", i + 1);
        scanf("%d", &vetor1[i]);
	}
	
	printf("\nO vetor 1 possui os seguintes valores: \n\n");
    
    for(i = 0; i < 10; i++){
        printf("Vetor[%d] = %d\n",i ,vetor1[i]);
    }
    
    printf("\n");
    
    for(i = 0; i < 10; i++) {
        printf("Digite o %dº valor: ", i + 1);
        scanf("%d", &vetor2[i]);
	}
	
	printf("\nO vetor 2 possui os seguintes valores: \n\n");
    
    for(i = 0; i < 10; i++){
        printf("Vetor[%d] = %d\n",i ,vetor2[i]);
    }
    
    for(i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(vetor1[i] == vetor2[j]){
              int repetido = 0; 
              for(int m = 0; m < k; m++){
                  if(intersecao[m] == vetor1[i]){
                      repetido = 1;
                      break;
                  }
              }
              
              if(!repetido){
                  intersecao[k] = vetor1[i];
                  k++;
              }
              break;
            }
        }
    }
    
    if(k > 0){
        printf("Interseçôes: ");
        for(i = 0; i < k; i++){
            printf("%d ", intersecao[i]);
        }
    }
    else{
        printf("\nOs vetores não possuem interseções! ");
    }
    
	return 0;
}

