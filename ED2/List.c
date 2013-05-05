#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "List.h"

/*
 Defines e variáveis globais
*/

static int masterIndex = 0;

/*
 Funções
*/

node initNode (){ /* Malloca e retorna um novo nodulo, já com um ponto vazio */
    node new = initEmptyNode();
    new->point = initEmptyPoint();
    return new;
}

node initEmptyNode () { /* Malloca e retorna um novo nodulo, sem ponto */
    node new = malloc(sizeof(Node));
    new->prox = NULL;
    new->index = masterIndex ++;
    return new;
}

node initHeadNode () { /* Malloca e retorna um novo nodulo, sem ponto, para ser a cabeça da lista */
    node new = malloc(sizeof(Node));
    new->prox = NULL;
    new->index = -1;
    return new;
}

node randNode() { /* Malloca e retorna um novo nodulo, já com um ponto com valores aleatórios */
    node new = initEmptyNode();
    new->point = randPoint();
    return new;
}

node removeProximoNodulo (node lista) { /* Remove o nodulo 'lista->prox' e devolve um ponteiro para ele */
    node new = lista->prox;
    lista->prox = new->prox;
    new->prox = NULL;
    return new;
}

void insereNodulo (node nodulo, node lista) { /* Insere o nodulo 'nodulo' logo depois do nodulo 'lista' */
    node aux = lista->prox;
    lista->prox = nodulo;
    nodulo->prox = aux;
}

node juntaLista (node lista1, node lista2) { /* Junta a 'lista2' logo depois da 'lista1' e devolve um ponteiro para a lista 1.
                                              Considera que ambas têm cabeça. */
    node nodulo = lista1;
    
    while (nodulo->prox != NULL) { /* Faz nodulo apontar para o fim da lista1 */
        nodulo = nodulo->prox;
    }
    
    nodulo->prox = lista2->prox; /* Junta as duas listas */
    
    return lista1;
}