#include <iostream> 
#include <fstream>  
#include <stdlib.h> 
#include <ctype.h> 
#include<conio.h>
#include<stdio.h>
#include<string.h>

struct cola{
int placas;
int estacionamiento;
char nombre[1000];
char modelo[1000];


struct cola *sig;
}*princ, *fin;
int j=0;


void acolar(){
struct cola *nuevo;
nuevo=(struct cola *)malloc(sizeof(struct cola));
printf("INTRODUCIR NOMBRE DEL PROPIETARIO:\n ");
scanf("%s",&nuevo->nombre);
printf("INTRODUCIR MODELO DEL AUTO:\n");
scanf("%s",&nuevo->modelo);
printf("INTRODUCIR PLACAS:\n");
scanf("%d",&nuevo->placas);
printf("INTRODUCIR NUMERO DE ESTACIONAMIENTO:\n");
scanf("%d",&nuevo->estacionamiento);
nuevo->sig=NULL;
if(princ==NULL){
princ=nuevo;
fin=nuevo;
}else{
fin->sig=nuevo;
fin=nuevo;
}
j++;
}

void mostrar(){
struct cola *aux;
aux=princ;
if(aux==NULL){
printf("COLA VACIA\n");
}else{
while(aux!=NULL){
printf("NOMBRE DEL PROPIETARIO:%s\n MODELO DEL AUTO:%s\n PLACAS DEL AUTO:%d\n NUMERO DE ESTACIONAMIENTO:%d\n \n", aux->nombre,aux->modelo,aux->placas,aux->estacionamiento);
aux=aux->sig;
}
}
getch();
}


void desacolar(){
struct cola *aux;
struct cola *aux1;
int cont;
aux=princ;
aux1=princ;
cont=0;
while(aux!=NULL){
if(aux->placas==aux1->placas){
if(cont==0){
princ=princ->sig;
}
}
aux=aux->sig;
aux1=aux;
cont=1;
}
}


main(){
int opc;
do{
printf("\n\n\n\t\tREGISTRO DE PERSONAS ***RESTAURANTE UPVM***\t\t\t\t\n");
printf("\n\t\t\t1. INGRESAR DATOS A LA COLA\n\t\t\t2. MOSTRAR DATOS DE LA COLA\n\t\t\t3. RETIRAR DATOS EN LA COLA\n\t\t\t4. SALIR\n\t\t\t");
scanf("%d", &opc);
system("cls");
switch (opc){
case 1:
acolar();
system("cls");
break;
case 2:
mostrar();
getch();
system("cls");
break;
case 3:
desacolar();
break;
default:
printf("SALIR DEL SISTEMA\n");
break;
}
}while(opc!=4);
}
