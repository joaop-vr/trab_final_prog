#include <stdio.h>
#include <stdlib.h>


#include "bib_main.h"


int main() {

    int num_pedidos = 10;                   // <--- default

    char mapa[7][23];
    struct localizacao Posicao;             // <-- STRUCT PARA GUARDAR A POSICAO DO CHAPEIRO
    Criando_mapa(mapa, &Posicao);

    struct lista_dupla Fila_pedidos;
    Fila_pedidos.tam = 0;
    Fila_pedidos.cabeca = NULL;
        
    Criar_pedidos(&num_pedidos, &Fila_pedidos);

    struct desempenho Status;
    Status.num_erros = 0;                   //numero de pedidos errados
    Status.num_lixo = 0;                    //numero de pedidos descartados no lixo
    Status.num_exito = 0;                   //numero de pedidos corretos
    Status.num_pedidos = num_pedidos;       //numero de pedidos no total

    struct topo Pilha_ingredientes;
    Pilha_ingredientes.cabeca = NULL;
    Pilha_ingredientes.tam = 0;           
    
    while (Verificar_fim(Status) == 0) {
        Imprimir(mapa, Fila_pedidos, Status, Pilha_ingredientes);
        Verificar_fim(Status);      
        Andar(mapa, &Status, &Posicao, &Pilha_ingredientes, &Fila_pedidos);
    }
    
    if (Verificar_fim(Status) == 1)
        return 0;
}