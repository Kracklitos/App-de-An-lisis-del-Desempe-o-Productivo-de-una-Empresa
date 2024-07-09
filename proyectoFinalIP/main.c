#include <stdio.h>
#include "Interface/menu.h"
#include "Logic/data.h"
#include "Interface/Salidas.h"

int main(void)
{
  DatosProductos product[5];
  Presentacion();
  menu(product);
  return 0;
}
