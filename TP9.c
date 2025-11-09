#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*==============================================
PILA (LIFO)
==============================================*/
typedef struct Elem {
    char dato;
    struct Elem* psig;
} Elem;

typedef Elem* Pila;

// Crear pila
void crearPila(Pila *p) {
    *p = NULL;
}

// Apilar
void apilar(Pila *p, char ele) {
    Elem* nuevo = (Elem*)malloc(sizeof(Elem));
    nuevo->dato = ele;
    nuevo->psig = *p;
    *p = nuevo;
}

// Desapilar
void desapilar(Pila *p, char *ele) {
    if(*p == NULL) return;
    Elem* aux = *p;
    *ele = aux->dato;
    *p = aux->psig;
    free(aux);
}

// Verificar si pila está vacía
int esVaciaPila(Pila p) {
    return p == NULL;
}

// Imprimir palabra invertida usando pila
void invertirPalabra() {
    Pila p;
    crearPila(&p);
    char letra;
    printf("Ingrese letras de la palabra (espacio para terminar): ");
    while(scanf(" %c",&letra) && letra != ' ') {
        apilar(&p, letra);
    }

    printf("Palabra invertida: ");
    while(!esVaciaPila(p)) {
        desapilar(&p, &letra);
        printf("%c", letra);
    }
    printf("\n");
}

// Palíndromo usando pila
void verificarPalindromo() {
    Pila p;
    crearPila(&p);
    char palabra[100];
    printf("Ingrese palabra: ");
    scanf("%s", palabra);
    int n = strlen(palabra);

    for(int i=0;i<n;i++) apilar(&p, palabra[i]);

    int esPal = 1;
    for(int i=0;i<n;i++){
        char letra;
        desapilar(&p, &letra);
        if(letra != palabra[i]){
            esPal = 0;
            break;
        }
    }
    if(esPal) printf("La palabra es palindromo.\n");
    else printf("No es palindromo.\n");
}

// Camino de ida y vuelta
void caminoIdaVuelta() {
    Pila p;
    crearPila(&p);
    char pueblo[50];
    printf("Ingrese pueblos por donde pasa (zzz para terminar):\n");
    while(1){
        scanf("%s", pueblo);
        if(strcmp(pueblo,"zzz")==0) break;
        apilar(&p, pueblo[0]); // guardamos primera letra por simplicidad
    }
    printf("Camino de ida: ");
    Pila aux = p;
    while(aux){
        printf("%c ", aux->dato);
        aux = aux->psig;
    }
    printf("\nCamino de vuelta: ");
    while(!esVaciaPila(p)){
        char letra;
        desapilar(&p, &letra);
        printf("%c ", letra);
    }
    printf("\n");
}

// Balanceo de paréntesis
void balanceoParentesis() {
    char cadena[100];
    printf("Ingrese cadena: ");
    scanf(" %99[^\n]", cadena);
    Pila p;
    crearPila(&p);
    int error = 0;

    for(int i=0; i<strlen(cadena); i++){
        char c = cadena[i];
        if(c=='(' || c=='[') apilar(&p,c);
        else if(c==')'){
            char tope;
            if(esVaciaPila(p)){ error=1; break; }
            desapilar(&p,&tope);
            if(tope!='('){ error=1; break; }
        }
        else if(c==']'){
            char tope;
            if(esVaciaPila(p)){ error=1; break; }
            desapilar(&p,&tope);
            if(tope!='['){ error=1; break; }
        }
    }

    if(!esVaciaPila(p)) error=1;

    if(error) printf("Error: simbolos no balanceados.\n");
    else printf("Los simbolos estan balanceados.\n");
}

// Almacén de contenedores
void almacenContenedores() {
    Pila pilaAlmacen, pilaAux;
    crearPila(&pilaAlmacen);
    crearPila(&pilaAux);
    int n;
    printf("Cantidad de contenedores a apilar: "); scanf("%d",&n);
    for(int i=1;i<=n;i++) apilar(&pilaAlmacen,i);

    int retirar;
    printf("Ingrese contenedor a retirar: "); scanf("%d",&retirar);

    // Sacar contenedores hasta encontrar
    char c;
    while(!esVaciaPila(pilaAlmacen)){
        char tope;
        desapilar(&pilaAlmacen, &tope);
        if(tope == retirar) break;
        apilar(&pilaAux, tope);
    }

    // Regresar contenedores
    while(!esVaciaPila(pilaAux)){
        char tope;
        desapilar(&pilaAux,&tope);
        apilar(&pilaAlmacen,tope);
    }

    printf("Contenedores restantes en pila: ");
    while(!esVaciaPila(pilaAlmacen)){
        char tope;
        desapilar(&pilaAlmacen,&tope);
        printf("%d ", tope);
    }
    printf("\n");
}

/*==============================================
COLA (FIFO)
==============================================*/
typedef struct NodoCola {
    char dato[50];
    char obra[5];
    struct NodoCola* psig;
} NodoCola;

typedef struct {
    NodoCola *pin, *pfin;
} Cola;

void crearCola(Cola *c){
    c->pin = c->pfin = NULL;
}

void encolar(Cola *c, char* ele, char* os){
    NodoCola* nuevo = (NodoCola*) malloc(sizeof(NodoCola));
    strcpy(nuevo->dato, ele);
    strcpy(nuevo->obra, os);
    nuevo->psig = NULL;
    if(c->pin == NULL) c->pin = nuevo;
    else c->pfin->psig = nuevo;
    c->pfin = nuevo;
}

void desencolar(Cola *c, char* ele, char* os){
    if(c->pin==NULL) return;
    NodoCola* aux = c->pin;
    strcpy(ele, aux->dato);
    strcpy(os, aux->obra);
    c->pin = aux->psig;
    if(c->pin==NULL) c->pfin=NULL;
    free(aux);
}

int esVaciaCola(Cola c){
    return c.pin==NULL;
}

// Pacientes con obra social
void pacientesObraSocial(){
    Cola co;
    crearCola(&co);
    char nom[50], obsoc[5];
    printf("Ingrese pacientes (zzz para terminar):\n");
    while(1){
        printf("Nombre: "); scanf(" %49[^\n]",nom);
        if(strcmp(nom,"zzz")==0) break;
        printf("Obra social (si/no): "); scanf(" %4s", obsoc);
        encolar(&co, nom, obsoc);
    }
    int c=0;
    char n[50], o[5];
    while(!esVaciaCola(co)){
        desencolar(&co, n, o);
        if(strcmp(o,"si")==0) c++;
    }
    printf("Hay %d pacientes con obra social\n", c);
}

// Cola hombres y mujeres
void separarColaHombresMujeres(){
    Cola original; crearCola(&original);
    Cola hombres; crearCola(&hombres);
    Cola mujeres; crearCola(&mujeres);

    char nombre[50], genero[10];
    printf("Ingrese personas y genero (zzz para terminar):\n");
    while(1){
        printf("Nombre: "); scanf(" %49[^\n]",nombre);
        if(strcmp(nombre,"zzz")==0) break;
        printf("Genero (H/M): "); scanf(" %9s", genero);
        encolar(&original, nombre, genero);
    }

    char n[50], g[10];
    while(!esVaciaCola(original)){
        desencolar(&original, n, g);
        if(g[0]=='H') encolar(&hombres,n,g);
        else encolar(&mujeres,n,g);
    }

    printf("Cola Hombres:\n");
    while(!esVaciaCola(hombres)){
        desencolar(&hombres,n,g);
        printf("%s ", n);
    }
    printf("\nCola Mujeres:\n");
    while(!esVaciaCola(mujeres)){
        desencolar(&mujeres,n,g);
        printf("%s ", n);
    }
    printf("\n");
}

// Cola con prioridad (1=alta,3=baja)
typedef struct NodoPrior {
    char dato[50];
    int prioridad;
    struct NodoPrior* psig;
} NodoPrior;

typedef struct {
    NodoPrior* inicio;
} ColaPrior;

void crearColaPrior(ColaPrior* c){ c->inicio=NULL; }

void encolarPrior(ColaPrior* c, char* ele, int prioridad){
    NodoPrior* nuevo = (NodoPrior*) malloc(sizeof(NodoPrior));
    strcpy(nuevo->dato,ele); nuevo->prioridad=prioridad;
    nuevo->psig=NULL;

    if(c->inicio==NULL || c->inicio->prioridad>prioridad){
        nuevo->psig=c->inicio;
        c->inicio=nuevo;
        return;
    }

    NodoPrior* aux=c->inicio;
    while(aux->psig && aux->psig->prioridad<=prioridad) aux=aux->psig;
    nuevo->psig=aux->psig;
    aux->psig=nuevo;
}

void mostrarColaPrior(ColaPrior c){
    NodoPrior* aux=c.inicio;
    printf("Cola con prioridad: ");
    while(aux){
        printf("%s(p%d) ", aux->dato, aux->prioridad);
        aux=aux->psig;
    }
    printf("\n");
}

// Cola con reingreso
void colaConReingreso(){
    Cola original; crearCola(&original);
    char nombre[50], ticket[5];
    printf("Ingrese personas y ticket(si/no) (zzz para terminar):\n");
    while(1){
        printf("Nombre: "); scanf(" %49[^\n]",nombre);
        if(strcmp(nombre,"zzz")==0) break;
        printf("Tiene ticket (si/no): "); scanf(" %4s", ticket);
        encolar(&original,nombre,ticket);
    }
    Cola final; crearCola(&final);
    char n[50], t[5];
    while(!esVaciaCola(original)){
        desencolar(&original,n,t);
        if(strcmp(t,"si")==0) encolar(&final,n,t);
    }
    printf("Cola final (solo con ticket):\n");
    while(!esVaciaCola(final)){
        desencolar(&final,n,t);
        printf("%s ", n);
    }
    printf("\n");
}

/*==============================================
PROGRAMA PRINCIPAL
==============================================*/
int main() {
    printf("=== TP9 Pilas y Colas Completas ===\n\n");

    printf("\n--- Ejercicio pila: palabra invertida ---\n");
    invertirPalabra();

    printf("\n--- Ejercicio pila: palindromo ---\n");
    verificarPalindromo();

    printf("\n--- Ejercicio pila: camino de ida y vuelta ---\n");
    caminoIdaVuelta();

    printf("\n--- Ejercicio pila: balance de parentesis ---\n");
    balanceoParentesis();

    printf("\n--- Ejercicio pila: almacen contenedores ---\n");
    almacenContenedores();

    printf("\n--- Ejercicio cola: pacientes con obra social ---\n");
    pacientesObraSocial();

    printf("\n--- Ejercicio cola: separar hombres y mujeres ---\n");
    separarColaHombresMujeres();

    printf("\n--- Ejercicio cola: cola con prioridad ---\n");
    ColaPrior cp; crearColaPrior(&cp);
    encolarPrior(&cp,"Cliente1",2);
    encolarPrior(&cp,"Cliente2",1);
    encolarPrior(&cp,"Cliente3",3);
    mostrarColaPrior(cp);

    printf("\n--- Ejercicio cola: cola con reingreso ---\n");
    colaConReingreso();

    return 0;
}