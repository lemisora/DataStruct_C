/*Programa. Algoritmo de Dijkstra -- Encontrar el camino más corto de un vértice específico 'S' a todos los demás
* Alumno: Leonardo Michel Domingo Sánchez
* + El propósito del algoritmo de Dijkstra es encontrar el camino más corto de un vértice 'S' a los demás (para grafos ponderados)
* + Permite reconstruir la ruta a seguir para tener el camino más corto
* - Inicializar g y s
* - S = {} != 0
* - Q = V[g]
* - while (Q!=0) {
*     u = extract - min(q)
*     s = s u {u}
*     for cada vertice v pertenece a Adj[u]
*       relax(u, v, w)
*   }
* - relax(u,v,w)
* - if(d[v] > d[u]+w(u,v))  ~Matriz de costos~
*     d[v] = d[u]+w(u,v)
*     pi(v) = u
* - extract-min(q) -> selecciona el vértice adyacente con el menor costo
* - Dijkstra(G,W,S)
*   -> g - Grafo
*   -> w - Matriz de costos
*   -> s - Vértice de origen
*
*   - Inicializar (G,S)
*
*/

#include <stdio.h>

//Funciones para el algoritmo de Dijkstra

void inicializar();
void extract_Min();
void relax();
void adj();
int main(){

  return 0;
}
