#include <stdio.h>

typedef struct Aluno{
    char nome[50];
    int matricula;
}Aluno;

Aluno a;

typedef struct Indice {
    int matricula; 
    long byte_offset; 
} Indice;

int main()
{
    FILE *arquivo_dados = fopen("alunos.bin", "wb+");
    FILE *arquivo_indices = fopen("indices.bin", "wb+");

    if (arquivo_dados == NULL || arquivo_indices == NULL){
        printf("Erro ao criar o arquivo!");
        return 1;
    }
    
     for(int i = 1; i <= 3; i++){
        printf("Digite o nome do aluno: \n");
        scanf("%s", a.nome);
        printf("Digite a matrícula do aluno: \n");
        scanf("%d", &a.matricula);
        
        long posicao_atual = ftell(arquivo_dados);
        
        fwrite(&a, sizeof(Aluno), 1, arquivo_dados);
        
        Indice idx;
        idx.matricula = a.matricula;
        idx.byte_offset = posicao_atual;
        
        fwrite(&idx, sizeof(Indice), 1, arquivo_indices);

    }
    
    fclose(arquivo_dados);
    fclose(arquivo_indices);
    
    
    int busca_matricula;
    printf("\nDigite o número de matrícula para busca: ");
    scanf("%d", &busca_matricula);
    
    FILE *f_idx = fopen("indices.bin", "rb");
    FILE *f_dat = fopen("alunos.bin", "rb");
    
    Indice temp_idx;
    int achou = 0;
    
    
    while(fread(&temp_idx, sizeof(Indice), 1, f_idx)) {
        if(temp_idx.matricula == busca_matricula) {
            fseek(f_dat, temp_idx.byte_offset, SEEK_SET);
            
            Aluno aluno_encontrado;
            fread(&aluno_encontrado, sizeof(Aluno), 1, f_dat);
            
            printf("Aluno encontrado: %s\n", aluno_encontrado.nome);
            achou = 1;
            break;
        }
    }
    
    if(!achou) printf("Aluno não cadastrado.\n");
    
    fclose(f_idx);
    fclose(f_dat);
    
    return 0;
}