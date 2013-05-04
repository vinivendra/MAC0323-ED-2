#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Point.h"

/*
 Defines e variáveis globais
 
    Opta-se por usar uma variável global dim em que guardar as dimensões. O código fica mais limpo do que se passássemos as dimensões como parâmetros sempre, e os protótipos das funcões podem ser iguais aos do enunciado.
*/

#define NULLFLOAT -10

static int dim = 0;


/*
 Funções
*/

void initDim(int D) { /* Seta a variável dim */
    dim = D;
}

point initEmptyPoint() { /* Malloca e retorna um novo ponto */
    point new = malloc((dim+1) * sizeof(float));
    new[dim] = NULLFLOAT;
    return new;
}

node initNode (){ /* Malloca e retorna um novo nodulo, já com um ponto vazio */
    node new = malloc(sizeof(Node));
    new->point = initEmptyPoint();
    new->prox = NULL;
    return new;
}

node initEmptyNode () { /* Malloca e retorna um novo nodulo, sem ponto */
    node new = malloc(sizeof(Node));
    new->prox = NULL;
    return new;
}

point randPoint() { /* Malloca e retorna um novo ponto, com valores aleatórios */
    int i = 0;
    point new = initEmptyPoint();
    
    for (i = 0; i < dim; i++) {
        new[i] = 1.0*rand()/RAND_MAX; /* Por enquanto, vai de 1 até 0 */
    }
    
    return new;
}

node randNode() { /* Malloca e retorna um novo nodulo, já com um ponto com valores aleatórios */
    node new = initEmptyNode();
    new->point = randPoint();
    return new;
}

float distance (point point1, point point2) { /* Retorna o quadrado da distância entre dois pontos */
    float resultado;
    int i = 0;
    
    for (i = 0; i < dim; i++)
        resultado += (point1[i]-point2[i]) * (point1[i]-point2[i]);
    
    return resultado;
}

/*
 PRECISA TESTAR SE CHAMAR O SRAND NO MAIN MUDA TAMBÉM OS VALORES DO RAND AQUI NA POINT.C
 */