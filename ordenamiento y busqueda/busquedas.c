#include "busquedas.h"

// -------------------------------
// Busqueda Secuencial
// -------------------------------
int busqueda_secuencial(const Data arr[], size_t n, int clave) {
    for (size_t i = 0; i < n; i++) {
        if (arr[i].valor == clave)
            return (int)i;
    }
    return -1;
}

// -------------------------------
// Busqueda Binaria
// -------------------------------
int busqueda_binaria(const Data arr[], size_t n, int clave) {
    int low = 0;
    int high = (int)n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid].valor == clave)
            return mid;
        else if (arr[mid].valor < clave)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // No encontrado
}