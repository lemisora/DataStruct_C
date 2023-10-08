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
void eliminaNodo();
void *pushDataQueue(Nodo *frente, int dato);
void pullDataQueue();

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
        printf("El dato desencolado es -> \n");
        break;
      case SHOW:
        printf("Los datos de la cola son: \n");
        break;
      case EXIT:
        printf("¡Fin del programa!\n");
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

void *pushDataQueue(Nodo *frente, int dato){
  Nodo *nuevoNodo = creaNodo(dato);
  nuevoNodo -> nextDato_Nodo = frente;      
  return nuevoNodo;
}

