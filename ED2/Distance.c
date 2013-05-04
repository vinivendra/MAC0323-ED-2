#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Distance.h"

/*
 Defines e variáveis globais
    Será usado um vetor de distâncias, que é a parte principal do algoritmo que calcula o limiar de conexidade. Ele deve ser inicializado, ordenado e então deve-se buscar a distância desejada, que é uma aproximação do limiar.
*/

#define TRUE 1
#define FALSE 0

static float **distancias;
static int n;

void initDistancias () {
    int k;
    
    distancias = malloc(n*sizeof(float *));
    for (k = 0; k < n; k++) distancias[k] = malloc(n*sizeof(float));
}

void initGrafo (node grafo) {
    node i, j;
    
    initDistancias();
    
    for (i = grafo; i != NULL; i = i->prox) {
        for (j = i->prox; j != NULL; j = j->prox) {
            float d = distance(i->point, j->point);
            distancias[i->index][j->index] = d;
            distancias[j->index][i->index] = d;
        }
    }
}



