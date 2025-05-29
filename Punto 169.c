// Ejercicio integrador punto 169

#include <stdio.h>

#define LIMITE 25000.0

void mostrar_menu() {
    printf("\nCONTROL DE GASTOS\n");
    printf("===================\n");
    printf("1. Ingresos\n");
    printf("2. Gastos\n");
    printf("3. Salida\n");
    printf("===================\n");
}

int leer_opcion() {
    int opcion;
    printf("Seleccione una opción (1-3): ");
    scanf("%d", &opcion);
    return opcion;
}

float ingresos(float saldo) {
    float ingreso;
    printf("Ingrese el monto del ingreso: $");
    scanf("%f", &ingreso);
    
    if (ingreso < 0) {
        printf("El ingreso no puede ser negativo.\n");
    } else if (ingreso > LIMITE) {
        printf("El ingreso no puede exceder $25,000.\n");
    } else {
        saldo += ingreso;
    }

    return saldo;
}

float gastos(float saldo) {
    float gasto;
    printf("Ingrese el monto del gasto: $");
    scanf("%f", &gasto);
    
    if (gasto < 0) {
        printf("El gasto no puede ser negativo.\n");
    } else if (gasto > LIMITE) {
        printf("El gasto no puede ser mayor a $25,000.\n");
    } else if (gasto > saldo) {
        printf("El gasto no puede exceder el saldo actual.\n");
    } else {
        saldo -= gasto;
    }

    return saldo;
}

int main() {
    float saldo = 0.0;
    int opcion;

    do {
        mostrar_menu();
        opcion = leer_opcion();

        switch (opcion) {
            case 1:
                saldo = ingresos(saldo);
                break;
            case 2:
                saldo = gastos(saldo);
                break;
            case 3:
                printf("Saldo final: $%.2f\n", saldo);
                printf("¡Hasta luego!\n");
                break;
            default:
                printf("Opción inválida. Intente de nuevo.\n");
        }

    } while (opcion != 3);

    return 0;
}
