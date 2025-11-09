#include "Producto.h"
#include <string.h>

// Constructor
void crearProducto(Producto *p, int cod, const char *fecha, double peso, double largo, double ancho, int cod_calidad) {
    p->cod_producto = cod;
    strncpy(p->fecha_produccion, fecha, 8);
    p->fecha_produccion[8]='\0';
    p->peso = peso;
    p->largo = largo;
    p->ancho = ancho;
    p->cod_calidad = cod_calidad;
}

// Modificadores
void modCod(Producto *p, int cod){ p->cod_producto = cod; }
void modFecha(Producto *p, const char *fecha){ strncpy(p->fecha_produccion, fecha, 8); p->fecha_produccion[8]='\0'; }
void modPeso(Producto *p, double peso){ p->peso = peso; }
void modLargo(Producto *p, double largo){ p->largo = largo; }
void modAncho(Producto *p, double ancho){ p->ancho = ancho; }
void modCalidad(Producto *p, int calidad){ p->cod_calidad = calidad; }

// Consultores
int verCod(Producto *p){ return p->cod_producto; }
char* verFecha(Producto *p){ return p->fecha_produccion; }
double verPeso(Producto *p){ return p->peso; }
double verLargo(Producto *p){ return p->largo; }
double verAncho(Producto *p){ return p->ancho; }
int verCalidad(Producto *p){ return p->cod_calidad; }
