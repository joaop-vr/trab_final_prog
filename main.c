#include <stdio.h>
#include <stdlib.h>


#include "bib_main.h"


int main() {

    int num_pedidos = 10;                   // <--- default

    char mapa[6][21];
    struct localizacao Posicao;             // <-- STRUCT PARA GUARDAR A POSICAO DO CHAPEIRO
    Criando_mapa(mapa, &Posicao);
    //Imprimir_mapa(mapa);                  // <-- CHECAGEM

    struct lista_dupla Fila_pedidos;
    Fila_pedidos.tam = 0;
    Fila_pedidos.cabeca = NULL;
        
    Criar_pedidos(&num_pedidos, &Fila_pedidos);

    struct desempenho Status;
    Status.num_erros = 0;                   //numero de pedidos errados
    Status.num_lixo = 0;                    //numero de pedidos descartados no lixo
    Status.num_exito = 0;                   //numero de pedidos corretos
    Status.num_pedidos = num_pedidos;       //numero de pedidos no total


    Status.movimentos = 1; //APAGAR APAGAR APAGAR APAGAR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    Imprimir_fila(Fila_pedidos);         // <-- CHECAGEM
    printf("\n----------------------------------------------------------\n");
    
    int temp = 0;
    while (/*Verificar_fim(Status)*/temp == 0) {
        Imprimir(mapa, Fila_pedidos);
        //Verificar_fim();      // <-- Precisa disso aqui??
        Andar(mapa, &Status, &Posicao);
        // printf("\nImprimindo dnv\n");
        // Imprimir(mapa, Fila_pedidos);
        // printf("\nsaiu da impressao\n");
    }
    

    return 0;
}