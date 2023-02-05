#include <stdio.h>
#include <stdlib.h>



#include "bib_pilha.h"


void Push (struct topo *P, int x) {
    struct nodo_simples *novo = malloc(sizeof(struct nodo_simples));
    if (P->cabeca == NULL) {
        P->inicio = novo;
        P->fim = novo;
        novo->igrediente = x;
        novo->prox = P->cabeca;
        P->cabeca = novo;
        P->tam++;
    }
    else {
        novo->igrediente = x;
        P->tam++;
        novo->prox = P->fim->prox;
        P->fim->prox = novo;
        P->fim = novo;
    }
    //printf("    Teste: %d", novo->igrediente);            //CHECAGEM
}

void Pop (struct topo *P) {
    if (P->cabeca == NULL) {
        printf("\n----------------------------------------------------------\n\n");
        printf("    Erro: lista esta vazia\n");
    }
    else {
        struct nodo_simples *aux = P->inicio;
        P->cabeca = P->inicio->prox;
        P->inicio = P->inicio->prox;
        P->tam--;
        free(aux);
    }
}
