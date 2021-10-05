#include "cambioDeBase.h"
#include "leerInput.h"

int main(int argc, char *argv[])
{
    int *origen;
    origen= (int*)malloc(sizeof(int));
    *origen=16;
    int *n;
    n= (int*)malloc(sizeof(int));
    n[0]= 15;
    n[1]= 15;
    n[2]= 15;
    n[3]= 15;
    n[4]= 15;
    n[5]= 15;
    n[6]= 15;
    n[7]= 15;
    n[8]= 15;
    n[9]= 15;
    n[10]= -1;
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
    //Test 2
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
    printf("\n");
    int i =0;
    while(base8[i]!=(-1))
    {
        printf("%i",base8[i]);
        i++;
    }
    printf("\n");
    free(destino);
    free(base8);
    free(numero);
    free(mostro);
    return 0;
}
