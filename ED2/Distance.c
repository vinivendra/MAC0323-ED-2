#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Distance.h"

/*
 Defines e variáveis globais
    Será usado um vetor de distâncias, que é a parte principal do algoritmo que calcula o limiar de conexidade. Ele deve ser inicializado, ordenado e então deve-se buscar a distância desejada, que é uma aproximação do limiar.
*/

#define YES 1
#define NO 0


static float **matrizDistancias;

void initMatriz (int n) { /* Malloca a memória necessária para a matriz 'distâncias' */
    int k;
    
    matrizDistancias = malloc(n*sizeof(float *));
    for (k = 0; k < n; k++) matrizDistancias[k] = malloc(n*sizeof(float));
}

/* Para não ter que recalcular inúmeras vezes a distância entre dois pontos (algo que demora, com muitas dimensões), opta-se
        por criar uma matriz com todas as distâncias. Como o número de pontos esperado não é tão grande, a memória allocada
        deve ser razoavelmente pequena. */

void initGrafo (node grafo, int n) { /* Popula a matriz 'distancias', que vai guardar as distancias entre todos os pontos. */
    node i, j;
    
    initMatriz(n);
    
    for (i = grafo->prox; i != NULL; i = i->prox) {
        for (j = i; j != NULL; j = j->prox) {
            float d = distance(i->point, j->point); /* Colocar o valor em [i][j] e em [j][i] permite acessar a matriz com quaisquer índices */
            matrizDistancias[i->index][j->index] = d;
            matrizDistancias[j->index][i->index] = d;
        }
    }
}

float quickDistance (node nodulo1, node nodulo2) { /* Acesso direto à matriz, sem ter que recalcular a distância (coisa que demora) */
    return matrizDistancias[nodulo1->index][nodulo2->index];
}


