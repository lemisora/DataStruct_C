#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void dijkstra(int n, int grafo[n][n] ,int vert_origen){
  int distancia[n];
  int visitado[n];

  for(int i = 0; i < n; i++){
    distancia[i] = INT_MAX;
    visitado[i] = 0;
  }

  distancia[vert_origen] = 0;

  for(int i = 0; i < n-1; i++){
    int u, min = INT_MAX;
    for(int j = 0; j < n; j++){
      if(!visitado[j] && distancia[j] < min){
        u = j;
        min = distancia[j];
      }
    }
    visitado[u] = 1;

    for(int j = 0; j < n; j++){
      if(!visitado[j] && grafo[u][j] && distancia[u] != INT_MAX && distancia[u] + grafo[u][j] < distancia[j])
        distancia[j] = distancia[u] + grafo[u][j];
    }

    printf("Vertice\tDistancia desde el origen\n");
    for(int i = 0; i < n; i++){
      if(distancia[i] != INT_MAX){
        printf("%i\t%i\n",i,distancia[i]);
      }else{
        printf("%i\t%s\n",i,"∞");
      }
    }
  }
}

int main(int argc, char **argv){
  int vertices = 0, entrada;
  printf("Ingrese la cantidad de vertices que tendrá el grafo (entre 1 y 9): "); 
  scanf("%i", &vertices);
  while(getchar() != '\n')
    vertices = vertices;

  int matrizGrafo[vertices][vertices];

  for(int i = 0; i < vertices; i++)
    for(int j = 0; j < vertices; j++){
      printf("Ingrese el dato de la matriz de adyacencia en la posición [%i,%i]: ",i+1, j+1);
      if(scanf("%i", &matrizGrafo[i][j]) == 1)
        matrizGrafo[i][j] = matrizGrafo[i][j];
      while (getchar() != '\n')
          matrizGrafo[i][j] = matrizGrafo[i][j];
    }

  printf("Ingrese el vértice desde el que desea calcular: \n");
  if(scanf("%d", &entrada) == 1)
    entrada = entrada;
  while (getchar() != '\n')
    entrada = entrada;
  
  dijkstra(vertices, matrizGrafo, entrada);

  return 0;
}

