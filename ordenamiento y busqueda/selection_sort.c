// selection_sort.c
#include <stdio.h>

// -------------------------------
// Estructuras
// -------------------------------

typedef struct {
    int valor;
} Data;

typedef struct Nodo {
    int valor;
    struct Nodo* siguiente;
} Nodo;

// -------------------------------
// Funcion Selection Sort para Vector
// -------------------------------
void selection_sort_vector(Data arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j].valor < arr[min_idx].valor) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            temp = arr[i].valor;
            arr[i].valor = arr[min_idx].valor;
            arr[min_idx].valor = temp;
        }
    }
}

// -------------------------------
// Funcion Selection Sort para Lista Enlazada
// -------------------------------
void selection_sort_lista(Nodo* cabeza) {
    Nodo* i;
    Nodo* j;
    int temp;

    for (i = cabeza; i != NULL; i = i->siguiente) {
        Nodo* min = i;
        for (j = i->siguiente; j != NULL; j = j->siguiente) {
            if (j->valor < min->valor) {
                min = j;
            }
        }
        if (min != i) {
            temp = i->valor;
            i->valor = min->valor;
            min->valor = temp;
        }
    }
}
