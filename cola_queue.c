//Alumnos: Leonardo Michel Domingo Sánchez, Marco Antonio Mota Herrera, Jorge Ulises del Moral Muñoz
//Programa 6. Cola -versión rústica-

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int opc = 0;
    int principio = 0, longitud = 7, final = 0;
    int cola[longitud];
    int i,dato = 0;                               //En ela variable <dato> se almacenarán los datos sacados de la cola
    bool bandera = true;

    //Encolar -Insertar dato-
    while(opc != 4){
        // system("clear");
        printf("\n1 -> Encola\n2 -> Desencolar\n3 -> Mostrar\n4 -> Salir\nIngresa una opción: ");
        scanf("%d",&opc);
        switch (opc) {
            case 1:
                if(principio == final && !bandera){
                    printf("¡Cola llena!\n");
                }else{
                    printf("\nIngrese el dato: ");
                    scanf("%d",&cola[final]);
                    final++;
                    // bandera = true;
                    if(final == longitud){
                        final = 0;
                        // bandera = true;
                    }
                    bandera = true;
                }
                break;
            case 2:
                if(principio == final && bandera){
                    printf("\n¡Cola vacía!\n");
                }else{
                    dato = cola[principio];
                    printf("\nSe ha extraído el dato -> %i\n",dato);
                    principio++;
                    // bandera = false;
                    if(principio == longitud){
                        principio = 0;
                        // bandera = false;
                    }
                    bandera = false;
                }
                break;
            case 3:
                if(principio == final && bandera){
                    printf("\n¡Cola vacía!\n");
                }else{
                    i = principio;
                    do{
                        printf("|%i|\n",cola[i]);
                        i++;
                        if(i == longitud){
                            i = 0;
                        }
                    }while(i!=final);
                }
                break;
            case 4:
                printf("¡Fin del programa!\n");
                break;
            default:
                printf("\n¡Opción inválida! ¡Inténtelo nuevamente!\n");
                break;
        }
    }

    return 0;
}
