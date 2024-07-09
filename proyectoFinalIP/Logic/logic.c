#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "Logic/data.h"

void InicializarDatos (DatosProductos product[]) {

   sprintf(product[0].nombre, "Jab\242n\n");
   product[0].precioVenta = 0.75;
   product[0].planAnual = 1500;
   product[0].prodReal[0] = 420;
   product[0].prodReal[1] = 100;
   product[0].prodReal[2] = 95;
   product[0].prodReal[3] = 0;
   product[0].prodReal[4] = 175;
   product[0].prodReal[5] = 600;
   product[0].prodReal[6] = 150;
   product[0].prodReal[7] = 0;
   product[0].prodReal[8] = 420;
   product[0].prodReal[9] = 0;
   product[0].prodReal[10] = 325;
   product[0].prodReal[11] = 460;

   sprintf(product[1].nombre, "Desodorante\n");
   product[1].precioVenta = 1.20;
   product[1].planAnual = 975;
   product[1].prodReal[0] = 250;
   product[1].prodReal[1] = 100;
   product[1].prodReal[2] = 50;
   product[1].prodReal[3] = 40;
   product[1].prodReal[4] = 0;
   product[1].prodReal[5] = 325;
   product[1].prodReal[6] = 385;
   product[1].prodReal[7] = 400;
   product[1].prodReal[8] = 80;
   product[1].prodReal[9] = 120;
   product[1].prodReal[10] = 95;
   product[1].prodReal[11] = 140;

   sprintf(product[2].nombre, "Shampoo\n");
   product[2].precioVenta = 3.25;
   product[2].planAnual = 700;
   product[2].prodReal[0] = 400;
   product[2].prodReal[1] = 50;
   product[2].prodReal[2] = 25;
   product[2].prodReal[3] = 25;
   product[2].prodReal[4] = 180;
   product[2].prodReal[5] = 40;
   product[2].prodReal[6] = 290;
   product[2].prodReal[7] = 360;
   product[2].prodReal[8] = 40;
   product[2].prodReal[9] = 95;
   product[2].prodReal[10] = 0;
   product[2].prodReal[11] = 95;

   sprintf(product[3].nombre, "Perfume\n");
   product[3].precioVenta = 7.80;
   product[3].planAnual = 1200;
   product[3].prodReal[0] = 360;
   product[3].prodReal[1] = 0;
   product[3].prodReal[2] = 135;
   product[3].prodReal[3] = 160;
   product[3].prodReal[4] = 140;
   product[3].prodReal[5] = 50;
   product[3].prodReal[6] = 50;
   product[3].prodReal[7] = 800;
   product[3].prodReal[8] = 75;
   product[3].prodReal[9] = 0;
   product[3].prodReal[10] = 0;
   product[3].prodReal[11] = 150;

   sprintf(product[4].nombre, "Acondicionador\n");
   product[4].precioVenta = 4.05;
   product[4].planAnual = 750;
   product[4].prodReal[0] = 400;
   product[4].prodReal[1] = 150;
   product[4].prodReal[2] = 175;
   product[4].prodReal[3] = 200;
   product[4].prodReal[4] = 0;
   product[4].prodReal[5] = 0;
   product[4].prodReal[6] = 25;
   product[4].prodReal[7] = 125;
   product[4].prodReal[8] = 0;
   product[4].prodReal[9] = 150;
   product[4].prodReal[10] = 95;
   product[4].prodReal[11] = 0;

}

int SumaProdReal (DatosProductos product[], int i){
    int suma = 0;
    int count = 0;
    int j;
        for (j=0; j < 12; j++){
            count = product[i].prodReal[j];
            suma += count;
        }
       return suma;
}

int IngresosPorVenta(DatosProductos product[], int suma, int cantProductos){
    int i;
    int ingresos;
    for (i=0; i < cantProductos; i++){
        ingresos = suma * product[i].precioVenta;
    }
    return ingresos;
}

int MayorGanancia (DatosProductos product[], int cantProductos){
    int maxgan = 0;
    int mg = 0;
    int i;
    for (i = 0; i < cantProductos; i++){
        int suma = SumaProdReal (product, i);
        if (suma > maxgan){
            maxgan = suma;
            mg = i;
        }
    }
    return mg;
}

int MayorPrecio (DatosProductos product[], int cantProductos){
    int maxpre = 0;
    int mp = 0;
    int i;
    for (i = 0; i < cantProductos; i++){
        if (product[i].precioVenta > maxpre){
            maxpre = product[i].precioVenta;
            mp = i;
        }
    }
    return mp;
}


bool solo_letras(char cadena[20]){
    int size,j=0;
    bool letra = true;

    size=strlen(cadena);
    if(size==0)
        letra = false;
    while(j<size&&letra==true){
        if(!isalpha(cadena[j]) && cadena[j]!=' '){
            letra=false;
        }
        else
            j++;
    }

    return letra;
}

