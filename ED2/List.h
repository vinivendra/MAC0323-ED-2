#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Point.h"


/*
 Typedefs
 */

typedef struct Node {
    point point;
    int index;
    struct Node* prox;
} Node;

typedef Node *node;

/*
 Protótipos
 */

node initNode ();
node initEmptyNode ();
node initHeadNode ();
node randNode();