#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#include "Interface/Entradas.h"
#include "Logic/logic.h"
#include "Interface/Salidas.h"
#include "Logic/data.h"

/*Menu principal de la aplicacion*/
void menu(DatosProductos product[]) {
    char resp;
    int cantProductos = 5;
    bool datos = false;
    do {
        system("cls");
        printf("   Opciones de la aplicaci\242n:\n");
        printf("1. Inicializar datos \n");
        printf("2. Mostrar datos \n");
        printf("3. Otras Opciones \n");
        printf("4. Terminar \n");
        resp = getche();
        printf("\n");
        switch (resp) {
        case '1':
            if(datos){
                printf("Los datos ya han sido inicializados \n");
                system("pause");
            }
            else{
                datos = true;
                cantProductos =  menuEntrada(product);
            }
            break;
        case '2':
            if (datos){
                mostrarDatos(product, cantProductos);
                system("pause");
            }
            else {
                printf("Los datos no han sido inicializados \n");
                system("pause");
            }
            break;
        case '3':
            if (datos)
                menuOpciones(product, cantProductos);
            else {
                printf("Los datos no han sido inicializados \n");
                system("pause");
            }
            break;
        case '4':
            break;
        default:
            printf("Opci\242n err\242nea \n");
            system("pause");
        }
    }
    while (resp != '4');
}

/*Submenu de inicializacion de los datos*/
int menuEntrada(DatosProductos product[]) {
    char resp = 0;
    int cantProductos = 5;
    do {
        system("cls");
        printf("   Opciones disponibles para inicializar los datos \n");
        printf("1. Inicializar por teclado \n");
        printf("2. Inicializar por funci\242n predeterminada \n");
        resp = getche();
        printf("\n");

        switch (resp) {
        case '1':
            cantProductos = entrarCantidadProductos();
            entrarDatos(product, cantProductos);
            printf("Datos inicializados \n");
            system("pause");
            break;
        case '2':
            InicializarDatos(product);
            cantProductos = 5;
            printf("Datos inicializados \n");
            system("pause");
            break;
        default:
            printf("Opci\242n err\242nea \n");
            system("pause");
        }
    }
    while (resp < '1' || resp > '2');
    return cantProductos;
}

/*Submenu con las funcionalidades de la aplicacion*/
void menuOpciones(DatosProductos product[], int cantProductos){
    int resp = 0;
    do {
        system("cls");
        printf("   Datos \n");
        printf("1. Mostrar productos que superaron el plan anual a producir. \n");
        printf("2. Mostrar relaci\242n de venta e ingresos de determinado producto. \n");
        printf("3. Mostrar si el producto de mayor ganancia es del de mayor precio. \n");
        printf("4. Mostrar meses en que no se produjo determinado producto. \n");
        printf("5. Atr\240s \n");
        scanf("%d", &resp);
        printf("\n");
        switch (resp) {
        case 1:
            if (resp) {
                system("cls");
                MostrarCumplimientoPlan(product, cantProductos);
                system("pause");
            }
            else {
                printf("Los datos no han sido inicializados \n");
                system("pause");
            }
            break;
        case 2:
            if (resp){
                system("cls");
                MostrarIngresos (product, cantProductos);
                system("pause");
            }
            else {
                printf("Los datos no han sido inicializados \n");
                system("pause");
            }
            break;
        case 3:
            if (resp){
                system("cls");
                MostrarRelacion (product, cantProductos);
                system("pause");
            }
            else {
                printf("Los datos no han sido inicializados \n");
                system("pause");
            }
            break;
        case 4:
            if (resp) {
                system("cls");
                NoHuboProduccion (product, cantProductos);
                ListadoMeses();
                system("pause");
            }
            else{
                printf("No se han actualizado las ventas \n");
                system("pause");
            }
            break;
        case 5:
            break;
        default:
            printf("Opci\242n err\242nea \n");
            system("pause");
        }
    }
    while ( resp!=5 && resp!=0);
}

