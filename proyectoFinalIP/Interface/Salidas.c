#include <stdio.h>
#include "Logic/logic.h"
#include "Logic/data.h"

void mostrarDatos(DatosProductos product[], int cantProductos){
    int i;
    int j;
    for(i = 0; i < cantProductos; ++i) {
        printf("Nombre del producto: %s\t", product[i].nombre);
        printf("Precio de venta del producto: %2f\n", product[i].precioVenta);
        printf("Plan Anual del producto: %i\n", product[i].planAnual);
        printf("Producci\242n anual de este producto en cada mes: \n");
        for(j = 0; j < 12; ++j){
            printf("%i.\n",product[i].prodReal[j]);
        }
        printf("\n");
    }
}

void MostrarCumplimientoPlan(DatosProductos product[],int cantProductos){
    int i;
    for (i=0; i < cantProductos; i++){
        int suma = SumaProdReal (product, i);
        if (suma > product[i].planAnual)
           printf("Pudo superar el plan anual por producir, el producto %s\n",product[i].nombre);
    }
}

void ListadoMeses() {
    printf("LISTADO DE MESES\n");
    printf("1. Enero\n");
    printf("2. Febrero\n");
    printf("3. Marzo\n");
    printf("4. Abril\n");
    printf("5. Mayo\n");
    printf("6. Junio\n");
    printf("7. Julio\n");
    printf("8. Agosto\n");
    printf("9. Septiembre\n");
    printf("10. Octubre\n");
    printf("11. Noviembre\n");
    printf("12. Diciembre\n");
}

void NoHuboProduccion (DatosProductos product[], int cantProductos) {
    int i;
    int j;
    for(i = 0; i < cantProductos; ++i) {
        printf("El producto %s no fue producido en el mes:\n", product[i].nombre);
        for(j=0; j < 12; j++){
          if (product[i].prodReal[j] == 0){
              printf("%d\n", j+1);
          }
        }
         printf("\n");
    }
 }

void MostrarIngresos (DatosProductos product[], int cantProductos){
    int i;
    for(i = 0; i < cantProductos; ++i) {
        int suma = SumaProdReal (product, i);
        int ingresos = IngresosPorVenta(product, suma, cantProductos);
        printf("Del producto %s\t", product[i].nombre);
        printf("El ingreso por su venta anual fue de %d\n", ingresos);
        printf("\n");
    }
}

void MostrarRelacion (DatosProductos product[], int cantProductos){
    int mp = MayorPrecio (product, cantProductos);
    int mg = MayorGanancia (product, cantProductos);
    printf("Producto con mayor ganancia: %s\n", product[mg].nombre);
    printf("Producto con mayor precio: %s\n", product[mp].nombre);
    printf("\n");
    if (mp = mg)
        printf("El producto que report\242 mayor ganancia fue el de mayor precio.\n");
    else
        printf("El producto que report\242 mayor ganancia no fue el de mayor precio.\n");
}

void Presentacion(){
    printf("   BIENVENIDO a la aplicaci\242n!!! \n\n");
    printf("   En esta le va a ser posible analizar el desempe\244o productivo de la subsede DAILY\n   de SUCHEL CAMACHO, dedicada a la fabricaci\242n de productos para el aseo.\n\n");
    printf("   Para analizar mejor es recomendable trabajar con 5 productos.\n\n   Esperemos le sea de utilidad!\n\n");
    system("pause");
    system("cls");
}
