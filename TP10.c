#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100

/*==============================================
ARCHIVOS SECUENCIALES
==============================================*/

// Ejercicio 1: Telecomunicaciones
typedef struct {
    int idCliente;
    int pulsos;
} Cliente;

typedef struct {
    int idCliente;
    int pulsos;
    double importe;
} Factura;

void generarFacturas() {
    Cliente clientes[MAX];
    Factura facturas[MAX];
    int n;
    printf("Ingrese cantidad de clientes: "); scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("ID Cliente %d: ", i+1); scanf("%d",&clientes[i].idCliente);
        printf("Pulsos consumidos: "); scanf("%d",&clientes[i].pulsos);
        double extra = (clientes[i].pulsos>203) ? (clientes[i].pulsos-203)*0.0475 : 0;
        facturas[i].idCliente = clientes[i].idCliente;
        facturas[i].pulsos = clientes[i].pulsos;
        facturas[i].importe = 26.50 + extra;
    }
    FILE *f = fopen("facturas.dat","wb");
    fwrite(facturas,sizeof(Factura),n,f);
    fclose(f);
    printf("Archivo de facturas generado.\n");
}

// Ejercicio 2: Correo Mendoza
typedef struct {
    char tipo[20]; // carta simple, certificada, documento, telegrama, encomienda
    char destinatario[50];
    char remitente[50];
    int codPostal;
} Correo;

void consultaCorreo() {
    FILE *f = fopen("correo.dat","rb");
    if(!f){ printf("No existe archivo correo.dat\n"); return; }
    Correo c;
    int total=0, telegramas=0, encomiendasMendoza=0;
    while(fread(&c,sizeof(Correo),1,f)){
        total++;
        if(strcmp(c.tipo,"telegrama")==0) telegramas++;
        if(strcmp(c.tipo,"encomienda")==0 && c.codPostal==5519) encomiendasMendoza++;
    }
    fclose(f);
    printf("Porcentaje telegramas: %.2f%%\n",100.0*telegramas/total);
    printf("Cantidad encomiendas a Mendoza (5519): %d\n", encomiendasMendoza);
}

// Ejercicio 3: Aseguradora
typedef struct {
    int nroPoliza;
    int nroMotor;
    char combustible[10];
    char titular[50];
    char fechaVenc[11]; // dd/mm/yyyy
} Vehiculo;

int mesActual() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    return tm.tm_mon +1;
}

void vehiculosVencen() {
    FILE *f = fopen("vehiculos.dat","rb");
    if(!f){ printf("No existe archivo vehiculos.dat\n"); return; }
    Vehiculo v[100];
    int n=0;
    while(fread(&v[n],sizeof(Vehiculo),1,f)) n++;
    fclose(f);
    // Listado vehículos vencen mes actual, ordenado por nroPoliza
    int mes = mesActual();
    // ordenar asc por nroPoliza
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(v[i].nroPoliza>v[j].nroPoliza){
                Vehiculo tmp=v[i]; v[i]=v[j]; v[j]=tmp;
            }
    int countComb[3]={0,0,0}; // GNC, Nafta, Gasoil
    printf("Vehiculos con poliza venciendo este mes:\n");
    for(int i=0;i<n;i++){
        int mesV=atoi(strtok(v[i].fechaVenc,"/")+3); // mes
        if(mesV==mes){
            printf("Poliza:%d, Titular:%s\n", v[i].nroPoliza, v[i].titular);
        }
        if(strcmp(v[i].combustible,"GNC")==0) countComb[0]++;
        else if(strcmp(v[i].combustible,"Nafta")==0) countComb[1]++;
        else if(strcmp(v[i].combustible,"Gasoil")==0) countComb[2]++;
    }
    int total=n;
    printf("Porcentaje combustible: GNC %.2f%%, Nafta %.2f%%, Gasoil %.2f%%\n",
           100.0*countComb[0]/total,100.0*countComb[1]/total,100.0*countComb[2]/total);
}

/*==============================================
ARCHIVOS DE ACCESO DIRECTO
==============================================*/

// Ejercicio 1: Carrefour
typedef struct {
    int codigo;
    char tipo[20];
    int stockAct;
    int stockMax;
    int stockMin;
    double precioGen;
    double precioClub;
} Producto;

void crearArchivoProductos() {
    FILE *f = fopen("productos.dat","wb");
    if(!f){ printf("Error al crear archivo\n"); return; }
    int n;
    printf("Cantidad de productos: "); scanf("%d",&n);
    Producto p;
    for(int i=0;i<n;i++){
        printf("Codigo: "); scanf("%d",&p.codigo);
        printf("Tipo: "); scanf("%s",p.tipo);
        printf("Stock actual: "); scanf("%d",&p.stockAct);
        printf("Stock maximo: "); scanf("%d",&p.stockMax);
        printf("Stock minimo: "); scanf("%d",&p.stockMin);
        printf("Precio general: "); scanf("%lf",&p.precioGen);
        // Calculo precio club
        if(strcmp(p.tipo,"lacteos")==0) p.precioClub=p.precioGen*0.95;
        else if(strcmp(p.tipo,"electronicos")==0) p.precioClub=p.precioGen*0.9;
        else if(strcmp(p.tipo,"perfumeria")==0) p.precioClub=p.precioGen*0.85;
        else p.precioClub=p.precioGen;
        fwrite(&p,sizeof(Producto),1,f);
    }
    fclose(f);
    printf("Archivo productos.dat creado.\n");
}

void simularVentas() {
    FILE *f = fopen("productos.dat","r+b");
    if(!f){ printf("No existe archivo\n"); return; }
    int codigo, club;
    printf("Ingrese codigo de producto vendido: "); scanf("%d",&codigo);
    printf("Cliente del club? (1=si,0=no): "); scanf("%d",&club);
    Producto p;
    double total=0;
    while(fread(&p,sizeof(Producto),1,f)){
        if(p.codigo==codigo){
            if(p.stockAct>0){
                p.stockAct--;
                fseek(f,-sizeof(Producto),SEEK_CUR);
                fwrite(&p,sizeof(Producto),1,f);
                total = club ? p.precioClub : p.precioGen;
                break;
            } else { printf("Producto sin stock\n"); break; }
        }
    }
    fclose(f);
    printf("Monto total venta: %.2f\n", total);
}

// Ejercicio 2: Maderera
typedef struct {
    int codMaterial;
    char nombre[50];
    double precio;
} Tarifa;

typedef struct {
    int nroPedido;
    char cliente[50];
    char telefono[15];
    int codMaterial;
    int cantidad;
    double total;
} Pedido;

void calcularPedidos() {
    FILE *fTar = fopen("tarifas.dat","rb");
    FILE *fPed = fopen("pedidos.dat","r+b");
    if(!fTar || !fPed){ printf("No existen archivos\n"); return; }

    Tarifa tarifas[100];
    int nTar=0;
    while(fread(&tarifas[nTar],sizeof(Tarifa),1,fTar)) nTar++;

    Pedido ped;
    while(fread(&ped,sizeof(Pedido),1,fPed)){
        for(int i=0;i<nTar;i++){
            if(tarifas[i].codMaterial==ped.codMaterial){
                ped.total = ped.cantidad*tarifas[i].precio;
                fseek(fPed,-sizeof(Pedido),SEEK_CUR);
                fwrite(&ped,sizeof(Pedido),1,fPed);
                break;
            }
        }
    }
    fclose(fTar); fclose(fPed);
    printf("Pedidos actualizados con total.\n");
}

void ingresarPedido() {
    FILE *fPed = fopen("pedidos.dat","ab");
    if(!fPed){ printf("No existe archivo pedidos.dat\n"); return; }
    Pedido p;
    printf("Nro pedido: "); scanf("%d",&p.nroPedido);
    printf("Cliente: "); scanf("%s",p.cliente);
    printf("Telefono: "); scanf("%s",p.telefono);
    printf("Codigo material: "); scanf("%d",&p.codMaterial);
    printf("Cantidad: "); scanf("%d",&p.cantidad);
    p.total=0;
    fwrite(&p,sizeof(Pedido),1,fPed);
    fclose(fPed);
    printf("Pedido agregado.\n");
}

void eliminarMaterial(int codMat) {
    FILE *fMat = fopen("tarifas.dat","r+b");
    if(!fMat){ printf("No existe archivo\n"); return; }
    Tarifa t;
    long pos;
    while(fread(&t,sizeof(Tarifa),1,fMat)){
        if(t.codMaterial==codMat){
            pos = ftell(fMat)-sizeof(Tarifa);
            fseek(fMat,pos,SEEK_SET);
            Tarifa vacio={0,"",0.0};
            fwrite(&vacio,sizeof(Tarifa),1,fMat);
            printf("Material %d eliminado\n",codMat);
            break;
        }
    }
    fclose(fMat);
}

/*==============================================
PROGRAMA PRINCIPAL
==============================================*/
int main() {
    printf("=== TP10 Archivos Completos ===\n");

    // Archivos secuenciales
    generarFacturas();
    consultaCorreo();
    vehiculosVencen();

    // Archivos de acceso directo
    crearArchivoProductos();
    simularVentas();
    calcularPedidos();
    ingresarPedido();
    eliminarMaterial(101); // ejemplo cod material

    return 0;
}
