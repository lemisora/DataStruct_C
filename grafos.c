#include <stdio.h>
#include <stdlib.h>

void leeNoVertices(int *noVertices);
void inicializaMatriz(int *matriz);
void leeGrafo(int *matriz);
void imprimeGrafo(int *matriz);
int determinaGrado(int *matriz);

int main(int argc,char **argv){

    return 0;
}

void leeNoVertices(int *noVertices){
    printf("\nIngrese el número de vértices: ");
    scanf("%i",noVertices);

}
