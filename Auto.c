#include "Auto.h"
#include <string.h>

void crearAuto(Auto *a, const char *patente, const char *marca, const char *modelo, int anio, double precio) {
    strncpy(a->patente, patente, 7); a->patente[7]='\0';
    strncpy(a->marca, marca, 30);
    strncpy(a->modelo, modelo, 30);
    a->anio = anio;
    a->precio = precio;
}

// Modificadores
void modMarca(Auto *a, const char *marca){ strncpy(a->marca, marca,30); }
void modModelo(Auto *a, const char *modelo){ strncpy(a->modelo, modelo,30); }
void modAnio(Auto *a, int anio){ a->anio = anio; }
void modPatente(Auto *a, const char *patente){ strncpy(a->patente, patente,7); a->patente[7]='\0'; }
void modPrecio(Auto *a, double precio){ a->precio = precio; }

// Consultores
char* verMarca(Auto *a){ return a->marca; }
char* verModelo(Auto *a){ return a->modelo; }
char* verPatente(Auto *a){ return a->patente; }
int verAnio(Auto *a){ return a->anio; }
double verPrecio(Auto *a){ return a->precio; }
