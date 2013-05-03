#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NULLFLOAT -10


/*
 Typedefs
*/

typedef float *point;

typedef struct node {
    point point;
    struct node* prox;
} node;




/*
 Protótipos
*/

point initPoint(int D);
node *initNode (int D);
point randPoint();
float distance (point, point);

/*
 Observações:
    Para facilitar na implementação, opta-se por usar point como um vetor de floats com D+1 posições.
    A posição point[D] terá sempre o valor arbitrario NULLFLOAT. Desse modo podemos sempre percorrer
    o vetor, mesmo sem saber quantas dimensões ele tem; basta parar ao achar uma posição com valor
    NULLFLOAT.
*/