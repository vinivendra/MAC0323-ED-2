#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Distance.h"

/*
 Defines e variáveis globais
    Será usado um vetor de distâncias, que é a parte principal do algoritmo que calcula o limiar de conexidade. Ele deve ser inicializado, ordenado e então deve-se buscar a distância desejada, que é uma aproximação do limiar.
*/

static float *distancias;