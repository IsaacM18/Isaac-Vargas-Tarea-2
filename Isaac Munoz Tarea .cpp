#include <cstring>
#include <iostream>

void ingresar_empleado();

int main() {
  // Variables de control
  int menu = 0;

  while (menu != 2) {
    printf("1. Ingresar empleado\n2.Salir\n\nDigite su opcion: ");
    scanf("%d", &menu);
    if (menu == 1) {
      ingresar_empleado();
    } else if (menu == 2) {
      puts("Vuelva pronto, Gracias!");
    } else {
      puts("Opcion invalida, digite de nuevo\n");
    }
  }
  return 0;
}

void ingresar_empleado() {
  // Variables de entrada estándar
  char nombre[20];
  int cedula = 0;
  int tipo_empleado = 0;
  double precio_x_hora = 0;
  int cant_horas = 0;

  // Variables de salida
  char tipo_empleado_string[20];
  double salario_ordinario = 0;
  double aumento = 0;
  double salario_bruto = 0;
  double deduccion_caja = 0;
  double salario_neto = 0;

  // Variables constantes
  const double deduccion_ley = 9.17;

  // Solicitar variables
  printf("Digite el nombre del empleado: ");
  scanf("%s", nombre);
  printf("Digite cedula: ");
  scanf("%d", &cedula);
  printf("Digite precio por hora de %s: ", nombre);
  scanf("%lf", &precio_x_hora);
  printf("Digite la cantidad de horas que trabajo %s: ", nombre);
  scanf("%d", &cant_horas);
  printf(
      "Digite el tipo de empleado (1: Operario 2: Tecnico 3: Profesional): ");
  scanf("%d", &tipo_empleado);

  // Calculo de resultados
  salario_ordinario = (precio_x_hora * cant_horas);
  if (tipo_empleado == 1) {
    strcpy(tipo_empleado_string, "Operario");
    aumento = 0.15;
  } else if (tipo_empleado == 2) {
    strcpy(tipo_empleado_string, "Tecnico");
    aumento = 0.10;
  } else {
    strcpy(tipo_empleado_string, "Profesional");
    aumento = 0.05;
  }
  salario_bruto = salario_ordinario + (salario_ordinario * aumento);
  deduccion_caja = salario_bruto * (deduccion_ley / 100);
  salario_neto = salario_bruto - deduccion_caja;

  // Mostrar resultados
  printf("Nombre del empleado (%s): %s\n", tipo_empleado_string, nombre);
  printf("Cedula de %s: %d\n", nombre, cedula);
  printf("Precio por hora: %lf\n", precio_x_hora);
  printf("Cantidad de horas trabajadas: %d\n", cant_horas);
  printf("Salario ordinario de %s: %lf\n", nombre, salario_ordinario);
  printf("Aumento del empleado: %lf%%\n", aumento * 100);
  printf("Salario bruto: %lf\n", salario_bruto);
  printf("Deduccion CCSS: %lf\n", deduccion_caja);
  printf("Salario neto de %s: %lf\n\n\n", nombre, salario_neto);
}