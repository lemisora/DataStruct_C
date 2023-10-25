#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

enum exec_Control{
  EXIT = 'Q', PRINT = 'P', READ = 'R', CALCULATE = 'C',
  exit_ = 'q', print = 'p', read_ = 'r', calculate = 'c',
};

int leeNoVertices();
void inicializaMatriz(int **matrix, int tam);
void leeGrafo(int **matrix);
void imprimeGrafo(int **matrix);
void calculaGradoVertices(int **matrix);

int main(int argc, char **argv){
  int i, vertex = 0;
  vertex = leeNoVertices();
  int matriz_Grafo[vertex][vertex];

  return 0;
}

int leeNoVertices(){
  int noVert;
  printf("\nIngrese el número de vértices del grafo: ");
  if(scanf("%i", &noVert) == 1)
    noVert = noVert;
  while(getchar() != '\n')
    noVert = noVert;
  return noVert;
}

void inicializaMatriz(int **matrix, int tam){
  int i, j = 0;
  for(int i = 0; i < tam; i++){

  }
}



