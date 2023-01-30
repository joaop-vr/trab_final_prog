#include <stdio.h>
#include <stdlib.h>

struct lista {
    int tam;
    struct nodo *cabeca;
    struct nodo *inicio;
    struct nodo *fim;
};

struct nodo {
    int valor;
    struct nodo *prox;
    struct nodo *ant;
};

int menu () {
    int op;
    printf("\n----------------------------------------------------------\n");
    printf("    Selecione o codigo da operacao que deseja realizar:\n");
    printf("    1 - Adicionar Item\n");
    printf("    2 - Remover Item\n");
    printf("    3 - Visualizar \n");
    printf("    4 - Sair\n");
    printf("\n    Operacao: ");
    scanf("%i", &op);
    return op;
}

void Criar_nodo (struct lista *P, int x) {
    struct nodo *novo = malloc(sizeof(struct nodo));

    /*Lista vazia*/
    if ( P->cabeca == NULL) {
        novo->valor = x;
        novo->ant = NULL;
        novo->prox = P->cabeca;
        P->cabeca = novo;
        P->inicio = novo;
        P->fim = novo;
        P->tam++;
    }    
    else {
        struct  nodo *aux = P->cabeca;
        while (x >= aux->valor && aux != P->fim)
            aux = aux->prox;

        /*Inserir na cabeca*/
        if (aux == P->inicio && x <= aux->valor) {
            novo->valor = x;
            novo->prox = aux;
            aux->ant = novo;
            novo->ant = NULL;
            P->cabeca = novo;
            P->inicio = novo;
            P->tam++;
        }
        /*Inserir no final*/
        else if (aux == P->fim && x >= aux->valor) {
            novo->valor = x;
            novo->ant = P->fim;
            (P->fim)->prox = novo;
            novo->prox = NULL;
            P->fim = novo;
            P->tam++;
        }
        /*Inserir no meio da lista*/
        else if (aux != P->cabeca) {
            novo->valor = x;
            novo->prox = aux;
            (aux->ant)->prox = novo;
            (novo->ant) = aux->ant;
            (aux->ant) = novo;
            P->tam++;      
        }
    free(aux);
    }
}

int Excluir_nodo (struct lista *P, int x) {
    if (P->cabeca == NULL) {
        printf("\n----------------------------------------------------------\n\n");
        printf("    Erro: lista esta vazia\n");
        return 0;
    }
    else {
        struct nodo *aux = P->cabeca;
        for (aux = P->cabeca; aux->valor != x; aux = aux->prox);

        /*Excluir da cabeca*/
        if (aux == P->inicio) {
            (aux->prox)->ant = (P->inicio)->ant;
            P->inicio = aux->prox;
            P->tam--;
            return 0;
        }
        /*Excluir do final*/
        else if (aux == P->fim) {
            (aux->ant)->prox = (P->fim)->prox;
            P->fim = (aux->ant);
            P->tam--;
            return 0;
        }
        /*Excluir do meio da lista*/
        else if (aux != P->cabeca) {
            (aux->prox)->ant = aux->ant;
            (aux->ant)->prox = aux->prox;
            P->tam--;   
            return 0;   
        }

        free(aux);
    }
    return -1;
}

void Imprimir (struct lista *P) {
    if (P->cabeca == NULL) {
        printf("\n----------------------------------------------------------\n\n");
        printf("    Erro: lista esta vazia\n");
    }
    else {
        struct nodo *aux;
        printf("\n----------------------------------------------------------\n\n");
        printf("    nodo: ");
        for (aux = P->cabeca; aux != NULL; aux = aux->prox ) {
            printf("%d  ", aux->valor);
        }
        printf("\n");
    }
}

int main () {

    struct lista P;
    P.tam = 0;
    P.cabeca = NULL;
    int op;
    op = menu();
    do {
        if (op <= 0 || op > 4) {
            printf("\n----------------------------------------------------------\n\n");
            printf("    Erro: Codigo Invalido\n");
        }
            
        else if (op == 1) {
            int x;
            printf("\n----------------------------------------------------------\n");
            printf("    Insira o valor: ");
            scanf("%d", &x);
            Criar_nodo (&P, x);
        }
        else if (op == 2) {
            int x;
            printf("\n----------------------------------------------------------\n");
            printf("    Insira o valor: ");
            scanf("%d", &x);
            if (Excluir_nodo(&P, x) == 0) {
                printf("\n----------------------------------------------------------\n");
                printf("    Valor excluido com sucesso!");
            }
            else {
                printf("\n----------------------------------------------------------\n");
                printf("    Erro: valor não encontrado!");
            }

        }
        else if (op ==3) {
            Imprimir(&P);
            }
        if (op != 4)
            op = menu();
    } while (op != 4);
    printf("    Finalizando...\n");
    return 0;
}
