#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

typedef struct {
    int cod_depto;
    char ubicacion[30];
    int capacidad;
    double precio_diario;
    int internet;
    int tv;
    char estado[20];
} Departamento;

// Constructor
void crearDepartamento(Departamento *d, int cod, const char *ubicacion, int capacidad, double precio_diario, int internet, int tv, const char *estado);

// Modificadores
void modEstado(Departamento *d, const char *estado);

// Consultores
int disponible(Departamento *d);
double calcularPrecio(Departamento *d, int dias);
void verDepartamento(Departamento *d);

#endif
