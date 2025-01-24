#define MAX_ZONAS 5
#define MAX_DIAS 30
#define LIMITE_PM25 25.0

typedef struct {
    char nombre[50];
    float nivelActual;
    float prediccion;
    float datosHistoricos[MAX_DIAS];
} Zona;

void inicializarZonas(Zona zonas[]);
void cargarDatos(Zona zonas[]);
void guardarDatos(Zona zonas[]);
void calcularPromedios(Zona zonas[]);
void predecirContaminacion(Zona zonas[]);
void emitirAlertas(Zona zonas[]);
void generarRecomendaciones(Zona zonas[]);
void mostrarDatos(Zona zonas[]);
