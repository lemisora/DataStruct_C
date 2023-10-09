#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum Execution{     //Caracteres para el control de ejecución del juego
  EXIT = 'q',       //Salir
  QUEUE = 'e',      //Encolar
  DEQUEUE = 'd',    //Desencolar
  SHOW = 'm',       //Mostrar
};
struct Nodo; typedef struct Nodo Nodo;        //Se define un struct llamado Nodo y se le crea un alias llamado Nodo; equivalente a package...renames en Ada
struct Cola; typedef struct Cola queue;       //Se define un struct llamado Cola y su alias es queue

struct Nodo{
  int dato;
  void *nextDato_Nodo;
};

struct Cola{
  Nodo *principioNodo,*finalNodo;
};

bool isEmpty(Nodo *p_inicio, Nodo *p_final){  //Función para verificar si la cola está vacía o no
  if(p_inicio == NULL && p_final == NULL)
    return true;
  else
    return false;
}

Nodo *creaNodo(int data);                     //Función para crear un nodo nuevo de la cola
void pullDataQueue(queue *cola);              //Función para sacar un nodo con un dato de la cola
void pushDataQueue(queue *cola, int dato);    //Función para añadir un nodo con un dato en la cola
void muestraQueue(queue *cola);               //Función para mostrar los datos de los nodos contenidos en la cola
void freeQueue(queue *cola);                  //Función para liberar la memoria de la cola

int main(){
  char opc;                                   //Variable para almacenar las opciones que escoja el usuario
  int dato = 0;                               //Variable para almacenar el dato a encolar o desencolado
  queue cola;                                 //Se crea un registro de tipo queue -- para la cola

  cola.principioNodo = NULL;                  //Se inicializan los apuntadores de registro Nodo* con NULL
  cola.finalNodo = NULL;

  printf("Este programa simula la ejecución de una cola, a continuación se le muestran algunas opciones\n\n");
  while (opc != EXIT) {
    puts("e. Encolar");
    puts("d. Desencolar");
    puts("m. Mostrar");
    puts("q. Salir");
    printf("\nIngrese la opción que desea: ");

    opc = getchar();                            //Se lee el carácter con la opción escogida por el usuario
    
    if(opc != '\n')                             //Se controla que la variable 'opc' almacene únicamente un carácter para evitar problemas de stdin
      while (getchar() != '\n')
        opc = opc;

    switch (opc) {
      case QUEUE:
        printf("Ingrese el dato a encolar: ");
        if(scanf("%i",&dato) == 1)              //Se controla que la variable 'dato' almacene únicamente un dato de tipo de entero
          dato = dato;
        while (getchar() != '\n')
          dato = dato;
        pushDataQueue(&cola,dato);              //Se añade un nodo a la cola con el dato ingresado por el usuario
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
        freeQueue(&cola);                         //Se libera la memoria --los datos contenidos en los nodos asociados a la cola
        printf("¡Fin del programa!\n");
        break;
    }
    printf("\n");
  }
  return 0;
}

Nodo *creaNodo(int data){
  Nodo *nuevoNodo = (Nodo*)malloc(sizeof(Nodo));            //Se crea un nuevo nodo reservando memoria para el mismo
  if(nuevoNodo == NULL){
    printf("¡Ha fallado la creación de un nuevo nodo!\n");
    exit(1);
  }
  nuevoNodo -> dato = data;
  nuevoNodo -> nextDato_Nodo = NULL;                        //Se inicializa el apuntador del siguiente nodo con NULL
  return nuevoNodo;                                         //Se regresa el apuntador del nodo creado
}

void pullDataQueue(queue *cola){
  int dato = 0;
  Nodo *temporal = cola -> principioNodo;                           //Se guarda la información del apuntador (la dirección) de Nodo actual en otro apuntador
  dato = temporal -> dato;                                          //Se almacena el dato que se va a sacar en la variable temporal 'dato'
  cola -> principioNodo = cola -> principioNodo -> nextDato_Nodo;   //Se le da otra dirección al apuntador actual, se mueve al siguiente nodo
  if(cola -> principioNodo == NULL)                                 //Si al sacar el dato el apuntador tiene NULL también se le da ese valor al finalNodo
    cola -> finalNodo = NULL;
  free(temporal);                                                   //Se libera la memoria en dicha dirección
  printf("El dato expulsado es -> %i",dato);
}

void pushDataQueue(queue *cola, int dato){
  Nodo *nuevoNodo = creaNodo(dato);                                 //Se crea un nodo y la dirección se le da al apuntador nuevoNodo
  nuevoNodo -> nextDato_Nodo = NULL;                                //Se inicializa el apuntador de nextDato_Nodo con NULL

  if(cola -> finalNodo != NULL)                                     
    cola -> finalNodo -> nextDato_Nodo = nuevoNodo;                 //Se le da la dirección del nuevoNodo al nodo final de la cola
  cola -> finalNodo = nuevoNodo;                                    

  if(cola -> principioNodo == NULL)                                 
    cola -> principioNodo = nuevoNodo;                              //En caso de que el principio de la cola no tenga ninguna dirección se le da la dirección del nuevoNodo
}

void muestraQueue(queue *cola){
  Nodo *actual = cola -> principioNodo;                             //Se almacena la dirección de principio Nodo en un apuntador
  while(actual != NULL){                                            //El ciclo termina cuando se llega al final de la cola, esta se denota con apuntador que no tiene dirección
    printf("|%i|",actual -> dato);
    actual = actual -> nextDato_Nodo;                               //Se mueve el apuntador a la dirección del siguiente apuntador
  }
  printf("\n");
}

void freeQueue(queue *cola){
  Nodo *a_Limpiar = cola -> principioNodo;                          //Se almacena la dirección de principioNodo en un apuntador
  while (a_Limpiar != NULL) {
    Nodo *temporal = a_Limpiar;                                     //Se almacena la dirección del apuntador previamente creado en otro apuntador
    a_Limpiar = a_Limpiar ->nextDato_Nodo;                          //Se mueve al apuntador a la dirección del siguiente apuntador
    free(temporal);                                                 //Se libera la memoria de la dirección guardada en el segundo apuntador creado que directamente era la primera posición de la cola
  }
}
