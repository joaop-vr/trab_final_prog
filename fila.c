#include <stdio.h>
#include <stdlib.h>



#include "bib_fila.h"


int Sortear_pedido ();

void Criar_nodo_fila (struct lista_dupla *P, struct nodo_dupla *novo) {

    /*fila vazia*/
    if ( P->cabeca == NULL) {
        novo->ant = NULL;
        novo->prox = P->cabeca;
        P->cabeca = novo;
        P->fim = novo;
        P->tam++;
    }   
    else {
        /*Inserindo no fim*/
        novo->ant = P->fim;
        P->fim->prox = novo;
        P->fim = novo;
        novo->prox = NULL;
        P->tam++;
    }

    
}

void Excluir_nodo_fila (struct lista_dupla *P) {
    if (P->cabeca == NULL) {
        printf("\n----------------------------------------------------------\n\n");
        printf("    Erro: fila esta vazia\n");
    }
    /*Excluindo o ultimo nodo restante*/
    else if (P->tam == 1) {
        free(P->cabeca);
        P->cabeca = NULL;
        P->tam--;
    }
    /*Excluindo primeiro nodo*/
    else {
        P->cabeca->prox->ant = NULL;
        P->cabeca = P->cabeca->prox;
        P->tam--;
    }
}