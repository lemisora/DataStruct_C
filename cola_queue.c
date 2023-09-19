#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int main(){
    int opc = 0;
    int principio = 0, longitud = 7, final = 0;
    int cola[longitud];
    int i,dato = 0;                               //En ela variable <dato> se almacenarán los datos sacados de la cola
    bool bandera = true;

    //Encolar -Insertar dato-
    while(opc != 4){
        printf("\n1 -> Encola\n2 -> Desencolar\n3 -> Mostrar\n4 -> Salir\nIngresa una opción: ");
        scanf("%i",&opc);
        if(opc == 1){
            if(principio == final && !bandera){
                printf("¡Cola llena!\n");
            }else{
                printf("\nIngrese el dato: ");
                scanf("%i",&cola[final]);
                final++;
                if(final == longitud){
                    final = 0;
                    bandera = true;
                }
            }
        }else if(opc == 2){
            if(principio == final && bandera){
                printf("\n¡Cola vacía!\n");
            }else{
                dato = cola[principio];
                principio++;
                if(principio == longitud){
                    principio = 0;
                    bandera = false;
                }
            }
        }else if(opc == 3){
            if(principio == final && bandera){
                printf("\n¡Cola vacía!\n");
            }else{
                i = principio;
                do{
                    printf("|%i",cola[i]);
                    i++;
                    if(i == longitud){
                        i = 0;
                    }
                }while(i!=final);
            }
        }
    }

    return 0;
}
