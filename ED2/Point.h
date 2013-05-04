#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NULLFLOAT -10


/*
 Typedefs
*/

typedef float *point;

typedef struct Node {
    point point;
    struct Node* prox;
} Node;

typedef Node *node;


/*
 Protótipos
*/

void initDim(int D);
point initEmptyPoint();
node initNode ();
node initEmptyNode ();
point randPoint();
node randNode();
float distance (point, point);

/*
 Observações:
    Para facilitar na implementação, opta-se por usar point como um vetor de floats com D+1 posições. A posição point[D] terá sempre o valor arbitrario NULLFLOAT. Desse modo podemos sempre percorrer o vetor, mesmo sem saber quantas dimensões ele tem; basta parar ao achar uma posição com valor NULLFLOAT.
        (ISSO É REALMENTE NECESSÁRIO??) 
*/