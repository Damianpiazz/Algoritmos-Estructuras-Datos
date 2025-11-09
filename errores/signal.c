#include <stdio.h>
#include <signal.h>

void manejador_div0(int sig) {
    printf("Error: División por cero detectada\n");
}

int main() {
    signal(SIGFPE, manejador_div0);
    int a = 1 / 0; // dispara SIGFPE
    return 0;
}
