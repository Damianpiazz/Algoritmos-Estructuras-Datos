#include <stdio.h>
#include <stdlib.h>

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
// Quick Sort para Vector
// -------------------------------
int partition_vector(Data arr[], int low, int high) {
    int pivot = arr[high].valor;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].valor <= pivot) {
            i++;
            Data temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    Data temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quick_sort_vector(Data arr[], int low, int high) {
    if (low < high) {
        int pi = partition_vector(arr, low, high);
        quick_sort_vector(arr, low, pi - 1);
        quick_sort_vector(arr, pi + 1, high);
    }
}

// -------------------------------
// Quick Sort para Lista Enlazada
// -------------------------------
Nodo* partition_lista(Nodo* head, Nodo** newHead, Nodo** newEnd) {
    Nodo* pivot = head;
    Nodo* prev = NULL;
    Nodo* cur = head;
    Nodo* tail = pivot;

    while (cur != NULL && cur != pivot) {
        if (cur->valor < pivot->valor) {
            if ((*newHead) == NULL)
                (*newHead) = cur;
            prev = cur;
            cur = cur->siguiente;
        } else {
            if (prev)
                prev->siguiente = cur->siguiente;
            Nodo* tmp = cur->siguiente;
            cur->siguiente = NULL;
            tail->siguiente = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if ((*newHead) == NULL)
        (*newHead) = pivot;

    (*newEnd) = tail;
    return pivot;
}

Nodo* quick_sort_recur_lista(Nodo* head, Nodo* end) {
    if (!head || head == end)
        return head;

    Nodo* newHead = NULL;
    Nodo* newEnd = NULL;

    Nodo* pivot = partition_lista(head, &newHead, &newEnd);

    if (newHead != pivot) {
        Nodo* temp = newHead;
        while (temp->siguiente != pivot)
            temp = temp->siguiente;
        temp->siguiente = NULL;

        newHead = quick_sort_recur_lista(newHead, temp);

        temp = newHead;
        while (temp->siguiente != NULL)
            temp = temp->siguiente;
        temp->siguiente = pivot;
    }

    pivot->siguiente = quick_sort_recur_lista(pivot->siguiente, newEnd);

    return newHead;
}

void quick_sort_lista(Nodo** headRef) {
    *headRef = quick_sort_recur_lista(*headRef, NULL);
}