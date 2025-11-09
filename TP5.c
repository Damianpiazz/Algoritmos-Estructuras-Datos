#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLEADOS 230
#define MAX_SECTORES 10
#define MAX_SUCURSALES 20
#define MAX_HABITACIONES 100
#define MAX_TRANSACCIONES 5000
#define MAX_PRODUCTOS 10000
#define MAX_INSPECTORES 20
#define MAX_ACTAS 2000
#define MAX_VECTOR 1500
#define MAX_MATRIZ_FILAS 14
#define MAX_MATRIZ_COLS 50
#define MAX_LIBROS 100
#define MAX_TELEFONOS 1000
#define MAX_PALABRAS 20
#define MAX_DIGITOS 10

// -------------------- ESTRUCTURAS --------------------
typedef struct { int cod_area; char nombre_area[30]; } Area;
typedef struct { int cod_sucursal; char sucursal[30]; } Sucursal;
typedef struct { int legajo; char nombre[30]; char apellido[30]; int sector; int sucursal; double sueldo; } Empleado;
typedef struct { int nro_habitacion; int piso; char tipo[20]; double precioXdia; char confort[20]; char estado[20]; } Habitacion;
typedef struct { int nro_cuenta; char fecha[11]; double monto; int nro_comerciante; } Transaccion;
typedef struct { int nro_item; char producto[30]; char marca[30]; char tipo[30]; double costo; int stock_min; int stock_actual; } Producto;
typedef struct { int nroActa; char dominio[10]; char tipoInfraccion[20]; char fecha[11]; char hora[6]; int idInspector; } Acta;
typedef struct { char titulo[30]; char autor[30]; int codigo; double precio; } Libro;
typedef struct { char nombre[30]; char numero[15]; } Telefono;

// -------------------- FUNCIONES GENERALES --------------------
void pausa() { printf("\nPresione Enter para continuar..."); getchar(); getchar(); }

// -------------------- EMPLEADOS --------------------
int elige_sector(Area sec[], int tot){
    int op;
    printf("Sectores disponibles:\n");
    for(int i=0;i<tot;i++) printf("%d - %s\n", sec[i].cod_area, sec[i].nombre_area);
    printf("Seleccione sector: "); scanf("%d",&op);
    return op;
}

int elige_sucursal(Sucursal suc[], int tot){
    int op;
    printf("Sucursales disponibles:\n");
    for(int i=0;i<tot;i++) printf("%d - %s\n", suc[i].cod_sucursal, suc[i].sucursal);
    printf("Seleccione sucursal: "); scanf("%d",&op);
    return op;
}

void carga_sectores(Area sec[], int tot){
    for(int i=0;i<tot;i++){
        sec[i].cod_area=i+1;
        printf("Nombre sector %d: ", i+1); scanf("%s", sec[i].nombre_area);
    }
}

void carga_sucursales(Sucursal suc[], int tot){
    for(int i=0;i<tot;i++){
        suc[i].cod_sucursal=i+1;
        printf("Nombre sucursal %d: ", i+1); scanf("%s", suc[i].sucursal);
    }
}

void carga_empleados(Empleado emp[], int tot, Sucursal suc[], Area sec[], int tot_suc, int tot_sec){
    for(int i=0;i<tot;i++){
        printf("Empleado %d\n", i+1);
        printf("Nombre: "); scanf("%s", emp[i].nombre);
        printf("Apellido: "); scanf("%s", emp[i].apellido);
        emp[i].sector = elige_sector(sec, tot_sec);
        emp[i].sucursal = elige_sucursal(suc, tot_suc);
        printf("Sueldo: "); scanf("%lf", &emp[i].sueldo);
    }
}

// -------------------- ORDENACION --------------------
void ordenar_seleccion(int v[], int n, char sentido){
    int i,j,aux;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            int swap = (sentido=='A') ? (v[i]>v[j]) : (v[i]<v[j]);
            if(swap){ aux=v[i]; v[i]=v[j]; v[j]=aux; }
        }
    }
}

void ordenar_burbuja(int v[], int n, char sentido){
    int i,j,aux;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            int swap = (sentido=='A') ? (v[j]>v[j+1]) : (v[j]<v[j+1]);
            if(swap){ aux=v[j]; v[j]=v[j+1]; v[j+1]=aux; }
        }
    }
}

void ver_vector(int v[], int n){ 
    for(int i=0;i<n;i++) printf("%d ", v[i]); 
    printf("\n"); 
}

// -------------------- BUSQUEDA --------------------
int busqueda_lineal(int v[], int n, int clave){
    for(int i=0;i<n;i++) if(v[i]==clave) return i;
    return -1;
}

int busqueda_dicotomica(int v[], int n, int clave){
    int ini=0, fin=n-1, medio;
    while(ini<=fin){
        medio=(ini+fin)/2;
        if(v[medio]==clave) return medio;
        else if(v[medio]<clave) ini=medio+1;
        else fin=medio-1;
    }
    return -1;
}

// -------------------- MATRICES --------------------
void ordenar_matriz_por_columna(int mat[MAX_MATRIZ_FILAS][MAX_MATRIZ_COLS], int filas, int cols, int col){
    int i,j,k,aux;
    for(i=0;i<filas-1;i++){
        for(j=i+1;j<filas;j++){
            if(mat[i][col]>mat[j][col]){
                for(k=0;k<cols;k++){ aux=mat[i][k]; mat[i][k]=mat[j][k]; mat[j][k]=aux; }
            }
        }
    }
}

void ordenar_matriz_palabras(char mat[MAX_PALABRAS][MAX_DIGITOS][2], int filas){
    char aux[2];
    for(int i=0;i<filas-1;i++){
        for(int j=i+1;j<filas;j++){
            if(strcmp(mat[i][0],mat[j][0])>0){
                strcpy(aux,mat[i][0]);
                strcpy(mat[i][0],mat[j][0]);
                strcpy(mat[j][0],aux);
            }
        }
    }
}

// -------------------- HOTEL --------------------
void listar_habitaciones(Habitacion hab[], int n){
    for(int i=0;i<n;i++)
        if(strcmp(hab[i].estado,"Libre")==0)
            printf("Hab %d Piso %d Tipo %s Precio %.2lf Confort %s\n",
                hab[i].nro_habitacion, hab[i].piso, hab[i].tipo, hab[i].precioXdia, hab[i].confort);
}

void liquidar_habitacion(Habitacion hab[], int nro){
    int dias; 
    printf("Dias ocupada: "); scanf("%d",&dias);
    printf("Total a pagar: %.2lf\n", dias*hab[nro].precioXdia);
}

// -------------------- COMERCIO --------------------
void listar_productos(Producto p[], int n){ 
    for(int i=0;i<n;i++)
        printf("%d %s %s %s %.2lf %d %d\n", p[i].nro_item, p[i].producto, p[i].marca, p[i].tipo, p[i].costo, p[i].stock_min, p[i].stock_actual); 
}

// -------------------- TRANSACCIONES --------------------
void listar_transacciones(Transaccion t[], int n){
    for(int i=0;i<n;i++)
        printf("%d %s %.2lf %d\n", t[i].nro_cuenta, t[i].fecha, t[i].monto, t[i].nro_comerciante);
}

// -------------------- RECURSION --------------------
double promedio_rec(int notas[], int n){
    if(n==1) return notas[0];
    return (notas[n-1]+(n-1)*promedio_rec(notas,n-1))/n;
}

int contar_stock_rec(Producto p[], int n, char marca[]){
    if(n==0) return 0;
    int res = contar_stock_rec(p,n-1,marca);
    if(strcmp(p[n-1].marca,marca)==0) res++;
    return res;
}

double precio_libro_rec(Libro l[], int n, char titulo[]){
    if(n==0) return -1;
    if(strcmp(l[n-1].titulo,titulo)==0) return l[n-1].precio;
    return precio_libro_rec(l,n-1,titulo);
}

// -------------------- MENUS --------------------
void menu_empleados(Empleado emp[], Sucursal suc[], Area sec[]){
    carga_sucursales(suc, MAX_SUCURSALES);
    carga_sectores(sec, MAX_SECTORES);
    carga_empleados(emp, MAX_EMPLEADOS, suc, sec, MAX_SUCURSALES, MAX_SECTORES);
}

void menu_vector(){
    int v[35], n=35, op; 
    for(int i=0;i<n;i++){ printf("Num %d: ",i+1); scanf("%d",&v[i]); }
    do{
        printf("\n1- Seleccion Asc\n2- Seleccion Desc\n3- Burbuja Asc\n4- Burbuja Desc\n0- Salir\n"); scanf("%d",&op);
        switch(op){
            case 1: ordenar_seleccion(v,n,'A'); ver_vector(v,n); break;
            case 2: ordenar_seleccion(v,n,'D'); ver_vector(v,n); break;
            case 3: ordenar_burbuja(v,n,'A'); ver_vector(v,n); break;
            case 4: ordenar_burbuja(v,n,'D'); ver_vector(v,n); break;
        }
    }while(op!=0);
}

// -------------------- PROGRAMA PRINCIPAL --------------------
int main(){
    Empleado emp[MAX_EMPLEADOS]; Area sec[MAX_SECTORES]; Sucursal suc[MAX_SUCURSALES];
    Habitacion hotel[MAX_HABITACIONES]; Transaccion trans[MAX_TRANSACCIONES];
    Producto productos[MAX_PRODUCTOS]; Acta actas[MAX_ACTAS]; 
    Libro libros[MAX_LIBROS]; Telefono telefonos[MAX_TELEFONOS];
    int opcion;
    do{
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1- Empleados y Registros\n2- Vector Ordenacion/Busqueda\n3- Hotel\n4- Comercio\n5- Transacciones\n6- Recursion/Libros\n0- Salir\n"); 
        scanf("%d",&opcion);
        switch(opcion){
            case 1: menu_empleados(emp,suc,sec); break;
            case 2: menu_vector(); break;
            case 3: listar_habitaciones(hotel,MAX_HABITACIONES); break;
            case 4: listar_productos(productos,MAX_PRODUCTOS); break;
            case 5: listar_transacciones(trans,MAX_TRANSACCIONES); break;
            case 6: {
                int notas[5]={7,8,9,10,6};
                printf("Promedio recursivo: %.2lf\n", promedio_rec(notas,5));
                printf("Productos marca X stock: %d\n", contar_stock_rec(productos,MAX_PRODUCTOS,"X"));
                char titulo[30]; printf("Buscar precio libro: "); scanf("%s", titulo);
                double precio = precio_libro_rec(libros, MAX_LIBROS, titulo);
                if(precio>=0) printf("Precio del libro: %.2lf\n", precio);
                else printf("Libro no encontrado\n");
                break;
            }
        }
    }while(opcion!=0);
    return 0;
}
