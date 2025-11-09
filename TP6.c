#include <stdio.h>
#include "Producto.h"
#include "Auto.h"
#include "Departamento.h"

int main(){
    // ---------------- Producto ----------------
    Producto p;
    int cod; char fecha[9]; double peso,largo,ancho;

    printf("Cargar producto:\nCodigo: "); scanf("%d",&cod);
    printf("Fecha produccion (AAAAMMDD): "); scanf("%s",fecha);
    printf("Peso: "); scanf("%lf",&peso);
    printf("Largo: "); scanf("%lf",&largo);
    printf("Ancho: "); scanf("%lf",&ancho);

    crearProducto(&p,cod,fecha,peso,largo,ancho,0);

    if(peso>=100 && peso<=250 && largo>=1000 && largo<=2500 && ancho>=50 && ancho<=65){
        printf("Ingrese fecha de hoy: "); scanf("%s",fecha);
        modFecha(&p,fecha);
        modCalidad(&p,1);
        printf("Se ha modificado la informacion del producto\n");
    } else printf("No se ha modificado la informacion del producto\n");

    printf("Producto actual:\nCodigo: %d\nFecha: %s\nPeso: %.2lf\nLargo: %.2lf\nAncho: %.2lf\nCalidad: %d\n",
        verCod(&p), verFecha(&p), verPeso(&p), verLargo(&p), verAncho(&p), verCalidad(&p));

    // ---------------- Autos ----------------
    Auto a1,a2;
    crearAuto(&a1,"AAA1234","Ford","Fiesta",2018,15000);
    crearAuto(&a2,"BBB5678","Toyota","Corolla",2018,18000);

    printf("Auto 1: %s %s %d %.2lf\n", verMarca(&a1), verModelo(&a1), verAnio(&a1), verPrecio(&a1));
    printf("Auto 2: %s %s %d %.2lf\n", verMarca(&a2), verModelo(&a2), verAnio(&a2), verPrecio(&a2));

    if(verPrecio(&a1)>verPrecio(&a2)) printf("Auto 1 es mas caro\n");
    else if(verPrecio(&a2)>verPrecio(&a1)) printf("Auto 2 es mas caro\n");
    else printf("Ambos autos tienen el mismo precio\n");

    if(verAnio(&a1)==verAnio(&a2)) printf("Ambos autos son del mismo anio\n");
    else printf("Autos de distinto anio\n");

    // ---------------- Departamento ----------------
    Departamento d;
    crearDepartamento(&d,101,"Playa",4,2000,1,1,"Libre");
    verDepartamento(&d);
    printf("Disponibilidad: %s\n", disponible(&d)?"Libre":"Ocupado");
    modEstado(&d,"Ocupado");
    verDepartamento(&d);
    printf("Precio 3 dias: %.2lf\n", calcularPrecio(&d,3));

    return 0;
}
