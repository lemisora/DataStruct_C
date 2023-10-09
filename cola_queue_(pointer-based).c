//Alumnos: Leonardo Michel Domingo Sánchez, Jorge Ulises del Moral Muñoz, Marcon Antonio Mota Herrera
/*Version con apuntadores de la cola*/

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
	bool flag;
    void *principio, *final;
	int tam;
}queue;

int main(){
    int i = 0,entrada = 0, opc = 0, dato = 0, longitud = 1, principio = 0, final = 0;
	queue.flag = true;														//Valor inicial de la bandera de operaciones para la cola
	queue.tam = 0;															//Se establece el tamaño inicial de la cola
	
													//Se almacena el tamaño de la cola en una variable independiente en el main para reservar la memoria inicialmente para el arreglo de nodos
	
    struct nodo *apuntadorNodos = NULL;										//Se crea un arreglo de nodos --Útil para la cola y su control
	
    apuntadorNodos = (struct nodo*)malloc(longitud*sizeof(struct nodo));	//Se reserva espacio inicialmente para los nodos
	
	queue.principio = &apuntadorNodos[0];
	queue.final = &apuntadorNodos[0];

	if(apuntadorNodos == NULL){												//Mensaje de error en caso de no funcionar la reservacion dinámica de memoria
		printf(" Ha fallado la reservacion de memoria!\n");
		return 1;
	}
	
/*	scanf("%i",&entrada);*/
/*	apuntadorNodos[0].ap_dato = &entrada;*/
/*	queue.principio = apuntadorNodos[0].ap_dato;*/
/*	printf("Content of principio -> %d\nAddress of principio -> %p\n",*queue.principio,(void*)queue.principio);*/
	
/*	printf("Content of principio -> %d\nAddress of principio -> %p\n",*apuntadorNodos[0].ap_dato,(void*)apuntadorNodos[0].ap_dato);*/

    while(opc != 4){
		
        printf("\n1. Encolar\n2. Desencolar\n3. Mostrar\n4. Salir\nIngrese la opcion que desea: ");
        scanf("%i",&opc);
	  if(i < 0){
      i = 0;
    }	
		if(opc == 1){
			longitud = queue.tam+1;	
			printf("\nLongitud del arreglo -> %i\tPosicion arreglo [%i]\nIngrese el dato: ",longitud ,i+1);
			struct nodo *apuntadorNodosRealloc = (struct nodo*)realloc(apuntadorNodos,longitud*sizeof(struct nodo));

			if(apuntadorNodos == NULL){
				printf(" Ha fallado la reasignacion de memoria!\n");
				free(apuntadorNodos);
				return 1;
			}
			apuntadorNodos = apuntadorNodosRealloc;						//Se hace referencia al apuntador con la memoria reasignada en el apuntador original
            
            scanf("%d",&entrada);
            apuntadorNodos[i].dato = entrada;
            apuntadorNodos[i].ap_dato = &apuntadorNodos[i].dato;
            printf("El dato ingresado es: %d\n",apuntadorNodos[i].dato);
			
			queue.tam++;
			longitud = queue.tam+1;
			i++;
			queue.final = &apuntadorNodos[i];
			queue.flag = true;
		}
		else if(opc == 2){
			if(queue.principio == queue.final && queue.flag){
				printf("Cola vacia!\n");
			}else{
				dato = apuntadorNodos[principio].dato;
				printf("\nDato -> %i\n",dato);
				// free(&apuntadorNodos[principio]);
				principio++;
        i--;
				queue.principio = &apuntadorNodos[principio];

				queue.flag = false;
			}
		}
		else if(opc == 3){
			// if(queue.principio == queue.final && queue.flag){
			// 	printf("\nCola vacía!\n");
			// }else{
			// 	int j = principio;
			// 	do {
			// 		printf("|%i|",apuntadorNodos[j].dato);
			// 		j++;
			// 		if(&apuntadorNodos[j] == &apuntadorNodos[queue.tam]){
			// 			j = 0;
			// 		}
			// 	}while (&apuntadorNodos[j] != queue.final);
			// }

			for(int j = principio; j < queue.tam; j++){
				printf("|%i|",*apuntadorNodos[j].ap_dato);
			}
			printf("\n");
		}
		else if(opc == 4){
			// for(int j = principio; queue.principio <= queue.final; j++){
				// printf("Dirección apuntadorNodos[%i] -> %p\tDirección queue.final -> %p\n",j+1,(void *)&apuntadorNodos[j].dato,(void *)queue.final);
				free(apuntadorNodos);
			// }

            printf("\n Fin del programa!\n");
		}
	}
    return 0;
}
