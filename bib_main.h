#ifndef BIB_MAIN_H
#define BIB_MAIN_H

#include "bib_lista.h"

struct desempenho {
    int num_erros;
    int num_lixo;
    int num_exito;
    int num_pedidos;
};

void Criando_mapa(char mapa[6][21]);

void Imprimir_mapa(char mapa[6][21]);

void Criar_pedidos (int *num_pedidos, struct lista_dupla *Fila_pedidos);

void Preencher_pedido (struct nodo_dupla *pedido, int sorteado, int i) ;

int Verificar_fim (struct desempenho Status);

void Imprimir_fila (struct lista_dupla *P);

#endif