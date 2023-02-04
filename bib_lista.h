#ifndef BIB_LISTA_H
#define BIB_LISTA_H

struct lista_simples {      // <-- PILHA DE IGREDIENTEAS
    int tam;
    struct nodo_simples *cabeca;
    struct nodo_simples *inicio;
    struct nodo_simples *fim;
};

struct nodo_simples {      
    int igrediente;
    struct nodo_simples *prox;
};

struct lista_dupla {              // <-- LISTA DE PEDIDOS
    int tam;
    struct nodo_dupla *cabeca;
    struct nodo_dupla *inicio;
    struct nodo_dupla *fim;
};

struct nodo_dupla {         
    int num_cliente;
    char *nome;
    int codigo;
    struct nodo_dupla *prox;
    struct nodo_dupla *ant;
};

struct topo {                       // <-- TOPO DA PILHA
    int tam;
    struct nodo_simples *inicio;
    struct nodo_simples *fim;
    struct nodo_simples *cabeca;
};

#endif