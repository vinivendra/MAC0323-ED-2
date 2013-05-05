#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Distance.h"

/*
 Defines e variáveis globais
    Será usado um vetor de distâncias, que é a parte principal do algoritmo que calcula o limiar de conexidade. Ele deve ser inicializado, ordenado e então deve-se buscar a distância desejada, que é uma aproximação do limiar.
    Para fácil acesso às distâncias, já que calculá-las é a parte mais demorada, utiliza-se uma matriz. Ela poderia ser a mesma que o vetor, mas como vamos reordenar o vetor não teremos mais fácil acesso; a matriz, por outro lado, uma vez inicializada permanecerá intacta.
*/

#define YES 1
#define NO 0

static float **matrizDistancias;
static float *vetorDistancias;

/*
 Funções
 */

void initMatriz (int n) { /* Malloca a memória necessária para a matriz 'matrizDistancias' */
    int k;
    
    matrizDistancias = malloc(n*sizeof(float *));
    for (k = 0; k < n; k++) matrizDistancias[k] = malloc(n*sizeof(float));
}

void initVetor (int n) {
    vetorDistancias = malloc(n*n*sizeof(float));
}

void initGrafo (node grafo, int n) { /* Popula a matriz 'matrizDistancias' e o vetor 'vetorDistancias', que vão guardar as distancias entre
                                        todos os pontos. */
    node i, j; /* Percorrem os pontos para pegar as distancias */
    int k = 0; /* Percorre o vetorDistancias */
    
    initMatriz(n);
    initVetor(n);
    
    for (i = grafo->prox; i != NULL; i = i->prox) {
        for (j = grafo->prox; j != NULL; j = j->prox) {
            float d = distance(i->point, j->point); /* Colocar o valor em [i][j] e em [j][i] permite acessar a matriz com quaisquer índices */
            matrizDistancias[i->index][j->index] = d;
            vetorDistancias[k++] = d;
        }
    }
}

float quickDistance (node nodulo1, node nodulo2) { /* Acesso direto à matriz, sem ter que recalcular a distância (coisa que demora) */
    return matrizDistancias[nodulo1->index][nodulo2->index];
}


