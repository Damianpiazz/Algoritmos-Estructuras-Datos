#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

// -------------------- 1. Maximos --------------------
int max2(int a, int b){ return (a>b)?a:b; }
int max3(int a,int b,int c){ return max2(a,max2(b,c)); }
int max5(int a,int b,int c,int d,int e){ return max2(max3(a,b,c), max2(d,e)); }
int max10(int arr[10]){
    int m=arr[0];
    for(int i=1;i<10;i++) if(arr[i]>m) m=arr[i];
    return m;
}

// -------------------- 2. Distancias --------------------
double distanciaPlano(double x1,double y1,double x2,double y2){
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}
double distanciaEspacio(double x1,double y1,double z1,double x2,double y2,double z2){
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2)+pow(z2-z1,2));
}

// -------------------- 3. Areas figuras --------------------
double areaCirculo(double r){ return M_PI*r*r; }
double areaCuadrado(double a){ return a*a; }
double areaRectangulo(double b,double h){ return b*h; }
double areaTriangulo(double b,double h){ return b*h/2.0; }
double areaTrapecio(double b1,double b2,double h){ return (b1+b2)*h/2.0; }

// -------------------- 4. Funciones matematicas --------------------
int raiz2doGrado(double a,double b,double c,double *r1,double *r2){
    double d = b*b - 4*a*c;
    if(d<0) return 0; // no reales
    *r1 = (-b + sqrt(d))/(2*a);
    *r2 = (-b - sqrt(d))/(2*a);
    return 1;
}
double promedio6(int arr[6]){
    int suma=0; for(int i=0;i<6;i++) suma+=arr[i]; return suma/6.0;
}
double celsiusAFahrenheit(double c){ return c*9.0/5 + 32; }
double fahrenheitACelsius(double f){ return (f-32)*5.0/9; }
double moduloVector2D(double x,double y){ return sqrt(x*x+y*y); }
void sumaVector2D(double x1,double y1,double x2,double y2,double *xr,double *yr){
    *xr = x1+x2; *yr=y1+y2;
}
char mayusAMinus(char c){ return (isupper(c))?tolower(c):c; }
char minusAMayus(char c){ return (islower(c))?toupper(c):c; }
double calcularPI(){ return 4*atan(1); }

// -------------------- 5. Conversiones de bases --------------------
int binarioADecimal(int b){
    int dec=0,p=1;
    while(b>0){ dec+=(b%10)*p; b/=10; p*=2; }
    return dec;
}
int decimalABinario(int n){
    int bin=0,p=1;
    while(n>0){ bin += (n%2)*p; n/=2; p*=10; }
    return bin;
}
int baseBADecimal(int n,int b){
    int dec=0,p=1;
    while(n>0){ dec+=(n%10)*p; n/=10; p*=b; }
    return dec;
}
int decimalABaseB(int n,int b){
    int res=0,p=1;
    while(n>0){ res += (n%b)*p; n/=b; p*=10; }
    return res;
}
int baseBBaseC(int n,int b,int c){
    int dec=baseBADecimal(n,b);
    return decimalABaseB(dec,c);
}

// -------------------- 6. Funciones logicas --------------------
int signo(int n){ return (n>0)?1:(n<0)?-1:0; }
int esMayus(char c){ return isupper(c); }
int esVocal(char c){
    c=tolower(c);
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}
int esMultiplo(int a,int b){ return (b!=0 && a%b==0); }

// -------------------- 7. Simulacion procedimiento --------------------
void ProcedimientoPP(int pValor,int *pRef,int *G3,int G2){
    int L1,L2;
    L1=G2;
    L2=*pRef;
    pValor = L1+L2;
    *pRef = L1-L2;
    *G3 = 10*L1;
}

// -------------------- 8. Numeros primos --------------------
int esPrimo(int n){
    if(n<2) return 0;
    for(int i=2;i<=n/2;i++) if(n%i==0) return 0;
    return 1;
}
void primosMenores(int n){
    printf("Primos menores que %d: ", n);
    for(int i=2;i<n;i++) if(esPrimo(i)) printf("%d ",i);
    printf("\n");
}

// -------------------- Menu principal --------------------
int main(){
    int opcion;
    do{
        printf("\n=== TP3: Funciones y Procedimientos ===\n");
        printf("1) Maximos 2,3,5,10 numeros\n");
        printf("2) Distancia entre puntos\n");
        printf("3) Areas figuras geometricas\n");
        printf("4) Raices 2do grado, promedio, conversiones\n");
        printf("5) Conversiones de bases\n");
        printf("6) Funciones logicas (signo, mayus, vocal, multiplo)\n");
        printf("7) Procedimiento simulacion\n");
        printf("8) Numeros primos menores que N\n");
        printf("0) Salir\n");
        printf("Seleccione opcion: ");
        scanf("%d",&opcion);

        switch(opcion){
            case 1:{
                int a,b,c,d,e,arr[10];
                printf("Ingrese 2 numeros: "); scanf("%d%d",&a,&b);
                printf("Max2=%d\n", max2(a,b));
                printf("Ingrese 3 numeros: "); scanf("%d%d%d",&a,&b,&c);
                printf("Max3=%d\n", max3(a,b,c));
                printf("Ingrese 5 numeros: "); scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
                printf("Max5=%d\n", max5(a,b,c,d,e));
                printf("Ingrese 10 numeros: ");
                for(int i=0;i<10;i++) scanf("%d",&arr[i]);
                printf("Max10=%d\n", max10(arr));
                break;
            }
            case 2:{
                double x1,y1,x2,y2,z1,z2;
                printf("Plano: ingrese x1 y1 x2 y2: "); scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
                printf("Distancia plano=%.2lf\n", distanciaPlano(x1,y1,x2,y2));
                printf("Espacio: ingrese x1 y1 z1 x2 y2 z2: "); scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&z1,&x2,&y2,&z2);
                printf("Distancia espacio=%.2lf\n", distanciaEspacio(x1,y1,z1,x2,y2,z2));
                break;
            }
            case 3:{
                double r,a,b,h,b1,b2;
                printf("Circulo radio: "); scanf("%lf",&r); printf("Area=%.2lf\n",areaCirculo(r));
                printf("Cuadrado lado: "); scanf("%lf",&a); printf("Area=%.2lf\n",areaCuadrado(a));
                printf("Rectangulo base altura: "); scanf("%lf%lf",&b,&h); printf("Area=%.2lf\n",areaRectangulo(b,h));
                printf("Triangulo base altura: "); scanf("%lf%lf",&b,&h); printf("Area=%.2lf\n",areaTriangulo(b,h));
                printf("Trapecio base1 base2 altura: "); scanf("%lf%lf%lf",&b1,&b2,&h); printf("Area=%.2lf\n",areaTrapecio(b1,b2,h));
                break;
            }
            case 4:{
                double r1,r2; int arr6[6]; double temp;
                double a,b,c;
                printf("Raices 2do grado: ingrese a b c: "); scanf("%lf%lf%lf",&a,&b,&c);
                if(raiz2doGrado(a,b,c,&r1,&r2)) printf("Raices: %.2lf %.2lf\n",r1,r2);
                else printf("No existen raices reales\n");
                printf("Promedio 6 numeros: "); for(int i=0;i<6;i++) scanf("%d",&arr6[i]);
                printf("Promedio=%.2lf\n", promedio6(arr6));
                printf("Temperatura C a F: "); scanf("%lf",&temp); printf("%.2lf\n",celsiusAFahrenheit(temp));
                printf("Temperatura F a C: "); scanf("%lf",&temp); printf("%.2lf\n",fahrenheitACelsius(temp));
                double x,y;
                printf("Vector2D x y: "); scanf("%lf%lf",&x,&y); printf("Modulo=%.2lf\n",moduloVector2D(x,y));
                double xr,yr; printf("Suma vector 2D (x1 y1 x2 y2): "); double x1,y1,x2,y2; scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
                sumaVector2D(x1,y1,x2,y2,&xr,&yr); printf("Suma vector (%.2lf, %.2lf)\n",xr,yr);
                char c; getchar(); printf("Ingrese letra para mayus->minus: "); scanf("%c",&c); printf("%c\n",mayusAMinus(c));
                getchar(); printf("Ingrese letra para minus->mayus: "); scanf("%c",&c); printf("%c\n",minusAMayus(c));
                printf("PI=%.5lf\n", calcularPI());
                break;
            }
            case 5:{
                int n,b,cB,cC;
                printf("Binario a decimal: "); scanf("%d",&n); printf("%d\n",binarioADecimal(n));
                printf("Decimal a binario: "); scanf("%d",&n); printf("%d\n",decimalABinario(n));
                printf("Decimal a base B: "); scanf("%d %d",&n,&b); printf("%d\n",decimalABaseB(n,b));
                printf("Base B a decimal: "); scanf("%d %d",&n,&b); printf("%d\n",baseBADecimal(n,b));
                printf("Base B a base C: "); scanf("%d %d %d",&n,&b,&cC); printf("%d\n",baseBBaseC(n,b,cC));
                break;
            }
            case 6:{
                int n1,n2; char c;
                printf("Signo de un numero: "); scanf("%d",&n1); printf("%d\n",signo(n1));
                getchar(); printf("Es mayuscula: "); scanf("%c",&c); printf("%d\n",esMayus(c));
                getchar(); printf("Es vocal: "); scanf("%c",&c); printf("%d\n",esVocal(c));
                printf("Es multiplo: "); scanf("%d%d",&n1,&n2); printf("%d\n",esMultiplo(n1,n2));
                break;
            }
            case 7:{
                int G1,G2,G3;
                printf("Ingrese G1 G2 G3: "); scanf("%d%d%d",&G1,&G2,&G3);
                printf("Antes: G1=%d G2=%d G3=%d\n",G1,G2,G3);
                ProcedimientoPP(G2,&G1,&G3,G2);
                printf("Despues: G1=%d G2=%d G3=%d\n",G1,G2,G3);
                break;
            }
            case 8:{
                int n; printf("Ingrese N: "); scanf("%d",&n);
                primosMenores(n);
                break;
            }
            case 0: printf("Saliendo...\n"); break;
            default: printf("Opcion invalida\n");
        }

    }while(opcion!=0);
    return 0;
}