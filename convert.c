#include "cambioDeBase.h"
#include "leerInput.h"

int main(int argc, char *argv[])
{
    printf("Test 1:\n");
    int *origen;
    origen= (int*)malloc(sizeof(int));
    *origen=2;
    int *n;
    n= (int*)malloc(sizeof(int)*11);
    n[0]= 1;
    n[1]= 1;
    n[2]= -1;
    int *mostrar;
    mostrar= (int*)malloc(sizeof(int));
    *mostrar=1;
    int* entero10= enteroXa10(origen,n,mostrar);
    int i0 =0;
    while(entero10[i0]!=(-1))
    {
        printf("%i",entero10[i0]);
        i0++;
    }
    printf("\n");
    int* fraccion10= fraccionXa10(origen,n,mostrar);
    i0 =0;
    while(fraccion10[i0]!=(-1))
    {
        printf("%i",fraccion10[i0]);
        i0++;
    }
    printf("\n");
    printf("Test 2:\n");
    int *destino = (int*)malloc(sizeof(int));
    *destino = 2;
    int *numero = (int*)malloc(sizeof(int)*5);
    int *mostro = (int*)malloc(sizeof(int));
    *mostro = 1;
    numero[0] = 2;
    numero[1] = 0;
    numero[2] = 0;
    numero[3] = 9;
    numero[4] = 9;
    int* base8 = entero10aX(destino,numero,mostro);
    int i =0;
    while(base8[i]!=(-1))
    {
        printf("%i",base8[i]);
        i++;
    }
    free(destino);
    free(base8);
    free(numero);
    free(mostro);
    printf("\n");
    printf("Test 3:\n");
    int * origen3= (int*)malloc(sizeof(int));
    *origen3= 16;
    int * destino3= (int*)malloc(sizeof(int));
    *destino3= 2;
    int * mostrar3= (int*)malloc(sizeof(int));
    *mostrar3= 1;
    int * n3= (int*)malloc(sizeof(int)*11);
    n3[0]=1;
    n3[1]=1;
    n3[2]=-1;
    int *entero= enteroXaY(origen3,destino3,n3,mostrar3);
    int i3 =0;
    while(entero[i3]!=(-1))
    {
        printf("%i",entero[i3]);
        i3++;
    }
    printf("\n");
    int* fraccion= fraccionXaY(origen3,destino3,n3,mostrar);
    i3 =0;
    while(fraccion[i3]!=(-1))
    {
        printf("%i",fraccion[i3]);
        i3++;
    }
    printf("\n");
    return 0;
}
