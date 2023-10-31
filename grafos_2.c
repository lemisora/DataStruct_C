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
  int vertex = 0, grado = 0;
  vertex = leeNoVertices();
  int matriz_Grafo[vertex][vertex];
  int i, j = 0;
  for(i = 0; i < vertex; i++)
    for(j = 0; j < vertex; j++)
      matriz_Grafo[i][j] = 0;

  for(i = 0; i < vertex; i++)
    for(j = 0; j < vertex; j++){
      printf("Ingrese el dato de la posición [%i, %i] -> ", i+1, j+1);
      scanf("%d",&matriz_Grafo[i][j]);
    }

  for(i = 0; i < vertex; i++)
    for(j = 0; j < vertex; j++)
      printf("%i,",matriz_Grafo[i][j]);


  //Grado de cada vertice
  for(i = 0; i < vertex; i++){
    grado = 0;
    for(j = 0; j < vertex; j++){
     if(matriz_Grafo[i][j] == 1)
        grado++;
    }
    printf("El grado del vértice es -> %i\n",grado);
  }


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

