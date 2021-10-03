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
    printf("%d",*(enteroXa10(origen,n,cantDig,mostrar)));
    free(origen);
    free(n);
    free(cantDig);
    free(mostrar);
    return 0;
}
