#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Distance.h"

#define YES 1
#define NO 0

int eSuficiente (float d, node pontos);

int main (int argc, char *argv[]) {
    
    /*
     -------------------------------------------------
     Declaração das variáveis
     -------------------------------------------------

     Parâmetros:
    */
    
    int n = 0;          /* Número de pontos */
	int m = 0;          /* Número de vezes para rodar */
	int s = 0;          /* Seed do srand()  */
    int D = 0;          /* Número de dimensões do hipercubo/da hiperesfera */
	int v = 0;          /* 1 para imprimir os pontos, 2 para os pontos e os resultados parciais */
    int c = 0;          /* Se o usuário vai escrever os pontos ele mesmo */
    float d = 0;        /* A distância a ser testada */
    
    char *parametro;    /* String para percorrer os parâmetros no argv[] */
    
    /*
     Contadores:
    */
    
    int i = 0;
    
    /*
     Outras variáveis:
    */
    
    node pontos = initHeadNode();       /* Ponteiro para a cabeça da futura lista de pontos */
    
    
    
    
    /*
     Inicializações
    */
    
    pontos->point = NULL;
    pontos->prox = NULL;
    
    
    /*
     Leitura de Parâmetros
    */
    
    for (i = 1; i < argc; i ++) { /* Percorre todos os parâmetros passados */
        parametro = argv[i];
        
        if (parametro[1] == 'N') { /* Atribui o valor do parâmetro à variável adequada */
            n = atoi(&parametro[2]);
        }
        else if (parametro[1] == 'M') {
            m = atoi(&parametro[2]);
        }
        else if (parametro[1] == 's') {
            s = atoi(&parametro[2]);
        }
        else if (parametro[1] == 'D') {
            D = atoi(&parametro[2]);
        }
        else if (parametro[1] == 'v') {
            v = 1;
        }
        else if (parametro[1] == 'V') {
            v = 2;
        }
        else if (parametro[1] == 'C') {
            c = 1;
        }
        else if (parametro[1] == 'd') {
            d = atof(&parametro[2]);
        }
    }
    
    /* Atualiza a seed do rand() */
    srand(s);
    
    /* Passa a quantidade de dimensões para a biblioteca */
    initDim(D);
    
    /*
     Inicialização dos pontos. Se o usuário passou o parâmetro -C, vamos pegar os dados da stdin.
     Caso contrário, vamos gerar os pontos aleatoriamente.
    */
    
    
    if (c == 1) {
        float x = 0;            /* Guardar o input do usuário */
        node nodulo = pontos;  /* Percorrer e criar a lista de pontos */
        
        i = D;                  /* Inicializa i de tal forma que a primeira iteração vá criar um nódulo novo */
        n = 0;                  /* Para contar o número de pontos que o usuário vai entrar */
        
        
        printf ("Por favor, digite os pontos desejados.\nQuando terminar, pressione Ctrl+D.\n");
        
        while (scanf("%f", &x) == 1) {
            if (i == D) {               /* O usuário vai começar um ponto novo */
                node aux = nodulo;     /* Inicializa o novo ponto */
                nodulo = initNode();
                aux->prox = nodulo;
                
                i = 0;                  /* Reinicia o contador, soma 1 no número de pontos */
                n ++;
            }
            
            nodulo->point[i] = x;       /* Insere o valor na coordenada */
            i++;
        }
        
        printf("Pontos gerados.\n");
    }
    else {
        node nodulo = pontos;           /* Percorrer e criar a lista de pontos */
        for (i = 0; i < n; i ++) {      /* Precisa criar n pontos */
            nodulo->prox = randNode();  /* Inicializa um novo ponto com valores aleatórios */
            nodulo = nodulo->prox;
        }
    }
    
    
    /*
     Impressão dos pontos (para depuração, principalmente)
    */
    
    
    if (v > 0) {        /* Se for 1 ou 2 (v ou V estiver presente) é necessário imprimir os pontos */
        node nodulo = pontos->prox;    /* Percorrer a lista de pontos */
        
        while (nodulo != NULL) {        /* Enquanto a lista não acabar */
            printf("(");
            for (i = 0; i < D; i++) {   /* Percorre as coordenadas do ponto */
                printf("%f", nodulo->point[i]);
                if (i < D-1) printf (", ");
            }
            printf(")\n");
            nodulo = nodulo->prox;      /* Vai para o próximo ponto */
        }
    }
    
    initGrafo(pontos, n);
    
    
    if (d >= 0) {       /* Se o usuário passou a distância, assume-se que ele quer saber se o grafo é conexo ou não */
        int result = eSuficiente(d, pontos);
        
        if (result == YES) {
            printf("O grafo é conexo.\n");
        }
        else {
            printf("O grafo não é conexo.\n");
        }
    }
    
    
    
    
    return 0;
}











#pragma mark funções auxiliares

node removeProximoNodulo (node lista) { /* Remove o nodulo 'lista->prox' e devolve um ponteiro para ele */
    node new = lista->prox;
    lista->prox = new->prox;
    new->prox = NULL;
    return new;
}

void insereNodulo (node nodulo, node lista) { /* Insere o nodulo 'nodulo' logo depois do nodulo 'lista' */
    node aux = lista->prox;
    lista->prox = nodulo;
    nodulo->prox = aux;
}

node juntaLista (node lista1, node lista2) { /* Junta a 'lista2' logo depois da 'lista1' e devolve um ponteiro para a lista 1.
                                                Considera que ambas têm cabeça. */
    node nodulo = lista1;
    
    while (nodulo->prox != NULL) { /* Faz nodulo apontar para o fim da lista1 */
        nodulo = nodulo->prox;
    }
    
    nodulo->prox = lista2->prox; /* Junta as duas listas */
    
    return lista1;
}


int eSuficiente (float d, node pontos) { /* Descobre se a distância d é suficiente para tornar o grafo 'pontos' conexo */
    
    float d2 = d*d; /* Evita ter que multiplicar a cada iteração */
    
    node desconectados = pontos; /* Lista de pontos que ainda não conectamos */
    node conectados = initEmptyNode(); /* Lista de pontos que já foram conectados */
    node noduloCon; /* Percorrer a conectados */
    node noduloDes; /* Percorrer a desconectados */
    
    conectados->prox = removeProximoNodulo(desconectados); /* Escolhe-se um ponto arbitrário para começar */
    
    noduloCon = conectados;
    noduloDes = desconectados;
        
    while (noduloCon->prox != NULL) { /* Percorre a conectados */
        while (noduloDes->prox != NULL) { /* Percorre a desconectados */
            if (quickDistance(noduloDes->prox, noduloCon->prox) <= d2) { /* Se a distância for menor, precisa conectar */
                insereNodulo(removeProximoNodulo(noduloDes), noduloCon->prox); /* Tira da desconectados, põe na conectados.
                                                                                   Colocamos o ponto logo depois de noduloCon,
                                                                                   garantindo que ele ainda será analisado.*/
            }
            else {
                noduloDes = noduloDes->prox; /* Se removemos um ponto da desconectados, não precisa andar. Caso contrário, anda. */
            }
        }
        noduloDes = desconectados; /* Reinicia do começo da desconectados */
        noduloCon = noduloCon->prox; /* Anda na conectados */
    }
    
    if (desconectados->prox == NULL) {/* Se a desconectados está vazia, é porque conseguimos conectar todos os pontos com a distância d */
        pontos = juntaLista(desconectados, conectados); /* Reconstruimos a lista 'pontos' que foi separada em duas no processo */
        return YES;
    }
    
    pontos = juntaLista(desconectados, conectados);
    return NO;
    
}











