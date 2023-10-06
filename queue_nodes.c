#include <stdio.h>
#include <stdbool.h>


struct Nodo{
  int dato;
  void *nextDato_Nodo;
};

typedef struct Nodo Nodo;

struct Cola{
  Nodo *principioNodo,*finalNodo;
};

typedef struct Cola queue;

bool isEmpty(Nodo *p_inicio, Nodo *p_final){
  if(p_inicio == NULL && p_final == NULL)
    return true;
  else
    return false;
}

Nodo creaNodo(int data);
void eliminaNodo();
void pushDataQueue(queue *cola, int dato);
void pullDataQueue();

int main(){
  queue cola;
  cola.principioNodo = NULL;
  cola.finalNodo = NULL;

  

  return 0;
}

Nodo creaNodo(){

}

void pushDataQueue(queue *cola, int dato){
   
}
