#include "funciones.h"
#include <stdio.h>

void menu() {
    printf("\nMenu de opciones:\n");
    printf("1. Ver datos actuales\n");
    printf("2. Calcular promedios historicos\n");
    printf("3. Predecir niveles de contaminacion\n");
    printf("4. Emitir alertas\n");
    printf("5. Generar recomendaciones\n");
    printf("6. Guardar datos en archivo\n");
    printf("7. Cargar datos desde archivo\n");
    printf("8. Salir\n");
    printf("Seleccione una opcion: ");
}

int main() {
    Zona zonas[MAX_ZONAS];
    int opcion;

    // Inicializar las zonas con datos predefinidos
    inicializarZonas(zonas);

    do {
        menu();
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                mostrarDatos(zonas);
                break;
            case 2:
                calcularPromedios(zonas);
                break;
            case 3:
                predecirContaminacion(zonas);
                break;
            case 4:
                predecirContaminacion(zonas); // Asegurarse de predecir antes de emitir alertas
                emitirAlertas(zonas);
                break;
            case 5:
                predecirContaminacion(zonas); // Asegurarse de predecir antes de generar recomendaciones
                generarRecomendaciones(zonas);
                break;
            case 6:
                guardarDatos(zonas);
                printf("Datos guardados correctamente.\n");
                break;
            case 7:
                cargarDatos(zonas);
                printf("Datos cargados correctamente.\n");
                break;
            case 8:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion invalida. Por favor, intente de nuevo.\n");
        }
    } while (opcion != 8);

    return 0;
}