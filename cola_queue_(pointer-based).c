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
    int i = 0,entrada, opc = 0, dato, longitud = 7;
    struct nodo *apuntadorNodos;
    apuntadorNodos = (struct nodo*)malloc(longitud*sizeof(struct nodo));

    while(opc != 4){
        printf("\n1. Encolar\n2.Desencolar\n3.Mostrar\n4.Salir\nIngrese la opción que desea: ");
        scanf("%i",&opc);
        switch(opc){
        case 1:
            printf("Ingrese el dato: Posición arreglo [%i]",i+1);
            scanf("%d",&entrada);
            apuntadorNodos[i].dato = entrada;
            apuntadorNodos[i].ap_dato = &apuntadorNodos[i].dato;
            printf("El dato ingresado es: %d\n",apuntadorNodos[i].dato);
            i++;
            break;
        case 2:
            dato = apuntadorNodos->dato;
            apuntadorNodos->dato = 0;
            printf("El dato desencolado es -> %i\n",dato);
            break;
        case 3:

            break;
        case 4:
            printf("\n¡Fin del programa!\n");
            break;
        }
        // queue.principio = apuntadorNodos->ap_dato;
        // queue.final = apuntadorNodos->ap_dato;
    }
    return 0;
}
