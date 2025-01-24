#include "funciones.h"
#include <stdio.h>

void menu() {
    printf("\nMGTH - Monitoreo de Gases Toxicos Historicos\n");
    printf("Menu de opciones:\n");
    printf("1. Ver datos actuales\n");
    printf("2. Calcular promedios historicos\n");
    printf("3. Predecir niveles de contaminacion\n");
    printf("4. Emitir alertas\n");
    printf("5. Generar recomendaciones\n");
    printf("6. Actualizar datos manualmente\n");
    printf("7. Guardar datos en archivo\n");
    printf("8. Cargar datos desde archivo\n");
    printf("9. Salir\n");
    printf("Seleccione una opcion: ");
}
void actualizarDatos(Zona zonas[]) {
    int opcionZona;
    float nuevoNivel;

    printf("Seleccione la zona a actualizar:\n");
    for (int i = 0; i < MAX_ZONAS; i++) {
        printf("%d. %s\n", i + 1, zonas[i].nombre);
    }
    printf("Seleccione una opcion (1-%d): ", MAX_ZONAS);
    scanf("%d", &opcionZona);

    if (opcionZona < 1 || opcionZona > MAX_ZONAS) {
        printf("Opcion invalida.\n");
        return;
    }

    printf("Ingrese el nuevo nivel de contaminacion (0-500): ");
    scanf("%f", &nuevoNivel);

    if (nuevoNivel < 0 || nuevoNivel > 500) {
        printf("Nivel invalido. Debe estar entre 0 y 500.\n");
        return;
    }

    zonas[opcionZona - 1].nivelActual = nuevoNivel;
    printf("Nivel actualizado para %s: %.2f\n", zonas[opcionZona - 1].nombre, nuevoNivel);
}

int main() {
    Zona zonas[MAX_ZONAS] = {
        {"CHIMBORAZO", 0.0, 0.0, {0}},
        {"TUNGURAHUA", 0.0, 0.0, {0}},
        {"AZUAY", 0.0, 0.0, {0}},
        {"EL_AEROPUERTO", 0.0, 0.0, {0}},
        {"ZONA_5", 0.0, 0.0, {0}} // Nombre generico para la quinta zona
    };
    int opcion;

    // Inicializar datos historicos aleatorios
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
                actualizarDatos(zonas);
                break;
            case 7:
                guardarDatos(zonas);
                printf("Datos guardados correctamente.\n");
                break;
            case 8:
                cargarDatos(zonas);
                printf("Datos cargados correctamente.\n");
                break;
            case 9:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion invalida. Por favor, intente de nuevo.\n");
        }
    } while (opcion != 9);

    return 0;
}