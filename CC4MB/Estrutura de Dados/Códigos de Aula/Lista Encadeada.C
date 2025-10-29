#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int conteudo;
    struct celula *seguinte;
}cel;

typedef struct celula *Lista;

Lista* cria_lista(){
    Lista *li = (Lista*) malloc (sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

int inserir(Lista *lista, int valor){
    if (lista == NULL){
        return 0;
    }
    
    cel* aux = (cel*) malloc(sizeof(cel));
    if(aux == NULL){return 0;}
     
    aux -> conteudo = valor;
    aux -> seguinte = NULL; 
    
    if((*lista) == NULL){ // Está inserindo o primeiro elemento na lista
        *lista = aux;
    }
    else{
        cel* temp = *lista;
        while(temp -> seguinte != NULL){
            temp = temp->seguinte;
        }
        
        temp -> seguinte = aux;
    }
    return 1;
}

void imprimir(Lista *lista){
    if(*lista == NULL){
        printf("A lista está vazia!");
        return;
    }
    else{
        cel* temp = *lista;
        while(temp != NULL){
            printf("\t%d", temp -> conteudo);
            temp = temp -> seguinte;
        }
    }
    printf("\n");
}

cel* buscar(Lista *lista, int elemento){
    
    if(*lista == NULL){
        return NULL;
    }
    
    cel* temp = *lista;
    while(temp != NULL){
        if(temp -> conteudo == elemento){
            return temp;
        }
        temp = temp -> seguinte;
    }
    return NULL;
}

/* void libera_lista(Lista* lista){
    if (lista == NULL) return; // Verifica se o ponteiro principal existe
    
    cel* atual = *lista; // Pega o endereço do primeiro nó
    cel* proximo;
    
    while(atual != NULL){
        proximo = atual->seguinte; // 1. GUARDA o endereço do próximo nó
        free(atual);              // 2. LIBERA o nó atual (onde 'atual' aponta)
        atual = proximo;          // 3. AVANÇA para o próximo nó
    }
    
    // Opcional, mas boa prática: Define o cabeçalho como NULL
    *lista = NULL; 
    
    // IMPORTANTE: Libera a memória do ponteiro Lista* que você alocou em cria_lista()
    free(lista); 
} */

void libera_lista(Lista *lista){
    if(lista != NULL){
        cel* aux;
        while(*lista != NULL){ // Percorrendo a lista e apagando todos os nós um a um
            aux = *lista;
            *lista = (*lista) -> seguinte; // Lista = aux -> seguinte;
            free(aux);
        }
        free(lista); // Apaga a Lista
    }        
}

int remover(Lista *lista, int x){
    if(lista == NULL) {return 0;}
    if(*lista == NULL) {return 0;}
    
    cel *ant, *aux = *lista;
    
    while(aux != NULL && aux -> conteudo != x){
        ant = aux;
        aux = aux -> seguinte;
    }
    if(aux == NULL) {return 0;}
    if(aux == *lista){
        *lista = aux -> seguinte;
    }
    else{
        ant -> seguinte = aux -> seguinte;
    }
    free(aux);
    return 1;
}

int main()

{
    Lista *lista;
    lista = cria_lista();
    
    /* cel c1, c2, c3;
    c1.conteudo = 1;
    c2.conteudo = 2;
    c3.conteudo = 3;
    
    c1.seguinte = &c2;
    c2.seguinte = &c3;
    c3.seguinte = NULL;
    
    *lista = &c1;
    
    cel* temp = *lista;
    
    while(temp != NULL){
        printf("\t%d", temp->conteudo);
        temp = temp->seguinte;
    }  */
    
    inserir(lista, 4);
    inserir(lista, 5);
    inserir(lista, 6);
    inserir(lista, 2);
    inserir(lista, 4);
    inserir(lista, 8);
    
    imprimir(lista);
    
    cel* no_encontrado = buscar(lista, 8);
    
    if(no_encontrado != NULL){
        printf("O elemento %d foi encontrado na lista e seu endereco é %p\n",    
            no_encontrado -> conteudo, (void*)no_encontrado);
    }
    else{
        printf("O elemento buscado não existe na lista");
    }
    remover(lista, 4);
    imprimir(lista);
    libera_lista(lista);
    
    return 0;
}
