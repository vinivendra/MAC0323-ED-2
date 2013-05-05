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