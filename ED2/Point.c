#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Point.h"

#define NULLFLOAT -10

point initPoint(int D) {
    point new = malloc((D+1) * sizeof(float));
    new[D] = NULLFLOAT;
    return new;
}

node *initNode (int D){
    node *new = malloc(sizeof(node));
    new->point = initPoint(D);
    new->prox = NULL;
    return new;
}