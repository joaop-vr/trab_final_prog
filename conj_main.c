#include <stdio.h>
#include <stdlib.h>
#include <time.h>



#include "bib_fila.h"
#include "bib_pilha.h" 
#include "bib_main.h"




int Sortear_pedido () {
    int x = rand() % 6;
    printf("Sorteado: %d",x);

    return x;
}

void Preencher_pedido (struct nodo_dupla *pedido, int sorteado, int i) {

    switch (sorteado) {
        case 0:
            pedido->num_cliente = i;    // <-- posição do cliente na fila
            pedido->nome = "X-Burger";  // <-- qual foi o pedido
            pedido->codigo = 1;  // <-- codigo do pedido (menu)
            break;
        case 1:
            pedido->num_cliente = i;
            pedido->nome = "X-Salada";
            pedido->codigo = 2;
            break;
        case 2:
            pedido->num_cliente = i;
            pedido->nome = "Combo 1 ";
            pedido->codigo = 3;
            break;
        case 3:
            pedido->num_cliente = i;
            pedido->nome = "Combo 2";
            pedido->codigo = 4;
            break;
        case 4:
            pedido->num_cliente = i;
            pedido->nome =  "Combo Vegetariano";
            pedido->codigo = 5;
            break;
        case 5:
            pedido->num_cliente = i;
            pedido->nome = "Combo Vegano";
            pedido->codigo = 6;
            break;
    }
}
void Criar_pedidos (int *num_pedidos, struct lista_dupla *Fila_pedidos) {
    
    int novo_num_pedidos;
    printf("\n----------------------------------------------------------\n");
    printf("    Informe o numero de pedidos a serem processados: ");
    scanf("%i", &novo_num_pedidos);
    *num_pedidos = novo_num_pedidos;
    
    int i;
    srand(time(NULL));
    for (i = 1; i <= *num_pedidos; i++) {
        struct nodo_dupla *pedido = malloc(sizeof(struct nodo_dupla));
        Criar_nodo_fila(Fila_pedidos, pedido);
        int sorteado = Sortear_pedido();      // <-- sorteia um numero de 1 a 6 (menu de opções de lanches)
        Preencher_pedido(pedido, sorteado, i);
    }

    
}

int Verificar_fim (struct desempenho Status) {
    if (Status.num_erros == 3) {
        system("clear");
        printf("----------------------------------------------------------\n");
        printf("    ***FIM DE JOGO***\n");
        printf("    Pedidos errados: %d\n", Status.num_erros);
        printf("----------------------------------------------------------\n");
        return -1;
    }
    else if (Status.num_lixo == 5) {
        system("clear");
        printf("----------------------------------------------------------\n");
        printf("    ***FIM DE JOGO***\n");
        printf("    Pedidos jogados no lixo: %d\n", Status.num_lixo);
        printf("----------------------------------------------------------\n");
        return -1;
    }
    else {
        system("clear");
        printf("----------------------------------------------------------\n");
        printf("    ***FIM DE JOGO***\n");
        printf("       Parabéns!!\n");
        printf("----------------------------------------------------------\n");
        return 0;
    }
}

void Imprimir_fila (struct lista_dupla *P) {
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

void Criando_mapa(char mapa[6][21]) {
    int column, row;
    for (row = 0; row < 6; row++) {
        for (column = 0; column < 21; column++) {
            if (row == 0 && column == 10) 
                mapa[row][column] = '@';
            else if (row == 2 && column == 19)
                mapa[row][column] = 'o';
            else if (row == 1 && column == 3)
                mapa[row][column] = '[';
            else if (row == 1 && column == 4)
                mapa[row][column] = 'R';
            else if (row == 1 && column == 5)
                mapa[row][column] = ']';
            else if (row == 2 && column == 3)
                mapa[row][column] = '[';
            else if (row == 2 && column == 4)
                mapa[row][column] = 'F';
            else if (row == 2 && column == 5)
                mapa[row][column] = ']';
            else if ((row == 4 && column == 1) || (row == 4 && column == 5) || (row == 4 && column == 9) || (row == 4 && column == 13) || (row == 4 && column == 17))
                mapa[row][column] = '[';
            else if ((row == 4 && column == 3) || (row == 4 && column == 7) || (row == 4 && column == 11) || (row == 4 && column == 15) || (row == 4 && column == 19))
                mapa[row][column] = ']';
            else if (row == 4 && column == 2)
                mapa[row][column] = 'p';
            else if (row == 4 && column == 6)
                mapa[row][column] = 'H';
            else if (row == 4 && column == 10)
                mapa[row][column] = 'Q';
            else if (row == 4 && column == 14)
                mapa[row][column] = 'S';
            else if (row == 4 && column == 18)
                mapa[row][column] = 'P';
            else if ((row == 0 && column == 9) || (row == 0 && column == 11))
                mapa[row][column] = '|';
            else if ((row == 0 && column == 0) || (row == 0 && column == 20) || (row == 5 && column == 0) || (row == 5 && column == 20))
                mapa[row][column] = '#';
            else if (column == 0 || (column == 20 && (row != 0 && row != 20)))
                mapa[row][column] = '|';
            else if (row == 0 || (row == 5 && (column != 0 && column != 20)))
                mapa[row][column] = '-';
            else
                mapa[row][column] = ' ';
            
        }
        
    }
}

void Imprimir_mapa(char mapa[6][21]) {
    int row, column;
    for (row = 0; row < 6; row++) {
        for (column = 0; column < 21; column++) {
            //if (row == 0 && column == 0 || row == 0 && column == 5 || row == 5 && column == 0 || row == 5 && column == 20)
                printf("%c", mapa[row][column]);
        }
        printf("\n");
    }
}