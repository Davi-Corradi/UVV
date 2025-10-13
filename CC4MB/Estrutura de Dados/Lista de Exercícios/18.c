#include <stdio.h>

int par(int x){
    if(x % 2 == 0){
        return 1;
    }
    return 0;
}

int main()

{

	int vetor[10];
    int i, temPar = 0;
    
	for(i = 0; i < 10; i++) {
        printf("Digite o %dº valor: ", i + 1);
        scanf("%d", &vetor[i]);
	}
	
	printf("\nO vetor possui os seguintes valores: \n\n");
    
    for(i = 0; i < 10; i++){
        printf("Vetor[%d] = %d\n",i ,vetor[i]);
    }
    
    printf("\nValores pares do vetor: ");
    
    for(i = 0; i < 10; i++){
        if(par(vetor[i])){
            printf("%d ", vetor[i]);
            temPar = 1;
        }
    }
    
    if(!temPar){
        printf("\nO vetor não possui valores pares! ");
    }
    
	return 0;
}