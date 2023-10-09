#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum Execution{     //Caracteres para el control de ejecución del juego
  EXIT = 'q',       //Salir
  QUEUE = 'e',      //Encolar
  DEQUEUE = 'd',    //Desencolar
  SHOW = 'm',       //Mostrar
};

struct Nodo;
struct Cola;

typedef struct Nodo Nodo;
typedef struct Cola queue;

struct Nodo{
  int dato;
  void *nextDato_Nodo;
};

struct Cola{
  Nodo *principioNodo,*apuntadorNodo,*finalNodo;
};

bool isEmpty(Nodo *p_inicio, Nodo *p_final){
  if(p_inicio == NULL && p_final == NULL)
    return true;
  else
    return false;
}

Nodo *creaNodo(int data);
void eliminaNodo();
void *pushDataQueue(Nodo *apuntadorNodo, int dato);
void pullDataQueue(Nodo *apuntadorNodo);

int main(){
  char opc;
  int dato = 0;
  queue cola;
  cola.principioNodo = NULL;
  cola.finalNodo = NULL;

  printf("Este programa simula la ejecución de una cola, a continuación se le muestran algunas opciones\n\n");
  while (opc != EXIT) {
    puts("e. Encolar");
    puts("d. Desencolar");
    puts("m. Mostrar");
    puts("q. Salir");
    printf("\nIngrese la opción que desea: ");

    opc = getchar();
    
    if(opc != '\n'){
      while (getchar() != '\n') {
        opc = opc;
      }
    }

    switch (opc) {
      case QUEUE:
        printf("Ingrese el dato a encolar: ");
        if(scanf("%i",&dato) == 1){
          dato = dato;
        }
        while (getchar() != '\n') {
          dato = dato;
        }
        cola.principioNodo = pushDataQueue(cola.principioNodo,dato);
        printf("El dato ingresado es -> %i\n",cola.principioNodo->dato);
        break;

      case DEQUEUE:
        pullDataQueue(cola.apuntadorNodo);
        printf("El dato eliminado es -> %i",dato);
        break;

      case SHOW:
        if(isEmpty(cola.principioNodo,cola.finalNodo))
          printf("¡Cola vacía!\n");
        else{
          printf("Los datos de la cola son: \n");
        }
        break;

      case EXIT:
        printf("¡Fin del programa!\n");
        if(cola.principioNodo != NULL){
          free(cola.principioNodo);
        }
        break;
    }
    printf("\n");
  }

  return 0;
}

Nodo *creaNodo(int data){
  Nodo *nuevoNodo = (Nodo*)malloc(sizeof(Nodo));  //Se crea un nuevo nodo reservando memoria para el mismo
  if(nuevoNodo == NULL){
    printf("¡Ha fallado la creación de un nuevo nodo!\n");
    exit(1);
  }
  nuevoNodo -> dato = data;
  nuevoNodo -> nextDato_Nodo = NULL;
  return nuevoNodo;
}

void *pushDataQueue(Nodo *apuntadorNodo, int dato){
  Nodo *nuevoNodo = creaNodo(dato);
  nuevoNodo -> nextDato_Nodo = apuntadorNodo;
  return nuevoNodo;
}

void pullDataQueue(Nodo *apuntadorNodo){
  int datoEliminado = 0;
  Nodo *nodoActual = apuntadorNodo;
  if(nodoActual != NULL){
    Nodo *nodoTemporal = nodoActual;
    datoEliminado = nodoActual->dato;
    apuntadorNodo = apuntadorNodo->nextDato_Nodo;
    free(nodoTemporal);
    printf("El dato sacado es -> %i\n",datoEliminado);
  }
}

