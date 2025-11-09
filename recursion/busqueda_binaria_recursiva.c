#include <stdio.h>

int busquedaBinaria(int arr[], int low, int high, int x) {
    if (low > high) return -1; // Caso base: elemento no encontrado

    int mid = low + (high - low) / 2;

    if (arr[mid] == x) return mid; // Caso base: elemento encontrado
    else if (arr[mid] < x)
        return busquedaBinaria(arr, mid + 1, high, x); // Mitad derecha
    else
        return busquedaBinaria(arr, low, mid - 1, x); // Mitad izquierda
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 7;
    int index = busquedaBinaria(arr, 0, n-1, x);
    if (index != -1)
        printf("Elemento %d encontrado en la posición %d\n", x, index);
    else
        printf("Elemento %d no encontrado\n", x);
    return 0;
}