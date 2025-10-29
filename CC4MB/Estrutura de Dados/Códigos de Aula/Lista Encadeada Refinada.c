#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Para usar 'bool' e 'true'/'false' em C

// =======================================================
// ESTRUTURAS E TIPOS
// =======================================================

/**
 * @brief Representa um nó (célula) da lista encadeada.
 */
typedef struct No {
    int dado;               // Conteúdo do nó. Usamos 'dado' ao invés de 'conteudo'.
    struct No *proximo;     // Ponteiro para o próximo nó. Usamos 'proximo' ao invés de 'seguinte'.
} No;

/**
 * @brief Tipo que representa o ponteiro para o ponteiro do primeiro nó (o "handle" da lista).
 * É o ponteiro que o usuário final manipula.
 */
typedef No* Lista;


// =======================================================
// FUNÇÕES DA LISTA
// =======================================================

/**
 * @brief Aloca e inicializa o cabeçalho da lista (o ponteiro para o ponteiro do primeiro nó).
 * @return Um ponteiro para Lista* (ponteiro para o handle da lista), ou NULL se a alocação falhar.
 */
Lista* lista_cria() {
    // Aloca a memória para o ponteiro que APONTA para o primeiro nó.
    Lista *li = (Lista*) malloc(sizeof(Lista)); 
    
    if (li == NULL) {
        // Profissional: Imprime uma mensagem de erro em caso de falha de alocação.
        perror("Erro ao alocar o cabeçalho da lista"); 
        return NULL;
    }
    
    *li = NULL; // Inicializa a lista como vazia, apontando o primeiro nó para NULL.
    return li;
}


/**
 * @brief Insere um novo elemento no FINAL da lista. (Inserção por Cauda)
 * @param lista O ponteiro para o ponteiro do primeiro nó (handle).
 * @param valor O valor inteiro a ser inserido.
 * @return true em caso de sucesso, false em caso de falha.
 */
bool lista_insere(Lista *lista, int valor) {
    if (lista == NULL) {
        return false; // Ponteiro handle inválido.
    }

    // 1. Aloca o novo nó
    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        perror("Erro ao alocar novo nó");
        return false;
    }
    
    // 2. Preenche os dados do novo nó
    novo->dado = valor;
    novo->proximo = NULL; 
    
    // 3. Encontra a posição de inserção (final da lista)
    if ((*lista) == NULL) { 
        // Lista vazia: O novo nó se torna o primeiro
        *lista = novo;
    } else {
        // Percorre até o último nó
        No* atual = *lista;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        // O último nó aponta para o novo nó
        atual->proximo = novo;
    }
    return true;
}

/**
 * @brief Remove o primeiro nó encontrado que contenha o valor 'x'.
 * @param lista O ponteiro para o ponteiro do primeiro nó (handle).
 * @param x O valor a ser removido.
 * @return true se o elemento foi encontrado e removido, false caso contrário.
 */
bool lista_remove(Lista *lista, int x) {
    if (lista == NULL || *lista == NULL) {
        return false; // Lista não existe ou está vazia
    }
    
    No *anterior = NULL;
    No *atual = *lista;

    // 1. Busca o nó e mantém o ponteiro para o anterior
    while (atual != NULL && atual->dado != x) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        return false; // Elemento não encontrado
    }

    // 2. Ajusta os ponteiros
    if (anterior == NULL) {
        // Caso: Removendo o primeiro nó
        *lista = atual->proximo;
    } else {
        // Caso: Removendo um nó no meio ou no fim
        anterior->proximo = atual->proximo;
    }

    // 3. Libera a memória do nó
    free(atual);
    return true;
}

/**
 * @brief Busca um elemento na lista.
 * @param lista O ponteiro para o ponteiro do primeiro nó (handle).
 * @param elemento O valor a ser buscado.
 * @return O ponteiro para o nó encontrado, ou NULL se não encontrado.
 */
No* lista_busca(Lista *lista, int elemento) {
    if (lista == NULL || *lista == NULL) {
        return NULL;
    }
    
    No* atual = *lista;
    while (atual != NULL) {
        if (atual->dado == elemento) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

/**
 * @brief Imprime todos os elementos da lista.
 * @param lista O ponteiro para o ponteiro do primeiro nó (handle).
 */
void lista_imprime(Lista *lista) {
    if (lista == NULL || *lista == NULL) {
        printf("A lista está vazia.\n");
        return;
    }
    
    printf("Lista: ");
    No* atual = *lista;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n"); // Marca o final da lista (melhor visualização)
}

/**
 * @brief Libera toda a memória alocada para os nós e o cabeçalho da lista.
 * Esta função usa a abordagem mais compacta (como a do seu professor).
 * @param lista O ponteiro para o ponteiro do primeiro nó (handle).
 */
void lista_libera(Lista *lista) {
    if (lista == NULL) {
        return;
    }
    
    No* no_a_liberar;
    // Enquanto o ponteiro do primeiro nó (*lista) não for NULL
    while (*lista != NULL) { 
        no_a_liberar = *lista;                      // Guarda o nó atual
        *lista = (*lista)->proximo;                 // Avança o cabeçalho para o próximo nó
        free(no_a_liberar);                         // Libera o nó que foi guardado
    }
    
    // Libera o ponteiro do ponteiro (o handle) que foi alocado em lista_cria()
    free(lista);
    printf("Lista liberada com sucesso.\n");
}


// =======================================================
// FUNÇÃO MAIN DE TESTE
// =======================================================

int main() {
    Lista *minha_lista;
    minha_lista = lista_cria();
    
    if (minha_lista == NULL) {
        return 1; // Falha na criação
    }
    
    // Testes de Inserção
    lista_insere(minha_lista, 4);
    lista_insere(minha_lista, 5);
    lista_insere(minha_lista, 6);
    lista_insere(minha_lista, 2);
    lista_insere(minha_lista, 8);
    
    lista_imprime(minha_lista); // Saída esperada: 4 -> 5 -> 6 -> 2 -> 8 -> NULL

    // Teste de Busca
    No* no_encontrado = lista_busca(minha_lista, 6);
    if (no_encontrado != NULL) {
        printf("Elemento %d encontrado no endereço %p\n", no_encontrado->dado, (void*)no_encontrado);
    } else {
        printf("Elemento não encontrado.\n");
    }

    // Teste de Remoção
    lista_remove(minha_lista, 4); // Remove o primeiro
    lista_remove(minha_lista, 6); // Remove do meio
    lista_remove(minha_lista, 99); // Não existe
    
    lista_imprime(minha_lista); // Saída esperada: 5 -> 2 -> 8 -> NULL

    // Libera a memória alocada
    lista_libera(minha_lista);
    
    // Tentar imprimir após liberar (deve imprimir "A lista está vazia.")
    lista_imprime(minha_lista); 

    return 0;
}
