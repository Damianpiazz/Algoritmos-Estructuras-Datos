#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*==============================================
LISTAS SIMPLES: LIBROS
==============================================*/

typedef struct {
    char nombre[50];
    int codigo;
    char autor[50];
    char editorial[50];
    float precio;
    int stock;
} Libro;

typedef struct Nodo {
    Libro dato;
    struct Nodo* psig;
} Nodo;

typedef Nodo* Lista;

void crearLista(Lista *l){
    *l = NULL;
}

void insertar(Lista *l, Libro elem){
    Nodo* nuevo = (Nodo*) malloc(sizeof(Nodo));
    nuevo->dato = elem;
    nuevo->psig = *l;
    *l = nuevo;
}

Nodo* buscarLibro(Lista l, char* nombre){
    Nodo* aux = l;
    while(aux){
        if(strcmp(aux->dato.nombre,nombre)==0) return aux;
        aux=aux->psig;
    }
    return NULL;
}

void imprimirStockCero(Lista l){
    Nodo* aux=l;
    printf("\nLibros con stock 0:\n");
    while(aux){
        if(aux->dato.stock==0)
            printf("Codigo: %d - Editorial: %s - Nombre: %s\n",
                   aux->dato.codigo, aux->dato.editorial, aux->dato.nombre);
        aux = aux->psig;
    }
}

void simularLibros(Lista *l){
    char resp='s';
    while(resp=='s'){
        printf("Desea reponer libros? (s/n): ");
        scanf(" %c",&resp);
        if(resp!='s') break;
        char nombre[50];
        printf("Ingrese nombre del libro: ");
        scanf(" %49[^\n]",nombre);
        Nodo* actual = buscarLibro(*l,nombre);
        if(actual){
            int stocknue;
            printf("Ingrese stock comprado: ");
            scanf("%d",&stocknue);
            actual->dato.stock += stocknue;
        }else{
            Libro reg;
            strcpy(reg.nombre,nombre);
            printf("Ingrese codigo: "); scanf("%d",&reg.codigo);
            printf("Ingrese autor: "); scanf(" %49[^\n]",reg.autor);
            printf("Ingrese precio: "); scanf("%f",&reg.precio);
            printf("Ingrese editorial: "); scanf(" %49[^\n]",reg.editorial);
            printf("Ingrese stock: "); scanf("%d",&reg.stock);
            insertar(l,reg);
        }
    }
}

/*==============================================
LISTAS SIMPLES: NUMEROS
==============================================*/
typedef struct NodoInt {
    int dato;
    struct NodoInt* psig;
} NodoInt;

typedef NodoInt* ListaInt;

void insertarInt(ListaInt* l, int val){
    NodoInt* nuevo = (NodoInt*) malloc(sizeof(NodoInt));
    nuevo->dato = val;
    nuevo->psig = *l;
    *l = nuevo;
}

int contarValor(ListaInt l, int val){
    int count=0;
    NodoInt* aux=l;
    while(aux){
        if(aux->dato==val) count++;
        aux=aux->psig;
    }
    return count;
}

void eliminarValor(ListaInt* l,int val){
    NodoInt* aux=*l;
    NodoInt* ant=NULL;
    while(aux){
        if(aux->dato==val){
            if(ant==NULL) *l=aux->psig;
            else ant->psig=aux->psig;
            free(aux);
            return;
        }
        ant=aux;
        aux=aux->psig;
    }
    printf("Valor no encontrado o aparece más de una vez\n");
}

/*==============================================
LISTAS SIMPLES: DEPARTAMENTOS
==============================================*/

typedef struct {
    char ubicacion[50];
    int dormitorios;
    int piso;
    int cochera;
    int antiguedad;
    float precio;
    float expensas;
} Departamento;

typedef struct NodoDep {
    Departamento dato;
    struct NodoDep* psig;
} NodoDep;

typedef NodoDep* ListaDep;

void insertarDep(ListaDep* l, Departamento reg){
    NodoDep* nuevo = (NodoDep*) malloc(sizeof(NodoDep));
    nuevo->dato = reg;
    nuevo->psig = *l;
    *l = nuevo;
}

Departamento departamentoMasCaro(ListaDep l){
    Departamento caro=l->dato;
    NodoDep* aux=l->psig;
    while(aux){
        if(aux->dato.precio>caro.precio) caro=aux->dato;
        aux=aux->psig;
    }
    return caro;
}

/*==============================================
LISTAS DE LISTAS: VIDEOLUB
==============================================*/

typedef struct {
    char titulo[50];
    int stock;
    float precio;
} Producto;

typedef struct NodoProd {
    Producto dato;
    struct NodoProd* psig;
} NodoProd;

typedef NodoProd* ListaProd;

typedef struct {
    int codSocio;
    char nombre[50];
    ListaProd historial;
} Socio;

typedef struct NodoSocio {
    Socio dato;
    struct NodoSocio* psig;
} NodoSocio;

typedef NodoSocio* ListaSocios;

void insertarSocio(ListaSocios* l, Socio s){
    NodoSocio* nuevo = (NodoSocio*) malloc(sizeof(NodoSocio));
    nuevo->dato = s;
    nuevo->dato.historial=NULL;
    nuevo->psig=*l;
    *l=nuevo;
}

NodoSocio* buscarSocio(ListaSocios l, int cod){
    NodoSocio* aux=l;
    while(aux){
        if(aux->dato.codSocio==cod) return aux;
        aux=aux->psig;
    }
    return NULL;
}

void insertarProducto(ListaProd* l, Producto p){
    NodoProd* nuevo = (NodoProd*) malloc(sizeof(NodoProd));
    nuevo->dato = p;
    nuevo->psig = *l;
    *l=nuevo;
}

void imprimirSocios(ListaSocios l){
    NodoSocio* aux=l;
    while(aux){
        printf("Socio %d - %s\n", aux->dato.codSocio, aux->dato.nombre);
        NodoProd* p=aux->dato.historial;
        while(p){
            printf("\tProducto: %s - Veces: %d\n", p->dato.titulo, p->dato.stock);
            p=p->psig;
        }
        aux=aux->psig;
    }
}

/*==============================================
ARREGLOS DE LISTAS: COMPETENCIA
==============================================*/

#define DISCIPLINAS 10
typedef struct {
    int dni;
    char escuela[50];
    char localidad[50];
    int edad;
    int puntaje;
} Competidor;

typedef struct NodoComp {
    Competidor dato;
    struct NodoComp* psig;
} NodoComp;

typedef NodoComp* ListaComp;

void insertarCompetidor(ListaComp* l, Competidor c){
    NodoComp* nuevo = (NodoComp*) malloc(sizeof(NodoComp));
    nuevo->dato=c;
    nuevo->psig=*l;
    *l=nuevo;
}

void mostrarGanadores(ListaComp arr[]){
    for(int i=0;i<DISCIPLINAS;i++){
        NodoComp* aux=arr[i];
        Competidor primero, segundo, tercero;
        primero.puntaje=segundo.puntaje=tercero.puntaje=-1;
        while(aux){
            if(aux->dato.puntaje>primero.puntaje){
                tercero=segundo;
                segundo=primero;
                primero=aux->dato;
            } else if(aux->dato.puntaje>segundo.puntaje){
                tercero=segundo;
                segundo=aux->dato;
            } else if(aux->dato.puntaje>tercero.puntaje){
                tercero=aux->dato;
            }
            aux=aux->psig;
        }
        printf("\nDisciplina %d - 3 mejores puntajes:\n",i+1);
        if(primero.puntaje!=-1) printf("1) %d - %s - Puntaje: %d\n",primero.dni,primero.escuela,primero.puntaje);
        if(segundo.puntaje!=-1) printf("2) %d - %s - Puntaje: %d\n",segundo.dni,segundo.escuela,segundo.puntaje);
        if(tercero.puntaje!=-1) printf("3) %d - %s - Puntaje: %d\n",tercero.dni,tercero.escuela,tercero.puntaje);
    }
}

/*==============================================
PROGRAMA PRINCIPAL
==============================================*/

int main(){
    printf("=== TP8 Listas Dinamicas Completas ===\n");

    // ---------- LISTA DE LIBROS ----------
    Lista libros;
    crearLista(&libros);

    char resp='s';
    while(resp=='s'){
        Libro reg;
        printf("Ingrese nombre del libro: ");
        scanf(" %49[^\n]", reg.nombre);
        printf("Ingrese codigo: "); scanf("%d",&reg.codigo);
        printf("Ingrese autor: "); scanf(" %49[^\n]",reg.autor);
        printf("Ingrese precio: "); scanf("%f",&reg.precio);
        printf("Ingrese editorial: "); scanf(" %49[^\n]",reg.editorial);
        printf("Ingrese stock: "); scanf("%d",&reg.stock);
        insertar(&libros,reg);
        printf("Desea ingresar otro libro? (s/n): "); scanf(" %c",&resp);
    }

    imprimirStockCero(libros);
    simularLibros(&libros);

    // ---------- LISTA DE NUMEROS ----------
    ListaInt listaNums = NULL;
    insertarInt(&listaNums, 5);
    insertarInt(&listaNums, 7);
    insertarInt(&listaNums, 5);
    int val;
    printf("Ingrese valor a buscar en lista de numeros: "); scanf("%d",&val);
    int count = contarValor(listaNums,val);
    printf("El valor %d aparece %d veces\n", val, count);
    if(count==1) eliminarValor(&listaNums,val);

    // ---------- LISTA DE DEPARTAMENTOS ----------
    ListaDep deps=NULL;
    Departamento dep1={"Centro",3,5,1,10,150000,5000};
    Departamento dep2={"Norte",2,3,0,5,180000,3000};
    insertarDep(&deps,dep1);
    insertarDep(&deps,dep2);

    Departamento caro = departamentoMasCaro(deps);
    printf("Departamento mas caro: %s con precio %.2f\n",caro.ubicacion,caro.precio);

    // ---------- LISTAS DE LISTAS: VIDEOLUB ----------
    ListaSocios socios=NULL;
    Socio s1={1,"Juan"};
    Socio s2={2,"Ana"};
    insertarSocio(&socios,s1);
    insertarSocio(&socios,s2);

    Producto p1={"Película A",1,10};
    Producto p2={"Juego PS1",1,50};
    insertarProducto(&socios->dato.historial,p1);
    insertarProducto(&socios->psig->dato.historial,p2);

    imprimirSocios(socios);

    // ---------- ARREGLOS DE LISTAS: COMPETENCIA ----------
    ListaComp disciplinas[DISCIPLINAS]={NULL};

    Competidor c1={12345,"Escuela 1","La Plata",12,95};
    Competidor c2={23456,"Escuela 2","La Plata",13,88};
    Competidor c3={34567,"Escuela 3","La Plata",12,75};

    insertarCompetidor(&disciplinas[0],c1);
    insertarCompetidor(&disciplinas[0],c2);
    insertarCompetidor(&disciplinas[0],c3);

    mostrarGanadores(disciplinas);

    return 0;
}
