#include <stdio.h>

#include <iostream>
#include <string>
void procesar_venta();
int main() {
  int numero_factura = 0;
  int cedula = 0;
  char nombre_comprador[20];
  int menu = 0;
  int localidad = 0;
  int cantidad_asientos = 0;
  double precio_entrada = 0;
  double precio_final = 0;

  // Variables para estadísticas
  int totalEntradasSol = 0;
  int totalEntradasSombra = 0;
  int totalEntradasPreferencial = 0;
  int acumuladoSol = 0;
  int acumuladoSombra = 0;
  int acumuladoPreferencial = 0;

  while (menu != 2) {
    printf("para salir del menu presione 2 \n");
    printf("para seguir con la compra, presione 1");
    scanf("%d", &menu);
    if (menu == 1) {
      printf("Digite el numero de factura: ");
      scanf("%d", &numero_factura);
      printf("Digite el numero de cedula: ");
      scanf("%d", &cedula);
      printf("Digite el nombre del comprador: ");
      scanf("%s", nombre_comprador);
      printf(
          "digite la localidad deseada 1- Sol Norte/Sur  2- Sombra "
          "Este/Oeste  3-Preferencial");
      scanf("%d", &localidad);
      printf("cuantas entradas desea comprar? \n Maximo se pueden 4!");
      scanf("%d", &cantidad_asientos);
      if (cantidad_asientos > 4) {
        printf("ha alcanzado el numero de entradas validas");
      } else {
        printf("La entrada Sol este/oeste tiene un precio de: 10500");
        printf("La entrada Sombra Este/Oeste tiene un precio de: 20500");
        printf("la entrada de la zona Preferencial es de: 25500");
        if (localidad == 1) {
          totalEntradasSol += cantidad_asientos;
          precio_entrada = 10500;
          acumuladoSol += cantidad_asientos * precio_entrada;
        } else if (localidad == 2) {
          precio_entrada = 20500;
          totalEntradasSombra += cantidad_asientos;
          acumuladoSombra += cantidad_asientos * precio_entrada;
        } else {
          precio_entrada = 25500;
          totalEntradasPreferencial += cantidad_asientos;
          acumuladoPreferencial += cantidad_asientos * precio_entrada;
        }

        printf("el total seria: %lf", precio_entrada * cantidad_asientos);
        precio_final =
            precio_entrada * cantidad_asientos + 1000 * cantidad_asientos;
        printf("los cargos por servicios serian de:%d",
               1000 * cantidad_asientos);
        printf("el precio total de las entradas seria %lf", precio_final);
      }
    } else if (menu == 2) {
      printf("Gracias por la compra, vuelta pronto!");
      printf("el total de entradas Sol es de: %d", totalEntradasSol);
      printf("el total de entradas sombra es de: %d", totalEntradasSol);
      printf("el total de entradas Preferencial es de: %d",
             totalEntradasPreferencial);
      printf("el acumulado de sol es de: %d", acumuladoSol);
      printf("el acumulado de sombra es de: %d", acumuladoSombra);
      printf("el acumulado de preferencial es de: %d", acumuladoPreferencial);
    } else {
      printf("digite un numero valido");
    }
  }
}