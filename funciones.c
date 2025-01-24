#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializarZonas(Zona zonas[]) {
    for (int i = 0; i < MAX_ZONAS; i++) {
        for (int j = 0; j < MAX_DIAS; j++) {
            zonas[i].datosHistoricos[j] = (float)(rand() % 50 + 10); // Valores aleatorios entre 10 y 50
        }
    }
}

void cargarDatos(Zona zonas[]) {
    FILE *archivo = fopen("datos_zonas.txt", "r");
    if (archivo) {
        for (int i = 0; i < MAX_ZONAS; i++) {
            fscanf(archivo, "%49s", zonas[i].nombre);
            fscanf(archivo, "%f", &zonas[i].nivelActual);
            for (int j = 0; j < MAX_DIAS; j++) {
                fscanf(archivo, "%f", &zonas[i].datosHistoricos[j]);
            }
        }
        fclose(archivo);
    }
}

void guardarDatos(Zona zonas[]) {
    FILE *archivo = fopen("datos_zonas.txt", "w");
    if (archivo) {
        for (int i = 0; i < MAX_ZONAS; i++) {
            fprintf(archivo, "%s %.2f ", zonas[i].nombre, zonas[i].nivelActual);
            for (int j = 0; j < MAX_DIAS; j++) {
                fprintf(archivo, "%.2f ", zonas[i].datosHistoricos[j]);
            }
            fprintf(archivo, "\n");
        }
        fclose(archivo);
    }
}

void calcularPromedios(Zona zonas[]) {
    for (int i = 0; i < MAX_ZONAS; i++) {
        float suma = 0.0;
        for (int j = 0; j < MAX_DIAS; j++) {
            suma += zonas[i].datosHistoricos[j];
        }
        float promedio = suma / MAX_DIAS;
        printf("%s: Promedio de PM2.5 en los ultimos 30 dias: %.2f\n", zonas[i].nombre, promedio);
    }
}

void predecirContaminacion(Zona zonas[]) {
    for (int i = 0; i < MAX_ZONAS; i++) {
        float suma = 0.0;
        int peso = MAX_DIAS;
        float divisor = 0.0;
        for (int j = MAX_DIAS - 1; j >= 0; j--) {
            suma += zonas[i].datosHistoricos[j] * peso;
            divisor += peso;
            peso--;
        }
        zonas[i].prediccion = suma / divisor;
        printf("%s: Prediccion de PM2.5 para las proximas 24 horas: %.2f\n", zonas[i].nombre, zonas[i].prediccion);
    }
}

void emitirAlertas(Zona zonas[]) {
    for (int i = 0; i < MAX_ZONAS; i++) {
        if (zonas[i].prediccion > LIMITE_PM25) {
            printf("ALERTA: %s superara el limite de PM2.5 (%.2f)\n", zonas[i].nombre, zonas[i].prediccion);
        }
    }
}

void generarRecomendaciones(Zona zonas[]) {
    for (int i = 0; i < MAX_ZONAS; i++) {
        if (zonas[i].prediccion > LIMITE_PM25) {
            printf("Recomendaciones para %s:\n", zonas[i].nombre);
            printf("- Reducir el trafico vehicular\n");
            printf("- Limitar actividades al aire libre\n");
            printf("- Considerar el cierre temporal de fuentes de contaminacion\n");
        }
    }
}

void mostrarDatos(Zona zonas[]) {
    for (int i = 0; i < MAX_ZONAS; i++) {
        printf("%s: Nivel actual: %.2f, Prediccion: %.2f\n", zonas[i].nombre, zonas[i].nivelActual, zonas[i].prediccion);
    }
}
