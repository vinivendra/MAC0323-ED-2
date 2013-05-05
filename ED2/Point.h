#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NULLFLOAT -10


/*
 Typedefs
*/

typedef float *point;


/*
 Protótipos
*/

void initDim(int D);
point initEmptyPoint();
point randPoint();
float distance (point p1, point p2);

/*
 Observações:
    Para facilitar na implementação, opta-se por usar point como um vetor de floats com D+1 posições. A posição point[D] terá sempre o valor arbitrario NULLFLOAT. Desse modo podemos sempre percorrer o vetor, mesmo sem saber quantas dimensões ele tem; basta parar ao achar uma posição com valor NULLFLOAT.
        (ISSO É REALMENTE NECESSÁRIO??)
    A função distance retorna o quadrado da distância, não a distância em si. Como ela será usada apenas para comparação entre distâncias, isso não prejudica o resultado do programa e aumenta a eficiência, pois não é necessário tirar a raiz quadrada (sqrt da math) todas as vezes que calcularmos a distância, que não serão poucas.
*/