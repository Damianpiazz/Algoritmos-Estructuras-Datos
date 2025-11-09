#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_Llantas 1000
#define MAX_TURNOS 4
#define MAX_TAM 6
#define MAX_MESAS 15
#define MAX_SILLAS 8
#define MAX_POSTRES 20
#define MAX_EMPLEADOS 230
#define MAX_SECTORES 10
#define MAX_SUCURSALES 20
#define MAX_HABITACIONES 100
#define MAX_TRANSACCIONES 5000
#define MAX_PRODUCTOS 10000
#define MAX_INSPECTORES 20
#define MAX_ACTAS 2000

// ------------------- ESTRUCTURAS -------------------
typedef struct {
    int cod_area;
    char nombre_area[30];
} Area;

typedef struct {
    int cod_sucursal;
    char sucursal[30];
} Lugar;

typedef struct {
    int legajo;
    char nombre[30];
    char apellido[30];
    int sector;
    int sucursal;
    double sueldo;
} Empleado;

typedef struct {
    int nro_habitacion;
    int piso;
    char tipo[20];
    double precioXdia;
    char confort[20];
    char estado[20]; // "Libre" o "Ocupada"
} Habitacion;

typedef struct {
    int nro_cuenta;
    char fecha[11];
    double monto;
    int nro_comerciante;
} Transaccion;

typedef struct {
    int nro_item;
    char producto[30];
    char marca[20];
    char tipo[20];
    double costo;
    int stock_minimo;
    int stock_actual;
} Producto;

typedef struct {
    int nroActa;
    char dominio[10];
    char tipoInfraccion[20];
    char fecha[11];
    char hora[6];
    int idInspector;
} Acta;

// ------------------- FUNCIONES GENERALES -------------------
void pausa() {
    printf("\nPresione Enter para continuar...");
    getchar();
    getchar();
}

// ------------------- EJERCICIO VECTORES -------------------
void promedio_vector(int n) {
    int V[n];
    double suma = 0, promedio;
    printf("=== PROMEDIO DE %d NUMEROS ===\n", n);
    for(int i=0; i<n; i++) {
        printf("Ingrese numero %d: ", i+1);
        scanf("%d", &V[i]);
        suma += V[i];
    }
    promedio = suma / n;
    printf("El promedio es: %.2lf\n", promedio);
}

void vector_maximo(int n) {
    int V[n], max;
    printf("Ingrese %d numeros enteros:\n", n);
    for(int i=0; i<n; i++) scanf("%d", &V[i]);
    max = V[0];
    for(int i=1; i<n; i++)
        if(V[i]>max) max = V[i];
    printf("El valor maximo es: %d\n", max);
}

void vector_buscar(int n) {
    int V[n], buscar, encontrado = 0;
    printf("Ingrese %d numeros enteros:\n", n);
    for(int i=0;i<n;i++) scanf("%d",&V[i]);
    printf("Ingrese el numero a buscar: "); scanf("%d",&buscar);
    for(int i=0;i<n;i++)
        if(V[i]==buscar) { encontrado = 1; break; }
    if(encontrado) printf("El numero existe en el vector.\n");
    else printf("El numero NO existe.\n");
}

// ------------------- EJERCICIO MATRICES -------------------
void comparar_matrices(int filas, int cols) {
    double M1[filas][cols], M2[filas][cols], suma1=0, suma2=0;
    for(int i=0;i<filas;i++)
        for(int j=0;j<cols;j++){
            printf("M1[%d][%d]: ", i+1,j+1);
            scanf("%lf",&M1[i][j]);
            suma1+=M1[i][j];
        }
    for(int i=0;i<filas;i++)
        for(int j=0;j<cols;j++){
            printf("M2[%d][%d]: ", i+1,j+1);
            scanf("%lf",&M2[i][j]);
            suma2+=M2[i][j];
        }
    if(suma1==suma2) printf("Las sumas coinciden.\n");
    else printf("Las sumas NO coinciden.\n");
}

void matriz_minimo(int filas,int cols){
    int M[filas][cols],min;
    for(int i=0;i<filas;i++)
        for(int j=0;j<cols;j++){
            printf("M[%d][%d]: ",i+1,j+1);
            scanf("%d",&M[i][j]);
        }
    min=M[0][0];
    for(int i=0;i<filas;i++)
        for(int j=0;j<cols;j++)
            if(M[i][j]<min) min=M[i][j];
    printf("El valor minimo es: %d\n",min);
}

void matriz_buscar(int filas,int cols){
    int M[filas][cols],valor,pos_f=-1,pos_c=-1;
    for(int i=0;i<filas;i++)
        for(int j=0;j<cols;j++){
            printf("M[%d][%d]: ",i+1,j+1);
            scanf("%d",&M[i][j]);
        }
    printf("Ingrese valor a buscar: "); scanf("%d",&valor);
    for(int i=0;i<filas;i++)
        for(int j=0;j<cols;j++)
            if(M[i][j]==valor){ pos_f=i; pos_c=j; break;}
    if(pos_f!=-1) printf("Valor encontrado en fila %d columna %d\n",pos_f+1,pos_c+1);
    else printf("Valor no encontrado\n");
}

// ------------------- EJERCICIO REGISTROS -------------------
int elige_sector(Area sectores[],int tot){
    int op;
    for(int i=0;i<tot;i++) printf("#%d %s\n",sectores[i].cod_area,sectores[i].nombre_area);
    printf("Seleccione sector: "); scanf("%d",&op);
    return op;
}

int elige_sucursal(Lugar sucursales[],int tot){
    int op;
    for(int i=0;i<tot;i++) printf("#%d %s\n",sucursales[i].cod_sucursal,sucursales[i].sucursal);
    printf("Seleccione sucursal: "); scanf("%d",&op);
    return op;
}

void cargar_empleados(Empleado emp[],int tot, Lugar suc[], Area sec[], int tot_suc,int tot_sec){
    for(int i=0;i<tot;i++){
        printf("Empleado %d\n",i+1);
        printf("Nombre: "); scanf("%s",emp[i].nombre);
        printf("Apellido: "); scanf("%s",emp[i].apellido);
        emp[i].sector=elige_sector(sec,tot_sec);
        emp[i].sucursal=elige_sucursal(suc,tot_suc);
        printf("Sueldo: "); scanf("%lf",&emp[i].sueldo);
    }
}

// ------------------- EJERCICIO HOTEL -------------------
void listar_habitaciones(Habitacion hab[], int tot){
    for(int i=0;i<tot;i++)
        if(strcmp(hab[i].estado,"Libre")==0)
            printf("Hab %d Piso %d Tipo %s Precio %.2lf Confort %s Estado %s\n",
                hab[i].nro_habitacion,hab[i].piso,hab[i].tipo,hab[i].precioXdia,hab[i].confort,hab[i].estado);
}

void liquidar_habitacion(Habitacion hab[],int nro){
    int dias;
    printf("Ingrese nro de dias ocupada: "); scanf("%d",&dias);
    double total=dias*hab[nro].precioXdia;
    printf("Total a pagar: %.2lf\n",total);
}

// ------------------- EJERCICIO BANCO -------------------
void listar_transacciones(Transaccion t[],int n){
    for(int i=0;i<n;i++)
        printf("Cuenta %d Fecha %s Monto %.2lf Comerciante %d\n",
            t[i].nro_cuenta,t[i].fecha,t[i].monto,t[i].nro_comerciante);
}

// ------------------- MENU PRINCIPAL -------------------
int main(){
    int opcion;
    Area sectores[MAX_SECTORES];
    Lugar sucursales[MAX_SUCURSALES];
    Empleado personal[MAX_EMPLEADOS];
    Habitacion hotel[MAX_HABITACIONES];

    while(1){
        printf("\n--- TP04 COMPLETO EN C ---\n");
        printf("1. Promedio de vector\n");
        printf("2. Maximo de vector\n");
        printf("3. Buscar en vector\n");
        printf("4. Comparar matrices\n");
        printf("5. Minimo de matriz\n");
        printf("6. Buscar en matriz\n");
        printf("7. Cargar empleados, sectores y sucursales\n");
        printf("8. Listar habitaciones hotel\n");
        printf("9. Liquidar habitacion\n");
        printf("0. Salir\n");
        printf("Opcion: "); scanf("%d",&opcion);

        switch(opcion){
            case 1: promedio_vector(150); break;
            case 2: vector_maximo(10); break;
            case 3: vector_buscar(10); break;
            case 4: comparar_matrices(8,10); break;
            case 5: matriz_minimo(3,3); break;
            case 6: matriz_buscar(3,3); break;
            case 7:
                for(int i=0;i<MAX_SECTORES;i++){
                    sectores[i].cod_area=i+1;
                    printf("Nombre sector %d: ",i+1); scanf("%s",sectores[i].nombre_area);
                }
                for(int i=0;i<MAX_SUCURSALES;i++){
                    sucursales[i].cod_sucursal=i+1;
                    printf("Nombre sucursal %d: ",i+1); scanf("%s",sucursales[i].sucursal);
                }
                cargar_empleados(personal,MAX_EMPLEADOS,sucursales,sectores,MAX_SUCURSALES,MAX_SECTORES);
                break;
            case 8:
                listar_habitaciones(hotel,MAX_HABITACIONES);
                break;
            case 9:
                int hab; printf("Ingrese nro habitacion a liquidar: "); scanf("%d",&hab);
                liquidar_habitacion(hotel,hab-1);
                break;
            case 0: exit(0);
            default: printf("Opcion invalida\n"); break;
        }
        pausa();
    }
    return 0;
}