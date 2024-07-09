#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "Interface/menu.h"
#include "Interface/Salidas.h"
#include "Logic/logic.h"
#include "Logic/data.h"

int entrarCantidadProductos(){
    int cantProductos;
    do {
       system("cls");
       printf("Introduzca la cantidad de productos con los que desea trabajar (debe de estar entre 2 y 5).\n");
       do{
           fflush(stdin);
           if(scanf("%d", &cantProductos)!=1)
           {
               printf("Error en el tipo de dato.\nPrueba otra vez: ");
               cantProductos = 0;
           }
           printf("\n");
       }while(cantProductos == 0);
       if (cantProductos > 5 || cantProductos < 2 ){
           printf("ERROR. La cantidad de productos debe de estar entre 2 y 5. \n");
           system("pause");
       }
     }while (cantProductos > 5 || cantProductos < 2);
     return cantProductos;
 }

void entrarProdReal (DatosProductos product[], int i, int j){
    int prodReal;
    do {
        printf("Introduzca la produccion real (Esto se repite para los 12 meses de la aplicaci\242n).\n");
        do{
            fflush(stdin);
            if(scanf("%d", &prodReal)!=1)
            {
                printf("Error en el tipo de dato.\nPrueba otra vez: ");
                prodReal = 0;
            }

            else if(prodReal < 0)
            {
                printf("Error en el signo.\nPrueba otra vez: ");
                prodReal = 0;
            }
            printf("\n");
        }while(prodReal == 0);
        if (prodReal <= 0){
            printf("La produccion real debe ser mayor o igual que 0. \n");
            system("pause");
        }
        else
            product[i].prodReal[j] = prodReal;
    }while (prodReal <= 0);
}

void entrarPlanAnual (DatosProductos product[], int i){
    int planAnual;
    do {
        fflush(stdin);
        system("cls");
        printf("Introduzca el plan anual de producci\242n (debe de estar entre 500 y 2000).\n");
        do{
            fflush(stdin);
            if(scanf("%d", &planAnual)!=1)
            {
                printf("Error en el tipo de dato.\nPrueba otra vez: ");
                planAnual = 0;
            }

            else if(planAnual < 0)
            {
                printf("Error en el signo.\nPrueba otra vez: ");
                planAnual = 0;
            }
            printf("\n");
        }while(planAnual == 0);
        if (planAnual > 2000 || planAnual < 500){
            printf("El plan anual de producci\242n debe de estar entre 500 y 2000.\n");
            system("pause");
        }
        else
            product[i].planAnual = planAnual;
    }while (planAnual > 2000 || planAnual < 500);
}

void entrarPrecioVenta (DatosProductos product[], int i){
    float precioVenta;
    do {
        fflush(stdin);
        system("cls");
        printf("Introduzca el precio de venta del producto (debe de estar entre 0.50 y 10.00).\n");
        do{
            fflush(stdin);
            if (scanf("%f", &precioVenta) < 0)
            {
                printf("Error en el signo.\nPrueba otra vez: ");
                precioVenta = 0;
            }
            printf("\n");
        }while(precioVenta == 0);
        if (precioVenta > 10.00 || precioVenta < 0.50){
            printf("El precio de venta del producto debe de estar entre 0.50 y 10.00.\n");
            system("pause");
        }
        else
            product[i].precioVenta = precioVenta;
    }while (precioVenta > 10.00 || precioVenta < 0.50);
}

void Nombre(DatosProductos product[], int i){
    char nom[50];
    int valid=0;
    do{
        printf("Introduzca el nombre del producto: ");
        fflush(stdin);
        gets(nom);
        valid=solo_letras(nom);
        if(valid==false)
            printf("El nombre es incorrecto\n");
     }while(valid==false);
    strcpy(product[i].nombre,nom);
}

   void entrarDatos(DatosProductos product[], int cantProductos){
       int i;
       int j;
       for(i = 0; i < cantProductos ; ++i){
           system("cls");
           Nombre(product, i);
           entrarPrecioVenta(product, i);
           entrarPlanAnual(product, i);
           system("cls");
           for(j = 0; j < 12; ++j){
               entrarProdReal(product,i, j);
           }
       }
   }

