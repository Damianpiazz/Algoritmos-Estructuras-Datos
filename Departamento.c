#include "Departamento.h"
#include <string.h>
#include <stdio.h>

void crearDepartamento(Departamento *d, int cod, const char *ubicacion, int capacidad, double precio_diario, int internet, int tv, const char *estado){
    d->cod_depto = cod;
    strncpy(d->ubicacion, ubicacion,30);
    d->capacidad = capacidad;
    d->precio_diario = precio_diario;
    d->internet = internet;
    d->tv = tv;
    strncpy(d->estado, estado,20);
}

void modEstado(Departamento *d, const char *estado){ strncpy(d->estado, estado,20); }

int disponible(Departamento *d){ return strcmp(d->estado,"Libre")==0; }

double calcularPrecio(Departamento *d, int dias){ return d->precio_diario*dias; }

void verDepartamento(Departamento *d){
    printf("Depto: %d, Ubicacion: %s, Capacidad: %d, Precio: %.2lf, Internet: %s, TV: %s, Estado: %s\n",
        d->cod_depto, d->ubicacion, d->capacidad, d->precio_diario,
        d->internet?"Si":"No", d->tv?"Si":"No", d->estado);
}
