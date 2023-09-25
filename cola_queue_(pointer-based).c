/*Versión con apuntadores de la cola*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
 *  1. Encolar
 *   - crear nodo [nodo_nuevo] con el dato
 *   - final.ap = nodo_nuevo
 *   - (nodo_nuevo).ap = null
 *
 *  2. Desencolar
 *   - dato = (principio.apuntador).dato
 *   - principio.apuntador = (principio.ap).ap
 *   - liberar espacio con free
 *
 *  3. Escribir
 *   - aux=principio.ap
 *   - while(aux.ap != NULL){
 *      printf("DATO: %d",aux.dato);
 *     }
 */

struct nodo{ //Struct para el manejo de apuntadores
    int dato, *ap_dato;
};

struct cola{
    int *principio, *final, tam;
};

int main(int argc, char *argv[]){

    return 0;
}
