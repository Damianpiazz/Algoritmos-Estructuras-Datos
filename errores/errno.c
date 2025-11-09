#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    FILE *fp = fopen("archivo.txt", "r");
    if (!fp) {
        printf("Error al abrir archivo: %s\n", strerror(errno));
    } else {
        fclose(fp);
    }
    return 0;
}
