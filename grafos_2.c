#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int leeNoVertices();
void multiplicaMatriz(int vertex, int matriz_A[][vertex], int matriz_B[][vertex], int matriz_resultado[][vertex]);

int main(int argc, char **argv){
  int vertex = leeNoVertices(); // Primero lee el número de vértices

  // Ahora que tenemos el número de vértices, podemos declarar las matrices
  int matriz_Grafo[vertex][vertex];
  int matriz_multiplicada[vertex][vertex];
  int matriz_M3[vertex][vertex]; // Matriz para M3
  int i, j;

  //Inicializa matriz en cero
  for(i = 0; i < vertex; i++)
    for(j = 0; j < vertex; j++)
      matriz_Grafo[i][j] = 0;

  //Llena la matriz de datos
  for(i = 0; i < vertex; i++){
    for(j = 0; j < vertex; j++){
      printf("Ingrese el dato de la posicion [%i, %i] -> ", i+1, j+1);
      scanf("%d",&matriz_Grafo[i][j]);
    }
  }

  //Imprime la matriz
  printf("La matriz es->\n");
  for(i = 0; i < vertex; i++){
    for(j = 0; j < vertex; j++){
      printf("[%i] ",matriz_Grafo[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  // Multiplica la matriz por sí misma para obtener M2
  multiplicaMatriz(vertex, matriz_Grafo, matriz_Grafo, matriz_multiplicada);

  // Imprimir matriz_multiplicada (M2)
  printf("La matriz multiplicada por si misma (M2) es:\n");
  for (i = 0; i < vertex; i++) {
    for (j = 0; j < vertex; j++) {
      printf("%d ", matriz_multiplicada[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  // Multiplica M2 por la matriz original para obtener M3
  multiplicaMatriz(vertex, matriz_multiplicada, matriz_Grafo, matriz_M3);

  // Imprimir matriz_M3
  printf("La matriz multiplicada por si misma tres veces (M3) es:\n");
  for (i = 0; i < vertex; i++) {
    for (j = 0; j < vertex; j++) {
      printf("%d ", matriz_M3[i][j]);
    }
    printf("\n");
  }

  return 0;
}

void multiplicaMatriz(int vertex, int matriz_A[][vertex], int matriz_B[][vertex], int matriz_resultado[][vertex]) {
  for (int i = 0; i < vertex; i++) {
    for (int j = 0; j < vertex; j++) {
      matriz_resultado[i][j] = 0;
      for (int k = 0; k < vertex; k++) {
        matriz_resultado[i][j] += matriz_A[i][k] * matriz_B[k][j];
      }
    }
  }
}

int leeNoVertices(){
  int noVert;
  printf("\nIngrese el numero de vertices del grafo: ");
  scanf("%i", &noVert);
  while(getchar() != '\n'); // Limpiar el buffer de entrada
  return noVert;
}
