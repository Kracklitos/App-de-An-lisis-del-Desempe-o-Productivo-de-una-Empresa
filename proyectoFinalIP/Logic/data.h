#ifndef DATOS_H
#define DATOS_H

typedef struct {
    char nombre[25];
    float precioVenta;
    int planAnual;
    int prodReal[12];
} DatosProductos;

DatosProductos product[5];

#endif

