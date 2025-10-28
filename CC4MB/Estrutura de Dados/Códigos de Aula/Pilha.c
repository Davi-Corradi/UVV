#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int conteudo;
    struct elemento *proximo;
} Elem;

typedef struct elemento *Pilha;

Pilha* cria_pilha(){
    Pilha *pil = malloc(sizeof(Pilha));
    if(pil != NULL){
        *pil = NULL;
    }
    return pil;
}

int push(Pilha *pilha, int valor){
    if(pilha == NULL) {return 0;}
    
    Elem* aux = malloc(sizeof(Elem));
    
    if(aux == NULL) {return 0;}
    
    aux -> conteudo = valor;
    aux -> proximo = *pilha;
    *pilha = aux;
     
     return 1;
}

void imprimir(Pilha *pilha){
    if(pilha == NULL || *pilha == NULL){
        printf("\nA pilha está vazia!");
        return;
    }
    
    printf("Pilha: ");
    Elem* no = *pilha;
    while(no != NULL){
        printf("%d -> ", no -> conteudo);
        no = no -> proximo;
    }
    printf("NULL\n");
} 

int pop(Pilha *pilha){
    if(pilha == NULL || *pilha == NULL) {return 0;}
    
    Elem* aux = *pilha;
    *pilha = aux -> proximo;
    int retorno = aux -> conteudo;
    
    free(aux);
    
    return retorno;
}

int consultar(Pilha *pilha){
    if(pilha == NULL || *pilha == NULL)
    {
        return 0;
    }
    printf("Topo: %d",(*pilha) -> conteudo);
    return (*pilha) -> conteudo;
}

void liberar(Pilha *pilha){
    if(pilha != NULL){
       Elem* no; 
       while(*pilha != NULL){
           no = *pilha;
           *pilha = (*pilha) -> proximo;
           free(no);
       }
       free(pilha);  
    }
}

int main()
{
    Pilha *pilha = cria_pilha();

    push(pilha, 10);
    push(pilha, 15);
    push(pilha, 20);
    
    imprimir(pilha);
    
    pop(pilha);
    imprimir(pilha);
    
    consultar(pilha);

    liberar(pilha);
    pilha = NULL;
    imprimir(pilha);
    
    return 0;
}
