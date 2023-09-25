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
}queue;

int main(int argc, char *argv[]){
    int entrada;
    char opc;
    printf("Ingrese un dato para añadirlo a la cola: ");
    scanf("%i",&entrada);
    struct nodo *apuntadorNodos;
    apuntadorNodos = malloc(sizeof(struct nodo));
    apuntadorNodos->dato = entrada;
    apuntadorNodos->ap_dato = &apuntadorNodos->dato;

    queue.principio = apuntadorNodos->ap_dato;
    queue.final = apuntadorNodos->ap_dato;

    printf("El dato ingresado es: %i\n¿Desea ingresar otro dato? [s/N] ",apuntadorNodos->dato);

    scanf("%c",&opc);
    if(opc == 's' || opc == 'S'){
        printf("Ingrese el dato a añadir: ");

    }else if(opc == 'n' || opc == 'N'){
        printf("\n¡Fin del programa!\n");
    }
    return 0;
}
