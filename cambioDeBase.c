#include "cambioDeBase.h"

int * enteroXa10 (int * origen,int * n,int * cantDig,int * mostrar)
{
    int * ultDig= (int *)malloc(sizeof(int));
    int * suma= (int *)malloc(sizeof(int));
    *ultDig=*cantDig-1;
    *suma=0;
    for(int i=*ultDig,exp=0; i>=0; i--,exp++)
    {
        *suma=*suma+(n[i]*pow(*origen,exp));
        if(*suma>=10000000000)
            return NULL; // La suma excede los 10 dígitos(¿Cortar iteración o devolver nada?)
        if(*mostrar==1)
        {
            printf("Operacion realizada: %lf + %d * %d ^ %d\n",*suma-(n[i]*pow(*origen,exp)),n[i],*origen,exp);
            printf("Se obtuvo parcialmente %d\n",*suma);
        }
    }
    free(ultDig);
    return suma;
}
