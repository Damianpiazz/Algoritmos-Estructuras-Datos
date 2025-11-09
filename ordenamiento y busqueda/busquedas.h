#ifndef BUSQUEDAS_H
#define BUSQUEDAS_H

#include <stddef.h> // Para size_t

// -------------------------------
// Tipos de datos
// -------------------------------
typedef struct {
    int valor;
} Data;

// -------------------------------
// Prototipos de funciones
// -------------------------------

// Busqueda Secuencial
// Retorna indice del elemento si se encuentra, -1 si no
int busqueda_secuencial(const Data arr[], size_t n, int clave);

// Busqueda Binaria
// Retorna indice del elemento si se encuentra, -1 si no
// Requiere arreglo ordenado
int busqueda_binaria(const Data arr[], size_t n, int clave);

#endif