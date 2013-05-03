#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Point.h"

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
    
    node *pontos = malloc(sizeof(node));       /* Ponteiro para a cabeça da futura lista de pontos */
    
    
    
    
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
    
    
    /*
     Inicialização dos pontos. Se o usuário passou o parâmetro -C, vamos pegar os dados da stdin.
     Caso contrário, vamos gerar os pontos aleatoriamente.
    */
    
    
    if (c == 1) {
        float x = 0;            /* Guardar o input do usuário */
        node* nodulo = pontos;  /* Percorrer a lista de pontos */
        
        i = D;                  /* Inicializa i de tal forma que a primeira iteração vá criar um nódulo novo */
        n = 0;                  /* Para contar o número de pontos que o usuário vai entrar */
        
        
        printf ("Por favor, digite os pontos desejados.\nQuando terminar, pressione Ctrl+D.\n");
        
        while (scanf("%f", &x) == 1) {
            if (i == D) {               /* O usuário vai começar um ponto novo */
                node *aux = nodulo;     /* Inicializa o novo ponto */
                nodulo = initNode(D);
                aux->prox = nodulo;
                
                i = 0;                  /* Reinicia o contador, soma 1 no número de pontos */
                n ++;
            }
            
            nodulo->point[i] = x;       /* Insere o valor na coordenada */
            i++;
        }
        
        printf("Pontos gerados.\n");
    }
    
    
    
    /*
     Impressão dos pontos (para depuração, principalmente)
    */
    
    
    if (v > 0) {        /* Se for 1 ou dois (v ou V estiver presente) é necessário imprimir os pontos */
        node *nodulo = pontos->prox;    /* Percorrer a lista de pontos */
        
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
    
    
    return 0;
}












