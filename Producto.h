#ifndef PRODUCTO_H
#define PRODUCTO_H

typedef struct {
    int cod_producto;
    char fecha_produccion[9];
    double peso;
    double largo;
    double ancho;
    int cod_calidad;
} Producto;

// Constructor
void crearProducto(Producto *p, int cod, const char *fecha, double peso, double largo, double ancho, int cod_calidad);

// Modificadores
void modCod(Producto *p, int cod);
void modFecha(Producto *p, const char *fecha);
void modPeso(Producto *p, double peso);
void modLargo(Producto *p, double largo);
void modAncho(Producto *p, double ancho);
void modCalidad(Producto *p, int calidad);

// Consultores
int verCod(Producto *p);
char* verFecha(Producto *p);
double verPeso(Producto *p);
double verLargo(Producto *p);
double verAncho(Producto *p);
int verCalidad(Producto *p);

#endif
