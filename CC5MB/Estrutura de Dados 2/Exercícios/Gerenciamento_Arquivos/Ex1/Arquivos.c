#include <stdio.h>

typedef struct Aluno{
    char nome[20];
    float nota;
}Aluno;

Aluno a;


int main()
{
    
    FILE *arquivo = fopen("exemplo.txt", "w");
    
    if (arquivo == NULL){
        printf("Erro ao criar o arquivo!");
        return 1;
    }
    printf("Lendo Dados\n\n");
    
    for(int i = 1; i <= 3; i++){
        printf("Digite o nome do aluno: ");
        scanf("%s", a.nome);
        printf("Digite a nota do aluno: ");
        scanf("%f", &a.nota);
        fprintf(arquivo, "%s|", a.nome);
        fprintf(arquivo, "%.2f|", a.nota);
        
    }
    
    fclose(arquivo);
    
    arquivo = fopen("exemplo.txt", "r");
    
    printf("\nDados exibidos no arquivo: \n\n");
    
    for(int j = 1; j <= 3; j++){
        fscanf(arquivo, "%[^|]", a.nome); 
        fgetc(arquivo);
        
        fscanf(arquivo, "%f", &a.nota);
        fgetc(arquivo);
        
        printf("Nome: %s\n" , a.nome);
        printf("Nota: %.2f\n", a.nota);
        printf("----------------\n");
    }
    
    fclose(arquivo);
    
    return 0;
}
