#include <cambioDeBase.h>
#include <leerInput.h>

int main(int argc, char *argv[])
{
    int * origen= (int *)malloc(sizeof(int));
    *origen=16;
    int * n= (int *)malloc(sizeof(int)*4);
    n[0]=10;
    n[1]=13;
    n[2]=4;
    n[3]=5;
    int * cantDig= (int *)malloc(sizeof(int));
    *cantDig=4;
    int * mostrar= (int *)malloc(sizeof(int));
    *mostrar=1;
    printf("Resultado: %d",*(enteroXa10(origen,n,cantDig,mostrar)));
    printf("\n");
    printf("\n");
    free(origen);
    free(n);
    free(cantDig);
    free(mostrar);


    int *destino = (int*)malloc(sizeof(int));
    *destino = 2;
    int *cant = (int*)malloc(sizeof(int));
    *cant = 5;
    int *numero = (int*)malloc(sizeof(int)*(*cant));
    int *mostro = (int*)malloc(sizeof(int));
    *mostro = 1;
    numero[0] = 2;
    numero[1] = 0;
    numero[2] = 0;
    numero[3] = 9;
    numero[4] = 9;
    int* base8 = entero10aX(destino,numero,cant,mostro);
    printf("\n");
    int i =0;
    while(base8[i]!=(-1)){
        printf("%i",base8[i]);
        i++;
    }
    printf("\n");
    free(destino);
    free(base8);
    free(numero);
    free(cant);
    free(mostro);
    return 0;
}
