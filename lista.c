#include <stdlib.h>
#include "lista.h"

struct elem {
    Musica valor;
    struct elem *prox;
};
typedef struct elem Elem;

struct lista {
    Elem *inicio;
    int qtd;
};

Lista criar_lista() {
    Lista li = (Lista) malloc(sizeof(struct lista));
    if (li == NULL)
        return NULL;
    li->inicio = NULL;
    li->qtd = 0;
    return li;
}

int inserir_inicio(Lista li, Musica m) {
    if (li == NULL || m == NULL)
        return 0;
    Elem *novo = (Elem *) malloc(sizeof(Elem));
    if (novo == NULL)
        return 0;
    novo->valor = m;
    novo->prox = li->inicio;
    li->inicio = novo;
    li->qtd++;
    return 1;
}

int inserir_final(Lista li, Musica m) {
    if (li == NULL || m == NULL)
        return 0;
    Elem *novo = (Elem *) malloc(sizeof(Elem));
    if (novo == NULL)
        return 0;
    novo->valor = m;
    novo->prox = NULL;
    if (li->inicio == NULL) {
        li->inicio = novo;
    } else {
        Elem *aux = li->inicio;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
    li->qtd++;
    return 1;
}

int inserir_posicao(Lista li, int pos, Musica m) {
    if (li == NULL || m == NULL || pos < 0 || pos > li->qtd)
        return 0;
    if (pos == 0)
        return inserir_inicio(li, m);
    Elem *novo = (Elem *) malloc(sizeof(Elem));
    if (novo == NULL)
        return 0;
    Elem *ant = li->inicio;
    int i;
    for (i = 0; i < pos - 1; i++)
        ant = ant->prox;
    novo->valor = m;
    novo->prox = ant->prox;
    ant->prox = novo;
    li->qtd++;
    return 1;
}

int remover_inicio(Lista li) {
    if (li == NULL || li->inicio == NULL)
        return 0;
    Elem *aux = li->inicio;
    li->inicio = aux->prox;
    destruir_musica(aux->valor);
    free(aux);
    li->qtd--;
    return 1;
}

int remover_final(Lista li) {
    if (li == NULL || li->inicio == NULL)
        return 0;
    if (li->inicio->prox == NULL)
        return remover_inicio(li);
    Elem *ant = li->inicio;
    Elem *aux = ant->prox;
    while (aux->prox != NULL) {
        ant = aux;
        aux = aux->prox;
    }
    ant->prox = NULL;
    destruir_musica(aux->valor);
    free(aux);
    li->qtd--;
    return 1;
}

int remover_posicao(Lista li, int pos) {
    if (li == NULL || pos < 0 || pos >= li->qtd)
        return 0;
    if (pos == 0)
        return remover_inicio(li);
    Elem *ant = li->inicio;
    int i;
    for (i = 0; i < pos - 1; i++)
        ant = ant->prox;
    Elem *aux = ant->prox;
    ant->prox = aux->prox;
    destruir_musica(aux->valor);
    free(aux);
    li->qtd--;
    return 1;
}

int acessar_inicio(Lista li, Musica *m) {
    if (li == NULL || li->inicio == NULL)
        return 0;
    *m = li->inicio->valor;
    return 1;
}

int acessar_posicao(Lista li, int pos, Musica *m) {
    if (li == NULL || pos < 0 || pos >= li->qtd)
        return 0;
    Elem *aux = li->inicio;
    int i;
    for (i = 0; i < pos; i++)
        aux = aux->prox;
    *m = aux->valor;
    return 1;
}

int quantidade(Lista li) {
    if (li == NULL)
        return 0;
    return li->qtd;
}

void destruir(Lista li) {
    if (li == NULL)
        return;
    while (li->inicio != NULL)
        remover_inicio(li);
    free(li);
}
