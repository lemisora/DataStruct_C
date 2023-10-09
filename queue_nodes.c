#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum Execution{     //Caracteres para el control de ejecución del juego
  EXIT = 'q',       //Salir
  QUEUE = 'e',      //Encolar
  DEQUEUE = 'd',    //Desencolar
  SHOW = 'm',       //Mostrar
}Control;

struct Nodo;
struct Cola;

typedef struct Nodo Nodo;
typedef struct Cola queue;

struct Nodo{
  int dato;
  void *nextDato_Nodo;
};

struct Cola{
  Nodo *principioNodo,*finalNodo;
};

bool isEmpty(Nodo *p_inicio, Nodo *p_final){
  if(p_inicio == NULL && p_final == NULL)
    return true;
  else
    return false;
}

Nodo *creaNodo(int data);
void pullDataQueue(queue *cola);
void pushDataQueue(queue *cola, int dato);
void muestraQueue(queue *cola);
void freeQueue(queue *cola);

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
        /*cola.principioNodo = */pushDataQueue(&cola,dato);
        printf("El dato ingresado es -> %i\n",cola.finalNodo->dato);
        break;

      case DEQUEUE:
        if(isEmpty(cola.principioNodo, cola.finalNodo))
          printf("¡Cola vacía!\n");
        else{
          pullDataQueue(&cola);
        }
        break;

      case SHOW:
        if(isEmpty(cola.principioNodo, cola.finalNodo))
          printf("¡Cola vacía!\n");
        else{
          printf("Los datos de la cola son: \n");
          muestraQueue(&cola);
        }
        break;

      case EXIT:
        printf("¡Fin del programa!\n");
        // if(cola.principioNodo != NULL){
        //   free(cola.principioNodo);
        // }
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

void pullDataQueue(queue *cola){
  int dato = 0;
  Nodo *temporal = cola -> principioNodo;              //Se guarda la información del apuntador (la dirección) de Nodo actual en otro apuntador
  dato = temporal -> dato;                 //Se almacena el dato que se va a sacar en la variable temporal 'dato'
  cola -> principioNodo = cola -> principioNodo -> nextDato_Nodo;  //Se le da otra dirección al apuntador actual, se mueve al siguiente nodo
  if(cola -> principioNodo == NULL)
    cola -> finalNodo = NULL;
  free(temporal);                           //Se libera la memoria en dicha dirección
  printf("El dato expulsado es -> %i",dato);
}

void pushDataQueue(queue *cola, int dato){
  Nodo *nuevoNodo = creaNodo(dato);
  nuevoNodo -> nextDato_Nodo = NULL;

  if(cola ->finalNodo != NULL)
    cola -> finalNodo -> nextDato_Nodo = nuevoNodo;
  cola -> finalNodo = nuevoNodo;

  if(cola -> principioNodo == NULL)
    cola -> principioNodo = nuevoNodo;
}

void muestraQueue(queue *cola){
  Nodo *actual = cola -> principioNodo;
  while(actual != NULL){
    printf("|%i|",actual -> dato);
    actual = actual ->nextDato_Nodo;
  }
  printf("\n");
}

void freeQueue(queue *cola){
  Nodo *a_Limpiar = cola -> principioNodo;
  while (a_Limpiar != NULL) {
    Nodo *temporal = a_Limpiar;
    a_Limpiar = a_Limpiar ->nextDato_Nodo;
    free(temporal);
  }
}


