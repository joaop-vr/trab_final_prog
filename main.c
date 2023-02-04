#include <stdio.h>
#include <stdlib.h>


#include "bib_main.h"

void Imprimir (struct lista_dupla *P) {
    if (P->cabeca == NULL) {
        printf("\n----------------------------------------------------------\n\n");
        printf("    Erro: lista esta vazia\n");
    }
    else {
        struct nodo_dupla *aux;
        printf("\n----------------------------------------------------------\n\n");
        printf("    Lista: ");
        for (aux = P->cabeca; aux != NULL; aux = aux->prox ) {
            printf("%d  ", aux->codigo);
        }
        printf("\n");
    }
}


int main(){

    int num_pedidos = 10;       // <--- default
    struct lista_dupla Fila_pedidos;
    Fila_pedidos.tam = 0;
    Fila_pedidos.cabeca = NULL;
        
    Criar_pedidos(&num_pedidos, &Fila_pedidos);

    Imprimir(&Fila_pedidos);
/*
    while (Verificar_fim == 0) {
        Imprimir(&Fila_pedidos);
        Verificar_fim();
        Andar();
    }*/


    return 0;
}